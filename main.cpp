#include<iostream>
#include"file.h"  

void Push(int element){
    
}
    void Pop(){

    }
    void enqueueFile(int){

    }

    void dequeueFile (){

    }

    void afficheEtatP(){

    }
    void afficheEtatF()
    {

    }

int main(int argc, char** argv){
//menu du projet
    
while(true){
    //menu principal
//etiquette
std::cout<<"bienvenue dans le menu principal : \n";
std::cout<<"\n MENU \n";
std::cout<<"1- PILE \n";
std::cout<<"2- FILE \n";
std::cout<<"3- QUITTER \n";
    int choix;
    std::cout << "entrer un nombre (1-3) pour faire votre choix \n";
    std::cin>>choix;

    if (choix == 1) {
            //sous menu pile
            int action, element;
            while (true){
        std::cout<<"\n MENU PILE \n";
        std::cout<<"a- push \n";
        std::cout<<"b- pop \n";
        std::cout<<"c- afficher la pile \n";
        std::cout<<"d- retour au menu principal \n";
        
            //int choice;
            std::cout<<"entrer la lettre de l'action que vous souhaitez faire \n";
            std::cin>>action;

            if (action == 1) {
                std::cout<<"entrer un nombre a ajouter : \n";
                std::cin>>element;
            Push(element);
            }
            else if (action == 2){
            Pop();
            }
            else if (action == 3){
            afficheEtatP();
            }
            else if (action == 4){
                break;//quitte la boucle pile pour revenir au menu principal
            } else {
                std::cout<<"choix invalide \n";
            }
        }
    }
    else if (choix == 2){//sous menu de file
        int action, element;
        while(true) {//bpucle pour le menu file
        std::cout<<"\n MENU FILE \n";
        std::cout<<"1- enqueue \n";
        std::cout<<"2- dequeue \n";
        std::cout<<"3- afficher la file \n";
        std::cout<<"4- retour au menu principal \n";
        //int choice;
        std::cout<<"entrer la lettre de l'action que vous souhaitez executer \n";
            std::cin>>action;

            if (action == 1) {
                std::cout<<" entrer un nombre a ajouter \n";
                std::cin>>element;
            enqueueFile(element);
            }else if (action == 2){
            dequeueFile();
            }else if (action == 3){
            afficheEtatF();
            }else if (action == 4){
            break;//quitte le boucle file pour revenir au menu principal
            }else{
            std::cout<<"choix invalide. \n";
            }
        }
    }else if (choix == 3){//quitter
        std::cout<<"AUREVOIR!!! \n";
        break;//quitte la boucle principale
    }else{
        std::cout<<"choix invalide \n";
    }
    }
    return 0;
}
         