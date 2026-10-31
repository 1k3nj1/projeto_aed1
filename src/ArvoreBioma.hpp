#pragma once

#include <iostream>
#include <string>
#include "PokemonEntity.hpp"
#include "DEFINTIONS.hpp"

using std::string;

class Bioma{
    private:
        string nome;
        PokemonEntity lista_pokemons[MAX_POKEMONS_BIOMA];
        int qtd_poke;
        // string imagem; // caso for usar, descomentar
    
    public:
        Bioma(string n);
        string get_nome() const;

        void insere_pokemon(int pos, PokemonEntity p, bool *ok);
};

struct NodeBioma{

    Bioma biome;
    NodeBioma* pai;
    NodeBioma* esq;
    NodeBioma* dir;

    NodeBioma(Bioma b, NodeBioma* p = nullptr){
        biome = b;
        pai = p;
        dir = nullptr;
        esq = nullptr;
    }
};

typedef struct NodeBioma *NodeBiomaPtr;

struct ArvoreBioma{
    NodeBiomaPtr raiz;
    NodeBiomaPtr atual;
};

void insere_bioma(ArvoreBioma &ab, Bioma b, bool *ok);
void retira_bioma(ArvoreBioma &ab, Bioma *b, bool *ok);
void destroi_node(NodeBiomaPtr b);
void destroi(ArvoreBioma &ab);
bool vazia(ArvoreBioma &ab);
int altura_node(NodeBiomaPtr p);
int altura(ArvoreBioma &ab);