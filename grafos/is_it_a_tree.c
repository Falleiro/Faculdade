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


registro *aloca_registro();
lista *aloca_lista();
void inclui_lista_adj(vertice *v, int valor);
void dfs(vertice *v, int raiz);
int main(){

    int qtd_vertice, qtd_aresta, a, b;

    // printf("Digite a quantidade de vertices e arestas:");
    scanf("%d %d", &qtd_vertice, &qtd_aresta);

    vertice *v;
    v = (vertice *)calloc(sizeof(vertice), qtd_vertice+1);


    for (int i = 0; i < qtd_aresta; i++)
    {
        // printf("Digite a aresta:");
        scanf("%d %d", &a, &b);
        inclui_lista_adj(&v[a],b);
        inclui_lista_adj(&v[b],a);
    }
    
    int verifica_conexo = 0;
    for (int i = 1; i <= qtd_vertice; i++)
    {
        if (v[i].visitado==0)
        {
            dfs(v,i);
            verifica_conexo++;
        }
    }
    
    if (verifica_conexo == 1 && qtd_aresta == qtd_vertice -1)
    {
        printf("YES");
    }else{
        printf("NO");
    }
    



    return 0;
}

registro *aloca_registro(){
    registro *novo = (registro *)calloc(sizeof(registro),1) ;
    return novo;
}
lista *aloca_lista(){
    lista *novo = (lista *)calloc(sizeof(lista), 1) ;
    return novo;
}

void inclui_lista_adj(vertice *v, int valor){

    if (v->adj == NULL) 
    {
        v->adj = aloca_lista();
    }
    registro *novo = aloca_registro();
    novo-> valor = valor;

    if (v->adj->inicio == NULL)
    {
        v->adj->inicio = novo;
        v->adj->fim = novo;
    }else{
        v->adj->fim->proximo = novo;
        v->adj->fim = novo;
    }    
}

void dfs(vertice *v, int raiz){
    v[raiz].visitado = 1;
    if (v[raiz].adj != NULL)
    {
        registro *aux = v[raiz].adj->inicio;
        while (aux != NULL)
        {
            if (v[aux->valor].visitado==0)
            {
                dfs(v,aux->valor);                
            }
            aux = aux->proximo;
        }
    }
}