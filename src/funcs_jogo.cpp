#include "funcs_jogo.hpp"
#include <cstdlib>

/*
    Função para calcular qual pokemon teve vantagem no confronto
    Retorna:
    1 - caso Pokemon do jogador tenha vantagem
    2 - caso Pokemon do computador tenha vantagem
    0 - caso de empate
*/
int calcula_vantagem(int tipoA, int tipoB) {
    if (tipoA == FOGO && tipoB == PLANTA) return 1;
    if (tipoA == PLANTA && tipoB == AGUA) return 1;
    if (tipoA == AGUA && tipoB == FOGO) return 1;
    if(tipoA == FOGO && tipoB == FOGO) return 2;
    if(tipoA == AGUA && tipoB == AGUA) return 2;
    if(tipoA == PLANTA && tipoB == PLANTA) return 2;
    return 0;
}

/*
    Construtor dos structs Botão
*/
Botao::Botao(sf::Vector2f pos, sf::Vector2f size, const std::string& label, const sf::Font& font):texto(font, label, 20) {
    box.setPosition(pos);
    box.setSize(size);
    box.setFillColor(sf::Color(70, 70, 70));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2.f);

    texto.setFillColor(sf::Color::White);
    // Centraliza o texto no botão
    texto.setPosition({pos.x + 15.f, pos.y + 10.f});
}

/*
    Função que verifica se o botão foi clicado
*/
bool Botao::clicado(const sf::RenderWindow& window) const {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);    
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    
    return box.getGlobalBounds().contains(worldPos);
}

// Procedimento para desenhar o botão
void Botao::desenhar(sf::RenderWindow& window) const {
    window.draw(box);
    window.draw(texto);
}

