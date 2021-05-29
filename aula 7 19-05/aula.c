//professor acabei ficando sem tempo então irei enviar da forma que ficou 

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

void copiarArvore(No **r, No **copia){
	if((*r)){
	    subArvore(copia,(*r)->valor);
	    copiarArvore(&(*r)->esq,copia);
        copiarArvore(&(*r)->dir,copia);
    }
}


void apagarArvore(No **r){
    if((*r)){
        apagarArvore(&(*r)->esq);
        apagarArvore(&(*r)->dir);
        free(*r);
        *r=NULL;
    }
}
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
No *buscarValor(No *raiz, int valor){
    if(!raiz){
        printf("Numero nao encontrado");
    }
    if(raiz->valor==valor){
        printf("Numero encontrado");
        return raiz;
    }
    if(raiz->valor < valor){
        buscarValor(raiz->esq,valor);
    }else{
        buscarValor(raiz->dir,valor);
    }
}

int maiorNo(No *no){
    if(no->dir){
        return maiorNo(no->dir);
    }else{
        return no->valor;
    }
}

No *removerNum(No *no,int valor){
    No *filho=NULL;
    if (!no){
        printf("Elemento nao encontrado");
    }
    if(valor<no->valor){
        no->esq= removerNum(no->esq,valor);
    }else if(valor>no->valor){
        no->dir= removerNum(no->dir,valor);
    }else{
        if(!no->dir){
            filho=no->esq;
            free(no);
            return filho;
        }else if(!no->esq){
            filho=no->esq;
            free(no);
            return filho;
        }else{
            no->valor= maiorNo(no->esq);
            no->esq= removerNum(no->esq,no->valor);
            return no;
        }
    }
}

int main(){
    int num,espaco=0;
    No *raiz=NULL;
    No *copia=NULL;
    int x=1;
    while(x != 0){
        printf("Digite o que deseja fazer\n1-Inserir numeros na arvore\n2-Buscar numeros na arvore\n3-Exibir Arvore\n4-Excluir numeros especificos\n5-Apagar arvore inteira\n0-sair do progama\n");
        scanf("%d", &x);
        switch (x){
            case 1:
                do{
                    printf("Insira o numero 0 para sair numero: ");
                    scanf("%d",&num);
                    if(num!=0){
                        subArvore(&raiz,num);
                        printf("aaa %d", num);
                    }
                }while(num != 0);
                printf("\n");
                break;
            case 2:
                printf("\nInforme  numero que deseja Buscar: ");
                scanf("%d",&num);
                buscarValor(raiz,num);
                printf("\n");
                break;
            case 3:
                printf("\n");
                printInOrdemAr(raiz,espaco);
                printf("\n");
                break;
            case 4:
                printf("\nInforme  numero que deseja Remover: ");
                scanf("%d",&num);
                removerNum(raiz,num);
                printf("\n");
                break;
            case 5:
                apagarArvore(&raiz);
                printf("Arvore apagada.\n");
                break;
            default:
                break;
        }
    }
}