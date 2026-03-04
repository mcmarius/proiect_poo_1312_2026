//
// Created by marius on 04.03.2026.
//

#include "../include/Ventilator.h"

#include <cmath>
#include <iostream>

Ventilator::Ventilator(int rpm, int zgomot) : m_rpm(rpm),
                                              m_zgomot(zgomot) {
}

Ventilator::Ventilator(int rpm) : m_rpm(rpm) {
}

Ventilator::Ventilator(int rpm, int zgomot, const std::string &firma) : m_rpm(rpm),
                                                                        m_zgomot(zgomot), firma(firma) {
}

Ventilator::Ventilator(const Ventilator &other) : m_rpm(other.m_rpm),
                                                  m_zgomot(other.m_zgomot),
                                                  firma(other.firma) {
    std::cout << "constr copiere ventilator " << m_rpm << " " << m_zgomot << " " << firma << "\n";
}

Ventilator &Ventilator::operator=(const Ventilator &other) {
    if (this == &other)
        return *this;
    this->m_rpm = other.m_rpm;
    m_zgomot = other.m_zgomot;
    firma = other.firma;
    return *this;
}

Ventilator::~Ventilator() {
    std::cout << "destr ventilator\n";
}

void Ventilator::start() {
    m_rpm = 999;
    m_zgomot = std::pow(m_rpm, 2);
}

void Ventilator::stop() {
    m_rpm = 0;
    m_zgomot = 20;
}

std::ostream &operator<<(std::ostream &os, const Ventilator &ventilator) {
    return os
           << "m_rpm: " << ventilator.m_rpm
           << " m_zgomot: " << ventilator.m_zgomot
           << " firma: " << ventilator.firma;
}
