#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    struct lista *adj;
}vertice;

typedef struct lista{
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro{
    struct registro *proximo;
    int valor;
}registro;

typedef struct distancia{
    int chegou;
    int distancia;
}distancia;

void dfs(int raiz, vertice *vertices,int *vetor, int contador);
void inclui_adj(vertice *v, int valor);
lista *aloca_lista();
registro *aloca_registro();
int main(){
    int qtd_vertice, qtd_aresta, a, b;
    printf("\nDigite o número de vértices e arestas:");
    scanf("%d %d",&qtd_vertice,&qtd_aresta);

    vertice *vertices;
    vertices = (vertice*)calloc(qtd_vertice+1,sizeof(vertice));

    for (int i = 0; i < qtd_aresta; i++)
    {
        printf("\nDigite a aresta %d:",i+1);
        scanf("%d %d",&a,&b);
        inclui_adj(&vertices[a],b);
        inclui_adj(&vertices[b],a);
    }

    distancia *distancias = (distancia*)calloc(qtd_vertice+1,sizeof(distancia));
    int contador = 0;
    int *vetor = (int*)calloc(qtd_vertice+1,sizeof(int));
    dfs(1,vertices,vetor, contador);
    

    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("Distancia o 1 para o %d:%d\n",i,vetor[i]);
    }
    
    


    return 0;

}

void dfs(int raiz, vertice *vertices,int *vetor, int contador)
{
    vertices[raiz].visitado = 1;
    vetor[raiz]= contador;
    contador++;
    
    registro *aux;
    if (vertices[raiz].adj != NULL)
    {
        aux = vertices[raiz].adj->inicio;

        while (aux != NULL)
        {
            if (vertices[aux->valor].visitado == 0)
            {
                dfs(aux->valor, vertices, vetor, contador);
            }
            aux = aux->proximo;
        }
    }
}

void inclui_adj(vertice *v, int valor){
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