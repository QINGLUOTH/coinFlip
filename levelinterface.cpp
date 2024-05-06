#include "levelinterface.h"
#include <QMenuBar>
#include "mystartpushbutton.h"
#include "qlabel.h"
#include <QLabel>
#include "mycoin.h"
#include <iostream>
#include <QPropertyAnimation>

LevelInterface::LevelInterface(QWidget *parent)
    : QMainWindow{parent}
{

}

void LevelInterface::paintEvent(QPaintEvent* qpe){
    QPainter qp(this);
    QPixmap qpm;
    qpm.load(":/res/res/PlayLevelSceneBg.png");
    //    qpm.scaled(this->width() * 0.5, this->height() * 0.5);  // 缩放
    qp.drawPixmap(0, 0, this->width(), this->height(), qpm);

    qpm.load(":/res/res/Title.png");
    qpm = qpm.scaled(qpm.width() * 0.5, qpm.height() * 0.5);  // 缩放
    qp.drawPixmap(10, 30, qpm);
}

void LevelInterface::levelInterfaceInterfaceInitFunc(){
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

    // 创建胜利图片
    QPixmap qp;
    qp.load(":/res/res/LevelCompletedDialogBg.png");
    // 使用QLabel显示图片
    QLabel* ql = new QLabel();
    this->ql = ql;
    ql->setPixmap(qp);
    ql->setFixedSize(qp.width(), qp.height());
    //                    ql->setGeometry(0,0,qp.width(),qp.height());
    ql->move( (this->width() - qp.width())*0.5 , -qp.height());
    ql->setParent(this);
    ql->setAttribute(Qt::WA_DeleteOnClose);

    // 设置开始音效
    // 设置播放音频
    QSoundEffect* qse1 = new QSoundEffect;
    qse1->setParent(this);
    qse1->setSource(QUrl::fromLocalFile(":/res/res/BackButtonSound.wav"));
    // 设置声音大小
    qse1->setVolume(0.25);
    connect(mspb, &QPushButton::clicked, [this, ql, qse1](){
        qse1->play();
        this->w->stackedWidget->setCurrentIndex(this->w->chooseLevelScenei);
    });

    // 显示关卡
    QLabel* qlabel = new QLabel();
    this->qlabel = qlabel;
    // 绑定显示界面
    qlabel->setParent(this);

    // 设置字体
    QFont qf;
    qf.setFamily("幼圆");
    qf.setPointSize(20);
    qlabel->setFont(qf);
    // 设置label位置和大小
    qlabel->setGeometry(QRect(30, this->height() - 50, 120, 50));

    // 创建金币的背景图
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            QLabel* ql = new QLabel;
            QPixmap localQPixmap = QPixmap(":/res/res/BoardNode(1).png");
            ql->setParent(this);
            // 设置图片
            ql->setPixmap(localQPixmap);

            // 设置起始位置
            ql->setGeometry(QRect(0, 0, localQPixmap.width(), localQPixmap.height()));
            // 设置标签位置
            ql->move(57 + i * 50 ,200 + j * 50);
        }
    }


}

// 判断是否通关
bool LevelInterface::isAllOne(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (this->gameData[i][j] == 0){
                return false;
            }
        }
    }

    return true;
}

void LevelInterface::qPushButtonDestroy(){
    for (int i = 0; i < this->v.size(); ++i) {
        v.at(i)->close();
    }

    v.clear();
}

void LevelInterface::setLevelInterfaceFunc(int currentLevelNum){
    ql->move( (this->width() - ql->width())*0.5 , -ql->height());

    dataConfig* dc = new dataConfig;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            this->gameData[i][j] = dc->mData[currentLevelNum][i][j];
        }
    }

    this->qPushButtonDestroy();
    // 设置标签内容
    this->qlabel->setText("level: " + QString::number(currentLevelNum));

    // 设置开始音效
    // 设置播放音频
    QSoundEffect* qse = new QSoundEffect;
    qse->setParent(this);
    qse->setSource(QUrl::fromLocalFile(":/res/res/ConFlipSound.wav"));
    QSoundEffect* qse1 = new QSoundEffect;
    qse1->setParent(this);
    qse1->setSource(QUrl::fromLocalFile(":/res/res/LevelWinSound.wav"));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            MyCoin* coin;
            if (this->gameData[i][j] == 1){
                // 1是金币
                coin = new MyCoin(":/res/res/Coin0001.png");
                // 设置显示窗口
                coin->setParent(this);
                // 设置coin在窗口上的位置
                coin->move(59 + i * 50 ,204 + j * 50);
                v.push_back(coin);
                coin->setAttribute(Qt::WA_DeleteOnClose);
            }else {
                // 0是银币
                coin = new MyCoin(":/res/res/Coin0008.png");
                // 设置显示窗口
                coin->setParent(this);
                // 设置coin在窗口上的位置
                coin->move(59 + i * 50 ,204 + j * 50);
                v.push_back(coin);
                coin->setAttribute(Qt::WA_DeleteOnClose);
            }
            this->coins[i][j] = coin;

            connect(coin, &QPushButton::clicked, [=](){
                qse->play();
                coin->setPix(this->gameData[i][j]);
                this->gameData[i][j] = !(this->gameData[i][j]);

                if (!(j >= 3)){
                    this->coins[i][j + 1]->setPix(this->gameData[i][j + 1]);
                    this->gameData[i][j + 1] = !(this->gameData[i][j + 1]);
                }

                if (!(j <= 0)){
                    this->coins[i][j - 1]->setPix(this->gameData[i][j - 1]);
                    this->gameData[i][j - 1] = !(this->gameData[i][j - 1]);
                }

                if (!(i >= 3)){
                    this->coins[i + 1][j]->setPix(this->gameData[i + 1][j]);
                    this->gameData[i + 1][j] = !(this->gameData[i + 1][j]);
                }

                if (!(i <= 0)){
                    this->coins[i - 1][j]->setPix(this->gameData[i - 1][j]);
                    this->gameData[i - 1][j] = !(this->gameData[i - 1][j]);
                }

                if (this->isAllOne()){
                    // 游戏胜利
//                    qse1->setLoopCount(-1);  // 设置循环次数, -1表示死循环
                    qse1->play();
                    for (int i = 0; i < 4; ++i) {
                        for (int j = 0; j < 4; ++j) {
                            // 禁用按钮
                            // 两种禁用方式
                            this->coins[i][j]->setDisabled(true);
//                            this->coins[i][j]->setEnabled(false);
                        }
                    }

                    // 设置移动的动态效果
                    QPropertyAnimation * animation1 =  new QPropertyAnimation(ql,"geometry");
                    // 设置事件间隔
                    animation1->setDuration(1000);
                    // 设置移动的起始位置
                    animation1->setStartValue(QRect(ql->x(),ql->y(),ql->width(),ql->height()));
                    // 设置移动的结束位置
                    animation1->setEndValue(QRect(ql->x(),ql->y()+114,ql->width(),ql->height()));
                    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
                    animation1->setEasingCurve(QEasingCurve::OutBounce);
                    // 开始执行动态效果
                    animation1->start();
                }
            });
        }
    }


}
