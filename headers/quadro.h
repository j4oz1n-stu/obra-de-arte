#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef GERA_QUADRO_H
#define GERA_QUADRO_H
#define X 20
#define Y 81

void inicializaQuadro (char quadro[20][80]);
void GeraMoldura (char quadro[20][80]);
void PrintaQuadro (char quadro[20][80]);
void GeraAsteriscos(char quadro[20][80], int Quant);
void GeraAsteriscosMais(char quadro[20][80], int Quant);
void GeraAsteriscosX(char quadro[20][80], int Quant);
void GeraAleatorias(char quadro[20][80], int Quant);
void GeraAnimacaoStar (char quadro[20][80], int linha, int coluna);
void GeraAnimacaoStar2 (char quadro[20][80], int linha, int coluna);
void GeraAnimacaoStar3 (char quadro[20][80], int linha, int coluna);
void GeraAnimacaoStar4 (char quadro[20][80], int linha, int coluna, int linha2, int coluna2);
void GeraRandomStarsAnimation (char quadro[20][80]);
#endif
