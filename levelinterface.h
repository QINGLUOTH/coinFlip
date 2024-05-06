#ifndef LEVELINTERFACE_H
#define LEVELINTERFACE_H

#include <QMainWindow>
#include "CoinFlipWindows.h"
#include <QPainter>
#include <QLabel>
#include <vector>
#include <QPushButton>
#include "mycoin.h"
#include "mystartpushbutton.h"
#include "dataconfig.h"

class LevelInterface : public QMainWindow
{
    Q_OBJECT
public:
    explicit LevelInterface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* qpe);
    Windows* w;
    void extracted();
    void levelInterfaceInterfaceInitFunc();
    void setLevelInterfaceFunc(int i);
    QLabel* qlabel;
    std::vector<QPushButton*> v;
    void qPushButtonDestroy();
    int gameData[4][4];
    bool isAllOne();
    MyCoin* coins[4][4];
    QLabel* ql;
signals:

};

#endif // LEVELINTERFACE_H
