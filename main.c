#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int ordemMaxima = 20;

void mostrarMatriz(double matriz[][ordemMaxima], int ordem);
double det(double matriz[][ordemMaxima], int ordem);
double calcularCofator(double matriz[][ordemMaxima], int ordem, int linha, int coluna);
bool menu();
bool receberElementos();
bool matrizesOrdem(int ordem);

int main(void) {
  printf("\e[1;1H\e[2J");    
  while(true){
    if(menu() == false){
      break;
    } 

  }
  return 0;
}

bool menu(){
  int op;
   printf("Este programa multiplica matrizes de ordem 2 e 3 e calcula determinante\n");
  printf("Aviso!!\nEste programa está na versão 1.0 podendo ainda conter falhas,\nno momento, o programa não pode receber nada além de números\nDigite 0 e pressione Enter para iniciar\n");
  scanf("%d",&op);
  if(op == 0){
    printf("\e[1;1H\e[2J");    

    printf("Digite o número do que você gostaria de fazer:\n");
    printf("1 - Multiplicar Matrizes de ordem 2\n");
    printf("2 - Multiplicar Matrizes de Ordem 3\n");
    printf("3 - Calcular Determinante:\n");
    printf("4 - Sair:\n");
    scanf("%d",&op);
    if(op == 1){
      matrizesOrdem(2);
    }else if(op == 2){
      matrizesOrdem(3);
    }else if(op == 3){
      receberElementos();
    } else if(op == 4){
      return false;
    }else{
        printf("\e[1;1H\e[2J");
          printf("Entrada invalida!!\n");
          menu();
      }  

}
  }
  


double calcularCofator(double matriz[][ordemMaxima],int ordem,int linha,int coluna){
  double matrizCofator[ordemMaxima][ordemMaxima];
  int n = ordem - 1;
  int x = 0;
  int y = 0;

  for (int i = 0; i < ordem; i++)
  {
    for (int j = 0; j < ordem; j++)
    {
      if(i != linha && j != coluna){
        matrizCofator[x][y] = matriz[i][j];
        y++;
        if(y >= n){
          x++;
          y = 0;

        }
      }
    }
    
  }
  // retorna o determinante de cada cofator 
  return pow(-1.0, linha + coluna) * det(matrizCofator, n);
}

double det(double matriz[][ordemMaxima], int ordem){

int determinante = 0;
  // Calcular Determinante
  if (ordem == 1){
    determinante = matriz[0][0];
  }else{
    for (int coluna = 0; coluna < ordem; coluna++)
    {
      determinante = determinante + matriz[0][coluna] * calcularCofator(matriz,ordem,0, coluna);
    }
    
  }
  return determinante;
}
void mostrarMatriz(double matriz[][20],int ordem){
  printf("A matriz Digitada foi:\n");
  for (int i = 0; i < ordem; i++)
    {
      for (int j = 0; j < ordem; j++)
      {
        printf("\t%.3lf", matriz[i][j]);
      }
  printf("\n");
    }
}
bool receberElementos(){
  printf("\e[1;1H\e[2J");   
    double matriz[ordemMaxima][ordemMaxima];
    int ordem;
    printf("Digite o número da ordem para encontrar o determinte:\n");
    printf("2 - Ordem 2\n");
    printf("3 - Ordem 3\n");
    printf("4 - Ordem 4\n");
    scanf("%d",&ordem);
    printf("\e[1;1H\e[2J"); 
    if(ordem < 2 || ordem > 4){
      printf("Entrada Invalida!!\n");
      menu();
    }  

    printf("Digite os elementos da Matriz\n");
    for( int i = 0; i < ordem; i++){
      for (int j = 0; j < ordem; j++){
        printf("Digite o elemento [%d] [%d]: ", i+1, j+1);
        scanf("%lf", &matriz[i][j]);
      }
    }

    mostrarMatriz(matriz, ordem);
    printf("O determinate da matriz é: %.3lf \n", det(matriz,ordem));
    printf("Deseja fazer mais alguma operação? Digite 1 para Sim e 2 para Não... :\n");
    int fim;
    scanf("%d", &fim);
    if(fim ==1){
      menu();
    }else{
      return false;
    }

}
// Calcular o produto de matrizes

bool matrizesOrdem(int ordem){
  int matriz1[ordem][ordem];
  int matriz2 [ordem][ordem];
  int resultado[ordem][ordem];
  int soma = 0;
  printf("Digite os valores da primeira Matriz\n");
  printf("%d\n", ordem);

  for (int i = 0; i < ordem; i++){
    for (int j = 0; j < ordem; j++){
      printf("Digite o elemento [%d] [%d]: ", i+1, j+1);
      scanf("%d", &matriz1[i][j]);
    }
  }
  printf("Digite os valores da segunda Matriz\n");
  for (int i = 0; i < ordem; ++i){
    for (int j = 0; j < ordem; ++j){
      printf("Digite o elemento [%d] [%d]: ", i+1, j+1);
      scanf("%d", &matriz2[i][j]);
    }
  }
  for (int c = 0; c < ordem; c++) {
      for (int d = 0; d < ordem; d++) {
        for (int k = 0; k < ordem; k++) {
          soma += matriz1[c][k]*matriz2[k][d];
        } 
        resultado[c][d] = soma;
        soma = 0;
      }
  }
  for (int c = 0; c < ordem; c++) {
      for (int d = 0; d < ordem; d++)
        printf("%d\t", resultado[c][d]);
 
      printf("\n");
    }
     printf("Deseja fazer mais alguma operação? Digite 1 para Sim e 2 para Não... :\n");
      int fim;
      scanf("%d", &fim);
      if(fim ==1){
        menu();
      }else{
        return false;
      }
}
