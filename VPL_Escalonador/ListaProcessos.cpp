    #include "ListaProcessos.hpp"

ListaProcessos::ListaProcessos(){
    _cabeca._id = 0;
    _cabeca._nome = "cabeca";
    _cabeca._prioridade = 6;
    _cabeca._prox = nullptr;

}


void ListaProcessos::adicionar_processo(Processo* proc){

    // Para primeira inserção na lista
    if(_cabeca._prox == nullptr){
        _cabeca._prox = proc;
        proc->_prox = nullptr;

    } else {
        // Para inserções no meio da lista
        Processo* bcd;
        for(bcd = &_cabeca; bcd->_prox != nullptr; bcd = bcd->_prox){ 
            if(bcd->_prox->_prioridade < proc->_prioridade){
                proc->_prox = bcd->_prox;
                bcd->_prox = proc;
                break;
            }
        }
        // Para inserção no final da lista
            if(bcd->_prox == nullptr){
                proc->_prox = bcd->_prox;
                bcd->_prox = proc;
            }
    }
}


Processo* ListaProcessos::remover_processo_maior_prioridade(){
    Processo* removido = _cabeca._prox;
    _cabeca._prox = removido->_prox;
    removido->_prox = nullptr;
    return removido;
}


Processo* ListaProcessos::remover_processo_menor_prioridade(){
    Processo* bcd;
    for(bcd = &_cabeca; bcd->_prox != nullptr; bcd = bcd->_prox){ 
        if(bcd->_prox->_prox == nullptr){
            Processo* removido = bcd->_prox;
            bcd->_prox = nullptr;
            return removido;   
        }
    }
    return nullptr;
}


Processo* ListaProcessos::remover_processo_por_id(int id){
    Processo* bcd;
    for(bcd = &_cabeca; bcd->_prox != nullptr; bcd = bcd->_prox){ 
        if(bcd->_prox->_id == id){
            Processo* removido = bcd->_prox;
            bcd->_prox = bcd->_prox->_prox;
            return removido;
        }
    }
    return nullptr;
}


void ListaProcessos::imprimir_lista(){
    for(Processo* bcd = _cabeca._prox; bcd != nullptr; bcd = bcd->_prox){ 
        bcd->imprimir_dados();
    }
}