#include<iostream>//bibliotheque permettant de gerer les entrees et les sorties
#include<vector>//bibliotheque permettant de gerer le tableau dynamique vector
#include<string>//bibliotheque permettant de gerer tous les types 

//structure de donnee pour gerer les element, leur type et leur valeur
struct Element {
    std::string type;
    std::string value;
};

std::vector<Element> pile;//stucture de donnee pour gerer les pile
std::vector<Element> file;//structure de donnee pour gerer les files

// Fonction pour ajouter un élément à la fin de la pile
void Push(){
    std::string type;
    std::cout << "Quel type d'element souhaitez-vous utiliser? (int, float, string) \n";
    std::cin >> type;

//creation d'un nouvel element de la pile
    Element element; 
    element.type = type;//stocke le type choisi par l'utilisateur (int, float ou string)

    if (type == "int"){
        int val;//variable pour stocker un entier temporairement
        std::cout << "Entrer un entier au choix \n";
        std::cin >> val;//saisir de l'entier par l'utilisateur
        element.value = std::to_string(val); // Conversion de l'entier en string(chaine de caracteres)
    } 
    else if (type == "float"){
        float val;//variable pour stocker un flottant temporairement
        std::cout << "Entrer un flottant au choix \n";
        std::cin >> val;//saisir du flottant par l'utilisateur
        element.value = std::to_string(val); // Conversion du flottant en string(chaine de caractere)
    } 
    else if(type == "string"){
        std::string val;//variable pour stocker une chaine de caractere temporairement
        std::cout << "Entrer une chaine de caractères au choix \n";
        std::cin.ignore(); // Ignorer le caractere de retour à la ligne
        std::getline(std::cin, val);//recupere toute la ligne de texte saisir par l'utilisateur
        element.value = val;//stocke directement la chaine de caractere
    } 
    else {
        //affiche ce message au cas ou le type entrer par l'utilisateur est invalide
        std::cout << "Type invalide !!!! \n";
        return; //sort de la fonction sans ajouter l'element
    }
//ajoute l'element dans la pile
    pile.push_back(element);
    std::cout << "L'element est ajoute à la pile ! \n";
}



// Fonction pour retirer un élément à la fin de la pile
void Pop(){
    if (pile.empty()){//verifie si la pile est vide
        std::cout << "La pile est vide... aucun element à retirer !!! \n";
    } else {
        Element element = pile.back(); // Accède directement au dernier élément de la pile et le recupere  
        pile.pop_back(); // Supprime le dernier élément de la pile
        std::cout << "Le dernier element de la pile retire est : ";
        if (element.type == "int"){//verifie si le dernier element est un entier
            std::cout << stoi(element.value) << "(int)\n";//passe la chaine de caracteres contenant 
                                                          //un nombre entier en une variable de 
                                                          //type int ( "42" devient 42 )
        } else if (element.type == "float"){
            std::cout << stof(element.value) << "(float)\n";//(string to float)
                                                            //pareillement, mais avec les flottants ( "3,4" devient 3,4 )
        } else if (element.type == "string"){
            std::cout << element.value << "(string)\n";
        }
    }
}

// Fonction pour ajouter un élément à la fin de la file
void enqueueFile(){
    std::string type;
    std::cout << "Quel type de valeurs souhaitez-vous manipuler ?(int, float, string) \n";
    std::cin >> type;

//creation d'un nouvel element de la file
    Element element; 
    element.type = type;//stocke le type d'element choisi par l'utilisateur
    if (type == "int"){
        int val;//variable pour stocker temporairement un entier 
        std::cout << "Entrer un entier \n";
        std::cin >> val;//recupere l'element saisi par l'utilisateur
        element.value = std::to_string(val);//convertir l'entier en chaine de caractere
    } else if (type == "float"){
        float val;//variable pour stocker un flottant te;porairement
        std::cout << "Entrer un flottant au choix \n";
        std::cin >> val;//recupere le flottant saisi par l'utilisateur
        element.value = std::to_string(val);//convertir le flottant en chaine de caractere
    } else if (type == "string"){
        std::string val;//variable pour stocker temporairement une chaine de caractere 
        std::cout << "Entrer une chaine de caracteres \n";
        std::cin.ignore(); //ignorer le caractere de retour à la ligne
        std::getline(std::cin, val);//recupere toute la ligne de texte saisir par l'utilisateur
        element.value = val;
    } else {
//affiche ce message au cas ou l'utilisateur ne fait aucun choix valide
        std::cout << "Type invalide !!! \n";
        return;//sort de la fonction sans ajouter l'element
    }
//ajoute l'element a la fin de la file
    file.push_back(element);
    std::cout << "L'element est ajouté \n";
}


