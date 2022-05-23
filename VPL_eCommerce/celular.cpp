#include "celular.hpp"

int Celular::codigo = 1;

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
  _modelo = modelo;
  _fabricante = fabricante;
  _armazenamento = armazenamento;
  _memoria = memoria;
  _peso = peso;
  _cor = cor;
  _qtd = qtd; 
  _valor = valor;
  _codigo = codigo;
  codigo++;
}