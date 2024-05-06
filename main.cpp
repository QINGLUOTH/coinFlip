#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>

// 翻金币案例
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->show();
    return a.exec();
}
