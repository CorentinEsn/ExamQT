#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "QPainter"

#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonOpen, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->pushButtonSave, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::changePosX);
    connect(ui->verticalSlider, &QSlider::valueChanged, this, &MainWindow::changePosY);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage()
{
    QStringList fileName = QFileDialog::getOpenFileNames(this, tr("Sélectionner une image"), ".", tr("PNG Image (*.png);;All (*.*)"));
    this->filePath = fileName[0];
}

void MainWindow::printImage()
{
    QImage img;
    img.load(filePath);
}

void MainWindow::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Sélectionner une image"), ".", tr("PNG Image (*.png);;All (*.*)"));
    this->filePath = fileName[0];

    QImage img;
    img = img.copy(posX, posY, width, height);
    img.save(filePath);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QImage img;
    img.load(filePath);

    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), img);

    painter.setPen(QPen(Qt::red, 1));
    painter.drawRect(posX, posY, width, height);
}

void MainWindow::changePosX(int value)
{
    this->posX = value;
    update();
}

void MainWindow::changePosY(int value)
{
    this->posY = value;
    update();
}
