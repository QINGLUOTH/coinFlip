#ifndef MYSTARTPUSHBUTTON_H
#define MYSTARTPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyStartPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyStartPushButton(QWidget *parent = nullptr);
    MyStartPushButton(QString normalImgPath, QString pressImgPath = "");

    // 默认显示的图片路径
    QString normalImgPath;
    // 鼠标按下时显示的图片路径
    QString pressImgPath;

    // 按钮弹起特效
    void zoom1();
    // 按钮按下特效
    void zoom2();

    // 鼠标按下事件
    void mousePressEvent(QMouseEvent* qme);
    // 鼠标弹起事件
    void mouseReleaseEvent(QMouseEvent* qme);
signals:

};

#endif // MYSTARTPUSHBUTTON_H
