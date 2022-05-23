#include "google_password.hpp"

#include <iostream>

bool passwordValido(std::string password){
    return (password.length() > 5 && password.length() < 51 &&
           !(password.find("123456") != std::string::npos) &&
           !(password.find(" ") != std::string::npos) );
}

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */

  if (passwordValido(password)) {
    m_passwords.insert ( std::pair<std::string, Usuario>(url,Usuario(login, password)) );
    }
}

void GooglePassword::remove(const std::string& url) {
  m_passwords.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */

  if (passwordValido(new_password)) {
    for (auto it = m_passwords.begin(); it != m_passwords.end(); it++) {
      if ((it->first == url) && (it->second.getPassword() == old_password)) {
        it->second.setLogin(login);
        it->second.setPassword(new_password);
        break;
      }
    }
  }
}

void GooglePassword::printPasswords() {
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
  std::cout << m_passwords.size() << std::endl;
  for (auto it = m_passwords.begin(); it != m_passwords.end(); it++) {
      std::cout << it->first << ": " 
                << it->second.getLogin() << " and " 
                << it->second.getPassword() << std::endl;
  }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  return (password.length() > 5 && password.length() < 51 &&
           !(password.find("123456") != std::string::npos) &&
           !(password.find(" ") != std::string::npos) );
}

