#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui -> pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> pushButton_persent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> pushButton_ac, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui -> pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui -> pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui -> pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui -> pushButton_devide, SIGNAL(clicked()), this, SLOT(math_operations()));
    ui -> pushButton_plus -> setCheckable(1);
    ui -> pushButton_minus -> setCheckable(1);
    ui -> pushButton_multiply -> setCheckable(1);
    ui -> pushButton_devide -> setCheckable(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() {
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if (ui -> result_show -> text().contains('.') && button -> text() == "0")
        new_label = ui -> result_show -> text() + button -> text();
    else {
        all_numbers = (ui -> result_show -> text() + button -> text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }
    ui -> result_show -> setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui -> result_show -> text().contains('.')))
        ui -> result_show -> setText(ui -> result_show -> text() + ".");
}

void MainWindow::operations() {
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if (button -> text() == "+/-") {
        all_numbers = (ui -> result_show -> text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui -> result_show -> setText(new_label);
    }
    else if (button -> text() == "%") {
        all_numbers = (ui -> result_show -> text()).toDouble();
        all_numbers *= 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui -> result_show -> setText(new_label);
    }
    else if (button -> text() == "AC") {
        ui -> pushButton_plus -> setChecked(0);
        ui -> pushButton_minus -> setChecked(0);
        ui -> pushButton_multiply -> setChecked(0);
        ui -> pushButton_devide -> setChecked(0);
        ui -> result_show -> setText("0");
    }
}

void MainWindow::math_operations() {
    QPushButton *button = (QPushButton *)sender();
    num_first = ui -> result_show -> text().toDouble();
    ui -> result_show -> setText("");
    button -> setChecked(1);

}

void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, num_second;
    QString new_label;
    num_second = ui -> result_show -> text().toDouble();
    if (ui -> pushButton_plus -> isChecked()) {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui -> result_show -> setText(new_label);
        ui -> pushButton_plus -> setChecked(0);
    }
    else if (ui -> pushButton_minus -> isChecked()) {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui -> result_show -> setText(new_label);
        ui -> pushButton_minus -> setChecked(0);
    }
    else if (ui -> pushButton_multiply -> isChecked()) {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui -> result_show -> setText(new_label);
        ui -> pushButton_multiply -> setChecked(0);
    }
    else if (ui -> pushButton_devide -> isChecked()) {
        if (num_second == 0)
            ui -> result_show -> setText("0");
        else {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);
            ui -> result_show -> setText(new_label);
        }
        ui -> pushButton_devide -> setChecked(0);
    }
}



















