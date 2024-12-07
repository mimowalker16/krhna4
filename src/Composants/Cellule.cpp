#include "Cellule.h"

Cellule::Cellule() : vivante(false) {}

bool Cellule::estVivante() const {
    return vivante;
}

void Cellule::setVivante(bool etat) {
    vivante = etat;
}
