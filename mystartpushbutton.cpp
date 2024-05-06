#include "mystartpushbutton.h"
#include <QPixmap>
#include <QString>
#include <QDebug>
#include <QPropertyAnimation>

MyStartPushButton::MyStartPushButton(QWidget *parent)
    : QPushButton{parent}
{

}
MyStartPushButton::MyStartPushButton(QString normalImgPath,
                                     QString pressImgPath){
    this->normalImgPath = normalImgPath;
    this->pressImgPath = pressImgPath;
    QPixmap qpm;
    bool isSuccessLoad = qpm.load(normalImgPath);
    if (!isSuccessLoad){
        qDebug() << __LINE__ << ": " << "no success load";
        return;
    }

    // 设置图标大小
    this->setFixedSize(qpm.width(), qpm.height());

    // 设置图片样式
    this->setStyleSheet("QPushButton{border:0px}");  // 设置图片边框为0像素点

    // 设置图片
    this->setIcon(qpm);

    // 设置图标大小
    this->setIconSize(QSize(qpm.width(), qpm.height()));
}

// 按钮弹起特效
void MyStartPushButton::zoom1(){
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}

// 按钮按下特效
void MyStartPushButton::zoom2(){
    // this绑定按钮
    // geometry特效样式
    QPropertyAnimation * animation1 =  new QPropertyAnimation(this,"geometry");
    // 设置间隔时间
    animation1->setDuration(200);
    // 设置开始位置
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    // 设置特效的结束位置
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    // 设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    // 开始执行动画
    animation1->start();
}

// 鼠标按下事件
void MyStartPushButton::mousePressEvent(QMouseEvent* qme){
    if (this->pressImgPath != ""){
        if (qme->button() == Qt::LeftButton){
            QPixmap qp;
            qp.load(this->pressImgPath);
            // 设置图标大小
            this->setFixedSize(qp.width(), qp.height());

            // 设置图片样式
            this->setStyleSheet("QPushButton{border:0px}");  // 设置图片边框为0像素点

            // 设置图片
            this->setIcon(qp);

            // 设置图标大小
            this->setIconSize(QSize(qp.width(), qp.height()));
        }
    }

    // 让父类的mousePressEvent函数来继续处理
    return QPushButton::mousePressEvent(qme);
}
// 鼠标弹起事件
void MyStartPushButton::mouseReleaseEvent(QMouseEvent* qme){
    if (this->pressImgPath != ""){
        if (qme->button() == Qt::LeftButton){
            QPixmap qp;
            qp.load(this->normalImgPath);
            // 设置图标大小
            this->setFixedSize(qp.width(), qp.height());

            // 设置图片样式
            this->setStyleSheet("QPushButton{border:0px}");  // 设置图片边框为0像素点

            // 设置图片
            this->setIcon(qp);

            // 设置图标大小
            this->setIconSize(QSize(qp.width(), qp.height()));
        }
    }

    // 让父类的mouseReleaseEvent函数来继续处理
    return QPushButton::mouseReleaseEvent(qme);
}
