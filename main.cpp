#include "Rationnel.h"

#include <iostream>

using namespace std;

int main() {
    Rationnel r1{}, r2{};

    cout << "Premier rationnel:" << endl;
    saisir(r1);
    cout << "Second rationnel:" << endl;
    saisir(r2);

    cout << "\nRationnels saisis:" << endl;
    afficher(r1);
    afficher(r2);

    cout << "\nOpérations:" << endl;
    addition(r1, r2);
    soustraction(r1, r2);
    multiplication(r1, r2);
    division(r1, r2);

    cout << "\nFormes irréductibles:" << endl;
    formeIrreductible(r1);
    formeIrreductible(r2);

    return 0;
}
