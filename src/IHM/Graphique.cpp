#include "Graphique.h"
#include "../Services/ServiceFichier.h"
#include <SFML/Graphics.hpp>

void Graphique::lancer(const std::string& cheminFichierEntree, int tailleCellule, int intervalle) {
    auto grilleInitiale = ServiceFichier::chargerDepuisFichier(cheminFichierEntree);
    Grille grille((int)grilleInitiale.size(), (int)grilleInitiale[0].size());

    for (int i = 0; i < grille.getHauteur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            grille.setCell(i, j, grilleInitiale[i][j].estVivante());
        }
    }

    sf::RenderWindow window(sf::VideoMode((unsigned int)(grille.getLargeur() * tailleCellule), (unsigned int)(grille.getHauteur() * tailleCellule)), "Jeu de la Vie");
    sf::RectangleShape cellule(sf::Vector2f((float)tailleCellule - 1, (float)tailleCellule - 1));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();
        const auto& cells = grille.getCellules();
        for (int i = 0; i < grille.getHauteur(); ++i) {
            for (int j = 0; j < grille.getLargeur(); ++j) {
                if (cells[i][j].estVivante()) {
                    cellule.setPosition((float)(j * tailleCellule), (float)(i * tailleCellule));
                    window.draw(cellule);
                }
            }
        }

        window.display();
        sf::sleep(sf::milliseconds(intervalle));
        grille.mettreAJour();
    }
}
