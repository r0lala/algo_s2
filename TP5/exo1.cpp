#include <tp5.h>
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

// A partir de ce TP, j'ai beaucoup travaillé en classe avec Sara Lafleur (les codes vont surement être très ressemblant)
int HashTable::hash(std::string element)
{
    // use this->size() to get HashTable size
	int hash_value = element[0];
    
    if(hash_value>this->size()){
        hash_value = hash_value % (this->size());
    }
    return hash_value;
}

void HashTable::insert(std::string element)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    int hash_value = this->hash(element);
    this->get(hash_value) = element;

}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
    //namescount = taille de name
    int hash_value = 0;
    for(int i=0; i < namesCount; i++){
        table.insert(names[i]); 
    }
}

bool HashTable::contains(std::string element)
{
    // Note: Do not use iteration (for, while, ...)
    int hash_value = this->hash(element);
    if(this->get(hash_value) == element){
        return true;
    }else{
        return false;
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 10;
	w = new HashWindow();
	w->show();

	return a.exec();
}
