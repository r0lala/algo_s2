#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    // il faut faire de la récursion sur l'ensemble des fonctions sauf la première

    void initNode(int value){
        // init initial node without children
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child

        if(value < this){
            if(this->left == nullptr){
                Node* noeud = new Node(value);
                this->left= noeud;
            }else{
                this->left->insertNumber(value);
            }
        }else if(value > this){
            if(this->right == nullptr){
                Node* noeud = new Node(value);
                this->right= noeud;
            }else{
                this->right-> insertNumber(value);
            }
        }
    }

	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        if(this->left == nullptr && this->right == nullptr){
            return 1;
        }else if(this->left != nullptr && this->right != nullptr){
            return 1 + std::max(this->left->height(),this->max->height())
        }else if(this->right != nullptr){
            return 1 + this->right->height();
        }else if(this->left != nullptr){
            return 1 + this->left->height();
        }
    }

	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        if(this->left == nullptr && this->right == nullptr){
            return 1;
        }else if(this->left != nullptr && this->right != nullptr){
            return 1 + this->left->nodesCount() + this->right->nodesCount();
        }else if(this->right != nullptr){
            return 1 + this->right->nodesCount();
        }else if(this->left != nullptr){
            return 1 + this->left->nodesCount();
        }
    }

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)

        if(this->left == nullptr && this->right == nullptr){
            return true;
        }else{
            return false;
	    }
    }

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->left == nullptr && this->right == nullptr){
            leaves[leavesCount] = this;
            leavesCount ++;
        }else if(this->left !=nullptr){
            this->left->allLeaves(leaves, leavesCount);
        }else if(this->right !=nullptr){
            this->right->allLeaves(leaves, leavesCount);
        }
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if(this->left == nullptr && this->right == nullptr){
            nodes[nodesCount] = this;
            nodesCount++;
        }else if(this->left !=nullptr){
            this->left->inorderTravel(nodes, nodesCount);
        }else if(this->right !=nullptr){
            this->right->inorderTravel(nodes, nodesCount);
        }
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount] = this;
        nodesCount++;
        if(this->left !=nullptr){
            this->left->preorderTravel(nodes, nodesCount);
        }if (this->right !=nullptr){
            this->right->preorderTravel(nodes, nodesCount);
        }
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
        if(this->left!=nullptr){
            this->left->postorderTravel(nodes,nodesCount);
        }if(this->right!= nullptr){
            this->right->postorderTravel(nodes, nodesCount);
        }
        nodes[nodesCount] =this;
        nodesCount++;

	}

	Node* find(int value) {
        // find the node containing value
		return nullptr;
	}
SearchTreeNode(int value) : Node(value) {initNode(value);}
    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
