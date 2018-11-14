#ifndef AREA_H
#define AREA_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Area : public QWidget
{
    Q_OBJECT
public:
    Area(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event);
    void bresenham(QPainter &event);
signals:
    void painting();
};

#endif // AREA_H
