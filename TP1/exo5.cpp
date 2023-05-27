#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n
    if(n==0){
        return 0;
    }
    // check length of z
    if(z.length()>2){
        return -1;
    }
    // if Mandelbrot, return 1 or n (check the difference)
    // otherwise, process the square of z and recall
    // isMandebrot
    z ={(z.x*z.x)-(z.y*z.y)+point.x, (2*z.x*z.y)+point.y} // cf cahier de brouillon 
    return isMandelbrot(z, n-1, point);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



