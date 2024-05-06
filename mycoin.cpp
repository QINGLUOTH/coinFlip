#include "mycoin.h"
#include <QString>
#include <QTimer>

MyCoin::MyCoin(QWidget *parent)
    : QPushButton{parent}
{

}

MyCoin::MyCoin(QString img){
    QPixmap localQPixmap = QPixmap();
    // 加载金币图片
    localQPixmap.load(img);

    // 设置按钮大小
    this->setFixedSize(localQPixmap.width(), localQPixmap.height());
    // 设置样式
    this->setStyleSheet("QPushButton{border:0px;}");
    // 设置图片
    this->setIcon(localQPixmap);
    // 设置图片大小
    this->setIconSize(QSize(localQPixmap.width(), localQPixmap.height()));
}

void MyCoin::setPix(int i){
    isAnimation = true;
    if (i == 1){
        QTimer* qt = new QTimer(this);
        qt->start(50);
        connect(qt, &QTimer::timeout, [=](){
            QPixmap localQPixmap = QPixmap();
            // 加载金币图片
            QString qs = QString(":/res/res/Coin000%1.png").arg(this->min++);
            localQPixmap.load(qs);

            // 设置按钮大小
            this->setFixedSize(localQPixmap.width(), localQPixmap.height());
            // 设置样式
            this->setStyleSheet("QPushButton{border:0px;}");
            // 设置图片
            this->setIcon(localQPixmap);
            // 设置图片大小
            this->setIconSize(QSize(localQPixmap.width(), localQPixmap.height()));
            if (max < min){
                min = 1;
                isAnimation = false;
                qt->stop();
            }
        });

    } else {
        QTimer* qt = new QTimer(this);
        qt->start(50);
        connect(qt, &QTimer::timeout, [=](){
            QPixmap localQPixmap = QPixmap();
            // 加载金币图片
            QString qs = QString(":/res/res/Coin000%1.png").arg(this->max--);
            localQPixmap.load(qs);

            // 设置按钮大小
            this->setFixedSize(localQPixmap.width(), localQPixmap.height());
            // 设置样式
            this->setStyleSheet("QPushButton{border:0px;}");
            // 设置图片
            this->setIcon(localQPixmap);
            // 设置图片大小
            this->setIconSize(QSize(localQPixmap.width(), localQPixmap.height()));
            if (max < min){
                max = 8;
                isAnimation = false;
                qt->stop();
            }
        });
    }

}

// 优化, 只有在金币翻完后才能继续翻
// mousePressEvent鼠标按下时执行
void MyCoin::mousePressEvent(QMouseEvent* qme){
    if (isAnimation){
        return;
    }else {
        QPushButton::mousePressEvent(qme);
    }
}
