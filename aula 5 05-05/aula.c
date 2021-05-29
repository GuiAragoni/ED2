#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq, *dir;
}No;
No *criaNo(int x){
    No *no=(No *) malloc(sizeof(No));
        if (!no){
            printf("Sem memoria\n");
            exit(0);
        }
        no->esq=NULL;
        no->dir=NULL;
        no->valor=x;
        return no;
}
void subArvore(No **no, int x){
    if(!(*no)){
        *no =criaNo(x);
    }else{
        if(x<(*no)->valor){
            subArvore(&(*no)->esq, x);
        }else{
            subArvore(&(*no)->dir, x);
        }
    }
}

void printArvore(No *no, int espaco){
    int i;
    if(!no){
        return;
    }
    printArvore(no->dir,espaco+1);
    for(i=0;i<espaco;++i){
        printf("\t");
    }
    printf("%d\n", no->valor);
    printArvore(no->esq, espaco+1);
}

int main(){
    int num,espaco=0;
    No *raiz=NULL;
    do{
        printf("Insira o numero 0 para sair numero: ");
        scanf("%d",&num);
        if(num!=0){
            subArvore(&raiz,num);
        }
    }while(num != 0);
    printArvore(raiz,espaco);
}
