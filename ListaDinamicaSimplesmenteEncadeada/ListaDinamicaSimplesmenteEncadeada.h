struct aluno{
    int matricula;
    char nome[40];
};

typedef struct elemento* Lista;

Lista* criar();
void liberar(Lista *li);
int cheia(Lista *li);
int tamanho(Lista *li);
int vazia(Lista *li);
int inserir_inicio(Lista *li, struct aluno al);
int inserir_final(Lista *li, struct aluno al);
int inserir_ordenado(Lista *li, struct aluno al);
int imprimir(Lista *li);
int remover_inicio(Lista*);
int remover_final(Lista*);
int remover_valor(Lista*, int mat);
int consultar_pos(Lista*, int pos, struct aluno *al);
int consultar_valor(Lista*, int mat, struct aluno *al);
int inserir_unico(Lista*, struct aluno al);
int informacoes(Lista*);
int remover_dois_inicio(Lista*);
int remover_dois_final(Lista*);
int inverter(Lista*);
Lista* concatenar(Lista*, Lista*);
Lista* copia(Lista*);
Lista* segmentar(Lista*, int n);

