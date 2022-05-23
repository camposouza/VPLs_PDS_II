#include "pizza.hpp"

std::string Pizza::descricao() const {
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */

  std::string qtd = std::to_string(this->m_qtd);
  std::string pedacos = std::to_string(this->_pedacos);
  
  std::string borda_recheada;
  if (this->_borda_recheada) { borda_recheada = "e borda recheada."; } 
  else { borda_recheada = "e sem borda recheada."; }
  
  return (qtd + "X Pizza " + this->_sabor + ", " + pedacos + " pedacos " + borda_recheada);
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  
  this->_sabor = sabor;
  this->_pedacos = pedacos;
  this->_borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}