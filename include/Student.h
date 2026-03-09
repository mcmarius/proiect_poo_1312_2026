//
// Created by marius on 04.03.2026.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H
#include <iostream>
#include <string>
#include <vector>


class Student {
    int nr_matricol;
    std::string nume;
    std::vector<std::string> preferinte;

public:
    Student(int nr_matricol, const std::string &nume, const std::vector<std::string> &preferinte);

    Student(const Student &other);

    Student &operator=(const Student &other);

    ~Student();

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};


#endif //OOP_STUDENT_H
