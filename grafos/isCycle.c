#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    struct lista *adj;
    int visitado;
} vertice;

typedef struct lista {
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_vertice_lista_adjacencia(vertice *v, int valor);
int dfs(int raiz, vertice *vertices, int pai);
int isCycle(int qtd_vertices, vertice *vertices);

int main() {
    int qtd_vertices, qtd_arestas, i, a, b;
    vertice *vertices;

    scanf("%d %d", &qtd_vertices, &qtd_arestas);

    vertices = (vertice *)calloc(sizeof(vertice), qtd_vertices + 1);

    for (i = 0; i < qtd_arestas; i++) {
        scanf("%d %d", &a, &b);
        incluir_vertice_lista_adjacencia(&vertices[a], b);
        incluir_vertice_lista_adjacencia(&vertices[b], a);
    }

    if (isCycle(qtd_vertices, vertices)) {
        printf("1\n");  // Ciclo detectado
    } else {
        printf("0\n");  // Nenhum ciclo detectado
    }

    return 0;
}

int isCycle(int qtd_vertices, vertice *vertices) {
    for (int i = 1; i <= qtd_vertices; i++) {
        if (vertices[i].visitado == 0) {
            if (dfs(i, vertices, -1)) {
                return 1;  // Ciclo encontrado
            }
        }
    }
    return 0;  // Nenhum ciclo encontrado
}

int dfs(int raiz, vertice *vertices, int pai) {
    vertices[raiz].visitado = 1;

    registro *aux = vertices[raiz].adj->inicio;

    while (aux != NULL) {
        if (vertices[aux->valor].visitado == 0) {
            if (dfs(aux->valor, vertices, raiz)) {
                return 1;  // Ciclo encontrado
            }
        } else if (aux->valor != pai) {
            return 1;  // Ciclo encontrado
        }
        aux = aux->prox;
    }
    return 0;  // Nenhum ciclo encontrado a partir deste vértice
}

void incluir_vertice_lista_adjacencia(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL) {
        v->adj->inicio = novo;
        v->adj->final = novo;
    } else {
        v->adj->final->prox = novo;
        v->adj->final = novo;
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
