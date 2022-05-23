#include <vector>
#include <iostream>
#include <set>

#include "Algoritmos.hpp"

template <class T> void read_input(std::vector<T>& vec) {
  T val;
  while (std::cin >> val) {
    vec.push_back(val);
  }
}

template <class T> void print_input(std::vector<T>& vec) {
  T last = vec[vec.size()];
  for (auto it = vec.begin(); it != (vec.end() - 1); it++) {
    std::cout << *it << ", ";
  }
  std::cout << *(vec.end()-1) << std::endl;
}

template <class T> T get_max(std::vector<T>& vec) {
  if (vec.empty()) {
    std::cout << "Erro: vetor vazio.\n";
  }
  for (auto it = vec.begin(); it != vec.end(); it++) {
    if (*it >= vec[0]) {
      vec[0] = *it; 
    }
  }
  return vec[0];
}

template <class T> unsigned int count_duplicates(std::vector<T>& vec) {
  std::set<T> set;
  for (auto it = vec.begin(); it != vec.end(); it++) {
    set.insert(*it);
  }
  return vec.size() - set.size();
}

template <class T> void test_print_input() {
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T> void test_get_max() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T> void test_count_dups() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main() {
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste) {
    case 0:
      test_print_input<std::string>();
      break;
    case 1:
      test_print_input<int>();
      break;
    case 2:
      test_get_max<double>();
      break;
    case 3:
      test_get_max<char>();
      break;
    case 4:
      test_count_dups<int>();
      break;
    case 5:
      test_count_dups<std::string>();
      break;
    default:
      std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}