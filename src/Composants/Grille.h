#ifndef GRILLE_H  
#define GRILLE_H  

#include <vector>  
#include "Cellule.h"  

class Grille {  
private:  
    std::vector<std::vector<Cellule>> cellules; // Matrice de cellules
    bool modeTorique;                           // Mode torique activé ou désactivé

public:  
    Grille(int lignes, int colonnes);             // Constructeur avec dimensions
    void afficher() const;                        // Affiche la grille dans la console
    void mettreAJour();                           // Met à jour la grille selon les règles du Jeu de la Vie
    int compterVoisinsVivants(int x, int y) const; // Compte les voisins vivants d'une cellule
    const std::vector<std::vector<Cellule>>& getCellules() const; // Retourne les cellules
    int getLargeur() const;                       // Retourne la largeur de la grille
    int getHauteur() const;                       // Retourne la hauteur de la grille
    void activerModeTorique(bool torique);        // Active ou désactive le mode torique
    void setCell(int x, int y, bool vivante);     // Définit l'état d'une cellule
    void initialiser(const std::vector<std::vector<int>>& etatInitial); // Initialise la grille avec un état donné
};  

#endif // GRILLE_H
