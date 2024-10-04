#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

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

typedef struct cenario {
    int max_rota;
    int max_capitao;
} cenario;

void mostra_lista_adj(lista *l);
void inclui_adj(vertice *v, int valor);
void dfs(vertice *v, int raiz, int *contador_vertices);

int main() {
    int qtd_vertices, qtd_arestas;
    int a, b;
    int qtd_cenarios, aux_cenario = 0;

    scanf("%d", &qtd_cenarios);
    if (qtd_cenarios < 1 || qtd_cenarios > 5) {
        return 0;
    }

    while (aux_cenario < qtd_cenarios) {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        if (qtd_vertices < 1 || qtd_vertices > 100000) {
            return 0;
        }
        if (qtd_arestas < 0 || qtd_arestas > 100000) {
            return 0;
        }

        vertice *vertices = (vertice *)calloc(qtd_vertices + 1, sizeof(vertice));

        for (int i = 0; i < qtd_arestas; i++) {
            scanf("%d %d", &a, &b);
            if (a == b) {
                return 0;
            }

            inclui_adj(&vertices[a], b);
            inclui_adj(&vertices[b], a);
        }

        cenario c;
        c.max_rota = 0;
        c.max_capitao = 1;

        for (int i = 1; i <= qtd_vertices; i++) {
            if (vertices[i].visitado == 0) {
                int contador_vertices = 0;
                dfs(vertices, i, &contador_vertices);
                c.max_rota++;
                c.max_capitao = (long long)c.max_capitao * contador_vertices % MOD;
            }
        }

        printf("%d %d\n", c.max_rota, c.max_capitao);

        aux_cenario++;
        free(vertices);  // Libera a memória alocada para cada cenário
    }

    return 0;
}

void inclui_adj(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = (lista *)calloc(1, sizeof(lista));
    }

    registro *novo = (registro *)calloc(1, sizeof(registro));
    novo->valor = valor;

    if (v->adj->inicio == NULL) {
        v->adj->inicio = novo;
        v->adj->fim = novo;
    } else {
        v->adj->fim->proximo = novo;
        v->adj->fim = novo;
    }
}

void dfs(vertice *v, int raiz, int *contador_vertices) {
    v[raiz].visitado = 1;
    (*contador_vertices)++;

    if (v[raiz].adj != NULL) {
        registro *aux = v[raiz].adj->inicio;

        while (aux != NULL) {
            if (v[aux->valor].visitado == 0) {
                dfs(v, aux->valor, contador_vertices);
            }
            aux = aux->proximo;
        }
    }
}
