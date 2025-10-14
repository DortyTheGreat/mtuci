#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentIndex(-1)
{

    audioOutput = new QAudioOutput(this);
    player = new QMediaPlayer(this);
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(1.0); // громкость от 0.0 до 1.0

    ui->setupUi(this);

    //connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->playButton, &QToolButton::clicked, this, &MainWindow::on_playButton_clicked);
    connect(ui->pauseButton, &QToolButton::clicked, this, &MainWindow::on_pauseButton_clicked);
    connect(ui->stopButton, &QToolButton::clicked, this, &MainWindow::on_stopButton_clicked);
    //connect(ui->nextButton, &QToolButton::clicked, this, &MainWindow::on_nextButton_clicked);
    //connect(ui->prevButton, &QToolButton::clicked, this, &MainWindow::on_prevButton_clicked);
    connect(ui->trackList, &QListWidget::doubleClicked, this, &MainWindow::on_trackList_doubleClicked);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(ui->positionSlider, &QSlider::sliderMoved, this, &MainWindow::on_positionSlider_sliderMoved);

    ui->positionSlider->setRange(0,0);

    loadDefaultTracks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("Choose MP3 files"),
                                                      QString(), tr("Audio Files (*.mp3 *.wav *.m4a)"));
    for (const QString &f : files) {
        trackFiles.append(f);
        ui->trackList->addItem(QFileInfo(f).fileName());
    }
    if (currentIndex == -1 && !trackFiles.isEmpty()) {
        currentIndex = 0;
    }
}

void MainWindow::playTrack(int index)
{
    if (index < 0 || index >= trackFiles.size()) return;

    currentIndex = index;
    player->setSource(QUrl::fromLocalFile(trackFiles.at(index)));
    player->play();
    ui->trackList->setCurrentRow(index);
}

void MainWindow::on_playButton_clicked()
{
    if (trackFiles.isEmpty()) return;

    if (player->source().isEmpty()) {
        playTrack(currentIndex >= 0 ? currentIndex : 0);
    } else {
        player->play();
    }
}

void MainWindow::on_pauseButton_clicked()
{
    player->pause();
}

void MainWindow::on_stopButton_clicked()
{
    player->stop();
}

void MainWindow::on_nextButton_clicked()
{
    if (trackFiles.isEmpty()) return;
    int next = (currentIndex + 1) % trackFiles.size();
    playTrack(next);
}

void MainWindow::on_prevButton_clicked()
{
    if (trackFiles.isEmpty()) return;
    int prev = (currentIndex - 1 + trackFiles.size()) % trackFiles.size();
    playTrack(prev);
}

void MainWindow::on_trackList_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    playTrack(row);
}

void MainWindow::positionChanged(qint64 pos)
{
    ui->positionSlider->setValue(static_cast<int>(pos));
    QString cur = msToString(pos);
    QString total = msToString(player->duration());
    ui->timeLabel->setText(cur + " / " + total);
}

void MainWindow::durationChanged(qint64 dur)
{
    ui->positionSlider->setRange(0, static_cast<int>(dur));
}

void MainWindow::on_positionSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::loadDefaultTracks()
{
    QDir d(QDir::currentPath() + "/tracks");
    if (!d.exists()) return;

    QStringList mp3s = d.entryList(QStringList() << "*.mp3" << "*.wav" << "*.m4a", QDir::Files);
    for (const QString &f : mp3s) {
        QString full = d.filePath(f);
        trackFiles.append(full);
        ui->trackList->addItem(f);
    }
    if (!trackFiles.isEmpty()) {
        currentIndex = 0;
    }
}

QString MainWindow::msToString(qint64 ms)
{
    int s = static_cast<int>(ms/1000);
    int minutes = s/60;
    int seconds = s%60;
    return QString::asprintf("%02d:%02d", minutes, seconds);
}
