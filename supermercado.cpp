//Alteração na soma dos produtos
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int pede_codigo(int tipo_funcao, int guarda);
float soma_troco(float total, float dinheiro, float troco);

int main(){
  float prod[5], dinheiro, total, troco, guarda;
  int qtd1[5], qtd2[5], codigo, i, opcao;
  char cancelar, nota_fiscal;
  int tipo_funcao;
  do{
    codigo = 5;
    dinheiro = 0;
    troco = 0;
    i = 0;
    guarda = 0;
    total = 0;
    
    prod[0] = 1;         qtd1[0] = 0;         qtd2[0] = 0;
    prod[1] = 2;         qtd1[1] = 0;         qtd2[1] = 0;
    prod[2] = 2;         qtd1[2] = 0;         qtd2[2] = 0;
    prod[3] = 5.50;      qtd1[3] = 0;         qtd2[3] = 0;
    prod[4] = 6.50;      qtd1[4] = 0;         qtd2[4] = 0;
    
    cout << "---------------------------------------";
    cout << "\nBem vindo ao nosso estabelecimento!";
    cout << "\n---------------------------------------";

    cout << endl;
    cout << "\nCodigo do produto: ";
    tipo_funcao = 0;
    codigo = pede_codigo(tipo_funcao, guarda);
    switch (codigo){
    case 0:
      cout << "\nQuantidade: ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd1[0] = qtd1[0] + guarda; // Se guarda_qtd1 for maior que 0 sera valido
      break;
    case 1:
      cout << "\nQuantidade: ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd1[1] = qtd1[1] + guarda;
      break;
    case 2:
      cout << "\nQuantidade: ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd1[2] = qtd1[2] + guarda;
      break;
    case 3:
     cout << "\nQuantidade: ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd1[3] = qtd1[3] + guarda;
      break;
    case 4:
     cout << "\nQuantidade: ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd1[4] = qtd1[4] + guarda;
      break;
    default:
      cout << "\nCodigo invalido, tente novamente!";
      break;
    }
    cout << "\nDeseja finalizar a compra?[S/N]: ";
    cin >> cancelar;

    while (cancelar == 'n' || cancelar == 'N'){ // Enquanto cancelar nao for igual n ou N vai repetir
      cout << "\nCodigo do produto: ";
      tipo_funcao = 0;
      codigo = pede_codigo(tipo_funcao, guarda);
      switch (codigo){
      case 0:
        cout << "\nQuantidade: ";
        tipo_funcao = 1;
        guarda = pede_codigo(tipo_funcao, guarda);
        qtd2[0] = qtd2[0] + guarda; // Se guarda_qtd1 for maior que 0 sera valido
        break;
      case 1:
        cout << "\nQuantidade: ";
        tipo_funcao = 1;
        guarda = pede_codigo(tipo_funcao, guarda);
        qtd2[1] = qtd2[1] + guarda;
        break;
      case 2:
        cout << "\nQuantidade: ";
        tipo_funcao = 1;
        guarda = pede_codigo(tipo_funcao, guarda);
        qtd2[2] = qtd2[2] + guarda;
        break;
      case 3:
        cout << "\nQuantidade: ";
        tipo_funcao = 1;
        guarda = pede_codigo(tipo_funcao, guarda);
        qtd2[3] = qtd2[3] + guarda;
        break;
      case 4:
        cout << "\nQuantidade: ";
        tipo_funcao = 1;
        guarda = pede_codigo(tipo_funcao, guarda);
        qtd2[4] = qtd2[4] + guarda;
        break;
      default:
        cout << "\nCodigo invalido, tente novamente!";
        break;
      }
      cout << "\nDeseja finalizar a compra?[S/N]: ";
      cin >> cancelar;
    }
    //system("cls");
    for (i = 0; i < 5; i++){
      total = total + ((prod[i] * qtd1[i]) + (prod[i] * qtd2[i])); // Total recebe a soma das variaveis
    }
    
    cout << "\nTotal da compra: " << total << " REAIS";
    cout << "\nDinheiro recebido: ";
    cin >> dinheiro;

    troco = soma_troco(total, dinheiro, troco);
    if(troco < 0){
    dinheiro = soma_troco(total, dinheiro, troco);
    troco = 1;
    troco = soma_troco(total, dinheiro, troco);
    }
    cout << "Troco R$ " << troco;
    
    cout << endl;
    cout << "\nDeseja emitir a sua nota fiscal?[S/N]: ";
    cin >> nota_fiscal;
    //system("cls");
    
    // nota fiscal
    if (nota_fiscal == 's' || nota_fiscal == 'S'){
      cout << "\n            PRECO UNI              QUANTIDADE                 PRECO";
      cout << endl;
      // Se qtd1[i] ou qtd2[i] for diferente de zero vai imprimir na nota fiscal                                          Somando a valor dos produtos
      if (qtd1[0] != 0 || qtd2[0] != 0){
        cout << "\nPao...........R$ 1.00................. " << qtd1[0] + qtd2[0] << " .......................R$ " << ((prod[0] * qtd1[0]) + (prod[0] * qtd2[0]));
      }
      if (qtd1[1] != 0 || qtd2[1] != 0){
        cout << "\nMussarela.....R$ 2.00................. " << qtd1[1] + qtd2[1] << " .......................R$ " << ((prod[1] * qtd1[1]) + (prod[1] * qtd2[1]));
      }
      if (qtd1[2] != 0 || qtd2[2] != 0){
        cout << "\nPresunto......R$ 2.00................. " << qtd1[2] + qtd2[2] << " .......................R$ " << ((prod[2] * qtd1[2]) + (prod[2] * qtd2[2]));
      }
      if (qtd1[3] != 0 || qtd2[3] != 0){
        cout << "\nLeite.........R$ 5.50................. " << qtd1[3] + qtd2[3] << " .......................R$ " << ((prod[3] * qtd1[3]) + (prod[3] * qtd2[3]));
      }
      if (qtd1[4] != 0 || qtd2[4] != 0){
        cout << "\nManteiga......R$ 6.50................. " << qtd1[4] + qtd2[4] << " .......................R$ " << ((prod[4] * qtd1[4]) + (prod[4] * qtd2[4]));
      }
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "\nTOTAL DA COMPRA...............................................R$ " << total;
      cout << "\nDINHEIRO RECEBIDO.............................................R$ " << dinheiro;
      cout << "\nTROCO.........................................................R$ " << troco;
      cout << endl;
      cout << "\nCOMPRA FINALIZADA, VOLTE SEMPRE!";
      cout << endl;
      cout << "\nSe deseja fazer uma nova compra digite 1: ";
      cin >> opcao;
    }
    else{
      cout << "\nCOMPRA FINALIZADA, VOLTE SEMPRE!";
      cout << "\nSe deseja fazer uma nova compra digite 1: ";
      cin >> opcao;
    }
    //system("cls");
  } while (opcao == 1); // Se opcao for igual a 1, sera feita uma nova compra
  return 0;
}

