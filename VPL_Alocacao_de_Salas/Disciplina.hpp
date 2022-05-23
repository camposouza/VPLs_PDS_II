#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <vector>
#include <algorithm>
#include "Alocacao.hpp"


struct Disciplina
{
    string _codigo, _nome;
    std::vector<Alocacao> _listaAloc;

    // Construtor
    Disciplina(string codigo = " ", string nome = " ");


    // Cria uma nova alocação para a disciplina a partir dos dados informados 
    // e insere na coleção
    void inserir_alocacao(string dia, string horario, string sala);


    // Remove uma alocação da coleção. Para facilitar, 
    // vamos assumir que existe apenas uma única alocação em cada horário.
    void remover_alocacao(string horario);


    // Imprime todas as alocações para a disciplina. Cada alocação deve ser impressa
    // em uma linha separada e seguindo o formato  "codigo nome dia horario sala". 
    // Além disso, a alocação deve ser impressa ordenada de acordo com o horário.
    void imprimir_alocacao();
};

#endif