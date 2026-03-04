//
// Created by marius on 04.03.2026.
//

#include "../include/Cladire.h"

Cladire::Cladire(const std::vector<Etaj> &etaje, const std::string &nume, const std::string &adresa) : etaje(etaje),
    nume(nume),
    adresa(adresa) {
}

std::ostream &operator<<(std::ostream &os, const Cladire &obj) {
    return os
           // << "etaje: " << obj.etaje
           << " nume: " << obj.nume
           << " adresa: " << obj.adresa;
}
