#ifndef SERVICE_FICHIER_H  
#define SERVICE_FICHIER_H  

#include <vector>  
#include <string>  
#include "../Composants/Cellule.h"

// Classe utilitaire pour gérer les fichiers de grille
class ServiceFichier {  
public:  
    // Charge une grille à partir d'un fichier
    static std::vector<std::vector<Cellule>> chargerDepuisFichier(const std::string& chemin);

    // Sauvegarde une grille dans un fichier
    static void sauvegarderDansFichier(const std::string& chemin, const std::vector<std::vector<Cellule>>& grille);  
};  

#endif // SERVICE_FICHIER_H  
