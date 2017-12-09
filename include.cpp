#include "include.h"
#include "game.h"
#include <QDesktopWidget>


Include::Include(){
}

int Include::screenWidth()
{
    QDesktopWidget widget;
    return widget.screenGeometry(-1).width();
}

int Include::screenHeight()
{
    QDesktopWidget widget;
    return widget.screenGeometry(-1).height();
}

int Include::randomInInterval(signed min, signed max)
{
    return (rand()%(max-min + 1) + min);
}
