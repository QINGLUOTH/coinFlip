#ifndef COINFLIPWINDOWS_H
#define COINFLIPWINDOWS_H
#include <QStackedWidget>
#include <QMainWindow>
#include <QSoundEffect>

struct Windows {
    QMainWindow* qMainWindow;
    QMainWindow* chooseLevelScene;
    QMainWindow* mainInterface;
    QMainWindow* levelInterface;
    QStackedWidget* stackedWidget;

    int mainInterfacei;
    int chooseLevelScenei;
    int levelInterfacei;
};
#endif // COINFLIPWINDOWS_H
