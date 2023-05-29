//Alteração na soma dos produtos
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int pede_codigo(int tipo_funcao, int guarda);
float soma_troco(float total, float dinheiro, float troco);

int main(){
  float preco[5], dinheiro, total, troco;
  int qtd[5], codigo, i, opcao, tipo_funcao, guarda;
  char cancelar, nota_fiscal;
  string nome_prod[5];
  do{
    codigo = 5;
    dinheiro = 0;
    troco = 0;
    i = 0;
    guarda = 0;
    total = 0;
    
    preco[0] = 1.00;   nome_prod[0] = "Pao";            qtd[0] = 0;
    preco[1] = 2.00;   nome_prod[1] = "Mussarela";      qtd[1] = 0;
    preco[2] = 2.00;   nome_prod[2] = "Presunto";       qtd[2] = 0;
    preco[3] = 5.50;   nome_prod[3] = "Leite";          qtd[3] = 0;
    preco[4] = 6.50;   nome_prod[4] = "Manteiga";       qtd[4] = 0;
    
    cout << "---------------------------------------";
    cout << "\nBem vindo ao nosso estabelecimento!";
    cout << "\n---------------------------------------";

    cout << endl;
    do{
    cout << "\nCodigo do produto: ";
    tipo_funcao = 0;
    codigo = pede_codigo(tipo_funcao, guarda);
    switch (codigo){
    case 0:
      cout << "\nQuantidade de " << nome_prod[0] << ": ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd[0] = qtd[0] + guarda; // Se guarda_qtd1 for maior que 0 sera valido
      break;
    case 1:
      cout << "\nQuantidade de " << nome_prod[1] << ": ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd[1] = qtd[1] + guarda;
      break;
    case 2:
      cout << "\nQuantidade de " << nome_prod[2] << ": ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd[2] = qtd[2] + guarda;
      break;
    case 3:
      cout << "\nQuantidade de " << nome_prod[3] << ": ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd[3] = qtd[3] + guarda;
      break;
    case 4:
      cout << "\nQuantidade de " << nome_prod[4] << ": ";
      tipo_funcao = 1;
      guarda = pede_codigo(tipo_funcao, guarda);
      qtd[4] = qtd[4] + guarda;
      break;
    default:
      cout << "\nCodigo invalido, tente novamente!";
      break;
    }
    cout << "\nDeseja finalizar a compra?[S/N]: ";
    cin >> cancelar;
    } while (cancelar == 'n' || cancelar == 'N');
    
    //system("cls");
    for (i = 0; i < 5; i++){
      total = total + (preco[i] * qtd[i]); // Total recebe a soma das variaveis
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
      if (qtd[0] != 0){
        cout << nome_prod[0] <<".............R$ "<< preco[0] <<"................. " << qtd[0] <<" .......................R$ " << preco[0] * qtd[0] << "\n";
      }
      if (qtd[1] != 0){
        cout << nome_prod[1] <<".............R$ "<< preco[1] <<"................. " << qtd[1] <<" .......................R$ " << preco[1] * qtd[1] << "\n";
      }
      if (qtd[2] != 0){
        cout << nome_prod[2] <<".............R$ "<< preco[2] <<"................. " << qtd[2] <<" .......................R$ " << preco[2] * qtd[2]  << "\n";
      }
      if (qtd[3] != 0 ){
        cout << nome_prod[3] <<".............R$ "<< preco[3] <<"................. " << qtd[3] <<" .......................R$ " << preco[3] * qtd[3] << "\n";
      }
      if (qtd[4] != 0){
        cout << nome_prod[4] <<".............R$ "<< preco[4] <<"................. " << qtd[4] <<" .......................R$ " << preco[4] * qtd[4] << "\n";
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
  int aux_codigo, i;
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