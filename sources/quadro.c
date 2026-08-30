#include <stdio.h>
#include <time.h>
#include "../headers/quadro.h"

#ifdef _WIN32
    #include <windows.h>
    #define PAUSA(ms) Sleep(ms)
    #define LIMPAR_TELA "cls"
#else
    #include <unistd.h>
    #define PAUSA(ms) usleep((ms) * 1000) // usleep recebe microsegundos
    #define LIMPAR_TELA "clear"
#endif


void inicializaQuadro (char quadro[20][80]){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 80; j++) {
            quadro[i][j]=' ';
        }
    }
}
void GeraMoldura (char quadro[20][80]){
    for (int i=0; i<20; i++){
        quadro[i][0]='|';
        quadro[i][79]='|';
    }
    for (int i=0; i<80; i++){
        quadro[0][i]='-';
        quadro[19][i]='-';
    }

}
void PrintaQuadro (char quadro[20][80]){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 80; j++) {
            printf("%c", quadro[i][j]);
        }
        printf("\n");
    }
}
void GeraAsteriscos(char quadro[20][80], int Quant){
    for(int i=0; i<Quant; i++){
        short NotValid= 1;
        int tentativas = 0;
        while(NotValid && tentativas<100){
            int coluna_rand = (rand()%78) +1;
            int linha_rand = (rand()%18) +1;
            if (quadro[linha_rand][coluna_rand]== ' '){
                NotValid = 0;
                quadro[linha_rand][coluna_rand] = '*';
                // se for 0 significa  que não vai gerar outro valor aleatorio, já que essa é uma posição válida
            }
        }
        if (NotValid){
            printf("não foi encontrada nenhuma posição válida, portanto o processo foi interrompido");
            return;
        }
    }
}
void GeraAsteriscosMais(char quadro[20][80], int Quant){
    for(int i=0; i<Quant; i++){
        short NotValid= 1;
        int tentativas = 0;
        while(NotValid && tentativas<100){
            int coluna_rand = (rand()%78) +1;
            int linha_rand = (rand()%18) +1;
            if (quadro[linha_rand][coluna_rand]== ' ' && quadro[linha_rand+1][coluna_rand]== ' ' && quadro[linha_rand-1][coluna_rand]== ' ' && quadro[linha_rand][coluna_rand+1]== ' ' && quadro[linha_rand][coluna_rand-1]== ' '){
                NotValid = 0;
                quadro[linha_rand][coluna_rand]= '*';
                quadro[linha_rand+1][coluna_rand]= '*';
                quadro[linha_rand-1][coluna_rand]= '*';
                quadro[linha_rand][coluna_rand+1]= '*';
                quadro[linha_rand][coluna_rand-1]= '*';
                // se for 0 significa  que não vai gerar outro valor aleatorio, já que essa é uma posição válida
            }
        }
        if (NotValid){
            printf("não foi encontrada nenhuma posição válida, portanto o processo foi interrompido");
            return;
        }
    }
}
void GeraAsteriscosX(char quadro[20][80], int Quant){
    for(int i=0; i<Quant; i++){
        short NotValid= 1;
        int tentativas = 0;
        while(NotValid && tentativas<100){
            int coluna_rand = (rand()%78) +1;
            int linha_rand = (rand()%18) +1;
            if (quadro[linha_rand][coluna_rand]== ' ' && quadro[linha_rand+1][coluna_rand+1]== ' ' && quadro[linha_rand-1][coluna_rand-1]== ' ' && quadro[linha_rand-1][coluna_rand+1]== ' ' && quadro[linha_rand+1][coluna_rand-1]== ' '){
                NotValid = 0;
                quadro[linha_rand][coluna_rand]= '*';
                quadro[linha_rand+1][coluna_rand+1]= '*';
                quadro[linha_rand-1][coluna_rand-1]= '*';
                quadro[linha_rand+1][coluna_rand-1]= '*';
                quadro[linha_rand-1][coluna_rand+1]= '*';
                // se for 0 significa  que não vai gerar outro valor aleatorio, já que essa é uma posição válida
            }
        }
        if (NotValid){
            printf("não foi encontrada nenhuma posição válida, portanto o processo foi interrompido");
            return;
        }
    }
}
void GeraAleatorias(char quadro[20][80], int Quant){
    for (int i=0; i<Quant; i++){
        int EscolhaRand = (rand()%3)+1;
        switch (EscolhaRand){
        case 1:
            GeraAsteriscos(quadro, 1);
            break;
        case 2:
            GeraAsteriscosMais(quadro, 1);
            break;
        case 3:
            GeraAsteriscosX(quadro, 1);
            break;
        }
    }
}
void GeraAnimacaoStar (char quadro[20][80], int linha, int coluna){
    char vetor[] = {'*', '@', '+', '#', ' ', ' '};
    int LinhaStart = linha;
    int ColunaStart = coluna;
    int centro = 0;
    int camada1 = 5;
    int camada2 = 4;
    for(int i=0; i<6; i++){
        //centro
        quadro[LinhaStart][ColunaStart] = vetor[(centro+i)%6];
        //primeira camada
        quadro[LinhaStart-1][ColunaStart] = vetor[(camada1+i)%6];
        quadro[LinhaStart+1][ColunaStart] = vetor[(camada1+i)%6];
        quadro[LinhaStart][ColunaStart-1] = vetor[(camada1+i)%6];
        quadro[LinhaStart][ColunaStart+1] = vetor[(camada1+i)%6];
        //segunda camada
        quadro[LinhaStart+1][ColunaStart+1] = vetor[(camada2+i)%6];
        quadro[LinhaStart-1][ColunaStart-1] = vetor[(camada2+i)%6];
        quadro[LinhaStart+1][ColunaStart-1] = vetor[(camada2+i)%6];
        quadro[LinhaStart-1][ColunaStart+1] = vetor[(camada2+i)%6];
        quadro[LinhaStart-2][ColunaStart] = vetor[(camada2+i)%6];
        quadro[LinhaStart+2][ColunaStart] = vetor[(camada2+i)%6];
        quadro[LinhaStart][ColunaStart-2] = vetor[(camada2+i)%6];
        quadro[LinhaStart][ColunaStart+2] = vetor[(camada2+i)%6];

        //certifica-se de que o desenho não passe da moldura
        GeraMoldura(quadro);
        //MOSTRA O QUADRO ATUAL NA TELA
        PrintaQuadro(quadro);
        PAUSA(80);
    }
    inicializaQuadro(quadro);
    GeraMoldura(quadro);
}
void GeraAnimacaoStar2 (char quadro[20][80], int linha, int coluna){
    char vetor[] = {'*', '@', '+', '#', ' ', ' ', ' '};
    int LinhaStart = linha;
    int ColunaStart = coluna;
    int centro = 0;
    int camada1 = 6;
    int camada2 = 5;
    int camada3 = 4;
    for(int i=0; i<7; i++){
        //centro
        quadro[LinhaStart][ColunaStart] = vetor[(centro+i)%7];
        //primeira camada
        quadro[LinhaStart-1][ColunaStart] = vetor[(camada1+i)%7];
        quadro[LinhaStart+1][ColunaStart] = vetor[(camada1+i)%7];
        quadro[LinhaStart][ColunaStart-1] = vetor[(camada1+i)%7];
        quadro[LinhaStart][ColunaStart+1] = vetor[(camada1+i)%7];
        //segunda camada
        quadro[LinhaStart-2][ColunaStart] = vetor[(camada2+i)%7];
        quadro[LinhaStart+2][ColunaStart] = vetor[(camada2+i)%7];
        quadro[LinhaStart][ColunaStart-2] = vetor[(camada2+i)%7];
        quadro[LinhaStart][ColunaStart+2] = vetor[(camada2+i)%7];
        //terceira camada
        quadro[LinhaStart][ColunaStart-3] = vetor[(camada3+i)%7];
        quadro[LinhaStart][ColunaStart+3] = vetor[(camada3+i)%7];
        GeraMoldura(quadro);
        //MOSTRA O QUADRO ATUAL NA TELA
        PrintaQuadro(quadro);
        PAUSA(80);
    }
    inicializaQuadro(quadro);
    GeraMoldura(quadro);
}
void GeraAnimacaoStar3 (char quadro[20][80], int linha, int coluna){
    char vetor[] = {'*', '@', '+', '#', ' '};
    int LenVetor = 5;
    int LinhaStart = linha;
    int ColunaStart = coluna;
    int centro = 0;
    int camada1 = 5;
    for(int i=0; i<5; i++){
        //centro
        quadro[LinhaStart][ColunaStart] = vetor[(centro+i)%5];
        //primeira camada
        quadro[LinhaStart-1][ColunaStart] = vetor[(camada1+i)%5];
        quadro[LinhaStart+1][ColunaStart] = vetor[(camada1+i)%5];
        quadro[LinhaStart][ColunaStart-1] = vetor[(camada1+i)%5];
        quadro[LinhaStart][ColunaStart+1] = vetor[(camada1+i)%5];

        GeraMoldura(quadro);
        //MOSTRA O QUADRO ATUAL NA TELA
        PrintaQuadro(quadro);
        PAUSA(80);
    }
    inicializaQuadro(quadro);
    GeraMoldura(quadro);
}
void GeraAnimacaoStar4 (char quadro[20][80], int linha, int coluna, int linha2, int coluna2){
    char vetor[] = {'*', '@', '+', '#', ' '};
    int LenVetor = 5;
    int LinhaStart = linha;
    int ColunaStart = coluna;
    int LinhaStart2 = linha2;
    int ColunaStart2 = coluna2;
    int centro = 0;
    int camada1 = 5;
    for(int i=0; i<5; i++){
        //figura1
        //centro
        quadro[LinhaStart][ColunaStart] = vetor[(centro+i)%5];
        //primeira camada
        quadro[LinhaStart-1][ColunaStart] = vetor[(camada1+i)%5];
        quadro[LinhaStart+1][ColunaStart] = vetor[(camada1+i)%5];
        quadro[LinhaStart][ColunaStart-1] = vetor[(camada1+i)%5];
        quadro[LinhaStart][ColunaStart+1] = vetor[(camada1+i)%5];

        //figura2
        //centro
        quadro[LinhaStart2][ColunaStart2] = vetor[(centro+i)%5];
        //primeira camada
        quadro[LinhaStart2-1][ColunaStart2] = vetor[(camada1+i)%5];
        quadro[LinhaStart2+1][ColunaStart2] = vetor[(camada1+i)%5];
        quadro[LinhaStart2][ColunaStart2-1] = vetor[(camada1+i)%5];
        quadro[LinhaStart2][ColunaStart2+1] = vetor[(camada1+i)%5];

        GeraMoldura(quadro);
        //MOSTRA O QUADRO ATUAL NA TELA
        PrintaQuadro(quadro);
        PAUSA(80);
    }
    inicializaQuadro(quadro);
    GeraMoldura(quadro);
}

