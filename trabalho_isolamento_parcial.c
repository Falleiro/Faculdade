#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
int criador_mapa(int mapa[100][100]);
int movimentar(int mapa[100][100]);
int infectar(int mapa[100][100]);
int contador_segundos(int mapa[100][100]);
int main(int argc, char const *argv[]){
    int mapa[100][100], mortos = 0, contaminados_total=0, vetor[1800], contador=1, qtd_infectados;

    srand(time(NULL));
    criador_mapa(mapa);

    for(int tempo=0; tempo<3600; tempo=tempo+2){
        movimentar(mapa);

        infectar(mapa);

        qtd_infectados=0;
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                if (mapa[i][j]==2) {
                    contaminados_total++;
                    qtd_infectados++;
                }
            }
        }

        vetor[contador]=qtd_infectados;
        contador++;
        for (int i =0; i<100; i++) {
            for (int j=0; j<100; j++) {
                if (mapa[i][j]==50){
                    int chance_morrer = rand() % 100;
                    if (chance_morrer!=0 && chance_morrer!=1 && chance_morrer!=2 && chance_morrer!=3 && chance_morrer!=4 && chance_morrer!=5 && chance_morrer!=6 && chance_morrer!=7 && chance_morrer!=8 && chance_morrer!=9) {
                        mapa[i][j]=-1;
                    }
                    else {
                        mapa[i][j]=0;
                        mortos++;
                    }
                }
            }
        }

        contador_segundos(mapa);

        sleep(2);
    }

    printf("Total de contaminados:%d\n", contaminados_total);
    for (contador=1; contador<=1800; contador++) {
        printf("Quantidade de infectados na iteração %d:%d; ", contador, vetor[contador]);
    }
    printf("\nMortos:%d\n", mortos);
    return 0 ;
}

int criador_mapa(int mapa[100][100]){
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            mapa[i][j]=0;
        }
    }
    int saudavel=0;
    while(saudavel < 495){
        int i= rand()%100;
        int j= rand()%100;
        if(mapa[i][j] == 0){
            mapa[i][j] = 1;
            saudavel += 1;
        }
    }  
    int infectado=0;
    while(infectado < 5){
        int i= rand()%100;
        int j= rand()%100;
        if(mapa[i][j] == 0){
            mapa[i][j] = 2;
            infectado += 1;
        }
    } 
    return 1;
}
int movimentar(int mapa[100][100]){
int auxiliar=0, i, j;
    while (auxiliar<250) {
        i=rand()%100;
        j=rand()%100;
        if(mapa[i][j] >= 1 && mapa[i][j] <= 31 || mapa[i][j]==-1){
            int verificador_repeticao = 0;
            int aleatorio = rand()%4 ;
            if (aleatorio == 0 && mapa[i-1][j]== 0 && i-1>=0 && verificador_repeticao == 0){
                mapa[i-1][j] = mapa[i][j] ;
                mapa[i][j] = 0;
                verificador_repeticao ++; 
                auxiliar++;
            }if (aleatorio == 1 && mapa[i+1][j]== 0 && i+1<100 && verificador_repeticao == 0){
                mapa[i+1][j] = mapa[i][j] ;
                mapa[i][j] = 0;
                verificador_repeticao ++;
                auxiliar++;
            }if (aleatorio == 2 && mapa[i][j+1]== 0 && j+1<100 && verificador_repeticao == 0){
                mapa[i][j+1] = mapa[i][j] ;
                mapa[i][j] = 0;
                verificador_repeticao ++;
                auxiliar++;
            }if (aleatorio == 3 && mapa[i][j-1]== 0 && j-1>=0 && verificador_repeticao == 0){
                mapa[i][j-1] = mapa[i][j] ;
                mapa[i][j] = 0;
                verificador_repeticao ++;
                auxiliar++;
            }
        }
    }
    return 1;
}
int infectar(int mapa[100][100]){
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (mapa[i][j]>=2 && mapa[i][j]<=50) {
                for (int x=i-3; x<=i+3; x++) {
                    for (int y=j-3; y<=j+3; y++) {
                        if (mapa[x][y]==1) {
                            int probabilidade = rand()%4;
                            if (probabilidade==1||probabilidade==2||probabilidade==3){
                                mapa[x][y]=2;
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}
int contador_segundos(int mapa[100][100]){
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (mapa[i][j]>1 && mapa[i][j]<50) {
                mapa[i][j]++;
            }
        }
    }
    return 1;
}