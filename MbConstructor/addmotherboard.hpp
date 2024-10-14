#ifndef ADDMOTHERBOARD_H
#define ADDMOTHERBOARD_H

#include <QDialog>
#include <iostream>
#include <QString>
#include <QErrorMessage>

namespace Ui
{
class AddMotherboard;
}

class AddMotherboard : public QDialog
{
    Q_OBJECT

public:
    explicit AddMotherboard(QWidget *parent = nullptr);
    ~AddMotherboard();

    int getWidht();
    int getHeight();

    void setWidth(int widthVal);
    void setHeight(int heightVal);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddMotherboard *ui;

    int height;
    int width;
};

#endif // ADDMOTHERBOARD_H
