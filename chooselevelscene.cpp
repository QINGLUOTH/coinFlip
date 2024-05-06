#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"
#include <QPainter>
#include <QMenuBar>
#include <mystartpushbutton.h>
#include <QLabel>
#include "levelinterface.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);
}

void ChooseLevelScene::ChooseLevelSceneInterfaceInitFunc(){
    QMenuBar* chooseLevelSceneQMenuBar = new QMenuBar();
    // 将菜单设置到当前界面中
    this->setMenuBar(chooseLevelSceneQMenuBar);
    QMenu* chooseLevelSceneQMenuBarM = new QMenu("开始");
    chooseLevelSceneQMenuBar->addMenu(chooseLevelSceneQMenuBarM);
    QAction* qa = new QAction("退出");
    chooseLevelSceneQMenuBarM->addAction(qa);
    // 退出按钮
    connect(qa, &QAction::triggered, [this](){
        this->w->qMainWindow->close();
    });

    // 返回按钮
    MyStartPushButton* mspb = new MyStartPushButton(":/res/res/BackButton.png",
                                                    ":/res/res/BackButtonSelected.png");

    // 设置按钮位置
    mspb->move(this->w->qMainWindow->width()-mspb->width(),
               this->w->qMainWindow->height()-mspb->height());
    mspb->setParent(this);

    // 设置开始音效
    // 设置播放音频
    QSoundEffect* qse1 = new QSoundEffect;
    qse1->setParent(this);
    qse1->setSource(QUrl::fromLocalFile(":/res/res/BackButtonSound.wav"));
    // 设置声音大小
    qse1->setVolume(0.25);
    connect(mspb, &QPushButton::clicked, [this, qse1](){
        qse1->play();
        this->w->stackedWidget->setCurrentIndex(this->w->mainInterfacei);
    });

    // 设置开始音效
    // 设置播放音频
    QSoundEffect* qse = new QSoundEffect;
    qse->setParent(this);
    qse->setSource(QUrl::fromLocalFile(":/res/res/TapButtonSound.wav"));
    // 设置声音大小
    qse->setVolume(0.25);

    // 创建关卡按钮
    for (int i = 0; i < 20; ++i) {
        MyStartPushButton* localMyStartPushButton = new MyStartPushButton(":/res/res/LevelIcon.png");
        localMyStartPushButton->setParent(this);
        localMyStartPushButton->move(25 + (i % 4) * 70 , 130 + (i / 4) * 70);

        // 设置关卡数字
        QLabel* ql = new QLabel;
        ql->setParent(this);
        ql->setFixedSize(localMyStartPushButton->width(),localMyStartPushButton->height());
        ql->setText(QString::number(i+1));
        ql->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
        ql->move(25 + (i % 4) * 70 , 130 + (i / 4) * 70);
        ql->setAttribute(Qt::WA_TransparentForMouseEvents,true);  //鼠标事件穿透

        connect(localMyStartPushButton, &QPushButton::clicked, [this, i, qse](){
            // 切换关卡页面
            auto levelInterface = ((LevelInterface*)this->w->levelInterface);
            levelInterface->setLevelInterfaceFunc(i+1);
            this->w->stackedWidget->setCurrentIndex(this->w->levelInterfacei);

            // 开始播放音频
            qse->play();
        });

    }
}

void ChooseLevelScene::paintEvent(QPaintEvent* qpe){
    QPainter qp(this);
    QPixmap qpm;
    qpm.load(":/res/res/OtherSceneBg.png");
    //    qpm.scaled(this->width() * 0.5, this->height() * 0.5);  // 缩放
    qp.drawPixmap(0, 0, this->width(), this->height(), qpm);

    qpm.load(":/res/res/Title.png");
    qp.drawPixmap((this->width() - qpm.width()) * 0.5, 30, qpm.width(), qpm.height(), qpm);
}

ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}