// Carregando a pokedex
void carregar_dex(GameData& game){
    game.Pokedex_planta[0] = PokemonEntity("Bulbasaur", TipoPokemon::PLANTA, "imagens/tipo_planta/bulbasaur.png");
    game.Pokedex_planta[1] = PokemonEntity("Chikorita", TipoPokemon::PLANTA, "imagens/tipo_planta/chikorita.png");
    game.Pokedex_planta[2] = PokemonEntity("Treecko", TipoPokemon::PLANTA, "imagens/tipo_planta/treecko.png");
    game.Pokedex_planta[3] = PokemonEntity("Turtwig", TipoPokemon::PLANTA, "imagens/tipo_planta/turtwig.png");
    game.Pokedex_planta[4] = PokemonEntity("Snivy", TipoPokemon::PLANTA, "imagens/tipo_planta/snivy.png");
    game.Pokedex_planta[5] = PokemonEntity("Chespin", TipoPokemon::PLANTA, "imagens/tipo_planta/chespin.png");
    game.Pokedex_planta[6] = PokemonEntity("Bellsprout", TipoPokemon::PLANTA, "imagens/tipo_planta/bellsprout.png");
    game.Pokedex_planta[7] = PokemonEntity("Hoppip", TipoPokemon::PLANTA, "imagens/tipo_planta/hoppip.png");
    game.Pokedex_planta[8] = PokemonEntity("Oddish", TipoPokemon::PLANTA, "imagens/tipo_planta/oddish.png");
    game.Pokedex_planta[9] = PokemonEntity("Celebi", TipoPokemon::PLANTA, "imagens/tipo_planta/celebi.png");
    game.Pokedex_planta[10] = PokemonEntity("Roselia", TipoPokemon::PLANTA, "imagens/tipo_planta/roselia.png");
    game.Pokedex_planta[11] = PokemonEntity("Rowlet", TipoPokemon::PLANTA, "imagens/tipo_planta/rowlet.png");
    game.Pokedex_planta[12] = PokemonEntity("Seedot", TipoPokemon::PLANTA, "imagens/tipo_planta/seedot.png");
    
    game.Pokedex_fogo[0] = PokemonEntity("Charmander", TipoPokemon::FOGO, "imagens/tipo_fogo/charmander.png");
    game.Pokedex_fogo[1] = PokemonEntity("Cyndaquil", TipoPokemon::FOGO, "imagens/tipo_fogo/cyndaquil.png");
    game.Pokedex_fogo[2] = PokemonEntity("Torchic", TipoPokemon::FOGO, "imagens/tipo_fogo/torchic.png");
    game.Pokedex_fogo[3] = PokemonEntity("Chimchar", TipoPokemon::FOGO, "imagens/tipo_fogo/chimchar.png");
    game.Pokedex_fogo[4] = PokemonEntity("Tepig", TipoPokemon::FOGO, "imagens/tipo_fogo/tepig.png");
    game.Pokedex_fogo[5] = PokemonEntity("Fennekin", TipoPokemon::FOGO, "imagens/tipo_fogo/fennekin.png");
    game.Pokedex_fogo[6] = PokemonEntity("Entei", TipoPokemon::FOGO, "imagens/tipo_fogo/entei.png");
    game.Pokedex_fogo[7] = PokemonEntity("Growlithe", TipoPokemon::FOGO, "imagens/tipo_fogo/growlithe.png");
    game.Pokedex_fogo[8] = PokemonEntity("Magmar", TipoPokemon::FOGO, "imagens/tipo_fogo/magmar.png");
    game.Pokedex_fogo[9] = PokemonEntity("Pansear", TipoPokemon::FOGO, "imagens/tipo_fogo/pansear.png");
    game.Pokedex_fogo[10] = PokemonEntity("Vulpix", TipoPokemon::FOGO, "imagens/tipo_fogo/vulpix.png");
    game.Pokedex_fogo[11] = PokemonEntity("Ponyta", TipoPokemon::FOGO, "imagens/tipo_fogo/ponyta.png");
    game.Pokedex_fogo[12] = PokemonEntity("Litwick", TipoPokemon::FOGO, "imagens/tipo_fogo/litwick.png");
    
    game.Pokedex_agua[0] = PokemonEntity("Squirtle", TipoPokemon::AGUA, "imagens/tipo_agua/squirtle.png");
    game.Pokedex_agua[1] = PokemonEntity("Totodile", TipoPokemon::AGUA, "imagens/tipo_agua/totodile.png");
    game.Pokedex_agua[2] = PokemonEntity("Mudkip", TipoPokemon::AGUA, "imagens/tipo_agua/mudkip.png");
    game.Pokedex_agua[3] = PokemonEntity("Piplup", TipoPokemon::AGUA, "imagens/tipo_agua/piplup.png");
    game.Pokedex_agua[4] = PokemonEntity("Oshawott", TipoPokemon::AGUA, "imagens/tipo_agua/oshawott.png");
    game.Pokedex_agua[5] = PokemonEntity("Froakie", TipoPokemon::AGUA, "imagens/tipo_agua/froakie.png");
    game.Pokedex_agua[6] = PokemonEntity("Horsea", TipoPokemon::AGUA, "imagens/tipo_agua/horsea.png");
    game.Pokedex_agua[7] = PokemonEntity("Magikarp", TipoPokemon::AGUA, "imagens/tipo_agua/magikarp.png");
    game.Pokedex_agua[8] = PokemonEntity("Poliwag", TipoPokemon::AGUA, "imagens/tipo_agua/poliwag.png");
    game.Pokedex_agua[9] = PokemonEntity("Seel", TipoPokemon::AGUA, "imagens/tipo_agua/seel.png");
    game.Pokedex_agua[10] = PokemonEntity("Suicune", TipoPokemon::AGUA, "imagens/tipo_agua/suicune.png");
    game.Pokedex_agua[11] = PokemonEntity("Tentacool", TipoPokemon::AGUA, "imagens/tipo_agua/tentacool.png");
    game.Pokedex_agua[12] = PokemonEntity("Wooper", TipoPokemon::AGUA, "imagens/tipo_agua/wooper.png");

    // Pokedex completa para o time do computador
    for (int i = 0; i < QTD_POKEMONS / 3; i++) {
        game.Pokedex[i] = game.Pokedex_planta[i];
        game.Pokedex[QTD_POKEMONS / 3 + i] = game.Pokedex_fogo[i];
        game.Pokedex[2 * (QTD_POKEMONS / 3) + i] = game.Pokedex_agua[i];
    }
}

