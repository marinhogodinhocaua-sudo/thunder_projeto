#ifndef MECANICAS_HPP
#define MECANICAS_HPP

#include "personagem.hpp"

// Pausa o jogo até o jogador pressionar ENTER
void pausar();

// Função que gerencia a luta até alguém morrer
void batalha(Personagem &heroi, Personagem &inimigo);

// Função que representa o evento de encontrar um baú
void eventoBau(Personagem &heroi);

#endif