void GeraRandomStarsAnimation (char quadro[20][80]){
    while(1){
        int EscolhaRand = (rand()%3)+1;
        int colunarand1 = (rand()%78) +1;
        int linharand1 = (rand()%18) +1;
        int colunarand2 = (rand()%78) +1;
        int linharand2 = (rand()%18) +1;
        int colunarand3 = (rand()%78) +1;
        int linharand3 = (rand()%18) +1;
        int colunarand4 = (rand()%78) +1;
        int linharand4 = (rand()%18) +1;
        int colunarand5 = (rand()%78) +1;
        int linharand5 = (rand()%18) +1;
        int colunarand6 = (rand()%78) +1;
        int linharand6 = (rand()%18) +1;
        switch (EscolhaRand){
            case 1:
                for(int i = 0; i<5; i++){
                GeraAnimacaoStar(quadro, linharand1, colunarand1);
                GeraAnimacaoStar3(quadro, linharand2, colunarand2);
                GeraAnimacaoStar2(quadro, linharand3, colunarand3);
                GeraAnimacaoStar4(quadro, linharand4, colunarand4, linharand5, colunarand5);
                }
                break;
            case 2:
                for(int i = 0; i<5; i++){
                GeraAnimacaoStar(quadro, linharand1, colunarand1);
                GeraAnimacaoStar3(quadro, linharand2, colunarand2);
                GeraAnimacaoStar2(quadro, linharand3, colunarand3);
                GeraAnimacaoStar3(quadro, linharand4, colunarand4);
                GeraAnimacaoStar3(quadro, linharand5, colunarand5);
                GeraAnimacaoStar3(quadro, linharand6, colunarand6);
                }
                break;
            case 3:
                for(int i = 0; i<5; i++){
                GeraAnimacaoStar(quadro, linharand1, colunarand1);
                GeraAnimacaoStar3(quadro, linharand2, colunarand2);
                GeraAnimacaoStar2(quadro, linharand3, colunarand3);
                GeraAnimacaoStar(quadro, linharand4, colunarand4);
                GeraAnimacaoStar2(quadro, linharand5, colunarand5);
                }
                break;
        }
    }
}
