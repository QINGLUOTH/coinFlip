#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CoinFlipWindows.h"

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
    QMainWindow* qm;
    Windows* win;
//    void paintEvent(QPaintEvent* qpe);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
