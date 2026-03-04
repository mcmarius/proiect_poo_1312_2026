//
// Created by marius on 04.03.2026.
//

#include "../include/Etaj.h"

Etaj::Etaj(const std::vector<Ventilator> &ventilatoare) : ventilatoare(ventilatoare) {
}

std::ostream &operator<<(std::ostream &os, const Etaj &etaj) {
    for (const auto &v: etaj.ventilatoare) {
        os << v << "\n";
    }
    return os;
}
