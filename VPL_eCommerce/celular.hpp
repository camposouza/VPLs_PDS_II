#ifndef CELULAR_H
#define CELULAR_H

#include <string>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de um celular.
 *
 */
class Celular {
 public:
  /**
   * @brief Construtor padrao que inicializa todas as variaveis da classe.
   *
   * @param modelo Modelo do celular. Ex: Galaxy s20.
   * @param fabricante Fabricante do celular. Ex: Samsung.
   * @param armazenamento Memoria interna total compartilhada. Ex: 4GB.
   * @param memoria Memoria RAM do celular. Ex: 4GB.
   * @param peso Peso em Kg do celular. Ex: 0.180Kg.
   * @param cor Cor do celular. Ex: branco.
   * @param qtd Quantidade de celulares do lote. Ex: 10 unidades.
   * @param valor Valor unitario do celular. Ex: R$ 756.25.
   */
  Celular(std::string modelo,
          std::string fabricante,
          int armazenamento,
          int memoria,
          double peso,
          std::string cor,
          int qtd,
          float valor);



 public:
  // Variaveis da classe.
  std::string _modelo;
  std::string _fabricante;
  int _armazenamento;
  int _memoria;
  double _peso;
  std::string _cor;
  int _qtd;
  float _valor;
  int _codigo;

 private:
  // Variavel estatica para atribuir os codigos dos celulares.
  static int codigo;

};

#endif