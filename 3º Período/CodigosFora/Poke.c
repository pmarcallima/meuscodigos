#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TIPO_MAX_TAMANHO 9
#define NOME_MAX_TAMANHO 100
#define POKEMON_MAX_QUANTIDADE 100

typedef struct Pokemon {
  char nome[NOME_MAX_TAMANHO];
  float ataque;
  float defesa;
  float vida;
  char tipo[TIPO_MAX_TAMANHO];
} Pokemon;

typedef struct Treinador {
  int quantidade;
  int pokemons_mortos;
  Pokemon pokemon[POKEMON_MAX_QUANTIDADE];
} Treinador;

void lerPokemons(Treinador *treinador, FILE *arquivo) {
  Pokemon pokemon;

  for (int i = 0; i < treinador->quantidade; i++) {
    fscanf(arquivo, "%s %f %f %f %s", pokemon.nome, &pokemon.ataque, &pokemon.defesa,
          &pokemon.vida, pokemon.tipo);

    strcpy(treinador->pokemon[i].nome, pokemon.nome);
    treinador->pokemon[i].ataque = pokemon.ataque;
    treinador->pokemon[i].defesa = pokemon.defesa;
    treinador->pokemon[i].vida = pokemon.vida;
    strcpy(treinador->pokemon[i].tipo, pokemon.tipo);

  }
}
Treinador *fazerTreinador(int num_pokemon) {
  Treinador *tmp = (Treinador *)malloc(sizeof(Treinador));
  tmp->quantidade = num_pokemon;

  return tmp;
}
float calcularFraqueza(char *tipo_atacando, char *tipo_alvo) {
  float fator = 1;
  if (strcmp(tipo_atacando, "pedra") == 0) {
    if (strcmp(tipo_alvo, "eletrico") == 0 || (strcmp(tipo_atacando, "elétrico") == 0)) 
      fator = 1.2;
    else if (strcmp(tipo_alvo, "gelo") == 0)
      fator = 0.8;
  }
  else if (strcmp(tipo_atacando, "eletrico") == 0 || (strcmp(tipo_atacando, "elétrico") == 0)) {
    if (strcmp(tipo_alvo, "agua") == 0 || (strcmp(tipo_atacando, "elétrico") == 0)) 
      fator = 1.2;
    else if (strcmp(tipo_alvo, "pedra") == 0)
      fator = 0.8;
  }
  else if (strcmp(tipo_atacando, "agua") == 0 || (strcmp(tipo_atacando, "água") == 0)) {
    if (strcmp(tipo_alvo, "fogo") == 0)
      fator = 1.2;
    else if (strcmp(tipo_alvo, "eletrico") == 0 || (strcmp(tipo_atacando, "elétrico") == 0))
      fator = 0.8;
  }
  else if (strcmp(tipo_atacando, "fogo") == 0) {
    if (strcmp(tipo_alvo, "gelo") == 0)
      fator = 1.2;
    else if (strcmp(tipo_alvo, "agua") == 0 || (strcmp(tipo_atacando, "água") == 0)) 
      fator = 0.8;
  }
  else if (strcmp(tipo_atacando, "gelo") == 0) {
    if (strcmp(tipo_alvo, "pedra") == 0)
      fator = 1.2;
    else if (strcmp(tipo_alvo, "fogo") == 0)
      fator = 0.8;
  }

  return fator;
}

int calcularDano(Pokemon *atacando, Pokemon *alvo) {
  float fator = calcularFraqueza(atacando->tipo, alvo->tipo);
  float ataque = (atacando->ataque * fator) ;
  float diferenca =(ataque - alvo->defesa);

  if (diferenca <= 0) {
     alvo->vida = alvo->vida - 1;
   // printf("O pokemon %s de defesa %f, sofreu %d de dano do pokemon %s de ataque %f e ficou com %f de vida\n", alvo->nome,alvo->defesa, -1, atacando->nome, ataque, alvo->vida);
  }
  else {
    alvo->vida =(alvo->vida - diferenca) ;
   //  printf("O pokemon %s de defesa %f, sofreu %f de dano do pokemon %s de ataque %f\n e ficou com %f de vida\n", alvo->nome,alvo->defesa, diferenca, atacando->nome,ataque, alvo->vida);
  }

  if (alvo->vida <= 0) {
    return 1;
  }

  return 0;
}

void imprimirResultados(Treinador *treinador_1, Treinador *treinador_2) {

  if (! (treinador_1->quantidade == treinador_1->pokemons_mortos)) {
    printf("Pokemons sobreviventes:\n");
    for (int i = treinador_1->pokemons_mortos; i < treinador_1->quantidade; i++)
      printf("%s\n", treinador_1->pokemon[i].nome);

  } else {
    printf("Pokemons sobreviventes:\n");
    for (int i = treinador_2->pokemons_mortos; i < treinador_2->quantidade; i++)
      printf("%s\n", treinador_2->pokemon[i].nome);
  }

  printf("Pokemons derrotados:\n");
  for (int i = 0; i < treinador_1->pokemons_mortos; i++)
    printf("%s ", treinador_1->pokemon[i].nome);
  for (int i = 0; i < treinador_2->pokemons_mortos; i++)
    printf("%s ", treinador_2->pokemon[i].nome);
  printf("\n");
}
void batalhar(Treinador *treinador_1, Treinador *treinador_2) {
  int fatalidade;

  do {
    if (treinador_1->pokemons_mortos < treinador_1->quantidade) {
      fatalidade= calcularDano(&treinador_1->pokemon[treinador_1->pokemons_mortos], &treinador_2->pokemon[treinador_2->pokemons_mortos]);
      if (fatalidade == 1) {
        printf("%s venceu %s\n", treinador_1->pokemon[treinador_1->pokemons_mortos].nome,
               treinador_2->pokemon[treinador_2->pokemons_mortos].nome);
        treinador_2->pokemons_mortos++;
      }
    } 
    if (treinador_2->pokemons_mortos < treinador_2->quantidade) {
      fatalidade= calcularDano(&treinador_2->pokemon[treinador_2->pokemons_mortos], &treinador_1->pokemon[treinador_1->pokemons_mortos]);

      if (fatalidade == 1) {
        printf("%s venceu %s\n", treinador_2->pokemon[treinador_2->pokemons_mortos].nome,
               treinador_1->pokemon[treinador_1->pokemons_mortos].nome);
        treinador_1->pokemons_mortos++;
      }
    }

  } while (treinador_1->quantidade > treinador_1->pokemons_mortos && treinador_2->quantidade > treinador_2->pokemons_mortos);

//caso o treinador tenha menos mortos que o total inicial, ele venceu
if (treinador_1->quantidade > treinador_1->pokemons_mortos)
      printf("Jogador 1 venceu\n");
else
      printf("Jogador 2 venceu\n");

}


int main() {
  int num_pokemon_1;
  int num_pokemon_2;
  FILE *arquivo = fopen("teste.txt", "r");

  fscanf(arquivo, "%d %d", &num_pokemon_1, &num_pokemon_2);

  Treinador *treinador_1 = fazerTreinador(num_pokemon_1);
  Treinador *treinador_2 = fazerTreinador(num_pokemon_2);

  lerPokemons(treinador_1, arquivo);
  lerPokemons(treinador_2, arquivo);
  fclose(arquivo);

  batalhar(treinador_1, treinador_2);
  imprimirResultados(treinador_1, treinador_2);

  free(treinador_1);
  free(treinador_2);

  return 0;
}
