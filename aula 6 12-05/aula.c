#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq, *dir;
}No;

//----------------------------------------------------------------
//cria o nó da arvore
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

//----------------------------------------------------------------
//cria a Arvore
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

//----------------------------------------------------------------
//copia a Arvore
void copiarArvore(No **r, No **copia){
	if((*r)){
	    subArvore(copia,(*r)->valor);
	    copiarArvore(&(*r)->esq,copia);
        copiarArvore(&(*r)->dir,copia);
    }
}

//----------------------------------------------------------------
//Apaga a arvore
void apagarArvore(No **r){
    if((*r)){
        apagarArvore(&(*r)->esq);
        apagarArvore(&(*r)->dir);
        free(*r);
        *r=NULL;
    }
}


// ----------------------------------------------------------------
// print em "In-Ordem" uma arvore
// dir depois esq == Decrescente
// esq depois dir == crescente
void printInOrdemAr(No *no, int espaco){
    int i;
    if(!no){
        return;
    }
    printInOrdemAr(no->dir,espaco+1);
    for(i=0;i<espaco;++i){
        printf("\t");
    }
    printf("%d\n", no->valor);
    printInOrdemAr(no->esq, espaco+1);
}


// ----------------------------------------------------------------
// Imprime Pre ordem
void printPreOrdemAr(No *no, int espaco){
    int i;
    if(!no){
        return;
    }
    printf("%d\n", no->valor);
    for(i=0;i<=espaco;++i){
        printf("\t");
    }
    printPreOrdemAr(no->esq,espaco+1);
    printPreOrdemAr(no->dir, espaco+1);

}

// ----------------------------------------------------------------
// Imprimo pos ordem 
void printPosOrdemAr(No *no, int espaco){
    int i;
    if(!no){
        return;
    }
    printPosOrdemAr(no->esq,espaco+1);
    printPosOrdemAr(no->dir, espaco+1);
    for(i=0;i<espaco;++i){
        printf("\t");
    }
    printf("%d\n", no->valor);
}


int main(){
    int num,espaco=0;
    No *raiz=NULL;
    No *copia=NULL;
    do{
        printf("Insira o numero 0 para sair numero: ");
        scanf("%d",&num);
        if(num!=0){
            subArvore(&raiz,num);
        }
    }while(num != 0);
    printf("\nIn-Ordem\n");
    printInOrdemAr(raiz,espaco);
    printf("\nPre-Ordem\n");
    printPreOrdemAr(raiz,espaco);
    printf("\nPos-Ordem\n");
    printPosOrdemAr(raiz,espaco);

    copiarArvore(&raiz,&copia);
    printf("\nCopia In-Ordem\n");
    printInOrdemAr(copia,espaco);

    apagarArvore(&copia);
    printf("\nVerificando:\n");
    printInOrdemAr(copia,espaco);
}
