#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaSimplesmenteEncadeada.h"

int main(){
    Lista *li, *lz, *lf;
    li = criar();
    lz = criar();
    struct aluno dados_aluno;

    dados_aluno.matricula = 6;
    inserir_unico(li, dados_aluno);
     dados_aluno.matricula = 6;
    inserir_unico(li, dados_aluno);
     dados_aluno.matricula = 6;
    inserir_unico(li, dados_aluno);
     dados_aluno.matricula = 6;
    inserir_unico(li, dados_aluno);
     dados_aluno.matricula = 9;
    inserir_unico(li, dados_aluno);
     dados_aluno.matricula = 8;
    inserir_unico(li, dados_aluno);
    dados_aluno.matricula = 6;
    inserir_unico(li, dados_aluno);
     dados_aluno.matricula = 10;
    inserir_unico(lz, dados_aluno);
     dados_aluno.matricula = 17;
    inserir_unico(lz, dados_aluno);
     dados_aluno.matricula = 4;
    inserir_unico(lz, dados_aluno);
     dados_aluno.matricula = 9;
    inserir_unico(lz, dados_aluno);
     dados_aluno.matricula = 8;
    inserir_unico(lz, dados_aluno);

    imprimir(li);
    printf("\n");
    imprimir(lz);

    lf = segmentar(lz, 3);
    printf("\n\n");
    imprimir(lz);
    printf("\n");
    imprimir(lf);

    printf("\n\nTamanho: %d Vazia: %d Cheia: %d\n\n", tamanho(li), vazia(li), cheia(li));
    printf("Valor consultado: %d\n\n", dados_aluno.matricula);
    informacoes(li);


    liberar(li);
    return 0;
}
