#include "hash.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

Hash::Hash(int max) {
  tamanho = 0;
  max_items = max;
  estrutura = new Assegurado[max_items];
}

Hash::~Hash() { delete[] estrutura; }

bool Hash::casasCheias() const { return (tamanho == max_items); }

int Hash::contarElementos() const { return tamanho; }

void Hash::recuperarItem(
    Assegurado &Assegurado,
    bool &localizado) { // parâmetro  e booleano passando como referência
    int localizacao_inicial = getHash(Assegurado);
    bool procurar_mais = true;
    int localizacao = localizacao_inicial;
    do {
    if (estrutura[localizacao].getIMEI() ==       Assegurado.getIMEI() ||
    estrutura[localizacao].getIMEI() == -1)
    procurar_mais = false;
    else
    localizacao = (localizacao +1) % max_items;
  }
    while(localizacao != localizacao_inicial && procurar_mais);
    int found = (estrutura[localizacao].getIMEI() ==     Assegurado.getIMEI());
    if(found) {
    Assegurado = estrutura[localizacao];
  }
}


void Hash::inserirItem(Assegurado Assegurado) {
    int localizacao = getHash(Assegurado);
   while(estrutura[localizacao].getIMEI()>0)
    localizacao = (localizacao + 1) % max_items;
    estrutura[localizacao] = Assegurado;
    tamanho++;
}

void Hash::deletarItem(Assegurado Assegurado) {
  int localizacao_inicial = getHash(Assegurado);
  bool procurar_mais = true;
  int localizacao = localizacao_inicial;
  do {
    if (estrutura[localizacao].getIMEI() == Assegurado.getIMEI() ||
    estrutura[localizacao].getIMEI() == -1)
    procurar_mais = false;
  else
  localizacao = (localizacao +1) % max_items;
  }
  while(localizacao != localizacao_inicial && procurar_mais);
  if (estrutura[localizacao].getIMEI() == Assegurado.getIMEI()){
    estrutura[localizacao] = Assegurado(-2,"");
    tamanho--;
    }
}

void Hash::print() {
    for (int i = 0; i < max_items; i++) {
    cout << i <<":"<<
      estrutura[i].getIMEI()<<", "<<
      estrutura[i].getLogin()<<endl;
  }
}

int Hash::getHash(Assegurado Assegurado) {
  return Assegurado.getIMEI() % max_items; // gerar m valor entre 0 e 99
}