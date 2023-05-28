#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if(origin.size()<=1){
		return;
	}

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
	for(int i=0 ; i<first.size() ; i++){
		first.get(i)=origin.get(i); // identique à first[i]=origin[i]
	}
	for(int j=0 ; j<second.size() ; j++){
		second[j]=origin[first.size()+1];
	}
	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);

	// merge
	merge(first, second, origin);
}

void merge(Array& first, Array& second, Array& result)
{
	int i=0;
	int firstI=0;
	int secondI=0;

	while(firstI<first.size() && secondI<second.size()){
		if(first[firstI] <= second[secondI]){
			result[i]=first[firstI];
			firstI++;
			i++;
		}else{
			result[i]=second[secondI];
			secondI++;
			i++;
		}
	}
	while(first<first.size()){
		result[i]=first[firstI];
		firstI++;
		i++;

	}
	while(secondI<second.size()){
		result[i]=second[secondI];
		secondI++;
		i++;
	}
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
