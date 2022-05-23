#include "Disciplina.hpp"


Disciplina::Disciplina(string codigo, string nome){
    _codigo = codigo;
    _nome = nome;
}


void Disciplina::inserir_alocacao(string dia, string horario, string sala){
    
    Alocacao aloc = Alocacao(dia, horario, sala);
    _listaAloc.push_back(aloc);
}


void Disciplina::remover_alocacao(string horario){
    
    int index = 0;
    for(Alocacao aloc : this->_listaAloc){
        if (aloc._horario == horario){
            _listaAloc.erase(_listaAloc.begin() + index);
        }
        index++;
    }   
}


bool sort_hora(Alocacao aloc1, Alocacao aloc2){  // Parâmetro do sort()
    return (aloc1._horario < aloc2._horario);
}
void Disciplina::imprimir_alocacao(){
    
    std::sort(_listaAloc.begin(), _listaAloc.end(), sort_hora);
    for(Alocacao i : this->_listaAloc){
        cout << this->_codigo << " " << this->_nome << " "; i.imprimir_dados();
    }
}
