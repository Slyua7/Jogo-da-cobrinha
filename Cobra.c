#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif



int main(void) {
  srand(time(NULL));

  int l,c,tela=32, parede=219, cobra = 219,comida =190;
  int vMtela[25][50];
  int cobrinhaX = rand()%23 + 1,cobrinhaY= rand()%43 + 1;
  char tecla;
  int caldaY[5000],caldaX[5000], tamanho=2;
  int controle=0,comidaX,comidaY,comidaqnt=0;
  int rastroX,rastroY;


  for(l = 0; l < 25; l++){
    for(c = 0; c < 50; c++){
      vMtela[l][c] = tela;
    }
  }
  for(c = 0; c <50;c++){
    l = 0;
    vMtela[l][c] = parede;
  }
   for(c = 0; c <50;c++){
    l = 24;
    vMtela[l][c] = parede;
  }
   for(l = 0; l <25;l++){
    c = 0;
    vMtela[l][c] = parede;
  }
   for(l = 0; l <25;l++){
    c = 49;
    vMtela[l][c] = parede;
  }
  
  while(1){
    
    if(kbhit()){
      tecla= getchar();
    }
    
    caldaY[controle] = cobrinhaY;
    caldaX[controle] = cobrinhaX;
    controle++;
    
    if(comidaqnt == 0){
      comidaY = rand()%48 + 1;
      comidaX = rand()%23 + 1;
      vMtela[comidaY][comidaX] = comida;
      comidaqnt++;
    }

    if(cobrinhaX == comidaX && cobrinhaY == comidaY){
      comidaqnt --;
      tamanho++;
    }
    else{
        rastroY = caldaY[controle-tamanho];
        rastroX = caldaX[controle-tamanho];
    }
    
    for(l=0;l<25;l++){
      for(c=0;c<50;c++){
        printf("%c",vMtela[l][c]);  
      }
      printf("\n");
    }

    if(cobrinhaX == 0 || cobrinhaX == 24 || cobrinhaY == 0 || cobrinhaY ==49){
      system(cls);
      printf("GameOver\n\n\n");
      system(pause);
      exit(0);
      }
    
    vMtela[cobrinhaY][cobrinhaX] = cobra;
    
    //arrow left
    if(tecla ==97 ){
      cobrinhaY -- ;
    }
    //arrow right
    if(tecla ==100 ){
      cobrinhaY ++;
    }
    // arrow up
    if(tecla == 119 ){
      cobrinhaX --; 
    }
    //arrow down
    if(tecla ==115 ){
      cobrinhaX ++;
    }

    if(cobrinhaX != rastroX && cobrinhaY != rastroY){
      vMtela[rastroY][rastroX] = tela;
    }

    Sleep(100);
    system(cls);
  
  }
  return 0;
}
