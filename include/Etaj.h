//
// Created by marius on 04.03.2026.
//

#ifndef OOP_ETAJ_H
#define OOP_ETAJ_H
#include <iostream>
#include <vector>

#include "Ventilator.h"

class Etaj {
    std::vector<Ventilator> ventilatoare;

public:
    explicit Etaj(const std::vector<Ventilator> &ventilatoare);

    friend std::ostream &operator<<(std::ostream &os, const Etaj &etaj);
};


#endif //OOP_ETAJ_H
