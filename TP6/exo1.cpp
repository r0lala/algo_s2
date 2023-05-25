#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */
	
	for(int nbr_n = 0 ; nbr_n < nodeCount ; nbr_n++){
		GraphNode* noeud = new GraphNode(nbr_n);
		this->appendNewNode(noeud);
	}

	for(int i =0; i < nodeCount ; i++){
		for(int j=0; j < nodeCount ; j++){
			if(adjacencies[i][j] >= 1){
				this->nodes[j]->appendNewEdge(this->nodes[i], adjacencies[i][j]);
			}
		}
	}

}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	*/
	nodes[nodesSize]=first;
	visited[first->value] =true;
	nodesSize++;

	for(Edge* lien=first->edges ; lien !=nullptr ; lien=lien->next)
	{
		if(visited[lien->destination->value] != true){
			deepTravel(lien->destination, nodes, nodesSize, visited);
		}
	}

}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	/**
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);
	visited[first->value] =true;

	while(nodeQueue.empty() != true){
		GraphNode *head = nodeQueue.front();
		nodeQueue.pop();
		
		nodes[nodesSize]= head;
		nodesSize++;

		for(Edge* lien=first->edges ; lien !=nullptr ; lien=lien->next){
			if(visited[lien->destination->value] != true){
				nodeQueue.push(lien->destination);
				visited[lien->destination->value] =true;
			}
		}
	}
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
	visited[first->value] =true;
	for(Edge* lien=first->edges ; lien !=nullptr ; lien=lien->next){
		if(visited[lien->destination->value] != true){
			bool result = detectCycle(lien->destination, visited);

			if(result == true){
				return true;
			}
		}else{
			return true;
		}    
		return false;
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}
