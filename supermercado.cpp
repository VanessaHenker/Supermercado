#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include "supermercado.cpp"

using namespace std;
int tamanho_produtos = 5;
int main()
{
  float prod[5], qtd[5], dinheiro, total, troco, guarda_qtd1, guarda_qtd2, dinheiro2, total2;
  int qtd2[5], codigo, i, opcao, n;
  string tipo_funcao;
  char cancelar, nota_fiscal;
  do{
    codigo = 5;
    dinheiro = 0;
    troco = 0;
    i = 0;
    guarda = 0;
    guarda_qtd2 = 0;
    total = 0;
    dinheiro2 = 0;
    total2 = 0;

    prod[0] = 1;         qtd[0] = 0;         qtd2[0] = 0;
    prod[1] = 2;         qtd[1] = 0;         qtd2[1] = 0;
    prod[2] = 2;         qtd[2] = 0;         qtd2[2] = 0;
    prod[3] = 5.50;      qtd[3] = 0;         qtd2[3] = 0;
    prod[4] = 6.50;      qtd[4] = 0;         qtd2[4] = 0;
    
    cout << "---------------------------------------";
    cout << "\nBem vindo ao nosso estabelecimento!";
    cout << "\n---------------------------------------";

    while (codigo > 4){ // Vai repetir enquanto codigo for maior que 4
      cout << endl;
      cout << "\nCodigo do produto: ";
      tipo_funcao = 'codigo';
      //cin >> codigo;
      codigo = pede_codigo(tipo_funcao, tamanho_produtos);
      
      do{
        switch (codigo){
        case 0:
          cout << endl;
          cout << "\nQuantidade de pao: ";
          tipo_funcao = 'quantidade';
          guarda = pede_codigo(tipo_funcao);
          qtd[0] = qtd[0] + guarda; // Se guarda_qtd1 for maior que 0 sera valido
          //cin >> guarda_qtd1;
          /*if (guarda_qtd1 < 0){ // Se de guarda_qtd1 for menor 0 sera invalido
            cout << "VALOR INVALIDO!";
          }
          else{*/
          //}
        break;
        case 1:
          cout << endl;
          cout << "\nQuantidade de mussarela: ";
          tipo_funcao = 'quantidade';
          guarda = pede_codigo(tipo_funcao);
          qtd[1] = qtd[1] + guarda;
          //cin >> guarda_qtd1;
          /*if (guarda_qtd1 < 0){
            cout << "\nVALOR INVALIDO!";
          }
          else{*/
          //}
          break;
        case 2:
          cout << endl;
          cout << "\nQuantidade de presunto: ";
          tipo_funcao = 'quantidade';
          guarda = pede_codigo(tipo_funcao);
          qtd[2] = qtd[2] + guarda;
          /*cin >> guarda_qtd;
          if (guarda_qtd1 < 0){
            cout << "\nVALOR INVALIDO!";
          }
          else
          {*/
          //}
          break;
        case 3:
          cout << endl;
          cout << "\nQuantidade de leite: ";
          cin >> guarda_qtd1;
          if (guarda_qtd1 < 0){
            cout << "\nVALOR INVALIDO!";
          }
          else{
            qtd1[3] = qtd1[3] + guarda_qtd1;
          }
          break;
        case 4:
          cout << endl;
          cout << "\nQuantidade de manteiga: ";
          cin >> guarda_qtd1;
          if (guarda_qtd1 < 0){
            cout << "\nVALOR INVALIDO!";
          }
          else{
            qtd1[4] = qtd1[4] + guarda_qtd1;
          }
          break;
        default:
          cout << "\nCodigo invalido, tente novamente!";
          break;
        }
      } while (guarda_qtd1 < 0); //  Vai repetir enquanto guarda_qtd for igual 0
    }
    cout << "\nDeseja finalizar a compra?[S/N]: ";
    cin >> cancelar;

    while (cancelar == 'n' || cancelar == 'N'){ // Enquanto cancelar nao for igual n ou N vai repetir
      do{
        cout << endl;
        cout << "\nCodigo do produto: ";
        cin >> codigo;
        do{
          switch (codigo){
          case 0:
            cout << endl;
            cout << "\nQuantidade de pao: ";
            cin >> guarda_qtd2;
            if (guarda_qtd2 < 0){ // Se de guarda_qtd1 for menor 0 sera invalido
              cout << "\nVALOR INVALIDO!";
            }
            else{
              qtd2[0] = qtd2[0] + guarda_qtd1;  // Se guarda_qtd1 for maior que 0 sera valido
            }
            break;
          case 1:
            cout << endl;
            cout << "\nQuantidade de mussarela: ";
            cin >> guarda_qtd2;
            if (guarda_qtd2 < 0){
              cout << "\nVALOR INVALIDO!";
            }
            else{
              qtd2[1] = qtd2[1] + guarda_qtd2;
            }
            break;
          case 2:
            cout << endl;
            cout << "\nQuantidade de presunto: ";
            cin >> guarda_qtd2;
            if (guarda_qtd2 < 0){
              cout << "\nVALOR INVALIDO!";
            }
            else{
              qtd2[2] = qtd2[2] + guarda_qtd2;
            }
            break;
          case 3:
            cout << endl;
            cout << "\nQuantidade de leite: ";
            cin >> guarda_qtd2;
            if (guarda_qtd2 < 0){
              cout << "\nVALOR INVALIDO!";
            }
            else{
              qtd2[3] = qtd2[3] + guarda_qtd2;
            }
            break;
          case 4:
            cout << endl;
            cout << "\nQuantidade de manteiga: ";
            cin >> guarda_qtd2;
            if (guarda_qtd2 < 0){
              cout << "\nVALOR INVALIDO!";
            }
            else{
              qtd2[4] = qtd2[4] + guarda_qtd2;
            }
            break;
          default:
            cout << "\nCodigo invalido, tente novamente!";
            break;
          }
        } while (guarda_qtd2 < 0); // Vai repetir enquanto guarda_qtd for igual 0
      } while (codigo > 4);         // // Vai repetir enquanto codigo for maior que 4

      cout << "\nDeseja finalizar a compra?[S/N]: ";
      cin >> cancelar;
    }
    system("cls");
    for (i = 0; i < 5; i++){
      total = total + ((prod[i] * qtd1[i]) + (prod[i] * qtd2[i])); // Total recebe a soma das variaveis
    }

    cout << "\nTotal da compra: " << total << " REAIS";
    cout << "\nDinheiro recebido: ";
    cin >> dinheiro;

    troco = dinheiro - total;

    total2 = total + total2;
    dinheiro2 = dinheiro + dinheiro2;

    while (troco < 0){
      cout << "\nDinheiro insuficiente. Faltam R$" << troco * (-1) << " REAIS";
      total2 = troco * (-1); // total2 recebe total para fazer a soma dentro do while
      cout << endl;
      cout << "\nQuanto sera o pagamento: ";
      cin >> dinheiro2;
      troco = dinheiro2 - total2;
      dinheiro = dinheiro + dinheiro2; // dinheiro recebe dinheiro2 para somar os valores que o usario enviou até se igual ou maior que o total
    }
    cout << "Troco R$ " << troco;
    cout << endl;
    cout << "\nDeseja emitir a sua nota fiscal?[S/N]: ";
    cin >> nota_fiscal;
    system("cls");
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
    system("cls");
  } while (opcao == 1); // Se opcao for igual a 1, sera feita uma nova compra
  return 0;
}
