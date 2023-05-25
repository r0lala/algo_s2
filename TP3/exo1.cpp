#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

int binarySearch(Array& array, int toSearch)
{
    int end = array.size();
	int start = 0;
    int middle = 0;

    while(start < end){
        middle = (start+end)/2;

		if (toSearch >array[middle]){
            start = middle +1;

        }
        else if(toSearch<array[middle]){
            end = middle-1;
        }
        else{
            return middle;
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
