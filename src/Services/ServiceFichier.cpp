#include "ServiceFichier.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// Charge une grille à partir d'un fichier
std::vector<std::vector<Cellule>> ServiceFichier::chargerDepuisFichier(const std::string& chemin) {  
    std::ifstream fichier(chemin);  
    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + chemin);
    }

    std::vector<std::vector<Cellule>> grille;  
    std::string ligne;

    while (std::getline(fichier, ligne)) {  
        std::vector<Cellule> ligneGrille;
        for (char c : ligne) {
            if (c == '0' || c == '1') { // Seuls '0' et '1' sont acceptés
                Cellule cellule;
                cellule.setVivante(c == '1'); // Cellule vivante si '1'
                ligneGrille.push_back(cellule);
            }
        }
        if (!ligneGrille.empty()) {
            grille.push_back(ligneGrille);
        }
    }

    if (grille.empty()) {
        throw std::runtime_error("Erreur : Le fichier est vide ou mal formaté.");
    }

    return grille;  
}

// Sauvegarde une grille dans un fichier
void ServiceFichier::sauvegarderDansFichier(const std::string& chemin, const std::vector<std::vector<Cellule>>& grille) {
    std::ofstream fichier(chemin);
    if (!fichier) {
        throw std::runtime_error("Impossible de sauvegarder dans le fichier : " + chemin);
    }

    for (const auto& ligne : grille) {
        for (const auto& cellule : ligne) {
            fichier << (cellule.estVivante() ? '1' : '0'); // Écrit '1' ou '0' pour chaque cellule
        }
        fichier << '\n'; // Fin de ligne pour chaque rangée
    }
}