void inicializa_arvore_biomas(GameData &game){
    game.bioma_planta[0] = Bioma("Amazonia");
    game.bioma_planta[1] = Bioma("Taiga");
    game.bioma_planta[2] = Bioma("Floresta Temperada");
    game.bioma_planta[3] = Bioma("Mata Atlantica");

    game.bioma_fogo[0] = Bioma("Magmania");
    game.bioma_fogo[1] = Bioma("Caldeira");
    game.bioma_fogo[2] = Bioma("Fornalha");
    game.bioma_fogo[3] = Bioma("Ignis");

    game.bioma_agua[0] = Bioma("Atlantico");
    game.bioma_agua[1] = Bioma("Coralia");
    game.bioma_agua[2] = Bioma("Mareia");
    game.bioma_agua[3] = Bioma("Abissal");

    PokemonEntity copia_planta[(QTD_POKEMONS/3) - 1];
    PokemonEntity copia_fogo[(QTD_POKEMONS/3) - 1];
    PokemonEntity copia_agua[(QTD_POKEMONS/3) - 1];

    for (int i = 0; i < QTD_POKEMONS/3 - 1; i++) {
        copia_planta[i] = game.Pokedex_planta[i+1];
        copia_fogo[i] = game.Pokedex_fogo[i+1];
        copia_agua[i] = game.Pokedex_agua[i+1];
    }

    for (int i = QTD_POKEMONS/3 - 2; i > 0; i--) {
        int j = rand() % (i + 1);
        PokemonEntity tmp_planta = copia_planta[i];
        PokemonEntity tmp_fogo = copia_fogo[i];
        PokemonEntity tmp_agua = copia_agua[i];

        copia_planta[i] = copia_planta[j];
        copia_planta[j] = tmp_planta;

        copia_fogo[i] = copia_fogo[j];
        copia_fogo[j] = tmp_fogo;

        copia_agua[i] = copia_agua[j];
        copia_agua[j] = tmp_agua;
    }

    int indice_proximo_copiar = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            bool ok_insere_poke_aux;

            game.bioma_planta[i].insere_pokemon(j, copia_planta[indice_proximo_copiar], &ok_insere_poke_aux);
            game.bioma_fogo[i].insere_pokemon(j, copia_fogo[indice_proximo_copiar], &ok_insere_poke_aux);
            game.bioma_agua[i].insere_pokemon(j, copia_agua[indice_proximo_copiar], &ok_insere_poke_aux);

            indice_proximo_copiar++;
        }
    }

    bool ok_bioma_aux, ok_insere_poke;

    cria_arvore(game.arvore_biomas);
    insere_bioma(game.arvore_biomas, Bioma("Inicial"), &ok_bioma_aux);

    game.arvore_biomas.raiz->biome.insere_pokemon(0, game.Pokedex_planta[0], &ok_insere_poke);
    game.arvore_biomas.raiz->biome.insere_pokemon(1, game.Pokedex_fogo[0], &ok_insere_poke);
    game.arvore_biomas.raiz->biome.insere_pokemon(2, game.Pokedex_agua[0], &ok_insere_poke);
}

// criando filas aleatórias
void randomiza_fila_pc(GameData &game){
    PokemonEntity copia[QTD_POKEMONS];

    
    for(int i = 0; i < QTD_POKEMONS; i++){
        copia[i] = game.Pokedex[i];
    }
    
    for (int i = QTD_POKEMONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        PokemonEntity tmp = copia[i];
        copia[i] = copia[j];
        copia[j] = tmp;
    }

    for(int i = 0; i < TAMANHO_TIMES; i++){
        bool aux;
        game.fila_PC.enfileira(copia[i], &aux);
    }
}

