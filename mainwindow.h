#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadImage();
    void printImage();
    void paintEvent(QPaintEvent *e);
    void saveImage();
    // modifier la position du rectangle en abscisse
        void changePosX(int value);

        // modifier la position du rectangle en coordonnée
        void changePosY(int value);

private:
    Ui::MainWindow *ui;
    QString filePath;
    int posX;
    int posY;
    int width;
    int height;
};
#endif // MAINWINDOW_H
