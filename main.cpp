#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"

#include<iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage()
{
    QStringList fileName = QFileDialog::getOpenFileNames(this, tr("Sélectionner une image"), ".", tr("Image (.png)"));
    this->filePath = fileName[0];
}

void MainWindow::printImage()
{
    QImage img;
    img.load(filePath);
}
