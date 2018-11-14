#ifndef BRESENHAM_H
#define BRESENHAM_H


class bresenham
{
public:
    bresenham();
    void init_bresenham();
    int dx,dy,x,x1,x2,y,y1,y2,aux1,aux2,p; //p variável de decisão  //aux1 = 2dy
                                           //dx = x1 - x2           //aux2 = 2dy - 2dx
                                           //dy = y1 - y2           //p = 2dy - dx
};

#endif // BRESENHAM_H
