#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main(){
  float prod[5], qtd1[5], qtd2[5], dinheiro, total, troco;
  int codigo, i, opcao;
  char cancelar, nota_fiscal;
  do{
    codigo = 5;
    dinheiro = 0;
    troco = 0;
    i = 0;
    total = 0;
    prod[0] = 1;        qtd1[0] = 0;    qtd2[0] = 0;
    prod[1] = 2;        qtd1[1] = 0;    qtd2[1] = 0;
    prod[2] = 2;        qtd1[2] = 0;    qtd2[2] = 0;
    prod[3] = 5.50;     qtd1[3] = 0;    qtd2[3] = 0;
    prod[4] = 6.50;     qtd1[4] = 0;    qtd2[4] = 0;

    cout << "---------------------------------------";
    cout << "\nBem vindo ao nosso estabelecimento!";
    cout << "\n---------------------------------------";

    while (codigo > 4){
      cout << "\nCodigo do produto: ";
      cin >> codigo;
      switch (codigo){
      case 0:
        cout << "\nQuantidade de pao: ";
        cin >> qtd1[0];
        break;
      case 1:
        cout << "\nQuantidade de mussarela: ";
        cin >> qtd1[1];
        break;
      case 2:
        cout << "\nQuantidade de presunto: ";
        cin >> qtd1[2];
        break;
      case 3:
        cout << "\nQuantidade de leite: ";
        cin >> qtd1[3];
        break;
      case 4:
        cout << "\nQuantidade de manteiga: ";
        cin >> qtd1[4];
        break;
      default:
        cout << "\nCodigo invalido, tente novamente!";
        break;
      }
    }
    cout << "\nDeseja finalizar a compra?[S/N]: ";
    cin >> cancelar;

    while (cancelar == 'n' || cancelar == 'N'){
      do{
        cout << "\nCodigo do produto: ";
        cin >> codigo;
        switch (codigo){
        case 0:
          cout << "\nQuantidade de pao: ";
          cin >> qtd2[0];
          break;
        case 1:
          cout << "\nQuantidade de mussarela: ";
          cin >> qtd2[1];
          break;
        case 2:
          cout << "\nQuantidade de presunto: ";
          cin >> qtd2[2];
          break;
        case 3:
          cout << "\nQuantidade de leite: ";
          cin >> qtd2[3];
          break;
        case 4:
          cout << "\nQuantidade de manteiga: ";
          cin >> qtd2[4];
          break;
        default:
         cout << "\nCodigo invalido, tente novamente!";
          break;
        }
      } while (codigo > 4);
      cout << "\nDeseja finalizar a compra?[S/N]: ";
      cin >> cancelar;
    }
    system("cls");
    for (i = 0; i < 5; i++){
      total = total + ((prod[i] * qtd1[i]) + (prod[i] * qtd2[i]));
    }
    system("cls");
    cout << "\nTotal da compra: " << total << " REAIS";
    cout << "\nDinheiro recebido: ";
    cin >> dinheiro;

    troco = dinheiro - total;

    while (troco < 0){
      cout << "\nDinheiro insuficiente. Faltam R$" << troco * (-1) << " REAIS";
      total = troco * (-1);
      cout << endl;
      cout << "\nQuanto sera o pagamento: ";
      cin >> dinheiro;

      troco = dinheiro - total;
    }

    cout << "Troco R$ " << troco;
    cout << endl;
    cout << "\nDeseja emitir a sua nota fiscal?[S/N]: ";
    cin >> nota_fiscal;
    system("cls");
    if (nota_fiscal == 's' || nota_fiscal == 'S'){
      cout << "\n            PRECO UNI              QUANTIDADE                 PRECO";
      cout << endl;
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
  system("cls");
  } while (opcao == 1);
  return 0;
}
