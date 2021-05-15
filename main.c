#include <stdio.h>
#include <stdbool.h>
bool menu(){
  int op;
  printf("Digite o que você gostaria de fazer:\n");
  printf("1 - Matriz de ordem 2\n");
  printf("2 - Matriz de Ordem 3:\n");
  printf("3 - Sair:\n");
  scanf("%d",&op);

  if(op == 1){
    matrizesOrdem2();
  }else if(op == 2){
    matrizesOrdem2();
  }else if(op == 3){
    return false;
  }

}
int matrizesOrdem2(){
  int matriz1[2][2];
  int matriz2 [2][2];
  printf("Digite os valores da pimeira Matriz\n");
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      printf("Digite o elemento [%d] [%d]: ", i, j);
      scanf("%d", &matriz1[i][j]);
    }
  }
  printf("Digite os valores da segunda Matriz\n");
  for (int i = 0; i < 2; ++i){
    for (int j = 0; j < 2; ++j){
      printf("Digite o elemento [%d] [%d]: ", i, j);
      scanf("%d", &matriz2[i][j]);
    }
  }
  int a11 = matriz1[0][0] * matriz2[0][0] + matriz1[0][1] * matriz2[1][0]; 
  int a12 = matriz1[0][0] * matriz2[0][1] + matriz1[0][1] * matriz2[1][1];   
  int a13 = matriz1[1][0] * matriz2[0][0] + matriz1[1][1] * matriz2[1][0]; 
  int a14 = matriz1[1][0] * matriz2[0][1] + matriz1[1][1] * matriz2[1][1];  
  printf("%d %d\n%d %d\n",a11,a12,a13,a14);
     
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