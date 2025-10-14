#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QStringList>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void on_stopButton_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_trackList_doubleClicked(const QModelIndex &index);
    void positionChanged(qint64 pos);
    void durationChanged(qint64 dur);
    void on_positionSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QStringList trackFiles;   // список путей к трекам
    QAudioOutput *audioOutput;
    int currentIndex;         // индекс текущего трека

    void loadDefaultTracks();
    void playTrack(int index);
    QString msToString(qint64 ms);
};

#endif // MAINWINDOW_H
