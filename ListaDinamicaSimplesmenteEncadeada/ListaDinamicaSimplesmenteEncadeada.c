#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaSimplesmenteEncadeada.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criar(){
    Lista *li;
    li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void liberar(Lista *li){
    if(li != NULL){
        Elemento *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int cheia(Lista *li){
    return 0;
}

int vazia(Lista *li){
    if(li == NULL) return -1;
    if(*li == NULL) return 1;
    return 0;
}

int tamanho(Lista *li){
    if(li == NULL) return 0;
    Elemento *no = *li;
    int cont = 0;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int inserir_inicio(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elemento *no;
    no = (Elemento*)malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = *li;
    *li = no;
    return 1;
}

int imprimir(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Elemento *no = *li;
    while(no != NULL){
        printf("%d -> ", no->dados.matricula);
        no = no->prox;
    }
    return 1;
}

int inserir_final(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elemento *no;
    no = (Elemento*)malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if(*li == NULL){
        *li = no;
    }
    else{
        Elemento *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int inserir_ordenado(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elemento *no = (Elemento*)malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;
    if(*li == NULL){
        no->prox = *li;
        *li = no;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = *li;
            *li = no;
        }
        else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

int remover_inicio(Lista *li){
    if(li == NULL) return 0;
    if(vazia(li)) return 0;
    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remover_final(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Elemento *no = *li;
    if(no->prox == NULL){
        *li = no->prox;
        free(no);
    }
    else{
        Elemento *ant, *no = *li;
        while(no->prox != NULL){
            ant = no;
            no = no->prox;
        }
        if(no == *li){
            *li = no->prox;
        }
        else{
            ant->prox = no->prox;
        }
        free(no);
    }
    return 1;
}

int remover_valor(Lista *li, int mat){
    if(li == NULL) return 0;
    if(vazia(li)) return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;
    if(no == *li){
        *li = no->prox;
    }
    else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consultar_pos(Lista *li, int pos, struct aluno *al){
    if(li == NULL || *li == NULL || pos <= 0) return 0;
    Elemento *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0;
    *al = no->dados;
    return 1;
}

int consultar_valor(Lista *li, int mat, struct aluno *al){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Elemento *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL) return 0;
    *al = no->dados;
    return 1;
}

int inserir_unico(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elemento *aux = *li;
    while(aux != NULL && aux->dados.matricula != al.matricula){
        aux = aux->prox;
    }
    if(aux != NULL) return 0;
    Elemento *no = (Elemento*)malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = *li;
    *li = no;
    return 1;
}

int informacoes(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    int pares = 0, impares = 0, maior, menor;
    Elemento *no = *li;
    while(no != NULL){
        if(no->dados.matricula % 2 == 0){
            pares++;
        }
        else{
            impares++;
        }
        if(no == *li){
            maior = no->dados.matricula;
            menor = no->dados.matricula;
        }
        else{
            if(no->dados.matricula > maior){
                maior = no->dados.matricula;
            }
            if(no->dados.matricula < menor){
                menor = no->dados.matricula;
            }
        }
        no = no->prox;
    }
    printf("Impares: %d\nPares: %d\nMaior: %d\nMenor: %d\n\n", impares, pares, maior, menor);
    return 1;
}

int remover_dois_inicio(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Elemento *no = *li;
    if(no->prox == NULL){
        *li = no->prox;
        free(no);
    }
    else{
        int i;
        for(i = 0; i < 2; i++){
            Elemento *no = *li;
            *li = no->prox;
            free(no);
        }
    }
    return 1;
}

int remover_dois_final(Lista *li){
    if(li == NULL) return 0;
    if(*li == NULL) return 0;
    Elemento *no = *li;
    if(no->prox == NULL){
        *li = no->prox;
        free(no);
    }
    else{
        int i;
        for(i = 0; i < 2; i++){
            Elemento *no = *li;
            if(no->prox == NULL){
                *li = no->prox;
                free(no);
                return 1;
            }
            Elemento *ant;
            while(no->prox != NULL){
                ant = no;
                no = no->prox;
            }
            ant->prox = no->prox;
            free(no);
        }
    }
    return 1;
}

int inverter(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    Elemento *ant = NULL;
    Elemento *atual = *li;
    Elemento *prox;
    while(atual != NULL){
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    *li = ant;
    return 1;
}

Lista* concatenar(Lista *li, Lista *lz){
    if(li == NULL || *li == NULL || lz == NULL || *lz == NULL) return 0;
    Lista *lf;
    lf = (Lista*)malloc(sizeof(Lista));
    if(lf != NULL){
        *lf = NULL;
    }
    else{
        return 0;
    }
    *lf = *li;
    Elemento *no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    no->prox = *lz;
    free(li);
    free(lz);
    return lf;
}

Lista* copia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    Lista *lf;
    lf = (Lista*)malloc(sizeof(Lista));
    if(lf != NULL){
        *lf = NULL;
    }
    else{
        return 1;
    }
    int i = 0;
    for(i = 0; i < tamanho(li); i++){
        Elemento *no;
        no = (Elemento*)malloc(sizeof(Elemento));
        if(no == NULL) return 0;
        no->prox = *lf;
        *lf = no;
    }
    Elemento *aux_1 = *li;
    Elemento *aux_2 = *lf;
    while(aux_1 != NULL){
        aux_2->dados = aux_1->dados;
        aux_1 = aux_1->prox;
        aux_2 = aux_2->prox;
    }
    return lf;
}

Lista* segmentar(Lista *li, int n){
    if(li == NULL) return 0;
    if(*li == NULL || (*li)->prox == NULL) return 0;
    Lista *lf;
    lf = (Lista*)malloc(sizeof(Lista));
    if(lf != NULL){
        *lf = NULL;
    }
    else{
        return 0;
    }
    Elemento *no = *li;
    int i;
    if(n > tamanho(li)) return 0;
    for(i = 1; i < n; i++){
        no = no->prox;
    }
    *lf = no->prox;
    no->prox = NULL;
    return lf;
}

