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

No *subArvore(No *raiz, No *no, int valor){
    if (!no){
        no=criaNo(valor);
        if (!raiz){
            return no;
        }
        if (valor< raiz->valor){
            raiz->esq=no;
        }else{
            raiz->dir=no;
        }
        return no;
    }
    if(valor<no->valor){
        return subArvore(no,no->esq,valor);
    }else{
        return subArvore(no,no->dir,valor);
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
            subArvore(&raiz,raiz,num);
        }
    }while(num != 0);
    printArvore(raiz,espaco);
}
