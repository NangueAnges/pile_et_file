#include<iostream>
#include<vector>
#include<string>


/*
    - structure representant un element de la file.
    - chaque element possede un type (int, float, string) et une valeur 
stockee sous forme de chaine de caracteres 
*/
struct Element {
    std::string type;
    std::string value;
};


std::vector<Element> pile;//declaration de la pile sous forme d'un tableau dynamique
std::vector<Element> file;//declaration de la file sous forme d'un tableauu dynamique


/*
    - ajoute un element dans la pile 
    en demandant a l'utilisateur le 
    type et la valeur a inserer.
*/
void Push(){
    std::string type;
    std::cout << "Quel type d'element souhaitez-vous utiliser? (int, float, string) \n";
    std::cin >> type;
    Element element; 
    element.type = type;

//demande et conversion de la valeur a partir du type choisi
    if (type == "int"){
        int val;
        std::cout << "Entrer un entier au choix \n";
        std::cin >> val;
        element.value = std::to_string(val);
    } 
    else if (type == "float"){
        float val;
        std::cout << "Entrer un flottant au choix \n";
        std::cin >> val;
        element.value = std::to_string(val); 
    } 
    else if(type == "string"){
        std::string val;
        std::cout << "Entrer une chaine de caractères au choix \n";
        std::cin.ignore(); // Ignore le retour à la ligne precedent pour eviter un bug avec getline()
        std::getline(std::cin, val);//recupere toute la ligne de texte saisir par l'utilisateur
        element.value = val;
    } 
    else {
        std::cout << "Type invalide !!!! \n";
        return; 
    }
//ajout de l'element dans la pile
    pile.push_back(element);
    std::cout << "L'element est ajoute a la pile ! \n";
}



/*
    - Retire et affiche l'element de la fin de la pile (LIFO).
    - Si la pile est vide, un message est affiche.
*/
void Pop(){
    if (pile.empty()){
        std::cout << "La pile est vide... aucun element à retirer !!! \n";
    } else {
        Element element = pile.back(); 
        pile.pop_back();
        std::cout << "Le dernier element de la pile retire est : ";
        if (element.type == "int"){
            std::cout << stoi(element.value) << "(int)\n";
        } else if (element.type == "float"){
            std::cout << stof(element.value) << "(float)\n";
        } else if (element.type == "string"){
            std::cout << element.value << "(string)\n";
        }
    }
}




/*
    - Ajoute un element dans la file en 
    demandant a l'utilisateur le type 
    et la valeur a inserer.
*/
void enqueueFile(){
    std::string type;
    std::cout << "Quel type de valeurs souhaitez-vous manipuler ?(int, float, string) \n";
    std::cin >> type;
    Element element; 
    element.type = type;

//demande et conversion de la valeur en fonction du type choisi
    if (type == "int"){
        int val;
        std::cout << "Entrer un entier \n";
        std::cin >> val;
        element.value = std::to_string(val);
    } else if (type == "float"){
        float val;
        std::cout << "Entrer un flottant au choix \n";
        std::cin >> val;
        element.value = std::to_string(val);
    } else if (type == "string"){
        std::string val;
        std::cout << "Entrer une chaine de caracteres \n";
        std::cin.ignore(); 
        std::getline(std::cin, val);   
        element.value = val;
    } else {
        std::cout << "Type invalide !!! \n";
        return;
    }
//ajout de l'element a la fin de la file
    file.push_back(element);
    std::cout << "L'element est ajouté \n";
}



/*
    - Retire et affiche l'element en tete de la file (FIFO).
    - si la file est vide, un message est affiche.
*/
void dequeueFile (){
    if (file.empty()){
        std::cout << "La file est vide \n";
    } else {
    
//recupere et supprime l'element en tete de la file
        Element first = file.front(); 
        file.erase(file.begin());
        std::cout << "Le premier element retire est : ";
        if (first.type == "int"){
            std::cout << stoi(first.value) << "(int)\n";//(permet de quitter de "42" a 42)
        } else if (first.type == "float"){
            std::cout << stof(first.value) << "(float)\n";//(permet de quitter de "42.5" a 42.5)
        } else if (first.type == "string"){
            std::cout << first.value << "(string)\n";
        }
    }
}




