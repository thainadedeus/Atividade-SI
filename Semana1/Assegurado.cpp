#include "Assegurado.h"

Assegurado::Assegurado(){
  this->IMEI  = -1; //aquela posição no vetor está vazia
  this->Login = ""; //qualquer coisa pode estar escrita
};  
Assegurado::Assegurado(int ra, std::string nome){ //recebendo no parâmetro e colocando no atributo
  this->IMEI    = IMEI;  // instanciando o objeto 
  this->Login  = Login;
}
string Assegurado::getLogin() const { //obter o objeto
  return Login;
}
int Assegurado::getIMEI() const{
  return IMEI;
}