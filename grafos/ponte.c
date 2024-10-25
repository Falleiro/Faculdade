#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado;
    struct lista *adj;
} vertice;

typedef struct lista {
    struct registro *inicio;
    struct registro *fim;
} lista;

typedef struct registro {
    struct registro *proximo;
    int valor;
} registro;

int CONTADOR = 1;

void inclui_adj(vertice *v, int valor);
lista *aloca_lista();
registro *aloca_registro();
int min(int a, int b);
void dfs(int raiz, int pai, vertice *v, int *in, int *lower);

int main(){
    int qtd_vertice, qtd_aresta, a, b;
    scanf("%d %d", &qtd_vertice, &qtd_aresta);

    vertice *vertices = (vertice*)calloc(qtd_vertice+1,sizeof(vertice));
    


    for (int i = 0; i < qtd_aresta; i++)
    {
        scanf("%d %d", &a, &b);
        inclui_adj(&vertices[a],b);
        inclui_adj(&vertices[b],a);
    }

    printf("Lista de Adjacencia:\n");
    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("%d: ", i);
        registro *aux = vertices[i].adj->inicio;
        if (vertices[i].adj != NULL)
        {
            while (aux != NULL)
            {
                printf("%d ", aux->valor);
                aux = aux->proximo;
            }   
        }
        printf("\n");
    }

    int *in = (int*)calloc(qtd_vertice + 1,sizeof(int));
    int *lower = (int*)calloc(qtd_vertice + 1,sizeof(int));
    dfs(1,-1,vertices, in, lower);
    printf("TABELA IN\n");
    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("%d:%d\n",i,in[i]);
    }
    printf("TABELA LOWER\n");
    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("%d:%d\n",i,lower[i]);
    }
    
    printf("\n");
    return 0;
}

void dfs(int raiz, int pai, vertice *v, int *in, int *lower){
    v[raiz].visitado = 1;
    in[raiz] = CONTADOR;
    lower[raiz] = CONTADOR;
    CONTADOR++;

    if (v[raiz].adj != NULL)
    {
        registro *aux = v[raiz].adj->inicio;
        while (aux != NULL)
        {
            if (v[aux->valor].visitado == 1 && aux->valor != pai)
            {
                lower[raiz] = min(lower[raiz], in[aux->valor]);
            }else if(v[aux->valor].visitado != 1){
                dfs(aux->valor, raiz, v, in, lower);
                if (lower[aux->valor] > in[raiz])
                {
                    printf("\nA aresta do vértice %d e %d é uma ponte", raiz, aux->valor);
                }
                lower[raiz] = min(lower[raiz],lower[aux->valor]);
            }
            aux = aux->proximo;
        }
    }
}

int min(int a, int b){
    if (a > b)
    {
        return b;
    }else
    {
        return a;
    }
}

void inclui_adj(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL) {
        v->adj->inicio = novo;
        v->adj->fim = novo;
    } else {
        v->adj->fim->proximo = novo;
        v->adj->fim = novo;
    }
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}