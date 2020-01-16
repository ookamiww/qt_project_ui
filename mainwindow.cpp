#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete topWidget;
    delete mainLayout;
    delete player;
    delete videoWidget;
    delete list;
}

void MainWindow::initWindow()
{
    //主界面
    ui->centralWidget->setStyleSheet("border-image: url(./01.png)");
    this->setFixedSize(QGuiApplication::primaryScreen()->availableSize());
    topWidget = new QStackedWidget(ui->centralWidget);
    topWidget->setStyleSheet("border-image: url(./02.png)");
    topWidget->setFixedSize(QGuiApplication::primaryScreen()->availableSize());
    topWidget->raise();

    //播放器
    player = new QMediaPlayer();
    videoWidget = new QVideoWidget();
    player->setVideoOutput(videoWidget);

    mainLayout = new QGridLayout(ui->centralWidget);
    mainLayout->addWidget(videoWidget,1,2,5,2,Qt::AlignCenter);

    mainLayout->setColumnStretch(0,13);
    mainLayout->setColumnStretch(1,23);
    mainLayout->setColumnStretch(6,13);
    mainLayout->setRowStretch(0,5);
    mainLayout->setRowStretch(1,20);
    mainLayout->setRowStretch(2,2);

}

void MainWindow::addPlayList()
{
    QDir dir("/home/ricardo/Videos/201_1215248922");

    QStringList filters;
    filters << "*.mp4" << "*.avi" << "*.mkv" << "*.ts";

    QFileInfoList fileNames = dir.entryInfoList(filters,QDir::Files|QDir::NoSymLinks);

    list = new QMediaPlaylist();
    for (int i = 0; i < fileNames.length(); i++) {
//        qDebug() << fileNames.at(i).absoluteFilePath() << endl;
        list->addMedia(QMediaContent(QUrl::fromLocalFile(fileNames.at(i).absoluteFilePath())));
    }

    list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(list);
    playVideo();

}

void MainWindow::playVideo()
{
    playerStatus = player->PlayingState;
    player->play();
}
