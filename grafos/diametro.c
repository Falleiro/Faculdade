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

void dfs(int raiz, vertice *vertices, int *vetor, int contador);
void inclui_adj(vertice *v, int valor);
lista *aloca_lista();
registro *aloca_registro();

int main() {
    int qtd_vertice,  a, b;
    scanf("%d", &qtd_vertice);

    vertice *vertices = (vertice *)calloc(qtd_vertice + 1, sizeof(vertice));

    for (int i = 1; i < qtd_vertice; i++) {
        scanf("%d %d", &a, &b);
        inclui_adj(&vertices[a], b);
        inclui_adj(&vertices[b], a);
    }

    int *vetor1 = (int *)calloc(qtd_vertice + 1, sizeof(int));
    int contador = 0;
    dfs(1, vertices, vetor1, contador);

    int maior = 1;
    for (int i = 1; i <= qtd_vertice; i++) {
        if (vetor1[i] > vetor1[maior]) {
            maior = i;
        }
    }

    for (int i = 1; i <= qtd_vertice; i++) {
        vertices[i].visitado = 0;
        vetor1[i] = 0;
    }

    contador = 0;
    dfs(maior, vertices, vetor1, contador);

    int diametro = 0;
    for (int i = 1; i <= qtd_vertice; i++) {
        if (vetor1[i] > diametro) {
            diametro = vetor1[i];
        }
    }

    printf("%d\n", diametro);


    return 0;
}

void dfs(int raiz, vertice *vertices, int *vetor, int contador) {
    vertices[raiz].visitado = 1;
    vetor[raiz] = contador;
    contador++;

    registro *aux;
    if (vertices[raiz].adj != NULL) {
        aux = vertices[raiz].adj->inicio;

        while (aux != NULL) {
            if (vertices[aux->valor].visitado == 0) {
                dfs(aux->valor, vertices, vetor, contador);
            }
            aux = aux->proximo;
        }
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


