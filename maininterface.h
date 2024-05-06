#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QStackedWidget>
#include "CoinFlipWindows.h"

namespace Ui {
class MainInterface;
}

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterface(QWidget *parent = nullptr);
    ~MainInterface();
    void paintEvent(QPaintEvent* qpe);
    Windows* w;
    void mainInterfaceInitFunc();
private:
    Ui::MainInterface *ui;
};



#endif // MAININTERFACE_H
