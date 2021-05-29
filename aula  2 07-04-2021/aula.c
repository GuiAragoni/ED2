#include <stdio.h>
#include <stdlib.h>


//pesquisa de numero inteiro de forma binaria recursiva
int PesquisaBinariaRec(int vet[], int val, int inf, int sup){ 
    if(inf<=sup){
        int meio=(inf+sup)/2;
        if(val==vet[meio])
            return meio;
        if(val<vet[meio])
            return PesquisaBinariaRec(vet,val,inf,meio-1);
        else
            return PesquisaBinariaRec(vet,val,meio+1,sup);
    }
    return -1; // numero nao encontrado
}  

int main(){
    //vetor pre definido para testes
    int vet[]={-10,-5,0,1,2,5,6};
    int tam=7,inf=0, valorbusca, posicao;
    printf("Digite um valor para busca:");
    scanf("%d", &valorbusca);
    posicao=PesquisaBinariaRec(vet,valorbusca,0,tam-1);
    if(posicao<0)
        printf("Valor nao encontrado");
    else
        printf("\nValor encontrado posicao %d", posicao+1);
}