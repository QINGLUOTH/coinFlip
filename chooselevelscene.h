#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QStackedWidget>
#include "CoinFlipWindows.h"

namespace Ui {
class ChooseLevelScene;
}

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    ~ChooseLevelScene();
    void paintEvent(QPaintEvent* qpe);
    Windows* w;
    void ChooseLevelSceneInterfaceInitFunc();
private:
    Ui::ChooseLevelScene *ui;
};

#endif // CHOOSELEVELSCENE_H
