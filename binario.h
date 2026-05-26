#ifndef BINARIO_H
#define BINARIO_H

#include <string>
using namespace std;

string decimalParaBinario(int numero);
string decimalParaOcta(int numero);
string decimalParaHexa(int numero);

int converterParaDecimal(string numero, int base);

string binarioParaOctal(string binario);
string binarioParaHexa(string binario);

string octalParaHexa(string octal);

bool validacao(string numero, int base);