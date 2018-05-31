#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "pelota.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <stdlib.h>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *MiEscena;
    QTimer *timer;
    pelota *esfera;
    QList <pelota*> esferas;

};


#endif // MAINWINDOW_H
