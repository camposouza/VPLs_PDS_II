#include "Alocacao.hpp"

Alocacao::Alocacao(string dia, string horario, string sala){
    _dia = dia;
    _horario = horario;
    _sala = sala;
}


void Alocacao::imprimir_dados(){
    cout << _dia << " " << _horario << " " << _sala << endl;
}