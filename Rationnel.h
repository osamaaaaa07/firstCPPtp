#ifndef RATIONNEL_H
#define RATIONNEL_H

struct Rationnel {
    int num;
    int den;
};

void saisir(Rationnel &r);
void afficher(Rationnel r);
void inverse(Rationnel &r);
void approximation(Rationnel r);
void formeIrreductible(Rationnel &r);
int pgcd(int a, int b);

void addition(Rationnel r1, Rationnel r2);
void soustraction(Rationnel r1, Rationnel r2);
void multiplication(Rationnel r1, Rationnel r2);
void division(Rationnel r1, Rationnel r2);

#endif
