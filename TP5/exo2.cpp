#include <QApplication>
#include <QString>
#include <time.h>
#include <stdio.h>
#include <string>
#include <math.h>

#include <tp5.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    // return an unique hash id from key
    int i = 0;
	unsigned long int hash_value = 0;
	while(key[i] != '\0')
	{
		hash_value += key[i]*std::pow(128, i);
        i++;
	}
	return hash_value;
}

struct MapNode : public BinaryTree
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value) : BinaryTree (value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        if(node->key_hash < this->key_hash){ //si la clé de hashage du noeud que je veux insérer < à mon noeud actuel
            if(this->left == nullptr){ // si son enfant droit est vide
                this->left= node; // mettre le noeud ici
            }else{
                this->left->insertNode(node); // sinon récursion
            }
        }else{ 
            if(this->right == nullptr){
                this->right= node;
            }else{
                this->right-> insertNode(node);
            }
        }
    }

    // crée un  noeud
    void insertNode(string key, int value){
        this->insertNode(new MapNode(key, value));
    }

    int getVal(string key){
        unsigned long int hash_value = hash(key);
        
        if(hash_value == this->key_hash){
            return this-> value;
        }else{
            if(this->left != nullptr){
                int left = this->left->getVal(key);
                
                if(left != 0){
                    return left;
                }
            }if(this->right != nullptr){
                return this->right->getVal(key);// /!\ recursion different de smt.get() !
            }else{
                return 0;
            }
        }
    }

    virtual ~MapNode() {}
    QString toString() const override {return QString("%1:\n%2").arg(QString::fromStdString(key)).arg(value);}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

struct Map{
    MapNode* root;
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value){
        if(root != nullptr){
            //créer un new node
            this->root->insertNode(key, value);
        }else{
            //créer un nouveau noeud dans la root
            this->root=new MapNode(key, value);
        }
    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key){
        return this->root->getVal(key);
    }
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;

    map.insert("Yolo", 20);
    for (std::string& name : TP5::names){
        if (rand() % 3 == 0){
            map.insert(name, rand() % 21);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));


    QApplication a(argc, argv);
    MainWindow::instruction_duration = 200;
    w = new MapWindow(*map.root);
    w->show();
    return a.exec();
}
