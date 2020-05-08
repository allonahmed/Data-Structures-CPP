#ifndef LAYEREDCANVAS_H
#define LAYEREDCANVAS_H

//You cannot include any addition libraries
#include <iostream>
#include <string>
#include <sstream>

class Image;
class Canvas;

class Image
{
private:
    //The Canvas class has access to the private fields of the Image class
    friend Canvas; 
    int length;
    int width;
    int width;
public:
};

class Canvas
{
private:
    int grid[10000];
    int row;
    int column;
    Canvas(Canvas&);
    Canvas& operator=(Canvas&);
public:
};

#endif