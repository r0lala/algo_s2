#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
    int size = toSort.size();

	for(int j=0 ; j < size ; j++){
		for(int i=j+1 ; i < size ; i++){
			if(toSort.get(i)>toSort.get(j)){
				toSort.swap(j, i);
			}
		}
	}
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
