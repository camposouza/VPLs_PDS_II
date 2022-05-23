#include "Processo.hpp"

Processo::Processo(int id, string nome, int prioridade){ 
    _id = id;
    _nome = nome;
    _prioridade = prioridade;

}

void Processo::imprimir_dados(){
    cout << this->_id << " " << this->_nome << " " << this->_prioridade << endl;
    
}