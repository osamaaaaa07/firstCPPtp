#include "Rationnel.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int pgcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a == 0 ? 1 : a;
}

void saisir(Rationnel &r) {
    do {
        cout << "Entrez le numérateur: ";
        cin >> r.num;
        cout << "Entrez le dénominateur: ";
        cin >> r.den;
        if (r.den == 0) {
            cout << "Le dénominateur ne peut pas être 0. Réessayez." << endl;
        }
    } while (r.den == 0);
}

void afficher(Rationnel r) {
    cout << r.num << "/" << r.den << endl;
}

void inverse(Rationnel &r) {
    if (r.num == 0) {
        cout << "Impossible d'inverser: numérateur nul." << endl;
        return;
    }
    int temp = r.num;
    r.num = r.den;
    r.den = temp;
}

void approximation(Rationnel r) {
    if (r.den == 0) {
        cout << "Approximation impossible: dénominateur nul." << endl;
        return;
    }
    cout << "Approximation de " << r.num << "/" << r.den << " = "
         << static_cast<double>(r.num) / r.den << endl;
}

void formeIrreductible(Rationnel &r) {
    if (r.den == 0) {
        cout << "Forme irréductible impossible: dénominateur nul." << endl;
        return;
    }

    int numAvant = r.num;
    int denAvant = r.den;
    int g = pgcd(r.num, r.den);
    r.num /= g;
    r.den /= g;
    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

    cout << "Forme irréductible de " << numAvant << "/" << denAvant << " : "
         << r.num << "/" << r.den << endl;
}

void addition(Rationnel r1, Rationnel r2) {
    Rationnel r;
    r.num = r1.num * r2.den + r2.num * r1.den;
    r.den = r1.den * r2.den;
    cout << r1.num << "/" << r1.den << " + " << r2.num << "/" << r2.den << " = ";
    afficher(r);
}

void soustraction(Rationnel r1, Rationnel r2) {
    Rationnel r;
    r.num = r1.num * r2.den - r2.num * r1.den;
    r.den = r1.den * r2.den;
    cout << r1.num << "/" << r1.den << " - " << r2.num << "/" << r2.den << " = ";
    afficher(r);
}

void multiplication(Rationnel r1, Rationnel r2) {
    Rationnel r;
    r.num = r1.num * r2.num;
    r.den = r1.den * r2.den;
    cout << r1.num << "/" << r1.den << " * " << r2.num << "/" << r2.den << " = ";
    afficher(r);
}

void division(Rationnel r1, Rationnel r2) {
    if (r2.num == 0) {
        cout << "Division impossible: second rationnel nul." << endl;
        return;
    }
    Rationnel r;
    r.num = r1.num * r2.den;
    r.den = r1.den * r2.num;
    cout << r1.num << "/" << r1.den << " / " << r2.num << "/" << r2.den << " = ";
    afficher(r);
}
