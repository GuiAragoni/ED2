#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq, *dir;
}no;

no *criarNo(){
    no *a;
    a=(no *)malloc(sizeof(no));
    if(a == NULL){
       return a;
    }else{
        a->esq=NULL;
        a->dir=NULL;
        return a;
    }

} 
no *cria_arvore(int x){
    no *a;
    a=criarNo();
    if(a){
        a->valor= x;
        return a;
    }else{
        puts("Sem memoria o suficiente");
        exit(1);
    }
}
void adc_esq(no *a, int x){
    no* aux;
    if(a->esq){
        puts("operaçãpo invalida");
    }else{
        aux= cria_arvore (x);
        a->esq = aux;
    }
}
void adc_dir(no *a, int x){
    no* aux;
    if(a->dir){
        puts("operaçãpo invalida");
    }else{
        aux= cria_arvore (x);
        a->dir = aux;
    }
}

int main(){
    no *raiz, *aux, *aux2;   
    int x;
    raiz=NULL;        // cria as variaveis e nós, e atribui a raiz a NULL
    do{
        printf("\nDigite um numero:");
        scanf("%d", &x);
        if(!raiz){                  
            raiz=cria_arvore(x);    //se a raiz for NULL, então cria a arvore 
        }else{
            aux=raiz;
            aux2=raiz;              //se não atribui o que esta na raiz aos auxiliares para percorer a raiz
            while(x!= aux->valor && aux2 != NULL){          //enquanto o numero for diferente do valor que está no aux e o aux2 for diferente de NULL
                aux=aux2;
                if(x< aux->valor){          //em seguida se iguala os aux  e verifica se o valor que o usuario digitou é menor ou maior ao que está  
                    aux2=aux->esq;          //no nó que se compara, no primeiro caso o nó raiz,
                }else{                      //após comparado ele vai para esquerda caso seja menor, e para a direita cajo seja maior
                    aux2=aux->dir;  
                }
            }
            if(x==aux->valor){                   // assim que o Do While acabar é possivel que o numero ja exista na arvore,
                puts("numero ja esta na arvore");//sendo assim não será possivel adc o valor novamente
            }else{
                if(x < aux->valor){         //após as comprações caso o numero seja menor do que está na ultima casa da arvore ele ira adicinar 
                    adc_esq(aux,x);         //esse numero a esquerda, e caso seja maior a direita.
                }else{
                    adc_dir(aux,x);
                }
            }
        }
    }while (x!=0);  //e todos os processos seram repetidos até a pessoa tentar inserir o 0 na arvore;
        
}