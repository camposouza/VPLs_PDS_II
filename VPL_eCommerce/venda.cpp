#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

void Venda::adicionaCelular(const Celular& celular) {
  m_celulares.push_back(celular);
}

bool sort_celular(Celular cel1, Celular cel2) {
  if (cel1._fabricante == cel2._fabricante) {
    return (cel1._modelo < cel2._modelo);
  } else {
    return (cel1._fabricante < cel2._fabricante);
  }
}
void Venda::ordena() {
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  m_celulares.sort(sort_celular);
}

void Venda::recarregaEstoque(int cod, int qtd) {
  for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
    if (it->_codigo == cod) {
        it->_qtd += qtd;
    }
  }
}

void Venda::efetuaVenda(int cod, int qtd) {
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */

  for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
    if (it->_codigo == cod && it->_qtd >= qtd) {
        it->_qtd -= qtd;
    }
  }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
    if (it-> _fabricante == fabricante) {
      it->_valor -= it->_valor * desconto / 100;
    }
  }
}

void Venda::removeModelo(int cod) {
 for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
    if (it->_codigo == cod){
      m_celulares.erase(it);
      break;
    }    
  }
}

void Venda::imprimeEstoque() const {
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */
  
  for (auto it = m_celulares.begin(); it != m_celulares.end(); it++) {
    std::string corFormatada = it->_cor;
    corFormatada[0] = toupper(corFormatada[0]);
    if (it->_qtd >= 1) {
      std::cout << it->_fabricante << " "<< it->_modelo << ", " 
                << it->_armazenamento << "GB" << ", " << it->_memoria << "GB RAM" << ", "
                << std::fixed << std::setprecision(0) << it->_peso * 1000 << " gramas, " 
                << corFormatada << ", ";
                if (it->_qtd == 1) {
                  std::cout << it->_qtd << " restante, ";
                } else {
                  std::cout << it->_qtd << " restantes, ";
                }
      std::cout << "R$ " << std::fixed << std::setprecision(2) << it->_valor << std::endl;
    }
  }
}