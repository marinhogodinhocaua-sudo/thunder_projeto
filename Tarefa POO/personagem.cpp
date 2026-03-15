#include "personagem.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

// Construtor Classe Pai
Personagem::Personagem(string _nome, string _classe, int _hp, int _forca, int _def, int _crit){
    nome = _nome;
    classeNome = _classe;
    hp = _hp;
    hpMax = _hp;
    forca = _forca;
    defesa = _def;
    chanceCritico = _crit;

    nivel = 1;
    xp = 0;
    xpProximoNivel = 100;

    nomeItem = "Item Basico";
    nivelItem = 1;
}

// Destrutor
Personagem::~Personagem() {
    cout << nome << " morreu." << endl;
}

// Verifica se está vivo
bool Personagem::estaVivo() {
    return hp > 0;
}

// Retorna nome
string Personagem::getNome() {
    return nome;
}

// Receber dano
void Personagem::receberDano(int dano) {

    int danoFinal = dano - defesa;

    if(danoFinal < 0)
        danoFinal = 0;

    hp -= danoFinal;

    if(hp < 0)
        hp = 0;

    cout << nome << " recebeu " << danoFinal << " de dano." << endl;
}

// Cura total
void Personagem::curarVida() {
    hp = hpMax;
    cout << nome << " recuperou toda a vida!" << endl;
}

// Ganhar XP
void Personagem::ganharXp(int quantidade) {

    xp += quantidade;

    cout << nome << " ganhou " << quantidade << " XP." << endl;

    if(xp >= xpProximoNivel){
        subirNivel();
    }
}

// Subir nível
void Personagem::subirNivel(){

    nivel++;
    xp = 0;

    xpProximoNivel += 50;

    hpMax += 10;
    forca += 2;
    defesa += 1;

    hp = hpMax;

    cout << nome << " subiu para o nivel " << nivel << "!" << endl;
}

// Ataque
int Personagem::realizarAtaque(){

    int dano = forca + nivelItem;

    int sorte = rand() % 100;

    if(sorte < chanceCritico){
        cout << "ATAQUE CRITICO!" << endl;
        dano *= 2;
    }

    return dano;
}

// Mostrar status
void Personagem::mostrarStatus(){

    cout << "\n===== STATUS =====" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Classe: " << classeNome << endl;
    cout << "HP: " << hp << "/" << hpMax << endl;
    cout << "Forca: " << forca << endl;
    cout << "Defesa: " << defesa << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "XP: " << xp << "/" << xpProximoNivel << endl;
    cout << "Item: " << nomeItem << " (Nivel " << nivelItem << ")" << endl;
}

// Aprimorar item padrão
void Personagem::aprimorarItem(){

    nivelItem++;

    cout << nomeItem << " foi aprimorado para nivel "
         << nivelItem << endl;
}

//
// CLASSES FILHAS
//

// MAGO
Mago::Mago(string nome)
: Personagem(nome, "Mago", 80, 15, 3, 30){
    nomeItem = "Cajado";
}

void Mago::aprimorarItem(){

    nivelItem++;
    forca += 3;

    cout << "O cajado do mago foi aprimorado!" << endl;
}


// CAVALEIRO
Cavaleiro::Cavaleiro(string nome)
: Personagem(nome, "Cavaleiro", 120, 12, 8, 10){
    nomeItem = "Espada";
}

void Cavaleiro::aprimorarItem(){

    nivelItem++;
    defesa += 2;

    cout << "A espada do cavaleiro foi reforcada!" << endl;
}


// LADINO
Ladino::Ladino(string nome)
: Personagem(nome, "Ladino", 100, 22, 5, 40){
    nomeItem = "Adaga";
}

void Ladino::aprimorarItem(){

    nivelItem++;
    chanceCritico += 5;

    cout << "A adaga do ladino ficou mais afiada!" << endl;
}


// MONSTRO
Monstro::Monstro(string nome, int hp, int forca)
: Personagem(nome, "Monstro", hp, forca, 2, 5){}