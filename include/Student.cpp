//
// Created by marius on 04.03.2026.
//

#include "Student.h"

Student::Student(int nr_matricol, const std::string &nume,
                 const std::vector<std::string> &preferinte) : nr_matricol(nr_matricol),
                                                               nume(nume),
                                                               preferinte(preferinte) {
}

Student::Student(const Student &other) : nr_matricol(other.nr_matricol),
                                         nume(other.nume),
                                         preferinte(other.preferinte) {
    std::cout << "cc student " << nume << "\n";
}

Student &Student::operator=(const Student &other) {
    if (this == &other)
        return *this;
    nr_matricol = other.nr_matricol;
    nume = other.nume;
    preferinte = other.preferinte;
    return *this;
}

Student::~Student() {
    std::cout << "\nDestructor Student: " << nume << "\n";
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os
            << "nr_matricol: " << student.nr_matricol
            << " nume: " << student.nume;
    for (const auto &pref: student.preferinte) {
        os << pref;
    }
    return os;
}
