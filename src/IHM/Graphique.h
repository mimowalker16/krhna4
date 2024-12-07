#ifndef GRAPHIQUE_H  
#define GRAPHIQUE_H  

#include <string>
#include "../Composants/Grille.h"

class Graphique {  
public:  
    static void lancer(const std::string& cheminFichierEntree, int tailleCellule, int intervalle);  
};  

#endif // GRAPHIQUE_H
