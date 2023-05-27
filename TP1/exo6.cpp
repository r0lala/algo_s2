#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* next;
};

struct Liste{
    Noeud* first;
    Noeud* last;
    int size;
};

struct DynaTableau{
    int* donnees;
    int size;
    int capacite;
    
};


void initialise(Liste* liste){
    liste->first=nullptr;
}

bool est_vide(const Liste* liste){
    if(liste->first==nullptr){
        return true;
    }else{
        return false;
    }
}

void ajoute(Liste* liste, int valeur){
    Noeud *new_n = new Noeud; //création nouveau noeud
    new_n->donnee=valeur;     //valeur du nouveau noeud
    new_n->next=nullptr;      //pas de noeud après lui
    //si pas de premier noeud existant
    if(liste->first==nullptr){
        liste->first= new_n; // alors le nouveau est le premier 
        liste->last=new_n;   //et le dernier pcq il est tout seul
    }//sinon (donc si y a au moins un noeud dans liste)
    else{
        liste->last->next=new_n; // le noeud après le dernier devient le nouveau noeud
        liste->last=liste->last->next; // et ce noeud devient le dernier de la liste
    }
}

void affiche(const Liste* liste){
    if(liste->first==nullptr){  //pas de noeud dans la liste
        cout<<"La liste est vide"<<endl; 
    }else{
        Noeud* noeud=liste->first;
        while(noeud->next!=nullptr){ // tant qu'il y a un noeud après
            cout<<"Noeud : "<<noeud<<" || valeur : "<<noeud->donnee<<endl; // on affiche
            noeud=noeud->next;
        }
    }
}

int recupere(const Liste* liste, int n){
    if(n==0 || n>liste->size){
        return -1;
    }else{
        Noeud* noeud = liste->first;

        while(int i=0 ; i<n-1 ; i++){
            noeud=noeud->next;
        }
        return noeud->donnee;
    }
}

int cherche(const Liste* liste, int valeur){
    Noeud* noeud=liste->first;
    for(int i=0 ; noeud!=nullptr ; i++){
        if(noeud->donnee==valeur){
            return i;
        }
        noeud=noeud->next;
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur){
    Noeud* noeud=liste->first;
    int i=0;
    while(i<n){
        noeud=noeud->next;
    }
    noeud->donnee=valeur;
}

void ajoute(DynaTableau* tableau, int valeur){
    if(tableau->size < tableau->capacite){
        tableau->donnees[tableau->size]=valeur; // j'ajoute un élément dans le tableau
        tableau->size++; // donc size augmente de un
    }else{

    }
}


void initialise(DynaTableau* tableau, int capacite){
    tableau->capacite=capacite;// si j'ai bien compris : capacité maximale
    tableau->size=0;// taille actuelle
    tableau->donnees= new int[capacite];
}

bool est_vide(const DynaTableau* liste){
    if(liste->size==0){
        return true;
    }else{
        return false;
    }
}

void affiche(const DynaTableau* tableau){
    for(int i=0 ; i<tableau->size ; i++){
        cout<<"Donnée à l'index "<<i<<" : "<<tableau->donnees[i]<<endl;
    }
}

int recupere(const DynaTableau* tableau, int n){
    if(n<tableau->size){
        return tableau->donnees[n];
    }else{
        return 0;
    }
}

int cherche(const DynaTableau* tableau, int valeur){
    for(int i=0 ; i<tableau->size ; i++){
        if(tableau->donnees[i]==valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur){

}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur){

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste){
    return 0;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur){

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste){
    return 0;
}


int main(){
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
