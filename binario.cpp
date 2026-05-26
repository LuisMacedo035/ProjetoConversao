#include <iostream>
#include <string>
#include "binario.h"
using namespace std;

string decimalParaBinario(int numero){
	string binario = "";

	while (numero > 0){
		int resto = numero % 2;
		binario = char(resto + '0') + binario;
		numero = numero/2;
	}
	return binario;
}

string decimalParaOcta(int numero){
	string octal = "";

	while (numero>0){
		int resto = numero % 8;
		octal = char(resto + '0') + octal;
		numero = numero/8;
	}
	return octal;
}

string decimalParaHexa(int numero){
	string hexa = "";

	while (numero > 0){
		int resto = numero % 16;
		if (resto < 10){
			hexa = char(resto + '0') + hexa;
		} else {
			hexa = char(resto - 10 + 'A') + hexa;
		}
		numero = numero/16;
	}
	return hexa;
}

int converterParaDecimal (string numero, int base){
	int decimal = 0;
	for (int i = 0; i<numero.length(); i++){
		char digito = numero[i];
		int valor;

		if (digito >= '0' && digito <= '9'){
			valor = digito - '0';
		} else {
			valor = digito - 'A' + 10;
		}
		decimal = decimal * base + valor;
	}

	return decimal;
}

string binarioParaOctal(string binario){
	while (binario.length() % 3 !=0){
		binario = "0" + binario;
	}
	string octal = "";
	for (int i = 0; i<binario.length(); i+=3){
		string grupo = "";
		grupo += binario[i];
		grupo += binario[i+1];
		grupo += binario[i+2];

		if (grupo == "000") octal += "0";
		if (grupo == "001") octal += "1";
		if (grupo == "010") octal += "2";
		if (grupo == "011") octal += "3";
		if (grupo == "100") octal += "4";
		if (grupo == "101") octal += "5";
		if (grupo == "110") octal += "6";
		if (grupo == "111") octal += "7";

	}
	return octal;
}

string binarioParaHexa(string binario){
	while (binario.length() % 4 != 0){
		binario = "0" + binario;
	}
	string hexa = "";
	for (int i = 0; i<binario.length(); i+= 4){
		string grupo = "";

		grupo += binario[i];
		grupo += binario[i+1];
		grupo += binario[i+2];
		grupo += binario[i+3];

		if (grupo == "0000") hexa += "0";
		if (grupo == "0001") hexa += "1";
		if (grupo == "0010") hexa += "2";
		if (grupo == "0011") hexa += "3";
		if (grupo == "0100") hexa += "4";
		if (grupo == "0101") hexa += "5";
		if (grupo == "0110") hexa += "6";
		if (grupo == "0111") hexa += "7";
		if (grupo == "1000") hexa += "8";
		if (grupo == "1001") hexa += "9";
		if (grupo == "1010") hexa += "A";
		if (grupo == "1011") hexa += "B";
		if (grupo == "1100") hexa += "C";
		if (grupo == "1101") hexa += "D";
		if (grupo == "1110") hexa += "E";
		if (grupo == "1111") hexa += "F";
	}

	return hexa;
}

string octalParaHexa(string octal){
	string binario = "";
	for (int i = 0; i<octal.length(); i++){
		if (octal[i] == '0') binario += "000";
		if (octal[i] == '1') binario += "001";
		if (octal[i] == '2') binario += "010";
		if (octal[i] == '3') binario += "011";
		if (octal[i] == '4') binario += "100";
		if (octal[i] == '5') binario += "101";
		if (octal[i] == '6') binario += "110";
		if (octal[i] == '7') binario += "111";
	}

	string hexa = "";
	for (int i = 0; i<binario.length(); i+= 4){
		string grupo = "";

		grupo += binario[i];
		grupo += binario[i+1];
		grupo += binario[i+2];
		grupo += binario[i+3];

		if (grupo == "0000") hexa += "0";
		if (grupo == "0001") hexa += "1";
		if (grupo == "0010") hexa += "2";
		if (grupo == "0011") hexa += "3";
		if (grupo == "0100") hexa += "4";
		if (grupo == "0101") hexa += "5";
		if (grupo == "0110") hexa += "6";
		if (grupo == "0111") hexa += "7";
		if (grupo == "1000") hexa += "8";
		if (grupo == "1001") hexa += "9";
		if (grupo == "1010") hexa += "A";
		if (grupo == "1011") hexa += "B";
		if (grupo == "1100") hexa += "C";
		if (grupo == "1101") hexa += "D";
		if (grupo == "1110") hexa += "E";
		if (grupo == "1111") hexa += "F";
	}
	return hexa;
}

bool validacao(string numero, int base){
	for (int i = 0; i<numero.length(); i++){
		char digito = numero[i];
		int valor;

		if (digito >= '0' and digito <= '9'){
			valor = digito - '0';
		} else if (digito >= 'A' and digito <= 'F'){
			valor = digito - 'A' + 10;
		} else {
			return false;
		}
		
		if (valor >= base){
			return false;
		}
	}
	return true;
}

