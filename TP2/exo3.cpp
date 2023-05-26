#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	int index_min=0;
    int size = toSort.size();

	for(int i=0 ; i < size ; i++){
		
	
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
