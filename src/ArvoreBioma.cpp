#include <iostream>
#include <string>
#include "PokemonEntity.hpp"
#include "ArvoreBioma.hpp"
#include "DEFINTIONS.hpp"

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

    if(ab.atual->esq != nullptr && ab.atual->dir != nullptr){
        *ok = false;
    } else {
        NodeBiomaPtr novo = new NodeBioma(b, ab.atual);

        if(ab.atual->esq == nullptr){
            ab.atual->esq = novo;
        } else {
            ab.atual->dir = novo;
        }

        *ok = true;
    }
}

// Operação de retirar bioma da árvore
// Provavelmente não será usada no projeto
void retira_bioma(ArvoreBioma &ab, Bioma *b, bool *ok){
    if (vazia(ab) || ab.atual == nullptr) {
        *ok = false;
        return;
    }

    if (ab.atual->esq != nullptr || ab.atual->dir != nullptr) {
        *ok = false; 
        return;
    }

    NodeBiomaPtr no_remover = ab.atual;
    *b = no_remover->biome;

    if (no_remover == ab.raiz) {
        ab.raiz = nullptr;
        ab.atual = nullptr;
    } else {
        NodeBiomaPtr pai = no_remover->pai;
        if (pai->esq == no_remover) {
            pai->esq = nullptr;
        } else if (pai->dir == no_remover) {
            pai->dir = nullptr;
        }
        ab.atual = pai; 
    }

    delete no_remover;
    *ok = true;
}

// Função auxiliar para destruir node
void destroi_node(NodeBiomaPtr b){
    if(b == nullptr){
        return;
    }

    destroi_node(b->esq);
    destroi_node(b->dir);

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
    if(p == nullptr){
        return 0;
    } else {
        int alt_esq = altura_node(p->esq);
        int alt_dir = altura_node(p->dir);

        int alt_maior = alt_esq;

        if(alt_dir > alt_esq){
            alt_maior = alt_dir;
        }
        return 1 + alt_maior;
    }
}