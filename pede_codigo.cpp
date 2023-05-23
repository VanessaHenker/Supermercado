#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef IOMANIP_H
#define IOMANIP_H
#include <iomanip>
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
using namespace std;
#endif

int pede_codigo(int tipo_funcao, int guarda){
  int aux_codigo;
  int aux_quantidade;

  if (tipo_funcao == 0){
    cin >> aux_codigo;
    while (aux_codigo > 4 || aux_codigo < 0){
      cout << "\nCodigo inválido, tente novamente!";
      cout << endl;
      cout << "\nCodigo do produto: ";
      cin >> aux_codigo;
    }
    return aux_codigo;
  }
  if (tipo_funcao == 1){
    cin >> aux_quantidade;
    while (aux_quantidade < 0){
      cout << "\nQuantidade inválida, tente novamente!";
      cout << endl;
      cout << "\nQuantidade: ";
      cin >> aux_quantidade;
    }
    return aux_quantidade;
  }
  return 0;
}
