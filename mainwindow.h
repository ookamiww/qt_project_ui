#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QLayout>
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDir>
#include <QFileInfo>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QWidget *topWidget;
    QMediaPlayer *player;
    QMediaPlaylist *list;
    QMediaPlayer::State playerStatus;
    QVideoWidget *videoWidget;
    QLayout *centerLayout;

    void initWindow();
    void addPlayList();
    void playVideo();

};

#endif // MAINWINDOW_H
