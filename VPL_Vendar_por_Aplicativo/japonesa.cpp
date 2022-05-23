#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
   std::string qtd = std::to_string(this->m_qtd);
   std::string sushi = std::to_string(this->_sushi);
   std::string temaki = std::to_string(this->_temaki);
   std::string hot = std::to_string(this->_hots);

  return (qtd + "X Comida japonesa - " + this->_combinado + ", " + sushi + " sushis, " +
          temaki + " temakis e " + hot + " hots.");
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  this->_combinado = combinado;
  this->_sushi = sushis;
  this->_temaki = temakis;
  this->_hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}