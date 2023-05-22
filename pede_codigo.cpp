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


int pede_codigo(string tipo_funcao, int tamanho){
    int aux_codigo;
    int aux_quantidade;

    if(tipo_funcao == "codigo"){
    cin >> aux_codigo;
    while(aux_codigo > tamanho || aux_codigo < 0){
        cout << "\nCodigo inválido, tente novamente";
        cin >> aux_codigo;
    }
    return aux_codigo;
    }

    if(tipo_funcao == "quantidade"){
    cin >> aux_quantidade;
    while(aux_quantidade < 0){ 
        cout << "\nQuantidade inválida, tente novamente";
        cin >> aux_quantidade;
    }
    return aux_quantidade;
    }
return 0;
}
