#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
  std::string qtd = std::to_string(this->m_qtd);
  
  std::string artesanal;
  if (this->_artesanal) { artesanal = "artesanal."; } 
  else { artesanal = "simples."; }

  return (qtd + "X Hamburguer " + this->_tipo + " " + artesanal);
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  this->_tipo = tipo;
  this-> _artesanal = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}