#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QLayout>
#include <QStackedWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>


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
    QVideoWidget *videoWidget;
    QLayout *centerLayout;

    void initWindow();
    void addPlayList();

};

#endif // MAINWINDOW_H
