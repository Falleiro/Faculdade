#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{

    struct lista *adj;

}vertice;

typedef struct lista{

    struct registro *inicio;
    struct registro *final;

}lista;

typedef struct registro{

    int valor;
    struct registro *proximo;

}registro;


lista *aloca_lista();
registro *aloca_registro();
void incluir_vertice_lista_adj(vertice *v, int valor);
void mostrar_lista(lista *l);
int main(){

    int qtd_vertice, qtd_aresta, a, b;
    

    printf("\nDigite a quantidade de vértices e arestas:");
    scanf("%d %d", &qtd_vertice, &qtd_aresta);
    
    vertice *vertices;
    vertices = (vertice *)calloc(sizeof(vertice), qtd_vertice + 1); 

    for (int i = 0; i < qtd_aresta; i++)
    {
        printf("\nDigite a aresta %d:", i+1);
        scanf("%d %d", &a, &b);

        incluir_vertice_lista_adj(&vertices[a], b);
        incluir_vertice_lista_adj(&vertices[b], a);
    }

    printf("Lista da Adjacencia: \n");
    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("Vertice: %d -> ", i);
        mostrar_lista(vertices[i].adj);
        printf("\n");
    }

    

    return 0;
}

lista *aloca_lista(){
    lista *novo = (lista *)calloc(sizeof(lista), 1);
    return novo;
}

registro *aloca_registro(){
    registro *novo = (registro *)calloc(sizeof(registro), 1);
    return novo;
}

void incluir_vertice_lista_adj(vertice *v, int valor){
    if (v->adj == NULL)
    {
        v->adj = aloca_lista();
    }

    registro *novo = aloca_registro();
    novo->valor = valor;

    if(v->adj->inicio == NULL){
        v->adj->inicio = novo;
        v->adj->final = novo;
    }
    else{
        v->adj->final->proximo = novo;
        v->adj->final = novo;
    }
    
}

void mostrar_lista(lista *l)
{

    registro *aux;
    if (l == NULL)
    {
        return;
    }

    if (l->inicio == NULL)
    {
        return;
    }

    aux = l->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
}
