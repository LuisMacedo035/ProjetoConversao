#include <iostream>
#include "binario.h"

using namespace std;

int main() {

    int opcao;

    do {

        cout << " CONVERSOR DE BASES " << endl;

        cout << "\n1 - Converter numero" << endl;
        cout << "2 - Modo passo a passo" << endl;
        cout << "3 - Modo batch" << endl;
        cout << "4 - Modo quiz" << endl;
        cout << "5 - Calculadora de maximos" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nEscolha: ";
        cin >> opcao;



        if (opcao == 1) {

            string numero;

            int baseOrigem;
            int baseDestino;


            cout << "\nDigite o numero: ";
            cin >> numero;

            cout << "Base de origem: ";
            cin >> baseOrigem;

            cout << "Base de destino: ";
            cin >> baseDestino;


            if (!validacao(numero, baseOrigem)) {

                cout << "\nNumero invalido!" << endl;
            }

            else {

                int decimal =
                    converterParaDecimal(numero, baseOrigem);


                if (baseDestino == 2) {

                    cout << "\nResultado: "
                         << decimalParaBinario(decimal)
                         << endl;
                }

                if (baseDestino == 8) {

                    cout << "\nResultado: "
                         << decimalParaOcta(decimal)
                         << endl;
                }

                if (baseDestino == 10) {

                    cout << "\nResultado: "
                         << decimal
                         << endl;
                }

                if (baseDestino == 16) {

                    cout << "\nResultado: "
                         << decimalParaHexa(decimal)
                         << endl;
                }
            }
        }



        if (opcao == 2) {

            int numero;

            cout << "\nDigite um numero decimal: ";
            cin >> numero;

            string binario =
                decimalParaBinarioPasso(numero);

            cout << "\nBinario: "
                 << binario << endl;
        }

        if (opcao == 3) {

            modoBatch();
        }


        if (opcao == 4) {

            modoQuiz();
        }


        if (opcao == 5) {

            calculadoraMaximos();
        }

    } while (opcao != 0);


    return 0;
}