//
// Created by marius on 04.03.2026.
//

#ifndef OOP_VENTILATOR_H
#define OOP_VENTILATOR_H
#include <string>


class Ventilator {
    int m_rpm = 0;
    int m_zgomot = 20;
    std::string firma = "made in china";

public:
    Ventilator(int rpm, int zgomot);

    explicit Ventilator(int rpm);

    Ventilator(int rpm, int zgomot, const std::string &firma);

    Ventilator(const Ventilator &other);

    Ventilator &operator=(const Ventilator &other);

    ~Ventilator();

    void start();

    void stop();

    friend std::ostream &operator<<(std::ostream &os, const Ventilator &ventilator);
};

#endif //OOP_VENTILATOR_H
