#include "QuadroAlocacao.hpp"

void QuadroAlocacao::inserir_alocacao(string codigo, string nome, 
string dia, string horario, string sala){

    // Formato do map:
    // _quadro[codigo] = Disciplina;

    if(_quadro.begin() == _quadro.end()){
        Disciplina discp = Disciplina(codigo, nome);
        discp.inserir_alocacao(dia, horario, sala);
        _quadro.insert(std::pair<string,Disciplina>(codigo, discp));
    }else{
        for(auto it = _quadro.begin(); it != _quadro.end(); it++){
            if(it->first == codigo){
                it->second.inserir_alocacao(dia, horario, sala);
            
            } else if(it == --_quadro.end()){
                Disciplina discp = Disciplina(codigo, nome);
                discp.inserir_alocacao(dia, horario, sala);
                _quadro.insert(std::pair<string,Disciplina>(codigo, discp));
            }
        }
    }
}


void QuadroAlocacao::remover_alocacao_disciplina(string codigo, string horario){
    for(auto it = _quadro.begin(); it != _quadro.end(); it++){
        if(it->first == codigo){
            it->second.remover_alocacao(horario);
        }
    }
}


vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas(){
    int oferta = 0, oferta_temp = 0;
    std::vector<Disciplina> v;
    Disciplina mais_of;
    
    for(auto it = _quadro.begin(); it != _quadro.end(); it++){
        for(auto it2 = it->second._listaAloc.begin(); it2 != it->second._listaAloc.end(); it2++){
            oferta_temp++;
        }
        if(oferta_temp > oferta){
            oferta = oferta_temp;
            mais_of = it->second;
            v.clear();
            v.push_back(mais_of);
        } else if(oferta_temp == oferta){
            oferta = oferta_temp;
            mais_of = it->second;
            v.push_back(mais_of);
        }
        oferta_temp = 0;
    }
    return v;
    
}


bool sort_discp(Disciplina aloc1, Disciplina aloc2){  // Parâmetro do sort()
    return aloc1._codigo < aloc2._codigo;
}
bool sort_aloc(Alocacao aloc1, Alocacao aloc2){  // Parâmetro do sort()
    return aloc1._horario < aloc2._horario;
}
void QuadroAlocacao::imprimir_alocacao_completa(){

    /*
    1 - Criei 2 vetores, 'vec_discp' e 'vec_aloc';
    2 - Preenchi os vetores;
    3 - Ordenei os dois vetores segundo os critérios;
    4 - Imprimi.
    */

    // 1 -
    std::vector<Disciplina> vec_discp;
    std::vector<Alocacao> vec_aloc;

    // 2 -
    for(auto it = _quadro.begin(); it != _quadro.end(); it++){
        vec_aloc.push_back(it->first);
        vec_discp.push_back(it->second);
    }

    // 3 -
    std::sort(vec_discp.begin(), vec_discp.end(), sort_discp);
    std::sort(vec_aloc.begin(), vec_aloc.end(), sort_aloc);
    
    // 4 - 
    for(auto it = _quadro.begin(); it != _quadro.end(); it++){
        it->second.imprimir_alocacao();
    }
    
}

