#include <iostream>
#include <string>
#include <fstream>
#include "binario.h"
#include "durelli.h"
using namespace std;

char valorParaCaractere(int valor) {

    if (valor < 10) {
        return valor + '0';
    }

    return valor - 10 + 'A';
}

string parteInteira(int numero, int base) {

    if (numero == 0) {
        return "0";
    }

    string resultado = "";

    while (numero > 0) {

        int resto = numero % base;

        resultado = valorParaCaractere(resto) + resultado;

        numero = numero / base;
    }

    return resultado;
}

string parteFracionaria(double fracao, int base, bool &truncado) {

    string resultado = "";

    int contador = 0;

    while (fracao > 0 && contador < 16) {

        fracao = fracao * base;

        int inteiro = (int) fracao;

        resultado += valorParaCaractere(inteiro);

        fracao = fracao - inteiro;

        contador++;
    }

    if (fracao > 0) {
        truncado = true;
    }

    return resultado;
}

string decimalParaBinarioPasso(int numero) {

    string binario = "";

    cout << "\nPASSO A PASSO:\n" << endl;

    while (numero > 0) {

        int resto = numero % 2;

        cout << numero<< " / 2 = " << numero / 2<< "  resto = "<< resto << endl;

        binario = char(resto + '0') + binario;

        numero = numero / 2;
    }

    return binario;
}

void modoBatch() {

    ifstream entrada("entrada.csv");

    ofstream saida("saida.csv");

    string valor;

    int baseOrigem;
    int baseDestino;


    while (entrada >> valor >> baseOrigem >> baseDestino) {

    int decimal = converterParaDecimal(valor, baseOrigem);

    string resultado;


    if (baseDestino == 2) {
        resultado = decimalParaBinario(decimal);
    }

    if (baseDestino == 8) {
        resultado = decimalParaOcta(decimal);
    }

    if (baseDestino == 16) {
        resultado = decimalParaHexa(decimal);
    }

    if (baseDestino == 10) {
        resultado = to_string(decimal);
    }


    saida << valor << ";"
          << baseOrigem << ";"
          << resultado << ";"
          << baseDestino << endl;
}

    entrada.close();

    saida.close();

}

void modoQuiz() {

    int nivel;
    int pontos = 0;

    cout << "===== QUIZ DE CONVERSAO =====" << endl;

    cout << "\nNiveis:" << endl;
    cout << "1 - Numeros pequenos" << endl;
    cout << "2 - Numeros medios" << endl;
    cout << "3 - Numeros grandes" << endl;
    cout << "4 - Muito grandes" << endl;
    cout << "5 - Insano" << endl;

    cout << "\nEscolha o nivel: ";
    cin >> nivel;


    int limite;

    if (nivel == 1) limite = 15;
    if (nivel == 2) limite = 63;
    if (nivel == 3) limite = 255;
    if (nivel == 4) limite = 1023;
    if (nivel == 5) limite = 4095;


    for (int rodada = 1; rodada <= 5; rodada++) {

        int numero = rand() % limite + 1;

        int baseOrigem = rand() % 15 + 2;

        int baseDestino = rand() % 15 + 2;


        while (baseDestino == baseOrigem) {
            baseDestino = rand() % 15 + 2;
        }


        string valor;

        // transforma o número para a base de origem
        valor = deDecimal(numero, baseOrigem);


        cout << "\n--------------------------------" << endl;

        cout << "Rodada " << rodada << endl;

        cout << "\nConverta:" << endl;

        cout << valor
             << " (base "
             << baseOrigem
             << ") para base "
             << baseDestino << endl;


        string resposta;

        cout << "\nResposta: ";
        cin >> resposta;


        string correta = deDecimal(numero, baseDestino);


        if (resposta == correta) {

            cout << "Correto!" << endl;

            pontos++;
        }
        else {

            cout << "Errado!" << endl;

            cout << "Resposta correta: "
                 << correta << endl;
        }
    }


    cout << "\n====================" << endl;

    cout << "Pontuacao final: "<< pontos<< "/5" << endl;
}

void calculadoraMaximos() {

    int k;

    cout << "Digite a quantidade de bits: ";
    cin >> k;

    int maximo = 1;

    for (int i = 0; i < k; i++) {
        maximo = maximo * 2;
    }

    maximo = maximo - 1;


    cout << "\nMaior valor representavel com "
         << k
         << " bits:\n" << endl;


    cout << "Decimal: "
         << maximo << endl;

    cout << "Binario: "
         << decimalParaBinario(maximo) << endl;

    cout << "Octal: "
         << decimalParaOcta(maximo) << endl;

    cout << "Hexadecimal: "
         << decimalParaHexa(maximo) << endl;
}
