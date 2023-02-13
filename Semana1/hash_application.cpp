#include <iostream>
#include "hash.h" 
#include <vector>
#include <utility>
using namespace std;

int main(){
  Hash AsseguradoHash(10);
   int   IMEIs[7]   = {
     12704, 31300, 1234,
     49001, 52202, 65606,
     91234};
  string Logins[7] = {
    "Pedro", "Raul", "Paulo",
    "Carlos", "Lucas", "Maria",
    "Samanta"}; 
	    
  for (int i = 0; i < 7; i++) {
  Assegurado Assegurado = Assegurado(IMEIs[i], Logins[i]);
   AsseguradoHash.inserirItem(Assegurado);
  }
  AsseguradoHash.print();  
  cout << "------------------------------" <<  endl;
  
  Assegurado AsseguradoBusca(12704,"");  
  bool     localizado = false;
  AsseguradoHash.recuperarItem(AsseguradoBusca, localizado);
  cout << AsseguradoBusca.getLogin() << " -> " << localizado << endl;
  
  cout << "------------------------------" <<  endl;

  AsseguradoHash.deletarItem(AsseguradoBusca);
  AsseguradoHash.print();
  cout << "Fim" << endl;  
}
