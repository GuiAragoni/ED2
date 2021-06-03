#include <stdio.h>
#include <stdlib.h>
#define max(a,b) \
({  __typeof__ (a) _a =(a); \
    __typeof__ (b) _b =(b); \
    _a > _b ? _a:_b ;})


typedef struct no{
    int valor, fb;
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
        }else if(x>(*no)->valor){
            subArvore(&(*no)->dir, x);
        }else{
            return;
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

void printInOrdemAr(No *no, int espaco){
    int i;
    if(!no){
        return;
    }
    printInOrdemAr(no->dir,espaco+1);
    for(i=0;i<espaco;++i){
        printf("\t");
    }
    printf("%d", no->valor);
    printf(" FB=%d\n", no->fb);
    printInOrdemAr(no->esq, espaco+1);
}

No *rotacaoDir(No *p){
    No *q=p->esq;
    p->esq=q->dir;
    q->dir=p;
    return q;
}

No *rotacaoEsq(No *p){
    No *q=p->dir;
    p->dir=q->esq;
    q->esq=p;
    return q;
}

No *balancear(No *p){
    if(p->fb<=-2){
        if(p->esq->fb>0)
            p->esq=rotacaoEsq(p->esq);
        p=rotacaoDir(p);
    }else{
        if(p->dir->fb<0)
            p->dir=rotacaoDir(p->dir);
        p=rotacaoEsq(p);
    }
}

int atualizaFB(No **no){
    int he, hd;
    if(*no==NULL){
        return 0;
    }
    he=atualizaFB(&(*no)->esq);
    hd=atualizaFB(&(*no)->dir);
    (*no)->fb=hd-he;
    if(abs((*no)->fb) >= 2){
        *no=balancear(*no);
        he=atualizaFB(&(*no)->esq);
        hd=atualizaFB(&(*no)->dir);
        (*no)->fb=hd-he;
    }
    return max(hd,he)+1;
}

No *buscarValor(No *raiz, int valor){
    if(!raiz){
        printf("Numero nao encontrado");
    }
    if(raiz->valor==valor){
        printf("Numero encontrado");
        return raiz;
    }
    if(raiz->valor > valor){
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
            filho=no->dir;
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
    No *busca=NULL;
    int x=1;
    while(x != 0){
        printf("\n--------------------------------\n1-Inserir numeros na arvore\n2-Buscar numeros na arvore\n3-Exibir Arvore\n4-Excluir numeros especificos\n5-Apagar arvore inteira\n0-sair do progama\nDigite o que deseja fazer: ");
        scanf("%d", &x);
        printf("--------------------------------\n");
        switch (x){
            case 1:
                printf("\n");
                do{
                    printf("Insira o numero 0 para sair numero: ");
                    scanf("%d",&num);
                    if(num!=0){
                        subArvore(&raiz,num);
                    }
                    atualizaFB(&raiz);
                }while(num != 0);
                printf("\n");
                break;
            case 2:
                printf("\nInforme  numero que deseja Buscar: ");
                scanf("%d",&num);
                busca = buscarValor(raiz,num);
                printf("\n");
                break;
            case 3:
                printf("\nA arvore armazenada e\n");
                printInOrdemAr(raiz,espaco);
                printf("\n");
                break;
            case 4:
                printf("\nInforme  numero que deseja Remover: ");
                scanf("%d",&num);
                removerNum(raiz,num);
                atualizaFB(&raiz);
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