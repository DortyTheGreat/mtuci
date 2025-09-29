/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *trackList;
    QHBoxLayout *controlsLayout;
    QToolButton *prevButton;
    QToolButton *playButton;
    QToolButton *pauseButton;
    QToolButton *stopButton;
    QToolButton *nextButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QHBoxLayout *positionLayout;
    QSlider *positionSlider;
    QLabel *timeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(640, 360);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        trackList = new QListWidget(centralwidget);
        trackList->setObjectName("trackList");

        verticalLayout->addWidget(trackList);

        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        prevButton = new QToolButton(centralwidget);
        prevButton->setObjectName("prevButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/prev.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevButton->setIcon(icon);

        controlsLayout->addWidget(prevButton);

        playButton = new QToolButton(centralwidget);
        playButton->setObjectName("playButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/play.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        playButton->setIcon(icon1);

        controlsLayout->addWidget(playButton);

        pauseButton = new QToolButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/pause.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pauseButton->setIcon(icon2);

        controlsLayout->addWidget(pauseButton);

        stopButton = new QToolButton(centralwidget);
        stopButton->setObjectName("stopButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/stop.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stopButton->setIcon(icon3);

        controlsLayout->addWidget(stopButton);

        nextButton = new QToolButton(centralwidget);
        nextButton->setObjectName("nextButton");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/next.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextButton->setIcon(icon4);

        controlsLayout->addWidget(nextButton);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        controlsLayout->addItem(horizontalSpacer);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        controlsLayout->addWidget(addButton);


        verticalLayout->addLayout(controlsLayout);

        positionLayout = new QHBoxLayout();
        positionLayout->setObjectName("positionLayout");
        positionSlider = new QSlider(centralwidget);
        positionSlider->setObjectName("positionSlider");
        positionSlider->setOrientation(Qt::Horizontal);

        positionLayout->addWidget(positionSlider);

        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");

        positionLayout->addWidget(timeLabel);


        verticalLayout->addLayout(positionLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MP3 Player", nullptr));
#if QT_CONFIG(tooltip)
        prevButton->setToolTip(QCoreApplication::translate("MainWindow", "Previous", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        playButton->setToolTip(QCoreApplication::translate("MainWindow", "Play", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pauseButton->setToolTip(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        stopButton->setToolTip(QCoreApplication::translate("MainWindow", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        nextButton->setToolTip(QCoreApplication::translate("MainWindow", "Next", nullptr));
#endif // QT_CONFIG(tooltip)
        addButton->setText(QCoreApplication::translate("MainWindow", "Add tracks...", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "00:00 / 00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
