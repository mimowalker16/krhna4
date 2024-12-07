#include "Grille.h"  
#include <iostream>  

// Constructeur : Initialise une grille de dimensions données, avec toutes les cellules mortes par défaut
Grille::Grille(int lignes, int colonnes)
    : cellules(lignes, std::vector<Cellule>(colonnes)), modeTorique(false) {}

// Affiche la grille dans la console (1 pour cellule vivante, 0 pour cellule morte)
void Grille::afficher() const {  
    for (const auto &ligne : cellules) {  
        for (const auto &cellule : ligne) {  
            std::cout << (cellule.estVivante() ? "1 " : "0 ");  
        }  
        std::cout << '\n';  
    }  
}

// Met à jour l'état de la grille selon les règles du Jeu de la Vie
void Grille::mettreAJour() {  
    int lignes = (int)cellules.size();  
    int colonnes = (int)cellules[0].size();  
    std::vector<std::vector<Cellule>> nouvelleGrille(lignes, std::vector<Cellule>(colonnes));  

    for (int x = 0; x < lignes; ++x) {  
        for (int y = 0; y < colonnes; ++y) {  
            int voisinsVivants = compterVoisinsVivants(x, y);  
            if (cellules[x][y].estVivante()) {  
                nouvelleGrille[x][y].setVivante(voisinsVivants == 2 || voisinsVivants == 3);  
            } else {  
                nouvelleGrille[x][y].setVivante(voisinsVivants == 3);  
            }  
        }  
    }  

    cellules = nouvelleGrille; // Remplacer l'ancienne grille par la nouvelle  
}

// Compte le nombre de voisins vivants d'une cellule donnée
int Grille::compterVoisinsVivants(int x, int y) const {  
    int voisinsVivants = 0;  
    int lignes = (int)cellules.size();  
    int colonnes = (int)cellules[0].size();  

    for (int dx = -1; dx <= 1; ++dx) {  
        for (int dy = -1; dy <= 1; ++dy) {  
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même  

            int nx = x + dx;  
            int ny = y + dy;  

            if (modeTorique) {  
                // Appliquer les règles de grille torique
                nx = (nx + lignes) % lignes;  
                ny = (ny + colonnes) % colonnes;  
            }  

            // Vérifier les limites pour les grilles non toriques
            if (nx >= 0 && nx < lignes && ny >= 0 && ny < colonnes && cellules[nx][ny].estVivante()) {  
                ++voisinsVivants;  
            }  
        }  
    }  
    return voisinsVivants;  
}

// Retourne les cellules de la grille
const std::vector<std::vector<Cellule>>& Grille::getCellules() const {  
    return cellules;  
}

// Retourne la largeur (nombre de colonnes) de la grille
int Grille::getLargeur() const {  
    return (int)cellules[0].size();  
}

// Retourne la hauteur (nombre de lignes) de la grille
int Grille::getHauteur() const {  
    return (int)cellules.size();  
}

// Active ou désactive le mode torique
void Grille::activerModeTorique(bool torique) {  
    modeTorique = torique;  
}

// Modifie l'état d'une cellule spécifique
void Grille::setCell(int x, int y, bool vivante) {
    if (x >= 0 && x < (int)cellules.size() && y >= 0 && y < (int)cellules[0].size()) {
        cellules[x][y].setVivante(vivante);
    } else {
        std::cerr << "Erreur : Coordonnées hors limites (" << x << ", " << y << ")\n";
    }
}

// Initialise la grille avec un état donné (par exemple, pour charger une configuration depuis un fichier)
void Grille::initialiser(const std::vector<std::vector<int>>& etatInitial) {
    int lignes = (int)etatInitial.size();
    int colonnes = (int)etatInitial[0].size();

    cellules = std::vector<std::vector<Cellule>>(lignes, std::vector<Cellule>(colonnes));

    for (int x = 0; x < lignes; ++x) {
        for (int y = 0; y < colonnes; ++y) {
            cellules[x][y].setVivante(etatInitial[x][y] == 1);
        }
    }
}