// Procedimento para exibir time do computador no início
void exibir_time_pc(GameData &game, sf::RenderWindow &window){
    Fila temp(TAMANHO_TIMES);
    
    float posicaoX = 100.f;
    float posicaoY = 250.f;

    int cont = 0;
    while(!game.fila_PC.vazia()){
        cont++;
        PokemonEntity aux;
        bool baux;

        game.fila_PC.desenfileira(&aux, &baux);

        sf::Text nome_pokemon(game.fonte, aux.get_nome());
        sf::Texture imagem_poke;
        imagem_poke.loadFromFile(aux.get_imagem());

        temp.enfileira(aux, &baux);

        sf::Sprite sprite_pokemon(imagem_poke);
        sprite_pokemon.setPosition({posicaoX, posicaoY});
        auto sz = imagem_poke.getSize();
        sprite_pokemon.setScale({static_cast<float>(200) / sz.x, static_cast<float>(200) / sz.y});
        
        adicionar_tipo(aux, nome_pokemon);

        // Centraliza o texto no botão
        nome_pokemon.setPosition({posicaoX, posicaoY + 200.f});
        
        posicaoX+=215.f;
    
        window.draw(sprite_pokemon);
        window.draw(nome_pokemon);
    }

    while(!temp.vazia()){
        PokemonEntity aux;
        bool baux;

        temp.desenfileira(&aux, &baux);
        game.fila_PC.enfileira(aux, &baux);
    }
    sf::Text texto_primeiro(game.fonte, "Primeiro");
    sf::Text texto_ultimo(game.fonte, "Ultimo");

    texto_primeiro.setPosition({120.f, 210.f});
    texto_ultimo.setPosition({980.f, 210.f});

    window.draw(texto_primeiro);
    window.draw(texto_ultimo);
}

void exibir_time_jogador(GameData &game, sf::RenderWindow &window){
    Fila temp(TAMANHO_TIMES);
    
    float posicaoX = 100.f;
    float posicaoY = 250.f;

    int cont = 0;
    while(!game.fila_jogador.vazia()){
        cont++;
        PokemonEntity aux;
        bool baux;

        game.fila_jogador.desenfileira(&aux, &baux);

        sf::Text nome_pokemon(game.fonte, aux.get_nome());
        sf::Texture imagem_poke;
        imagem_poke.loadFromFile(aux.get_imagem());

        temp.enfileira(aux, &baux);

        sf::Sprite sprite_pokemon(imagem_poke);
        sprite_pokemon.setPosition({posicaoX, posicaoY});
        auto sz = imagem_poke.getSize();
        sprite_pokemon.setScale({static_cast<float>(200) / sz.x, static_cast<float>(200) / sz.y});
        
        adicionar_tipo(aux, nome_pokemon);
        // Centraliza o texto no botão
        nome_pokemon.setPosition({posicaoX, posicaoY + 200.f});
        
        posicaoX+=215.f;
        
        window.draw(sprite_pokemon);
        window.draw(nome_pokemon);
    }
    
    while(!temp.vazia()){
        PokemonEntity aux;
        bool baux;
        
        temp.desenfileira(&aux, &baux);
        game.fila_jogador.enfileira(aux, &baux);
    }
    sf::Text texto_primeiro(game.fonte, "Primeiro");
    sf::Text texto_ultimo(game.fonte, "Ultimo");
    
    texto_primeiro.setPosition({120.f, 210.f});
    texto_ultimo.setPosition({980.f, 210.f});
    
    window.draw(texto_primeiro);
    window.draw(texto_ultimo);
}

// Randomizando a fila das escolhas possíveis do jogador no estado de CAPTURA
void randomiza_fila_escolha(GameData &game, Fila &f){
    
    PokemonEntity copia[MAX_POKEMONS_BIOMA];
    
    for(int i = 0; i < MAX_POKEMONS_BIOMA; i++){
        PokemonEntity aux_pok;
        bool aux_ok;
        game.arvore_biomas.atual->biome.get_pokemon(i, &aux_pok, &aux_ok);

        if(aux_ok){
            copia[i] = aux_pok;
        }
    }
    
    for (int i = MAX_POKEMONS_BIOMA - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        PokemonEntity tmp = copia[i];
        copia[i] = copia[j];
        copia[j] = tmp;
    }

    
    for(int i = 0; i < MAX_POKEMONS_BIOMA; i++){
        bool aux;
        f.enfileira(copia[i], &aux);
    }
    
}

// Define cor do texto dependendo do tipo do Pokemon
void adicionar_tipo(PokemonEntity p, sf::Text &tipo_texto){
    if(p.get_tipo() == TipoPokemon::FOGO){
        tipo_texto.setFillColor(sf::Color(255, 0, 0));
    }
    if(p.get_tipo() == TipoPokemon::PLANTA){
        tipo_texto.setFillColor(sf::Color(0, 255, 0));
    }
    if(p.get_tipo() == TipoPokemon::AGUA){
        tipo_texto.setFillColor(sf::Color(0, 0, 255));
    }
}

