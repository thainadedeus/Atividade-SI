#include <iostream>
using namespace std;

class Assegurado{
private :
  int         IMEI; //chave de busca
  std::string Login;  // informação relacionada
public:  
  Assegurado(); //método construtor sem parâmetro na alocação de memória
  Assegurado(int IMEI, std::string Login); // construtor para poder configurar o Ra e a informação
  string getLogin() const; // obter o nome
  int getIMEI() const; //obter o ra
};