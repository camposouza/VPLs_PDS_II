#include "pedido.hpp"


Pedido::~Pedido() {
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++) {
    delete *it;
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float valor_total = 0;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++) {
    valor_total += ( (*it)->getQtd() * (*it)->getValor() );
  }
  return valor_total;
}

void Pedido::adicionaProduto(Produto* p) {
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */

  std::string resumo = "";
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++) {
    resumo = resumo + (*it)->descricao() + "\n";
  }
  
  resumo = resumo + "Endereco: " + this->m_endereco + "\n";

  return resumo;
}