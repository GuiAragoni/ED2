#include <stdio.h>
#include<stdlib.h>

int busca_rec(int vet[], int val, int tam){
    if (val==vet[tam])
        return tam;
    else if(tam<0)
        return-1;
    else
        return busca_rec(vet,val,tam-1);
}
int main(){
    int tam;
    int posicao;
    int val;
    
    scanf("%d", &tam);
    int vet[tam];
    for(int i=0;i<tam;i++){
        printf("digite o(s) numero(s) no vetor: ");
        scanf("%d", &vet[i]);
    }
    printf("\nDigite o valor que quer buscar buscar: ");
    scanf("%d", &val);
    posicao = busca_rec(vet, val , tam-1);

    if (posicao < 0)
        printf("Valor nao encontrado");
    else
        printf("Valor encontrado na posicao %d", posicao+1);
}