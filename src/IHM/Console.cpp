#include "Console.h"
#include "../Services/ServiceFichier.h"
#include <iostream>
#include <string>

void Console::lancer(const std::string& cheminFichierEntree, const std::string& cheminFichierSortie, int iterations) {
    auto grilleInitiale = ServiceFichier::chargerDepuisFichier(cheminFichierEntree);

    Grille grille((int)grilleInitiale.size(), (int)grilleInitiale[0].size());
    for (int i = 0; i < grille.getHauteur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            grille.setCell(i, j, grilleInitiale[i][j].estVivante());
        }
    }

    for (int iter = 0; iter < iterations; ++iter) {
        std::cout << "Iteration " << iter + 1 << ":\n";
        grille.afficher();
        std::string nomFichier = cheminFichierSortie + "_iter_" + std::to_string(iter + 1) + ".txt";
        ServiceFichier::sauvegarderDansFichier(nomFichier, grille.getCellules());
        grille.mettreAJour();
        std::cout << "---------------------\n";
    }
}
