#pragma once

#include <iostream>
#include <string>
#include "PokemonEntity.hpp"

struct NodePokemon{
    PokemonEntity poke;
    NodePokemon* next;
};

typedef struct NodePokemon *NodePtr;

class Fila {
    private:
        NodePtr inicio;
        NodePtr fim;
        int tamanho;
        int capacidade_maxima;
    
    public:
        Fila(int t);
        void enfileira(PokemonEntity p, bool *ok);
        void desenfileira(PokemonEntity *p, bool *ok);
        bool cheia();
        bool vazia();
        void esvazia_fila();

        int get_tamanho() const;

        void pegaPrimeiro(PokemonEntity &p) const;
};