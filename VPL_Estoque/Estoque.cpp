  #include "Estoque.hpp"
  #include <iostream>
  #include <algorithm>


  void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    auto it = _estoque.find(mercadoria);
    if (it == _estoque.end()) {
      _estoque.insert(std::pair<std::string, unsigned int>(mercadoria, qtd));
    } else { it->second += qtd; }  
  }

  void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    auto it = _estoque.find(mercadoria);
    if (it == _estoque.end()) { 
      std::cout << mercadoria << "inexistente" << std::endl; 
    }
    else if (it->second < qtd) {
      std:: cout << mercadoria << "insuficiente" << std::endl; 
    }
    else { 
      it->second -= qtd;
    }
  }

  unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    auto it = _estoque.find(mercadoria);
    if (it == _estoque.end()) {
      return 0;
    } else {
      return it->second;
    }
  }

  void Estoque::imprime_estoque() const {
    for (auto it = _estoque.begin(); it != _estoque.end(); it++) {
      std::cout << it->first << ", " << it->second << std::endl;
    }
  }

  Estoque& Estoque::operator += (const Estoque& rhs) {
    for (auto it = rhs._estoque.begin(); it != rhs._estoque.end(); it++) {
      this->add_mercadoria(it->first, it->second);
    }
    return *this;
  }

  Estoque& Estoque::operator -= (const Estoque& rhs) {
    for (auto it = rhs._estoque.begin(); it != rhs._estoque.end(); it++) {
      this->sub_mercadoria(it->first, it->second);
    }
    return *this;
  }

  bool operator < (Estoque& lhs, Estoque& rhs) {
    if (lhs._estoque.size() >= rhs._estoque.size()) { 
      return false; 
    }
    for (auto it = lhs._estoque.begin(); it != lhs._estoque.end(); it++) {
      if (rhs._estoque.find(it->first) == rhs._estoque.end()) {
        return false;
      } 
      if (lhs._estoque.find(it->first)->second >= rhs._estoque.find(it->first)->second) {
        return false;
      }
    }
    return true;
  }

  bool operator > (Estoque& lhs, Estoque& rhs) {
    for (auto it = rhs._estoque.begin(); it != rhs._estoque.end(); it++) {
      if (lhs._estoque.find(it->first) == lhs._estoque.end()) {
        return false;
      } else if (rhs._estoque.find(it->first)->second >= lhs._estoque.find(it->first)->second) {
        return false;
      }
    }
    return true;
  }