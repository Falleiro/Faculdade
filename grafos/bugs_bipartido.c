#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    struct lista *adj;
    int cor; // 0 = não visitado, 1 = cor 1, -1 = cor oposta
} vertice;

typedef struct lista {
    struct registro *inicio;
    struct registro *final;
} lista;

typedef struct registro {
    int valor;
    struct registro *proximo;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_vertice_lista_adj(vertice *v, int valor);
void mostrar_lista(lista *l);
int dfs(int raiz, vertice *vertices, int cor);

int main() {
    int qtd_vertice, qtd_aresta, a, b, qtd_cenarios;
    vertice *vertices;

    printf("\nDigite a quantidade de cenários: ");
    scanf("%d", &qtd_cenarios);

    for (int cenario = 0; cenario < qtd_cenarios; cenario++) {
        printf("\nDigite a quantidade de insetos e interação entre eles: ");
        scanf("%d %d", &qtd_vertice, &qtd_aresta);

        vertices = (vertice *)calloc(qtd_vertice + 1, sizeof(vertice)); // Corrigido o uso de calloc

        for (int i = 0; i < qtd_aresta; i++) {
            printf("\nDigite a interação %d: ", i + 1);
            scanf("%d %d", &a, &b);

            incluir_vertice_lista_adj(&vertices[a], b);
            incluir_vertice_lista_adj(&vertices[b], a);
        }

        int isBipartite = 1;

        for (int i = 1; i <= qtd_vertice; i++) {
            if (vertices[i].cor == 0) { // Se ainda não foi visitado
                if (!dfs(i, vertices, 1)) { // Inicia a DFS com a cor 1
                    isBipartite = 0;
                    break;
                }
            }
        }

        printf("Cenário #%d:\n", cenario + 1);
        if (isBipartite) {
            printf("Nenhum inseto suspeito encontrado!\n");
        } else {
            printf("Insetos suspeitos encontrados!\n");
        }

        // Liberando memória alocada
        for (int i = 1; i <= qtd_vertice; i++) {
            free(vertices[i].adj); // Liberar as listas de adjacência
        }
        free(vertices); // Liberar o array de vértices
    }

    return 0;
}

lista *aloca_lista() {
    lista *novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_registro() {
    registro *novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void incluir_vertice_lista_adj(vertice *v, int valor) {
    if (v->adj == NULL) {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if (v->adj->inicio == NULL) {
        v->adj->inicio = novo;
        v->adj->final = novo;
    } else {
        v->adj->final->proximo = novo;
        v->adj->final = novo;
    }
}

void mostrar_lista(lista *l) {
    registro *aux;
    if (l == NULL) {
        return;
    }

    if (l->inicio == NULL) {
        return;
    }

    aux = l->inicio;

    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
}

int dfs(int raiz, vertice *vertices, int cor) {
    vertices[raiz].cor = cor;

    registro *aux = vertices[raiz].adj->inicio;

    while (aux != NULL) {
        if (vertices[aux->valor].cor == 0) { // Se o vértice adjacente ainda não foi colorido
            if (!dfs(aux->valor, vertices, -cor)) { // Alterna a cor
                return 0;
            }
        } else if (vertices[aux->valor].cor == cor) { // Se encontramos um vértice da mesma cor, o grafo não é bipartido
            return 0;
        }
        aux = aux->proximo;
    }

    return 1; // Certifica-se de que a função retorna 1 (verdadeiro) se o grafo for bipartido
}
