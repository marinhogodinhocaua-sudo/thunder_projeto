#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath> // para std::sqrt
using namespace std;

// Funções matemáticas obrigatórias

double soma(double a, double b) {
    return a + b;
}

double subtracao(double a, double b) {
    return a - b;
}

double produto(double a, double b) {
    return a * b;
}

double divisao(double a, double b) {
    if (b == 0) {
        cout << "Erro: divisao por zero!" << endl;
        return 0; // valor arbitrário em caso de erro
    }
    return a / b;
}

double potencia(double a, int b) {
    double resultado = 1;
    if (b >= 0) {
        for (int i = 0; i < b; i++)
            resultado *= a;
    } else { // expoente negativo
        for (int i = 0; i < -b; i++)
            resultado *= a;
        resultado = 1 / resultado;
    }
    return resultado;
}

int raizQuadrada(int a) {
    if (a < 0) {
        cout << "Erro: raiz quadrada de numero negativo!" << endl;
        return -1; // valor arbitrário em caso de erro
    }
    return static_cast<int>(sqrt(a));
}

// Função para mostrar o menu
void mostrarMenu() {
    cout << "=== Calculadora ===" << endl;
    cout << "1 - Soma" << endl;
    cout << "2 - Subtracao" << endl;
    cout << "3 - Produto" << endl;
    cout << "4 - Divisao" << endl;
    cout << "5 - Potencia" << endl;
    cout << "6 - Raiz quadrada" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    int opcao;
    double a, b;
    int expoente;

    do {
        mostrarMenu();
        cin >> opcao;

        switch(opcao) {
            case 1:
                cout << "Digite o primeiro numero: ";
                cin >> a;
                cout << "Digite o segundo numero:";
                cin >> b;
                cout << "Resultado: " << soma(a, b) << endl;
                break;
            case 2:
               cout << "Digite o primeiro numero: ";
                cin >> a;
                cout << "Digite o segundo numero:";
                cin >> b;
                cout << "Resultado: " << subtracao(a, b) << endl;
                break;
            case 3:
                cout << "Digite o primeiro numero: ";
                cin >> a;
                cout << "Digite o segundo numero:";
                cin >> b;
                cout << "Resultado: " << produto(a, b) << endl;
                break;
            case 4:
                cout << "Digite o primeiro numero: ";
                cin >> a;
                cout << "Digite o segundo numero:";
                cin >> b;
                cout << "Resultado: " << divisao(a, b) << endl;
                break;
            case 5:
                cout << "Digite a base: ";
                cin >> a;
                cout << "Digite o expoente:";
                cin >> expoente;
                cout << "Resultado: " << potencia(a, expoente) << endl;
                break;
            case 6:
                cout << "Digite um numero inteiro: ";
                cin >> a;
                cout << "Resultado: " << raizQuadrada(static_cast<int>(a)) << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }

        cout << endl;

    } while(opcao != 0);

    return 0;
}