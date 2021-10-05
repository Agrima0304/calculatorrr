#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

double firstNum;
bool userIsTypingSecondNumber=false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setAlignment(Qt::AlignRight);
    connect(ui->zero,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->one,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->two,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->three,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->four,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->five,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->six,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->seven,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->eight,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->nine,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->plusminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->multiplication,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    ui->plus->setCheckable(true);
     ui->minus->setCheckable(true);
      ui->multiplication->setCheckable(true);
       ui->divide->setCheckable(true);






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if((ui->plus->isChecked()||ui->minus->isChecked()||ui->multiplication->isChecked()||ui->divide->isChecked())&&(!userIsTypingSecondNumber))
    {
       labelNumber=button->text().toDouble();
       userIsTypingSecondNumber=true;
       newLabel=QString::number(labelNumber,'g',15);
    }
    else
       {
        if(ui->label->text().contains('.')&&button->text()=="0")
        {
            newLabel=ui->label->text()+button->text();
        }
        else
        {
            labelNumber=(ui->label->text()+button->text()).toDouble();
             newLabel=QString::number(labelNumber,'g',15);
        }

    }
    ui->label->setText(newLabel);
}



void MainWindow::on_decimal_released()
{
    ui->label->setText(ui->label->text()+".");
}
void MainWindow::unary_operation_pressed()
{
    QPushButton *button=(QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if(button->text()=="+/-")
    {
        labelNumber=ui->label->text().toDouble();
        labelNumber=labelNumber*-1;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text()=="%")
    {
        labelNumber=ui->label->text().toDouble();
        labelNumber=labelNumber*0.01;
        newLabel=QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

}



void MainWindow::on_clear_released()
{
ui->plus->setChecked(false);
ui->minus->setChecked(false);
ui->multiplication->setChecked(false);
ui->divide->setChecked(false);
userIsTypingSecondNumber=false;
ui->label->setText("0");
}


void MainWindow::on_equalto_released()
{
    double labelNumber,secondNum;
    QString newLabel;
    secondNum=ui->label->text().toDouble();

 if(ui->plus->isChecked())
 {
     labelNumber=firstNum+secondNum;
     newLabel=QString::number(labelNumber,'g',15);
     ui->label->setText(newLabel);
     ui->plus->setChecked(false);
 }
 else if(ui->minus->isChecked())
 {
     labelNumber=firstNum-secondNum;
     newLabel=QString::number(labelNumber,'g',15);
     ui->label->setText(newLabel);
     ui->minus->setChecked(false);
 }
 else if(ui->multiplication->isChecked())
 {
     labelNumber=firstNum*secondNum;
     newLabel=QString::number(labelNumber,'g',15);
     ui->label->setText(newLabel);
     ui->multiplication->setChecked(false);
 }
 else if(ui->divide->isChecked())
 {
     labelNumber=firstNum/secondNum;
     newLabel=QString::number(labelNumber,'g',15);
     ui->label->setText(newLabel);
     ui->divide->setChecked(false);
 }
 userIsTypingSecondNumber=false;
}
void MainWindow::binary_operation_pressed()
{
  QPushButton *button=(QPushButton*)sender();
  firstNum=ui->label->text().toDouble();
  button->setChecked(true);
}

