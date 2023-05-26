#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
    int index_min=0;
    int size = toSort.size(); // get c'est l'intérieur
    for(uint j=0 ; j < size ; j++)
    {
        for(uint i=j+1; i < size ; i++)
        {
            if(toSort.get(i)<toSort.get(index_min))
            {
                index_min =i;// recup index min
            }
        }
        toSort.swap(j,index_min); // swap : la place de déplacement avant
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
