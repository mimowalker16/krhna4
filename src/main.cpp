#include "IHM/Console.h"
#include "IHM/Graphique.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>

int main() {
    std::string cheminFichierEntree;
    std::string mode;
    int iterationsOuTaille;
    int intervalle = 100;

    std::cout << "Voulez-vous charger une grille depuis un fichier ? (oui/non) : ";
    std::string choix;
    std::cin >> choix;

    if (choix == "oui") {
        std::cout << "Entrez le chemin du fichier d'entrée : ";
        std::cin >> cheminFichierEntree;
    } else {
        std::cout << "Entrez la taille de la grille (lignes colonnes) : ";
        int lignes, colonnes;
        std::cin >> lignes >> colonnes;

        std::cout << "Voulez-vous générer une grille aléatoire ? (oui/non) : ";
        std::string choixAleatoire;
        std::cin >> choixAleatoire;

        cheminFichierEntree = "grille_temporaire.txt";
        std::ofstream fichier(cheminFichierEntree);
        if (!fichier) {
            std::cerr << "Erreur : impossible de créer le fichier." << std::endl;
            return 1;
        }

        if (choixAleatoire == "oui") {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 1);

            for (int i = 0; i < lignes; ++i) {
                for (int j = 0; j < colonnes; ++j) {
                    fichier << dis(gen); // Génère un 0 ou 1 aléatoire
                }
                fichier << "\n";
            }
            std::cout << "Grille aléatoire générée dans le fichier : " << cheminFichierEntree << std::endl;
        } else {
            for (int i = 0; i < lignes; ++i) {
                for (int j = 0; j < colonnes; ++j) {
                    fichier << "0 "; // Grille vide par défaut
                }
                fichier << "\n";
            }
        }

        fichier.close();
    }

    std::cout << "Choisissez le mode ('console' ou 'graphique') : ";
    std::cin >> mode;

    if (mode == "console") {
        std::cout << "Entrez le nombre d'itérations : ";
        std::cin >> iterationsOuTaille;
        Console::lancer(cheminFichierEntree, "resultat", iterationsOuTaille);
    } else if (mode == "graphique") {
        std::cout << "Entrez la taille des cellules en pixels : ";
        std::cin >> iterationsOuTaille;
        std::cout << "Entrez l'intervalle entre les mises à jour (en ms, par défaut 100) : ";
        std::cin >> intervalle;
        Graphique::lancer(cheminFichierEntree, iterationsOuTaille, intervalle);
    } else {
        std::cerr << "Mode invalide. Veuillez relancer le programme." << std::endl;
    }

    return 0;
}
