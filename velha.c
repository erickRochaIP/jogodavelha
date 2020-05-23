#include <stdio.h>
#include <stdlib.h>

void printabuleiro(int **tabuleiro){
  printf("    0  1  2\n");
    for(int i = 0; i < 3; i++){
      printf("\n%i  ", i);
      for(int j = 0; j < 3; j++){
        if(tabuleiro[i][j] == 0){
          printf("   ");
        }else if(tabuleiro[i][j] == 1){
          printf("X  ");
        }else if(tabuleiro[i][j] == 2){
          printf("O  ");
        }else{
          printf("Alguma coisa errada aconteceu com o joguinho ;-;\n");
          free (tabuleiro);
          exit(0);
        }
      }
      if(i!=2){
        printf("\n");
        printf("   --+--+--");
      }
      printf("\n");
    }
  printf("\n");
}

int alguemVenceu(int **tabuleiro){
//testa se alguem venceu
for(int i = 0; i < 3; i++){
//se alguem venceu na horizontal
if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2] && tabuleiro [i][0] != 0){
return tabuleiro[i][0];
}
//se alguem venceu na vertical
if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i] && tabuleiro [0][i] != 0){
return tabuleiro[0][i];
}


//se alguem venceu em algum digonal
if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2] && tabuleiro [0][0] != 0){
return tabuleiro[0][0];
}


if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0] && tabuleiro [0][2] != 0){
return tabuleiro[0][2];
}
}
if(tabuleiro[0][0] != 0 && tabuleiro[0][1] != 0 && tabuleiro[0][2] != 0 && tabuleiro[1][0] != 0 && tabuleiro[1][1] != 0 && tabuleiro[1][2] != 0 && tabuleiro[2][0] != 0 && tabuleiro[2][1] != 0 && tabuleiro[2][2] != 0){
return 3;
}
return 0;
}

void vezde(int jogador, int **tabuleiro){
  //pergunta e muda o tabuleiro baseado na resposta
  int x, y;
  if(jogador == 1){
    printf("Vez de X\n");
  }else{
    printf("Vez de O\n");
  }
  do{
    do{
      printf("Informe posicao (cima-baixo)\n");
      scanf("%i", &x);
      printf("Informe posicao (esquerda-direita)\n");
      scanf("%i", &y);
      if(x<0 || x>2 || y<0 || y>2){
        printf("As posicoes devem estar entre 0 e 2\n");
      }
    }while(x<0 || x>2 || y<0 || y>2);
    if(tabuleiro[x][y]!=0)
      printf("Posicao ja foi preenchida\n");
  }while(tabuleiro[x][y]!=0);
  tabuleiro[x][y] = jogador;
  printabuleiro(tabuleiro);
}

int main (void){

  int **tabuleiro;
  int jogada=0;

  tabuleiro = (int **)malloc(3*sizeof(int *));
  for(int i = 0; i < 3; i++){
    tabuleiro[i] = (int *) malloc (3 * sizeof(int));
  }

  printabuleiro(tabuleiro);

  while(1){
    if(jogada%2==0){
      vezde(1, tabuleiro);
    }else{
      vezde(2, tabuleiro);
    }
    int vitoria=alguemVenceu(tabuleiro);
    if(vitoria != 0){
      switch (vitoria){
        case 1:
          printf("Jogador X venceu\n");
          break;
        case 2:
          printf("Jogador O venceu\n");
          break;
        case 3:
          printf("Jogo empatado\n");
          break;
      }
      free(tabuleiro);
      exit(0);
    }
    jogada++;
  }

  return 0;
}
