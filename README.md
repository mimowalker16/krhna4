# Jeu de la Vie (Game of Life)

> Une implémentation du **Jeu de la Vie** de Conway en utilisant les principes de la programmation orientée objet (POO) en C++. Ce projet propose une simulation interactive avec deux modes : un affichage console et un affichage graphique (via la bibliothèque SFML).

---

## 🧩 Introduction

Le **Jeu de la Vie** est un automate cellulaire conçu par le mathématicien **John Conway**. Ce jeu simule l'évolution de cellules sur une grille en appliquant des règles simples à chaque itération :

1. Une cellule vivante avec 2 ou 3 voisines vivantes survit.
2. Une cellule morte avec exactement 3 voisines vivantes devient vivante (naît).
3. Dans les autres cas, une cellule vivante meurt (surpopulation ou isolement).

Ce projet permet de simuler et visualiser cette évolution de manière interactive, avec la possibilité de personnaliser l'état initial via un fichier ou de générer aléatoirement les cellules.

---

## 🚀 Comment cloner le dépôt

Assurez-vous d'avoir **Git** installé sur votre système. Ensuite, utilisez la commande suivante pour cloner le projet :

```bash
git clone https://github.com/votre-utilisateur/jeu-de-la-vie.git
cd jeu-de-la-vie
```

---

## 📖 Manuel d'utilisation

### ⚙️ Compilation

Ce projet nécessite les prérequis suivants :

- **Compilateur C++** compatible avec C++11 ou supérieur (ex. : `g++`).
- **SFML** (Simple and Fast Multimedia Library) installé sur votre système.

#### Commande de compilation :
Utilisez la commande suivante pour compiler le projet :

```bash
g++ -o JeuDeLaVie src/main.cpp src/IHM/*.cpp src/Composants/*.cpp src/Services/*.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

### ▶️ Exécution

Après la compilation, lancez l'exécutable avec la commande suivante :

```bash
./JeuDeLaVie [fichier_entree]
```

#### Paramètres :
- `[fichier_entree]` (optionnel) : Chemin vers un fichier contenant l'état initial de la grille (au format texte). Si ce paramètre n'est pas fourni, une grille aléatoire est générée.

Exemple d'exécution avec un fichier d'entrée nommé `Grille.txt` :
```bash
./JeuDeLaVie Grille.txt
```

### Modes d'utilisation :
- **Mode console** : Permet de visualiser l'évolution directement dans la console.
- **Mode graphique** : Ouvre une fenêtre interactive utilisant SFML pour afficher l'automate.

Au lancement, vous serez invité à choisir le mode souhaité.

---

## 📜 License

Ce projet est sous licence CESI. Vous êtes libre de l'utiliser, le modifier et le distribuer sous les conditions suivantes :

```
CESI License

Copyright (c) 2024 [MERRAKCHI Mouayad]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Game of life"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```

---

## 👨‍💻 Contributions

Les contributions sont les bienvenues ! Si vous souhaitez contribuer :

1. Clonez le projet.
2. Créez une branche pour vos modifications (`git checkout -b feature-nouvelle-fonctionnalite`).
3. Effectuez vos changements et soumettez une Pull Request.

---

## 📧 Contact

Pour toute question ou suggestion, veuillez me contacter à l'adresse suivante : [mouayadmerrakchi@gmail.com](mailto:mouayadmerrakchi@gmail.com).

---

## 📝 Remarques importantes

- Veillez à bien installer SFML avant de compiler le projet.
- Pour une simulation fluide en mode graphique, assurez-vous d'avoir une configuration matérielle compatible.

Bon jeu et amusez-vous bien avec cette simulation de vie ! 🌟
