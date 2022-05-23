#ifndef LISTA_PROCESSOS_H
#define LISTA_PROCESSOS_H
#include "Processo.hpp"

struct ListaProcessos
{
    Processo _cabeca;

    // Construtor
    ListaProcessos();


    // Recebe um Processo (ponteiro) e o adiciona na lista de maneira ORDENADA 
    // considerando a prioridade informada. A ordenação da prioridade deve ser 
    // DECRESCENTE, ou seja, do maior para o menor. Logo, um processo de prioridade 
    // 5 deve aparecer antes na lista que um processo com prioridade 1. 
    // Em caso de prioridades iguais, a ordem de inserção deve ser respeitada.
    void adicionar_processo(Processo* proc);


    // Remove da lista o processo de maior prioridade, para facilitar, o primeiro 
    // da lista (não precisa respeitar a ordem de inserção). Você deve 
    // retornar um ponteiro para o processo removido da lista (não é necessário 
    // desalocar a memória). 
    Processo* remover_processo_maior_prioridade();


    // Remove da lista o processo de menor prioridade, para facilitar, o último 
    // elemento da lista (não precisa respeitar a ordem de inserção). Você deve 
    // retornar um ponteiro para o processo removido da lista (não é necessário 
    // desalocar a memória). 
    Processo* remover_processo_menor_prioridade();


    // Remove da lista um processo de acordo com o id. Você deve retornar um 
    // ponteiro para o processo removido da lista (não é necessário desalocar a 
    // memória). Caso não exista na lista um processo com o id informado deve-se 
    // retornar nullptr.
    Processo* remover_processo_por_id(int id);


    // Imprime a situação atual da lista, ou seja, percorre toda a lista (do início 
    // para o final) e chama o método 'imprimir_dados()' de cada processo
    void imprimir_lista();

};


#endif