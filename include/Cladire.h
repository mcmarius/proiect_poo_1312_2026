//
// Created by marius on 04.03.2026.
//

#ifndef OOP_CLADIRE_H
#define OOP_CLADIRE_H
#include <vector>

#include "Etaj.h"

class Cladire {
    std::vector<Etaj> etaje;
    std::string nume;
    std::string adresa;

public:
    Cladire() = default;

    Cladire(const std::vector<Etaj> &etaje, const std::string &nume, const std::string &adresa);

    friend std::ostream &operator<<(std::ostream &os, const Cladire &obj);
};

#endif //OOP_CLADIRE_H