/* 
    - affiche le contenu actuel de la pile.
    - i la file est vide, un message est affiche.
*/
void afficheEtatP(){
    if(pile.empty()) {
        std::cout << "La pile est vide !! \n";
    } else {
        std::cout << "Le contenu de la pile est : \n";
        std::cout << "Pile = [ Top = ";
        for(int i = (pile.size() - 1); i >= 0; i--) {
            if (i != (pile.size() - 1)){
                std::cout <<" , ";
            }
        std::cout <<pile[i].value<<" ";

//ajoute le type d'element entrer par l'utilisateur en plus de sa valeur(34 (int)) 
            if (pile[i].type == "int"){
                std::cout << "(int)";
            } else if (pile[i].type == "float"){
                std::cout << "(float)";
            } else if (pile[i].type == "string"){
                std::cout << "(string)";
            }
        }
        std::cout << "]\n";
    }
}



/*
    - Affiche le contenu actuel de la file
    - si la file est vide, un message est affiche.
*/
void afficheEtatF(){
    if (file.empty()){
        std::cout << "La file est vide !!!! \n";
    } else {
        std::cout << "Le contenu de la file est : \n";
        std::cout << "File = [ Front = ";
        for(size_t i = 0; i < file.size(); i++) { // size_t est un type entier non signé
            if (i != 0){
            std::cout << " , ";
            }
        std::cout << file[i].value << " ";
//verifie le type de l'element et l'affiche 
            if (file[i].type == "int"){
                std::cout << "(int)";
            } else if (file[i].type == "float"){
                std::cout << "(float)";
            } else if(file[i].type == "string"){
                std::cout << "(string)";
            }
        }
        std::cout << "]\n"; 
    }
}



/*
    - fonction principale qui lance
    le programme et le menu principal 
    proposant des options disponibles pour
    manipuler la file
    - elle gere egalement l'interaction 
    utilisateur avec le menu principal
    - l'utilisateur peut ajouter, retirer
    et afficher les elements de la file
*/
int main(int argc, char** argv) {
    std::cout << "BIENVENUE DANS CETTE APPLICATION BASEE SUR L'IMPLEMENTATION DES PILES ET DES FILES DANS UN TABLEAU DYNAMIQUE \n";
    
    while(true) {
        // Menu principal de l'application
        int choix;
        std::cout << "Bienvenue dans le menu principal : \n";
        std::cout << "\nMENU PRINCIPAL\n";
        std::cout << "   1- PILE \n";
        std::cout << "   2- FILE \n";
        std::cout << "   3- QUITTER \n";
        std::cout << "Entrer un nombre (1-3) pour faire votre choix \n";
        std::cin >> choix;

        if (choix == 1) {
            // affiche le Sous-menu de la PILE lorsque l'utilisateur choisir la premiere option
            int action;
            while (true) {
                std::cout << "\n      SOUS MENU PILE \n";
                std::cout << "            1- push \n";
                std::cout << "            2- pop \n";
                std::cout << "            3- afficher la pile \n";
                std::cout << "            4- retour au menu principal \n";
                std::cout << "          ***Entrer la lettre de l'action que vous souhaitez faire \n";
                std::cin >> action;

                if (action == 1) {
                    Push();
                } else if (action == 2) {
                    Pop();
                } else if (action == 3) {
                    afficheEtatP();
                } else if (action == 4) {
                    break; // Retour au menu principal
                } else {
                    std::cout << "Choix invalide \n";
                }
            }
        } 
        
        
        else if (choix == 2) {
            //affiche le Sous-menu de la FILE lorsque l'utilisateur choisir la deuxieme option
            int action;
            while(true) {
                std::cout << "\n          SOUS MENU FILE \n";
                std::cout << "                1- enqueue \n";
                std::cout << "                2- dequeue \n";
                std::cout << "                3- afficher la file \n";
                std::cout << "                4- retour au menu principal \n";
                std::cout << "              ***Entrer la lettre de l'action que vous souhaitez executer \n";
                std::cin >> action;

                if (action == 1) {
                    enqueueFile();
                } else if (action == 2) {
                    dequeueFile();
                } else if (action == 3) {
                    afficheEtatF();
                } else if (action == 4) {
                    break; // Retour au menu principal
                } else {
                    std::cout << "Choix invalide. \n";
                }
            }
        }
        
        
         else if (choix == 3) {
            //affiche ce message lorsque l'utiisateur choisit la troisieme option
            std::cout << "AUREVOIR!!! \n";
            break; // Quitte la boucle principale
        }
        
        
         else {
            //affiche ce message au cas ou l'utitlisateur fait un choix non correspondant
            std::cout << "Choix invalide \n";
        }
    }
    return 0;
}