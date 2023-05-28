#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	if(size<=1){
		return;
	}
	// split
	int pivot= size/2;
	int valueP=toSort[pivot];

	for(int i=0 ; i<size ; i++){
		if(pivot!=i){
			if(toSort[i]<valueP){ // partie + petite que pivot
				lowerArray[lowerSize]=toSort[i];//on ajoute l'élément du tableau original dans lowerArray
				lowerSize++;//taille augmente
			}else{ // partie + grande que pivot
				greaterArray[greaterSize]=toSort[i];//idem mais dans greaterArray
				lowerSize++;
			}
		}
	}
	
	// recursiv sort of lowerArray and greaterArray
	recursivQuickSort(lowerArray,lowerSize);
	recursivQuickSort(greaterArray, greaterSize);

	// merge
	int i=0;
	for(int j=0 ; j<lowerSize ; j++){
		toSort[i]=lowerArray[j];
		i++;
	}
	toSort[i]=valueP; // jonction des tableaux
	i++;
	for(int j=0 ; j<greaterSize ; j++){
		toSort[i]=greaterArray[j];
		i++;
	}

}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
