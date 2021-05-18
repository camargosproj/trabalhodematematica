#include <stdio.h>
#include <stdbool.h>

int det(){
int matriz[2][2] = 
{{1,4},
{3,2}};

}
void matrizesOrdem(int ordem){
  int matriz1[ordem][ordem];
  int matriz2 [ordem][ordem];
  int resultado[ordem][ordem];
  int soma = 0;
  printf("Digite os valores da pimeira Matriz\n");
  printf("%d\n", ordem);

  for (int i = 0; i < ordem; i++){
    for (int j = 0; j < ordem; j++){
      printf("Digite o elemento [%d] [%d]: ", i, j);
      scanf("%d", &matriz1[i][j]);
    }
  }
  printf("Digite os valores da segunda Matriz\n");
  for (int i = 0; i < ordem; ++i){
    for (int j = 0; j < ordem; ++j){
      printf("Digite o elemento [%d] [%d]: ", i, j);
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

}
bool menu(){
  int op;
  printf("Digite o que você gostaria de fazer:\n");
  printf("1 - Matriz de ordem 2\n");
  printf("2 - Matriz de Ordem 3:\n");
  printf("3 - Calcular Determinante:\n");
  printf("4 - Sair:\n");
  scanf("%d",&op);

  if(op == 1){
    matrizesOrdem(2);
  }else if(op == 2){
    matrizesOrdem(3);
  }else if(op == 3){
    det();
  } else if(op == 4){
    return false;
  }

}

int main(void) {
  printf("\e[1;1H\e[2J");    
  while(true){
    if(menu() == false){
      break;
    }   

  }
  return 0;
}
