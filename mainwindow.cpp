#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include "maininterface.h"
#include <QStackedWidget>
#include <mystartpushbutton.h>
#include "chooselevelscene.h"
#include "CoinFlipWindows.h"
#include "levelinterface.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置窗口的大小
    this->setFixedSize(320, 588);

    // 设置窗口标题
    this->setWindowTitle("翻金币");
    // 设置窗口图标
    this->setWindowIcon(QIcon(":/res/res/Coin0001.png"));
    // 主页面
    MainInterface* mainInterface = new MainInterface;
    mainInterface->setFixedSize(this->width(), this->height());
//    mainInterface->show();

    Windows* win = new Windows;
    ChooseLevelScene* chooseLevelScene = new ChooseLevelScene;
    chooseLevelScene->setFixedSize(this->width(), this->height());
    LevelInterface* levelInterface = new LevelInterface;
    levelInterface->setFixedSize(this->width(), this->height());

    // 实现同一窗口切换页面
    QStackedWidget* stackedWidget = new QStackedWidget(this);

    win->mainInterfacei = stackedWidget->addWidget(mainInterface);
    win->chooseLevelScenei = stackedWidget->addWidget(chooseLevelScene);
    win->levelInterfacei = stackedWidget->addWidget(levelInterface);

    win->qMainWindow = this;
    win->mainInterface = mainInterface;
    win->chooseLevelScene = chooseLevelScene;
    win->levelInterface = levelInterface;
    win->stackedWidget = stackedWidget;
    mainInterface->w = win;
    this->win = win;
    chooseLevelScene->w = win;
    levelInterface->w = win;

    stackedWidget->setFixedSize(this->width(), this->height());
    stackedWidget->setCurrentIndex(win->mainInterfacei);

    chooseLevelScene->ChooseLevelSceneInterfaceInitFunc();
    mainInterface->mainInterfaceInitFunc();
    levelInterface->levelInterfaceInterfaceInitFunc();
}

//void MainWindow::paintEvent(QPaintEvent* qpe){
//    QPainter qp(this);
//    QPixmap qpm;
//    qpm.load(":/res/res/OtherSceneBg.png");
//    qpm.scaled(this->width() * 0.5, this->height() * 0.5);  // 缩放
//    qp.drawPixmap(0, 0, this->width(), this->height(), qpm);

//    qpm.load(":/res/res/Title.png");
//    qpm.scaled(this->width() * 0.5, this->height() * 0.5);  // 缩放
//    qp.drawPixmap(10, 30, qpm);
//}

MainWindow::~MainWindow()
{
    delete win;
    delete ui;
}

