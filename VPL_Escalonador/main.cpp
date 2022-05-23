// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"
#include "ListaProcessos.hpp"

int main(){

    //Inicializando Lista
    ListaProcessos Lista;
    

    char input;
    while (cin >> input) {
        switch (input) {
            
            case 'a':
            {   
                int id, prioridade;
                string nome;
                
                cin >> id;
                cin >> nome;
                cin >> prioridade;

                /* // Como eu estava tentando fazer:
                Processo proc;
                proc->_id = id;
                proc->_nome = nome;
                proc->_prioridade = prioridade;
                Lista.adicionar_processo(&proc);
                */

                Processo *proc;
                proc = new Processo(id, nome, prioridade);
                Lista.adicionar_processo(proc);   
               
                break;
            }
            case 'm':

                Lista.remover_processo_maior_prioridade();
                break;

            case 'n': 

                Lista.remover_processo_menor_prioridade();
                break;   

            case 'r':
                int id;
                cin >> id;

                Lista.remover_processo_por_id(id);                  
                break;     

            case 'p':
                
                Lista.imprimir_lista();
                break;

            case 'b':

                avaliacao_basica();
                break;                            
        }
    }
    
    return 0;
}