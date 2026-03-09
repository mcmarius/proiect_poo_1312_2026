#include <iostream>
#include <array>
#include <optional>
#include <ostream>
#include <vector>

#include "Cladire.h"
#include "Etaj.h"
#include "Student.h"
#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"


class Facultate {
    std::optional<Cladire> cladire;
    std::string nume;
    std::vector<Student> studenti;

public:
    Facultate(const std::optional<Cladire> &cladire, const std::string &nume, const std::vector<Student> &studenti);

    Facultate(const Facultate &other);

    Facultate &operator=(const Facultate &other);

    ~Facultate() = default;

    friend std::ostream &operator<<(std::ostream &os, const Facultate &facultate);
};

std::ostream &operator<<(std::ostream &os, const Facultate &facultate) {
    if (facultate.cladire.has_value()) {
        os << "cladire: " << *facultate.cladire;
    }
    os << " nume: " << facultate.nume;
    return os;
}

Facultate::Facultate(const std::optional<Cladire> &cladire, const std::string &nume,
                     const std::vector<Student> &studenti) : cladire(cladire),
                                                             nume(nume),
                                                             studenti(studenti) {
}

Facultate::Facultate(const Facultate &other) : cladire(other.cladire),
                                               nume(other.nume),
                                               studenti(other.studenti) {
}

Facultate &Facultate::operator=(const Facultate &other) {
    if (this == &other)
        return *this;
    cladire = other.cladire;
    nume = other.nume;
    studenti = other.studenti;
    return *this;
}


class Inchisoare : public Facultate {
    int gravitate;

public:
    Inchisoare(const std::optional<Cladire> &cladire, const std::string &nume, const std::vector<Student> &studenti,
               int gravitate)
        : Facultate(cladire, nume, studenti),
          gravitate(gravitate) {
    }

    Inchisoare(const Inchisoare &other)
        : Facultate(other),
          gravitate(other.gravitate) {
    }

    Inchisoare &operator=(const Inchisoare &other) {
        if (this == &other)
            return *this;
        Facultate::operator =(other);
        gravitate = other.gravitate;
        return *this;
    }
};

class Baza {
    int z{3};

    void g() const {
        std::cout << z;
    }

protected:
    int x;

    void f() const {
        std::cout << "f\n";
        g();
    }

public:
    void ff() {
        x++;
    }

    explicit Baza(int x_) : x(x_) {
        std::cout << "Constructor Bază: " << x << "\n";
        f();
    }
};

class Derivata : public Baza {
public:
    Derivata() : Baza(1) {
        std::cout << "Constructor 1 Derivată: " << x << "\n";
        f();
        ff();
        // z;
        // g();
    }

    void k() {
        x--;
    }
};

class Derivata2 : protected Derivata {
public:
    Derivata2() : Derivata() {
        std::cout << "Constructor 1 Derivată2: " << x << "\n";
        f();
        ff();
        k();
    }
};

class Derivata3 : public Derivata2 {
public:
    Derivata3() : Derivata2() {
        std::cout << "Constructor 1 Derivată3: " << x << "\n";
        f();
        ff();
        k();
    }
};


int main() {
    Derivata deriv;
    Derivata2 deriv2;
    deriv.ff();
    // deriv2.ff();
    deriv.k();
    // deriv2.k();
    // deriv.x;
    Ventilator ventilator1{300, 20};
    ventilator1.start();
    ventilator1.stop();
    std::cout << ventilator1 << "\n\n";
    std::cout << "Hello, 1312!\n";
    Example e1;
    e1.g();
    std::array<int, 100> v{};
    int nr;
    std::cout << "Introduceți nr: ";
    /////////////////////////////////////////////////////////////////////////
    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
    /// dați exemple de date de intrare folosind fișierul tastatura.txt
    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
    /// pentru cât mai multe ramuri de execuție.
    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
    ///
    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
    /// pentru a simula date introduse de la tastatură.
    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
    ///
    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
    /// program care merg (și să le evitați pe cele care nu merg).
    ///
    /////////////////////////////////////////////////////////////////////////
    std::cin >> nr;
    /////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < nr; ++i) {
        std::cout << "v[" << i << "] = ";
        std::cin >> v[i];
    }
    std::cout << "\n\n";
    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
    for (int i = 0; i < nr; ++i) {
        std::cout << "- " << v[i] << "\n";
    }
    ///////////////////////////////////////////////////////////////////////////
    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
    /// alt fișier propriu cu ce alt nume doriți.
    /// Exemplu:
    /// std::ifstream fis("date.txt");
    /// for(int i = 0; i < nr2; ++i)
    ///     fis >> v2[i];
    ///
    ///////////////////////////////////////////////////////////////////////////
    return 0;
}
