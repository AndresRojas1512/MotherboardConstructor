#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addMotherboardButton_clicked()
{
    AddMotherboard motherboard(nullptr);
    motherboard.setModal(true);
    motherboard.exec();

    if (motherboard.getWidht() == -1 || motherboard.getHeight() == -1)
    {
        return;
    }
}
