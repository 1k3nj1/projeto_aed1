#pragma once

#include <iostream>
#include <string>
#include "PokemonEntity.hpp"
#include "DEFINITIONS.hpp"

using std::string;

class Bioma{
    private:
        string nome;
        PokemonEntity lista_pokemons[MAX_POKEMONS_BIOMA];
        int qtd_poke;
    
    public:
        Bioma() : nome(""), qtd_poke(0) {} // Construtor padrão adicionado
        Bioma(string n);
        string get_nome() const;

        void insere_pokemon(int pos, PokemonEntity p, bool *ok);
        void get_pokemon(int pos, PokemonEntity *p, bool *ok);
        
};

struct NodeBioma{

    Bioma biome;
    NodeBioma* pai;
    NodeBioma *filhos[3];

    // Inicializa 'biome' diretamente com 'b' na lista de inicialização
    NodeBioma(Bioma b, NodeBioma* p = nullptr) : biome(b), pai(p) {
        for(int i = 0; i < 3; i++){
            filhos[i] = nullptr;
        }
    }
};

typedef struct NodeBioma *NodeBiomaPtr;

struct ArvoreBioma{
    NodeBiomaPtr raiz;
    NodeBiomaPtr atual;
};

void cria_arvore(ArvoreBioma &ab);
void insere_bioma(ArvoreBioma &ab, Bioma b, bool *ok);
void retira_bioma(ArvoreBioma &ab, Bioma *b, bool *ok);
void destroi_node(NodeBiomaPtr b);
void destroi(ArvoreBioma &ab);
bool vazia(ArvoreBioma &ab);
int altura_node(NodeBiomaPtr p);
int altura(ArvoreBioma &ab);