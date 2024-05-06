#include "maininterface.h"
#include "ui_maininterface.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QTimer>
#include "maininterface.h"
#include <mystartpushbutton.h>
#include <QDebug>
#include <QSoundEffect>

MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);

    // 退出按钮
    connect(ui->closeAction, &QAction::triggered, [this](){
        this->w->qMainWindow->close();
    });


}

MainInterface::~MainInterface()
{
    delete ui;
}

void MainInterface::paintEvent(QPaintEvent* qpe){
    QPainter qp(this);
    QPixmap qpm;
    qpm.load(":/res/res/PlayLevelSceneBg.png");
//    qpm.scaled(this->width() * 0.5, this->height() * 0.5);  // 缩放
    qp.drawPixmap(0, 0, this->width(), this->height(), qpm);

    qpm.load(":/res/res/Title.png");
    qpm = qpm.scaled(qpm.width() * 0.5, qpm.height() * 0.5);  // 缩放
    qp.drawPixmap(10, 30, qpm);
}

void MainInterface::mainInterfaceInitFunc(){
    // 开始按钮
    MyStartPushButton* mspb = new MyStartPushButton(":/res/res/MenuSceneStartButton.png");
    mspb->setParent(this);
    mspb->move(this->width() * 0.5 - mspb->width() * 0.5,this->height() * 0.7);

    // 设置开始音效
    // 设置播放音频
    QSoundEffect* qse = new QSoundEffect;
    qse->setParent(this);
    qse->setSource(QUrl::fromLocalFile(":/res/res/TapButtonSound.wav"));
    // 设置声音大小
    qse->setVolume(0.25);

    connect(mspb, &QPushButton::clicked, [mspb, this, qse](){
        mspb->zoom1();
        mspb->zoom2();

        // 开始播放音频
        qse->play();

        // 延时执行
        QTimer::singleShot(500, this, [this](){
            this->w->stackedWidget->setCurrentIndex(this->w->chooseLevelScenei);
        });
    });
}

