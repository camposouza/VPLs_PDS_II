#ifndef ALOCACAO_H
#define ALOCACAO_H

#include <iostream>
using namespace std;

struct Alocacao
{
    string _dia, _horario, _sala;

    // Construtor
    Alocacao(string dia = " ", string horario = " ", string sala = " ");


    // Faz a impressão dos atributos no seguinte formato: 
    // "dia horario sala", com uma quebra de linha ao final.
    void imprimir_dados();
};

#endif