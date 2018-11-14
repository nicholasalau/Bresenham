#include "area.h"
#include <stdio.h>
#include <QDebug>

Area::Area(QWidget *parent) : QWidget(parent)
{

}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    bresenham(painter);
    emit painting();
}

void Area::bresenham(QPainter &painter)
{
    painter.save();
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::blue));
    int xi=100;
    int yi=50;
    int xf=100;
    int yf=100;
    int i = 0, x = 0, y = 0, steps = 0, dx = 0, dy = 0, p = 0, incX = 0, incY = 0;
    dx = abs(xf - xi);
    dy = abs(yf - yi);
    x = xi;
    y = yi;

    //Define step
    if(abs(dx) > abs(dy))
    {
       steps = dx;
    }
    else
    {
       steps = dy;
    }

    //Define incX e incY
    if(xf > xi)
    {
       x = xi;
       incX = 1;
    }
    else
    {
       x = xf;
       incX = -1;
    }

    if(yf > yi)
    {
        y = yi;
        incY = 1;
    }
    else
    {
        y = yf;
        incY = -1;
    }

    //Desenho de retas em cima quando dx = 0 ou dy = 0
    if ((dx == 0) || (dy == 0))
    {
        qDebug("é reta");

        painter.drawPoint(x,y);
        i = 0;

        if(dx == 0)
        {
            /*qDebug("dx = 0");
            if(incY > 0)
            {
                //y = yi;
                for(y = yi; y <= yf; y++)
                {             
                    painter.drawPoint(x,y);
                }
            }
            else
            {
                //y = yf;
                for(y = yf; y <= yi; y++)
                {

                    painter.drawPoint(x,y);
                }
            }*/

            for(i = 0; i < steps; i++)
            {
                y = y + incY;
                painter.drawPoint(x,y);
            }
        }
        else if(dy == 0)
        {
            /*if(incX > 0)
            {
                qDebug("aumenta x");
                for(x = xi; x <= xf; x++)
                {
                    qDebug("printa pixel");
                    painter.drawPoint(x,y);
                }
            }
            else
            {
                for(x = xf; x <= xi; x++)
                {
                    painter.drawPoint(x,y);
                }
            }*/

            for(i = 0; i < steps; i++)
            {
                x = x + incX;
                painter.drawPoint(x,y);
            }
        }
    }
    else //Desenho de retas com inclinação
    {
        //painter.drawPoint(x,y);

        qDebug("reta inclinada");

        if(dx >= dy)
        {
            p = 2*dy - dx;
            while(x!=xf)//for(i = 0;i < steps;i++)
            {
                if(p >= 0)
                {
                    x = x + incX;
                    y = y + incY;
                    //painter.drawPoint(x,y);
                    p = p + 2*(dy - dx);
                }
                else
                {
                    x = x + incX;
                    //painter.drawPoint(x,y);
                    p = p + 2*dy;
                }

                painter.drawPoint(x,y);
            }
        }
        else if (dy >= dx)
        {
            p = 2*dx - dy;
            while(y!=yf)//for(i = 0;i < steps;i++)
            {
                if(p >= 0)
                {
                    x = x + incX;
                    y = y + incY;
                    //painter.drawPoint(x,y);
                    p = p + 2*(dx - dy);
                }
                else
                {
                    y = y + incY;
                    //painter.drawPoint(x,y);
                    p = p + 2*dx;
                }

                painter.drawPoint(x,y);
            }
        }
    }
    painter.restore();
}
