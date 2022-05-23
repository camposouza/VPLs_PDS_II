#include "Nave.hpp"
#include <iostream>

using namespace std;

Nave::Nave(Ponto2D posicao, double forca, double energia){
    _posicao = posicao;
    _forca = forca;
    _energia = energia;
}

void Nave::mover(double dx, double dy){
    this->_posicao._x += dx;
    this->_posicao._y += dy;
}

double Nave::calcular_distancia(Nave* nave){
    return this->_posicao.calcular_distancia(&nave->_posicao);
}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n){
    
    Nave* NaveMaisProxima;
    double distancia = 999999;

    for(int i = 0; i < n; i++){
        
        if(naves[i]->_posicao._x != this->_posicao._x or 
           naves[i]->_posicao._y != this->_posicao._y){
            
            double d = calcular_distancia(naves[i]);
            if (d < distancia){
                distancia = d;
                NaveMaisProxima = naves[i];
            }
        }
        
    }
    return NaveMaisProxima;
}


void Nave::atacar(Nave** naves, int n){
    
    Nave* alvo = determinar_nave_mais_proxima(naves, n);
    double d = calcular_distancia(alvo);
    
    double dano = (100/d) * this->_forca;
    if(dano > 30)
        alvo->_energia -= 30;
    else
        alvo->_energia -= dano;
    
    if(alvo->_energia <= 50){
        cout << "Energia baixa!" << endl;
    }
}

void Nave::imprimir_status(){
    cout << this->_posicao._x << " " << this->_posicao._y << " " << this->_energia << endl;

}