#include "Assegurado.h"

class Hash {
 public:
  Hash(int max_items = 100); 
  ~Hash(); //desalocar os recursos
  bool casasCheias() const; //verificar se todos estão preenchidos
  int contarElementos() const; //quantos elementos estão na estrutura
  
  void recuperarItem(Assegurado&assegurado, bool& localizado); //funcionalidade 1
  void inserirItem(Assegurado assegurado); // funcionalidade 2
  void deletarItem(Assegurado assegurado); // funcionalidade 3
  void print();
 private:
  int getHash(Assegurado assegurado);
  int   max_items;
  int   tamanho;
  Assegurado* estrutura; //vetor do objeto aluno
};