// Exibe texto com base no resultado do confronto
void calcular_resultado_batalha(GameData &game){
    int resultado = calcula_vantagem(game.poke_atual_jogador.get_tipo(), game.poke_atual_PC.get_tipo());
    if(resultado == 1){
        game.pontos_jogador++;
        game.resultado_batalha.setString("Voce Venceu Essa Rodada!");
        game.resultado_batalha.setFillColor(sf::Color(0, 255, 0));
        game.resultado_batalha.setPosition({280.f, 50.f});
    }
    else if(resultado == 2){
        game.resultado_batalha.setString("Empate!");
        game.resultado_batalha.setFillColor(sf::Color(255, 255, 255));
        game.resultado_batalha.setPosition({520.f, 50.f});
    }
    else if(resultado == 0){
        game.pontos_PC++;
        game.resultado_batalha.setString("Voce Perdeu Essa Rodada!");
        game.resultado_batalha.setFillColor(sf::Color(255, 0, 0));
        game.resultado_batalha.setPosition({280.f, 50.f});
    }
    game.resultado_batalha.setScale({2.f, 2.f});
}

// Exibe texto com base no resultado final da batalha
void calcular_resultado_combate(GameData &game){
    if(game.pontos_jogador > game.pontos_PC){
        game.resultado_batalha.setString("Voce Venceu este Combate!");
        game.resultado_batalha.setFillColor(sf::Color(0, 255, 0));
        game.resultado_batalha.setPosition({280.f, 100.f});
    }
    else if(game.pontos_jogador < game.pontos_PC){
        game.resultado_batalha.setString("Voce Perdeu este Combate!");
        game.resultado_batalha.setFillColor(sf::Color(255, 0, 0));
        game.resultado_batalha.setPosition({280.f, 100.f});
    }
    else{
        game.resultado_batalha.setString("Empate!");
        game.resultado_batalha.setFillColor(sf::Color(255, 255, 255));
        game.resultado_batalha.setPosition({520.f, 100.f});
    }
}
void exibir_time_vencedor(GameData &game, sf::RenderWindow &window){
    Fila temp(TAMANHO_TIMES + TAMANHO_TIMES);
    float posicaoX = 100.f;
    float posicaoY = 250.f;
    int cont = 0;
    while(!game.jogador_aux.vazia()){
        cont++;
        PokemonEntity aux;
        bool baux;
        game.jogador_aux.desenfileira(&aux, &baux);
        sf::Text nome_pokemon(game.fonte, aux.get_nome());
        sf::Texture imagem_poke;
        imagem_poke.loadFromFile(aux.get_imagem());

        temp.enfileira(aux, &baux);

        sf::Sprite sprite_pokemon(imagem_poke);
        sprite_pokemon.setPosition({posicaoX, posicaoY});
        auto sz = imagem_poke.getSize();
        sprite_pokemon.setScale({static_cast<float>(200) / sz.x, static_cast<float>(200) / sz.y});
        
        adicionar_tipo(aux, nome_pokemon);
        // Centraliza o texto no botão
        nome_pokemon.setPosition({posicaoX, posicaoY + 200.f});
        
        if(game.pontos_jogador > game.pontos_PC){
            if(cont % 2 != 0){
                window.draw(sprite_pokemon);
                window.draw(nome_pokemon);
                posicaoX+=215.f;
            }
        }
        else if(game.pontos_jogador < game.pontos_PC){
            if(cont % 2 == 0){
                window.draw(sprite_pokemon);
                window.draw(nome_pokemon);
                posicaoX+=215.f;
            }
        }
    }
    while(!temp.vazia()){
        PokemonEntity aux;
        bool baux;
        
        temp.desenfileira(&aux, &baux);
        game.jogador_aux.enfileira(aux, &baux);
    }
}

bool prepara_biomas(GameData& game, int indice) {
    NodeBiomaPtr atual = game.arvore_biomas.atual;

    if (atual == nullptr || indice < 0 || indice >= 4) {
        return false;
    }

    if (atual->filhos[0] == nullptr) {
        atual->filhos[0] =
            new NodeBioma(game.bioma_planta[indice], atual);
        atual->filhos[1] =
            new NodeBioma(game.bioma_fogo[indice], atual);
        atual->filhos[2] =
            new NodeBioma(game.bioma_agua[indice], atual);
    }

    return true;
}
