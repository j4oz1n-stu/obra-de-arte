#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/quadro.h"

int main(){
    srand(time(NULL));
    short True = 1;
    while(True){
        printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
        printf("=================================\n");
        printf("1- encerrar programa\n");
        printf("2- iniciar o programa\n"); //arbitrario, qualquer botão serve para iniciar o programa, menos o 1
        char FlagEnd;
        scanf(" %c", &FlagEnd);
        if (FlagEnd=='1'){
            True = 0;
            return 0;
        }
        printf("=================================\n");


        char quadro[20][80];
        inicializaQuadro(quadro);
        GeraMoldura(quadro);
        printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
        printf("1 - asterisco simples.\n");
        printf("2 - simbolo de soma com asteriscos.\n");
        printf("3 - letra X com asteriscos.\n");
        printf("4 - figuras aleatorias.\n");
        printf("5 - animação de estrelas\n");


        printf("Digite o tipo de figura basica desejada::\n");
        int FlagChoice;
        scanf("%d", &FlagChoice);

        int Quant;
        if(FlagChoice!=5){
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio):\n");
            scanf("%d", &Quant);
            if (Quant<=0){
                Quant = rand()%101; //para ir até 100
            }
            else if (Quant>100){
                Quant = 100;
            }
        }

        switch (FlagChoice){
        case 1:
            GeraAsteriscos(quadro, Quant);
            PrintaQuadro(quadro);
            break;
        case 2:
            GeraAsteriscosMais(quadro, Quant);
            PrintaQuadro(quadro);
            break;
        case 3:
            GeraAsteriscosX(quadro, Quant);
            PrintaQuadro(quadro);
            break;
        case 4:
            GeraAleatorias(quadro, Quant);
            PrintaQuadro(quadro);
            break;
        case 5:
            GeraRandomStarsAnimation(quadro);
            break;
        default:
            printf("não tem essa opcao");
            break;
        }


    }
}