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

typedef struct fila
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
}fila;

void inclui_adj(vertice *v, int valor);
lista *aloca_lista();
registro *aloca_registro();
int CONTADOR = 0;
int main(){
    int cenarios;
    scanf("%d",&cenarios);
    for (int cenario = 0; cenario < cenarios; cenario++)
    {
        int qtd_vertice, qtd_arestas, a, b;
        scanf("%d %d",&qtd_vertice, &qtd_arestas);
        vertice *vertices = (vertice*)calloc(qtd_vertice+1,sizeof(vertice));

        for (int i = 0; i < qtd_arestas; i++)
        {
            scanf("%d %d", &a, &b);
            inclui_adj(&vertices[a],b);
            inclui_adj(&vertices[b],a);
        }
        
        fila *f = (fila*)calloc(1,sizeof(fila));
        f->qtd = qtd_vertice;
        registro *aux = (registro *)calloc(1, sizeof(registro));
        aux->valor = 1;
        f->inicio=aux;
        f->fim=aux;
        int contador = 1;
        
        while(f->inicio != NULL)
        {
            int vertice_atual = f->inicio->valor;
            f->inicio = f->inicio->proximo;

            if (vertices[vertice_atual].visitado == 0)
            {
                vertices[vertice_atual].visitado = 1;
                contador++;

                registro *aux = vertices[vertice_atual].adj->inicio;
                while (aux != NULL)
                {
                    if (vertices[aux->valor].visitado == 0)
                    {
                        registro *novo = aloca_registro();
                        novo->valor = aux->valor;
                        if (f->fim == NULL)
                        {
                            f->inicio = novo;
                            f->fim = novo;
                        }
                        else
                        {
                            f->fim->proximo = novo;
                            f->fim = novo;
                        }
                    }
                    aux = aux->proximo;
                }
            }
        }
        printf("%d\n",contador);
    }
    

    return 0;
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

