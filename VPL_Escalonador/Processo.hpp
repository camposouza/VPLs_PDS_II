#ifndef PROCESSO_H
#define PROCESSO_H
#include <iostream>
using namespace std;

struct Processo{
    int _id, _prioridade;
    string _nome;
    struct Processo* _prox;

    // Construtor
    Processo(int id = 0, string nome = " ", int prioridade = 0);

    // Daz a impressão dos atributos no seguinte formato: 
    // "id nome prioridade", com uma quebra de linha ao final.
    void imprimir_dados();

};

#endif