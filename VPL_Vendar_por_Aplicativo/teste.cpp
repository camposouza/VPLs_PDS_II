#include <iostream>
#include <string>

using namespace std;

int main(){
    string resumo = "";
    string p1 = "Produto 1 ";
    string p2 = "Produto 2 ";
    resumo = resumo + p1 + p2;
    string endereco = "Av. Getulio N545";
    string resumoComEndereco = resumo + endereco;

    cout << resumoComEndereco << endl;

}

