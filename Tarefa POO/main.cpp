#include <iostream>
#include <cstdlib>
#include <ctime>
#include "personagem.hpp"
#include "mecanica.hpp"

using namespace std;

int main() {

    srand(time(nullptr));

    string nome;
    int escolha;

    cout << "Digite o nome do heroi: ";
    cin >> nome;

    cout << "\nEscolha sua classe:\n";
    cout << "1 - Mago\n";
    cout << "2 - Cavaleiro\n";
    cout << "3 - Ladino\n";
    cout << "Opcao: ";
    cin >> escolha;

    Personagem* heroi;

    if(escolha == 1)
        heroi = new Mago(nome);
    else if(escolha == 2)
        heroi = new Cavaleiro(nome);
    else
        heroi = new Ladino(nome);

    cout << "\nSua aventura na masmorra comeca...\n";

    // 10 rodadas da dungeon
    for(int rodada = 1; rodada <= 10; rodada++){

        if(!heroi->estaVivo()){
            cout << "\nVoce morreu na masmorra...\n";
            delete heroi;
            return 0;
        }

        cout << "\n===== RODADA " << rodada << " =====\n";

        int evento = rand() % 3;

        if(evento == 0){
            cout << "O corredor esta vazio...\n";
        }

        else if(evento == 1){
            eventoBau(*heroi);
        }

        else{

            Monstro inimigo("Goblin", 60 + rodada*5, 10 + rodada);

            batalha(*heroi, inimigo);
        }

        heroi->mostrarStatus();

        pausar();
    }

    // Boss final
    cout << "\nVoce chegou na sala final da masmorra...\n";
    cout << "O BOSS apareceu!\n";

    Monstro boss("Dragao Ancestral", 200, 25);

    batalha(*heroi, boss);

    if(heroi->estaVivo())
        cout << "\nVOCE VENCEU A MASMORRA!\n";
    else
        cout << "\nO boss foi forte demais...\n";

    delete heroi;

    return 0;
}