#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <iostream>

using namespace std;

// Classe Pai
class Personagem {
protected:
    string nome;
    string classeNome; // Para mostrar na tela "Mago", "Guerreiro"
    int hp;
    int hpMax;
    int forca;
    int defesa;
    int chanceCritico; // Porcentagem de 0 a 100
    int nivel;
    int xp;
    int xpProximoNivel;
    string nomeItem;
    int nivelItem;

public:
    // Construtor principal
    Personagem(string _nome, string _classe, int _hp, int _forca, int _def, int _crit);
    
    // Destrutor
    virtual ~Personagem();

    // Métodos de Ação (A lógica do jogo)
    void receberDano(int dano);
    void curarVida();
    void ganharXp(int quantidade);
    int realizarAtaque(); // Retorna o valor do dano causado
    void mostrarStatus();
    
    // Getters (Para verificar informações)
    bool estaVivo();
    string getNome();

    virtual void aprimorarItem();
    
private:
    void subirNivel();
};

// Classes Filhas

class Mago : public Personagem {
public:
    Mago(string n);
    void aprimorarItem() override; 
};

class Cavaleiro : public Personagem {
public:
    Cavaleiro(string n);
    void aprimorarItem() override;
};

class Ladino : public Personagem {
public:
    Ladino(string n);
    void aprimorarItem() override;
};

// Inimigo genérico
class Monstro : public Personagem {
public:
    Monstro(string nome, int hp, int forca);
};

#endif