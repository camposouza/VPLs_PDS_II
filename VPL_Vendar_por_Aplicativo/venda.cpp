#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++) {
    delete (*it);
  }
}

void Venda::adicionaPedido(Pedido* p) {
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */

  int num_pedido = 1;
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++) {
    std::cout << "Pedido " << num_pedido << std::endl;
    num_pedido++;
    std::cout << (*it)->resumo();
  }

  float total = 0;
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++) {
    total += (*it)->calculaTotal();
  }

  std::cout << "Relatorio de Vendas" << std::endl 
            << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << total << std::endl
            << "Total de pedidos: " << num_pedido-1;

}