// Fonction pour retirer un élément au début de la file
void dequeueFile (){
    if (file.empty()){//verifie si la file est vide
        std::cout << "La file est vide \n";
    } else {
        Element first = file.front(); // Identifie et récupère le premier élément de la file
        file.erase(file.begin()); // Supprime cet élément de la file
        std::cout << "Le premier element retire est : ";
//verifie le type du premier element de la file
        if (first.type == "int"){
            std::cout << stoi(first.value) << "(int)\n";//(permet de quitter de "42" a 42)
        } else if (first.type == "float"){
            std::cout << stof(first.value) << "(float)\n";//(permet de quitter de "42.5" a 42.5)
        } else if (first.type == "string"){
            std::cout << first.value << "(string)\n";
        }
    }
}


// Fonction permettant d'afficher les éléments contenus dans la pile
void afficheEtatP(){
    if(pile.empty()) {//verifie si la pile est vide
        std::cout << "La pile est vide !! \n";
    } else {
        std::cout << "Le contenu de la pile est : \n";
        std::cout << "Pile = [ Top = ";//ouvre l'affichage de la pile
        for(int i = (pile.size() - 1); i >= 0; i--) { // Parcours la pile du sommet à 
                                                      //la base et affiche l'element sans la virgule a le fin
            if (i != (pile.size() - 1)){//verifie que l'element n'est pas le dernier 
                std::cout <<" , ";//ajoute une virgule si ce n'est pas le dernier element
            }
        std::cout <<pile[i].value<<" ";//ajoute la valeur de l'element saisir par l'utilisateur
//ajoute le type d'element entrer par l'utilisateur en plus de sa valeur(34 (int)) 
            if (pile[i].type == "int"){
                std::cout << "(int)";
            } else if (pile[i].type == "float"){
                std::cout << "(float)";
            } else if (pile[i].type == "string"){
                std::cout << "(string)";
            }
        }
        std::cout << "]\n";//ferme l'affichage de la pile
    }
}


// Fonction permettant d'afficher les éléments de la file
void afficheEtatF(){
    if (file.empty()){//verifie si la file est vide
        std::cout << "La file est vide !!!! \n";
    } else {
        std::cout << "Le contenu de la file est : \n";
        std::cout << "File = [ Front = ";//ouvre l'affichage de la file
        for(size_t i = 0; i < file.size(); i++) { // size_t est un type entier non signé
                                                  //parcours la file du debut a la fin et
                                                  //affiche l'element sans virgule a la fin
            if (i != 0){//verifie s'il ne s'agit pas du premier element
            std::cout << " , ";//affiche une virgule sauf avant le premier element
            }
        std::cout << file[i].value << " ";//ajoute la valeur de l'entier saisir par l'utilisateur
//verifie le type de l'element et l'affiche 
            if (file[i].type == "int"){
                std::cout << "(int)";
            } else if (file[i].type == "float"){
                std::cout << "(float)";
            } else if(file[i].type == "string"){
                std::cout << "(string)";
            }
        }
        std::cout << "]\n";//ferme l'affichage de la file 
    }
}


// Fonction principale du programme
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
            // affiche le Sous-menu de la PILE lorsque l'utilisateur choisir lq premiere option
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
        } else if (choix == 2) {
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
        } else if (choix == 3) {
            //affiche ce message lorsque l'utiisateur choisit la troisieme option
            std::cout << "AUREVOIR!!! \n";
            break; // Quitte la boucle principale
        } else {
            //affiche ce message au cas ou l'utitlisateur fait un choix non correspondant
            std::cout << "Choix invalide \n";
        }
    }
    return 0;
}