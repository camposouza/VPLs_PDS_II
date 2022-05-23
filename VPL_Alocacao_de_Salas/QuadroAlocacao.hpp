#ifndef QUADROALOCACAO_H
#define QUADROALOCACAO_H
#include "Disciplina.hpp"
#include <vector>
#include <map>

struct QuadroAlocacao
{
    std::map<string, Disciplina> _quadro;

    // Cria uma nova alocação para uma determinada disciplina de acordo 
    // com os parâmetros informados. Todas as disciplinas possuem códigos diferentes, 
    // ou seja, únicos.
    void inserir_alocacao(string codigo, string nome, 
    string dia, string horario, string sala);


    // Remove a alocação em um determinado horário para a disciplina com o 
    // código informado. Lembrando que os horários de alocação são únicos em 
    // cada disciplina.
    void remover_alocacao_disciplina(string codigo, string horario);


    // Recupera todas as disciplinas que possuem o maior número de alocações.
    vector<Disciplina> recuperar_disciplinas_mais_ofertadas();


    // Imprime todo o quadro de alocação. As disciplinas devem estar ordenadas 
    // pelo código, e as alocações pelo horário da oferta.
    void imprimir_alocacao_completa();
};

#endif