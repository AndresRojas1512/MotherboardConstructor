#include "addmotherboard.hpp"
#include "ui_addmotherboard.h"

AddMotherboard::AddMotherboard(QWidget *parent) : QDialog(parent), ui(new Ui::AddMotherboard)
{
    std::cout << "AddMotherboard Constructor" << std::endl;
    ui->setupUi(this);
    this->setWindowTitle("Choose motherboard");
}

AddMotherboard::~AddMotherboard()
{
    delete ui;
}


void AddMotherboard::on_buttonBox_accepted()
{
    QString heightStr = this->ui->lineEdit->text();
    int heightValue = heightStr.toInt();

    QString widthStr = this->ui->lineEdit_2->text();
    int widthValue = widthStr.toInt();

    if (heightValue > 0 && widthValue > 0)
    {
        this->height = heightValue;
        this->width = widthValue;
    }
    else
    {
        QErrorMessage *error = new QErrorMessage();
        error->showMessage("Enter natural numbers!");
    }
    this->close();
};

int AddMotherboard::getWidht()
{
    return this->width;
}

int AddMotherboard::getHeight()
{
    return this->height;
}

void AddMotherboard::setWidth(int widthVal)
{
    this->width = widthVal;
}

void AddMotherboard::setHeight(int heightVal)
{
    this->height = heightVal;
}
