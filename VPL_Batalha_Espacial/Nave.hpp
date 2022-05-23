#ifndef NAVE_H
#define NAVE_H

#include "Ponto2D.hpp"

struct Nave{
    Ponto2D _posicao;
    double _forca, _energia;

    // Construtor
    Nave(Ponto2D posicao , double forca = 1, double energia = 100);
    
    // Atualiza a posição da nave nos eixos x e y somando 
    // valores dx e dy, respectivamente
    void mover(double dx, double dy);
    
    // Calcula e retorna a distância euclidiana para outra nave 
    // qualquer passada como parâmetro (ponteiro).
    double calcular_distancia(Nave* nave);
    
    // Recebe um array de ponteiros para naves e um parâmetro que 
    // informa a quantidade de elementos nesse array. Determina 
    // qual a nave mais próxima e retorna um ponteiro para essa nave
    Nave* determinar_nave_mais_proxima(Nave** naves, int n);
    
    // A nave que sofre um ataque tem o seu valor de energia reduzido, 
    // onde a quantidade de dano é dada pela equação: dano = (100/d)*forca, 
    // onde d é a distância para a nave, e a força é o parâmetro informado no 
    // construtor. O máximo de dano (limite) que uma nave pode fazer em outra 
    // é 30. Se após um ataque a nave atacada tiver energia menor/igual a 50 
    // deve ser impressa a mensagem "Energia baixa!".
    void atacar(Nave** naves, int n);
    
    // Imprime a situação atual da nave no seguinte formato "x y energia
    void imprimir_status();
};

#endif