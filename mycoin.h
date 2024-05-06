#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString img);
    int currentindex;
    void setPix(int i);
    int min = 1;
    int max = 8;

    bool isAnimation;
    // 优化, 只有在金币翻完后才能继续翻
    void mousePressEvent(QMouseEvent* qme);
signals:

};

#endif // MYCOIN_H
