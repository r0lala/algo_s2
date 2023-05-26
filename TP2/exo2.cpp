#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());
    int size = toSort.size();

	// insertion sort from toSort to sorted
    sorted[0] = toSort[0];
    for(int i=1; i < size ; i++)
    {   
        int position =0;
        while(position < i && toSort.get(i)>sorted.get(position))
        {
          position++;
        }
        sorted.insert(position,toSort.get(i));

    }
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
