#include "../src/Composants/Grille.h"
#include "../src/Composants/Cellule.h"
#include <iostream>
#include <cassert>

// Fonction de test unitaire pour valider la grille à une itération t
void testValiditeGrille() {
    // Création d'une grille 3x3 avec un état initial connu
    Grille grille(3, 3);
    std::vector<std::vector<int>> etatInitial = {
        {0, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    };
    grille.initialiser(etatInitial);

    // Mise à jour de la grille pour une itération
    grille.mettreAJour();

    // État attendu après l'application des règles
    std::vector<std::vector<int>> etatAttendu = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    };

    // Vérification de l'état calculé
    const auto& cellules = grille.getCellules();
    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            assert(cellules[y][x].estVivante() == (etatAttendu[y][x] == 1));
        }
    }

    std::cout << "Test unitaire de validité de la grille : Réussi\n";
}

int main() {
    testValiditeGrille();
    return 0;
}
