#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define USUARIO 3
#define MAQUINA 3

typedef enum
{
    Pedra,
    Papel,
    Tesoura,
    size_escolha
}Escolha_e;

typedef enum
{
    Vitoria,
    Derrota,
    Empate  
}Ganhador_e;

void draw_pedra();
void draw_papel();
void draw_tesoura();

int result(int usuario, int maquina, int tab[USUARIO][MAQUINA]);

                                    // Pedra    Papel    Tesoura
int tab_result[USUARIO][MAQUINA] = {{Empate,  Derrota,  Vitoria},  // Pedra
                                    {Vitoria, Empate,   Derrota},  // Papel
                                    {Derrota, Vitoria,  Empate}};  // Tesoura

typedef void (*jkp)(void);

typedef struct 
{
    jkp jokenpo;
}Jokenpo_t;

Jokenpo_t draw[] =
{
    draw_pedra, 
    draw_papel,
    draw_tesoura
};
const int size_draw = sizeof(draw) / sizeof(draw[0]);

int main()
{
    int entrada;
    
    // gerando uma escolha aleatorio
    srand(time(0));
    int maquina = rand() % size_escolha;

    printf("Vamos comecar o jogo\n");
    printf("\t\t\t 1-PEDRA, 2-PAPEL E 3-TESOURA.\n");
    printf("O que voce escolhe?\n\n");

    scanf("%i", &entrada);
    --entrada;

    if( entrada == Pedra || entrada == Tesoura || entrada == Papel)
    {
        result(entrada, maquina, tab_result);

    }else{
        printf("Opcao invalida!!!\n");
    }

    return 0;
}

int result(int usuario, int maquina, int tab[USUARIO][MAQUINA])
{ 
   
   switch(tab[usuario][maquina])
    {
        case Vitoria: 
        printf("\nVoce:\n");
        draw[usuario].jokenpo();
        printf("\nMaquina:\n");
        draw[maquina].jokenpo();
        printf("\nVenceu !!!\n");
        break;

        case Derrota:
        printf("\nVoce:\n");
        draw[usuario].jokenpo();
        printf("Maquina:\n");
        draw[maquina].jokenpo(); 
        printf("\nPerdeu !!!\n");
        break;
        
        case Empate:
        printf("\nVoce:\n");
        draw[usuario].jokenpo();
        printf("Maquina:\n");
        draw[maquina].jokenpo(); 
        printf("\nEmpate !!!\n");
        break; 
    }  
}

// Isso é uma ASCII ART
void draw_pedra()
{
    printf("    _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}

void draw_papel()
{
    printf("     _______      \n");
    printf("---'    ____)____ \n");
    printf("           ______)\n");
    printf("          _______)\n");
    printf("         _______) \n");
    printf("---.__________)   \n");    
}

void draw_tesoura()
{
    printf("    _______       \n");
    printf("---'   ____)____  \n");
    printf("          ______) \n");
    printf("       __________)\n");
    printf("      (____)      \n");
    printf("---.__(___)       \n");
}


