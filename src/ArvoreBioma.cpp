#include <iostream>
#include <string>
#include "PokemonEntity.hpp"
#include "ArvoreBioma.hpp"
#include "DEFINITIONS.hpp"

using namespace std;

// Métodos da classe Bioma
string Bioma::get_nome() const{
    return nome;
}

Bioma::Bioma(string n){
    nome = n;
    qtd_poke = 0;
}

void Bioma::insere_pokemon(int pos, PokemonEntity p, bool *ok) {
    if (qtd_poke >= MAX_POKEMONS_BIOMA || pos < 0 || pos > qtd_poke) {
        *ok = false;
        return;
    }

    for (int i = qtd_poke; i > pos; i--) {
        lista_pokemons[i] = lista_pokemons[i - 1];
    }

    lista_pokemons[pos] = p;
    qtd_poke++;
    *ok = true;
}

void Bioma::get_pokemon(int pos, PokemonEntity *p, bool *ok){
    if (pos < 0 || pos >= qtd_poke) {
        *ok = false;
        return;
    }

    *p = lista_pokemons[pos];
    *ok = true;
}

void cria_arvore(ArvoreBioma &ab){
    ab.raiz = nullptr;
    ab.atual = ab.raiz;
}

// Operação de inserir bioma na árvore
void insere_bioma(ArvoreBioma &ab, Bioma b, bool *ok){
    if(vazia(ab)){
        ab.raiz = new NodeBioma(b, nullptr);
        ab.atual = ab.raiz;
        *ok = true;
        return;
    }

    if(ab.atual == nullptr){
        *ok = false;
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (ab.atual->filhos[i] == nullptr) {
            NodeBiomaPtr novo = new NodeBioma(b, ab.atual);
            ab.atual->filhos[i] = novo;
            *ok = true;
            return; 
        }
    }

    // Se percorreu os 3 filhos e nenhum estava nulo, o nó atual está cheio
    *ok = false;
}

// Operação de retirar bioma da árvore
// Provavelmente não será usada no projeto
void retira_bioma(ArvoreBioma &ab, Bioma *b, bool *ok){
    if (vazia(ab) || ab.atual == nullptr) {
        *ok = false;
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (ab.atual->filhos[i] != nullptr) {
            *ok = false; 
            return;
        }
    }

    NodeBiomaPtr no_remover = ab.atual;
    *b = no_remover->biome;

    if (no_remover == ab.raiz) {
        ab.raiz = nullptr;
        ab.atual = nullptr;
    } else {
        NodeBiomaPtr pai = no_remover->pai;

        for (int i = 0; i < 3; i++) {
            if (pai->filhos[i] == no_remover) {
                pai->filhos[i] = nullptr;
                break;
            }
        }
        ab.atual = pai; 
    }

    delete no_remover;
    *ok = true;
}

// Função auxiliar para destruir node
void destroi_node(NodeBiomaPtr b){
    if (b == nullptr) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        destroi_node(b->filhos[i]);
    }

    delete b;
}

// Operação para destruir arvore completa
void destroi(ArvoreBioma &ab){
    destroi_node(ab.raiz);
    ab.raiz = nullptr;
    ab.atual = nullptr;
}

// Operação de verificação de arvore vazia
bool vazia(ArvoreBioma &ab){
    return ab.raiz == nullptr;
}

// Operação de calculo da altura da arvore
int altura(ArvoreBioma &ab){
    return altura_node(ab.raiz);
}

// Função auxiliar para calculo da altura da arvore
int altura_node(NodeBiomaPtr p){
    if (p == nullptr) {
        return 0;
    }

    int alt_maior = 0;

    for (int i = 0; i < 3; i++) {
        int h = altura_node(p->filhos[i]);
        if (h > alt_maior) {
            alt_maior = h;
        }
    }

    return 1 + alt_maior;
}