int pede_codigo(int tipo_funcao, int guarda){
  int aux_codigo;
  int aux_quantidade;

  if (tipo_funcao == 0){
    cin >> aux_codigo;
    while (aux_codigo > 4 || aux_codigo < 0){
      cout << "\nCodigo invalido, tente novamente!";
      cout << endl;
      cout << "\nCodigo do produto: ";
      cin >> aux_codigo;
    }
    return aux_codigo;
  }
  if (tipo_funcao == 1){
    cin >> aux_quantidade;
    while (aux_quantidade < 0){
      cout << "\nQuantidade invalida, tente novamente!";
      cout << endl;
      cout << "\nQuantidade: ";
      cin >> aux_quantidade;
    }
    return aux_quantidade;
  }
  return 0;
}

float soma_troco(float total, float dinheiro, float troco){
  float total2, dinheiro2;
    total2 = 0;
    dinheiro2 = 0;
    total2 = total + total2;
    dinheiro2 = dinheiro + dinheiro2; 
    if(troco == 0){
      troco = dinheiro - total;
    return troco;
    }
    if(troco < 0){
      while (troco < 0){
      cout << "\nDinheiro insuficiente. Faltam R$" << troco * (-1) << " REAIS";
      total2 = troco * (-1); // total2 recebe total para fazer a soma dentro do while
      cout << endl;
      cout << "\nQuanto sera o pagamento: ";
      cin >> dinheiro2;
      troco = dinheiro2 - total2;
      dinheiro = dinheiro + dinheiro2; // dinheiro recebe dinheiro2 para somar os valores que o usario enviou até se igual ou maior que o total
    }
    return dinheiro;
  }
    if(troco > 0){
      troco = 0;
      troco = dinheiro - total;
    return troco;
    }
  return 0;
}