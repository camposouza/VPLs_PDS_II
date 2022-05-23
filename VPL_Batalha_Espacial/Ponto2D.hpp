#ifndef PONTO2D_H
#define PONTO2D_H

#include <cmath>

struct Ponto2D{
    double _x, _y;

    // Contrutor
    Ponto2D(double x = 0, double y = 0);

    // Calcula a distância euclidiana para outro ponto no plano
    double calcular_distancia(Ponto2D* ponto);
};

#endif