#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    atmosphereModel = new atmosphere_exponential(1.225, 101325, 9.81);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculateButton_clicked()
{
    double height = ui->lineEdit->text().toDouble();

    double density = atmosphereModel->getDensity(height, 0.0);

    QString output = QString("Height = %1 m\nDensity = %2 kg/m³").arg(height).arg(density, 0, 'e', 6);

    ui->textBrowser->setText(output);
}

