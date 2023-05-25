#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
	// do not use increments, use two different binary search loop
	int end = array.size();
	int start = 0;
    int middle = 0;

	indexMin = indexMax = -1;

    while(start < end){
        middle = (start+end)/2;

		if (toSearch>array[middle]){
            start = middle +1;
        }
        else if(toSearch<array[middle]){
            end = middle;
        }
        else{
            //mettre à jour le indexmin puis le end 
			indexMin = middle;
			end = middle;
		}
	}

    int end = array.size();
    int start = 0;
    int middle = 0;

	while(start < end){
        middle = (start+end)/2;

		if (toSearch>array[middle]){
            start = middle +1;
        }
        else if(toSearch<array[middle]){
            end = middle;
        }
        else{
            //mettre à jour indexmax et start
			indexMax = middle;
            start = middle +1;
		}
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
