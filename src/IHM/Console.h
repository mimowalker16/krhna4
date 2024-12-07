#ifndef CONSOLE_H  
#define CONSOLE_H  

#include <string>
#include "../Composants/Grille.h"

class Console {  
public:  
    static void lancer(const std::string& cheminFichierEntree, const std::string& cheminFichierSortie, int iterations);  
};  

#endif // CONSOLE_H
