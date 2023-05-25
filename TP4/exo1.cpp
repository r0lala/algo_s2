#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow *w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
	int child_g = nodeIndex * 2 + 1;
	return child_g;
}

int Heap::rightChild(int nodeIndex)
{
	int child_d = nodeIndex * 2 + 2;
	return child_d;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;

	this->get(i) = value;
	while (i > 0 && this->get(i) > this->get((i - 2) / 2))
	{
		this->swap(i, (i - 1) / 2);
		i = (i - 2) / 2;
	}
}

//Si le noeud à l’indice nodeIndex n’est pas supérieur
//à ses enfants, reconstruit le tas à partir de cet index.
void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i_max = nodeIndex;

	if(this->leftChild(nodeIndex)<heapSize && this->get(nodeIndex)<this->get(this->leftChild(nodeIndex))){
			i_max=this->leftChild(nodeIndex);
	}
	if(this->rightChild(nodeIndex)<heapSize && this->get(i_max)<this->get(this->rightChild(nodeIndex))){
			i_max=this->rightChild(nodeIndex);
	}

	if(i_max!=nodeIndex){
		this->swap(nodeIndex, i_max);
		this->heapify(heapSize, i_max);
	}
}

//Construit un tas à partir des valeurs de numbers (vous pouvez
//utiliser soit insertHeapNode soit heapify)
void Heap::buildHeap(Array &numbers)
{
	for(int i=0; i<numbers.size() ; i++){
		this->insertHeapNode(i, numbers[i]);
	}
}

void Heap::heapSort()
{
	int size = this->size()-1;
	// ne pas mettre le -1 directement dans les conditions du for()
	for(int i=size; i>0 ; i--){
		this->swap(0,i);
		this->heapify(i,0);
	}

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
	w = new HeapWindow();
	w->show();

	return a.exec();
}
