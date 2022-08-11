#include "module.h"
#include <stdio.h>  
#include <stdlib.h> //Necessário para as funções rand()
#include <time.h>   //Função time

/*Função de aleatorização do vetor de dados para a criação da árvore binária
  - Essa função está aleatorizando valores de 0 a 100*/

void randomize_vet(int *vet, int TAM){
    srand(time(NULL));  //Aleatoria verdadeiramente os números
    
    for(int i=0; i<TAM; i++){
        vet[i] = rand() % 100 + 1;
    }
}

/*Função básica para o print desse vetor, chamada todas as vezes que deseja
  mostrar como o vetor está ordenado*/
void printf_vet(int *vet, int TAM){
    for(int i=0; i<TAM; i++)
        printf("%d ",vet[i]);

   printf("\n");
}

/*Parte principal da ordenação com base na HeapSort, pegamos
  i = inicio e f = final*/
void cria_Heap(int *vet, int i, int f){
    int aux = vet[i];   //Primeira posição da partição
    int j = i*2+1;      //Primeiro filho

    //Teste para saber se estamos dentro do vetor
    while (j<=f){
        //Teste para sabermos de o filho é menor que o final
        if(j<f){
            //Verificação de qual dos filhos é maior, ja que o pai tem dois filhos
            if(vet[j] < vet[j+1]){
                j = j+1;
            }
        }

        //Teste para sabermos se o filho é maior que o próprio pai
        if(aux < vet[j]){
            vet[i] = vet[j];
            i = j;      //Filho se torna o pai
            j = 2*i+1;  //Repete o processo da criação do filho
        }else
            j = f+1;
    }

    //Antigo pai assumira o lugar do filho analisado anteriomente
    vet[i] = aux;
}

/*Função de ordenação HeapSort, aqui faremos a criação e posteriomente
  sua ordenação, deixando correspondente ao esperado*/
void heap_Sort(int *vet, int TAM){
    int aux;

    /*Criação do Heap, isso é aonde ira estruturar a árvore
      a partir dos dados propostos*/
    for(int i=(TAM-1)/2; i>=0; i--){
        cria_Heap(vet, i, TAM-1);
    }

    /*Pega o maior elemento da Heap, e coloca na sua posição
      corresposndente na array*/
    for (int i=TAM-1; i>=1; i--){
        aux = vet[0];
        vet [0] = vet [i];
        vet [i] = aux;
        cria_Heap(vet, 0, i-1); //Reconstrui a heap
    }
}