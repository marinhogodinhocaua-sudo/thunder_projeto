#include "mecanica.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// Pausa o jogo até o jogador apertar Enter
void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.get();
    cin.ignore();
}

// Sistema de batalha
void batalha(Personagem &heroi, Personagem &inimigo) {

    cout << "\nUm " << inimigo.getNome() << " apareceu!\n";

    while(heroi.estaVivo() && inimigo.estaVivo()) {

        cout << "\nTurno do heroi!\n";
        int dano = heroi.realizarAtaque();
        inimigo.receberDano(dano);

        pausar();

        if(!inimigo.estaVivo()) {
            cout << inimigo.getNome() << " foi derrotado!\n";
            heroi.ganharXp(50);
            break;
        }

        cout << "\nTurno do inimigo!\n";
        dano = inimigo.realizarAtaque();
        heroi.receberDano(dano);
    }

    pausar();
}

// Evento de baú
void eventoBau(Personagem &heroi) {

    cout << "\nVoce encontrou um BAU misterioso!\n";

    int sorte = rand() % 3;

    if(sorte == 0) {
        cout << "Voce encontrou uma pocao de cura!\n";
        heroi.curarVida();
    }

    else if(sorte == 1) {
        cout << "Voce encontrou um aprimoramento para seu item!\n";
        heroi.aprimorarItem();
    }

    else {
        cout << "Voce encontrou um tomo de conhecimento!\n";
        heroi.ganharXp(30);
    }

    pausar();
}