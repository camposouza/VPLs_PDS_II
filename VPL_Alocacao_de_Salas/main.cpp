// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_alocacao.hpp"

int main(){

    QuadroAlocacao quadro;

    char input;
    while (cin >> input) {
        switch (input) {
            
            case 'a':
            {   string codigo, nome, dia, horario, sala;
                cin >> codigo;
                cin >> nome;
                cin >> dia;
                cin >> horario;
                cin >> sala;

                quadro.inserir_alocacao(codigo, nome, dia, horario, sala);
               
                break;
            }
            case 'm':
            {
                std:: vector <Disciplina> v = quadro.recuperar_disciplinas_mais_ofertadas();
                for(auto it = v.begin(); it != v.end(); it++){
                    it->imprimir_alocacao();
                }
                
                break;
            }
            case 'r':
            {     
                string codigo, horario;
                cin >> codigo;
                cin >> horario;

                quadro.remover_alocacao_disciplina(codigo, horario);

                break;     
            }
            case 'p':
            {   
                quadro.imprimir_alocacao_completa();

                break;
            }
            case 'b':
            {
                avaliacao_basica();

                break;                            
            }
        }
    }
    
    return 0;
}