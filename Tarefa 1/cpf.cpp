#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>  // para isdigit

using namespace std;

// Função de validação do CPF
bool validarCPF(const vector<int>& cpf) {
    if (cpf.size() != 11) return false;

    // Verificar se todos os números são iguais
    bool todosIguais = true;
    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            todosIguais = false;
            break;
        }
    }
    if (todosIguais) return false;

    int soma = 0;

    // Primeiro dígito verificador
    for (int i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);
    }

    int resto = soma % 11;
    int dig1 = (resto < 2) ? 0 : 11 - resto;

    if (dig1 != cpf[9]) return false;

    // Segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * (11 - i);
    }

    resto = soma % 11;
    int dig2 = (resto < 2) ? 0 : 11 - resto;

    if (dig2 != cpf[10]) return false;

    return true;
}

// Função para gerar CPF válido
vector<int> gerarCPF() {
    vector<int> cpf(11);

    for (int i = 0; i < 9; i++) {
        cpf[i] = rand() % 10;
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);
    }

    int resto = soma % 11;
    cpf[9] = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += cpf[i] * (11 - i);
    }

    resto = soma % 11;
    cpf[10] = (resto < 2) ? 0 : 11 - resto;

    return cpf;
}

// Função para mostrar o CPF no formato padrão
void mostrarCPF(const vector<int>& cpf) {
    for (int i = 0; i < 11; i++) {
        cout << cpf[i];
        if (i == 2 || i == 5) cout << ".";
        if (i == 8) cout << "-";
    }
    cout << endl;
}

// Função para ler CPF no formato com pontos e traço
vector<int> lerCPFFormatado() {
    string entrada;
    vector<int> cpf;

    cin >> entrada;

    for (char c : entrada) {
        if (isdigit(c)) {
            cpf.push_back(c - '0');
        }
    }

    return cpf;
}

int main() {
    srand(time(nullptr));
    int opcao;

    cout << "=== Sistema de CPF ===" << endl;
    cout << "1 - Gerar CPF" << endl;
    cout << "2 - Validar CPF" << endl;
    cout << "Escolha: ";
    cin >> opcao;

    if (opcao == 1) {
        vector<int> cpf = gerarCPF();
        cout << "CPF Gerado: ";
        mostrarCPF(cpf);
    }
    else if (opcao == 2) {
        cout << "Digite o CPF (formato 123.456.789-09): ";
        vector<int> cpf = lerCPFFormatado();

        if (validarCPF(cpf))
            cout << "CPF valido!" << endl;
        else
            cout << "CPF invalido!" << endl;
    }
    else {
        cout << "Opcao invalida" << endl;
    }

    return 0;
}