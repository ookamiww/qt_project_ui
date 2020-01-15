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


}

void MainWindow::addPlayList()
{

}
