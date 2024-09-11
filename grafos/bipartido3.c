#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    struct lista *adj;
}vertice;

typedef struct lista
{
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro{
    struct registro *prox;
    int valor;
}registro;

void inclui_adj(vertice *v, int valor);
int dfs(vertice *v, int raiz, int cor);
int main(){
    int qtd_vertice, qtd_aresta, a, b;
    scanf("%d %d", &qtd_vertice, &qtd_aresta);

    vertice *vertices = (vertice*)calloc(qtd_vertice + 1, sizeof(vertice));


    for (int i = 0; i < qtd_aresta; i++)
    {
        scanf("%d %d", &a, &b);
        inclui_adj(&vertices[a],b);
        inclui_adj(&vertices[b],a);
    }

    int cor = 1, isbipartido = 1;
    for (int i = 1; i <= qtd_vertice; i++)
    {
        if (vertices[i].visitado == 0)
        {
            if (!dfs(vertices,i,cor))
            {
                isbipartido = 0;
                break;
            }
        }
    }
    if (isbipartido)
    {
        printf("é bipartido");
    }else{
        printf("não é bipartido");
    }
    
    
    return 0;
}

int dfs(vertice *v, int raiz, int cor){
    v[raiz].visitado = cor;
    if (v[raiz].adj != NULL)
    {
        registro *aux = v[raiz].adj->inicio;
        while (aux != NULL)
        {
            if (v[aux->valor].visitado == 0)
            {
                if (!dfs(v,aux->valor, -cor))
                {
                    return 0;
                }
            }else if(v[aux->valor].visitado == cor){
                return 0;
            }
            
            aux = aux->prox;
        }
        
    }
    return 1;
}

void inclui_adj(vertice *v, int valor){
    if (v->adj == NULL)
    {
        v->adj = (lista *)calloc(1, sizeof(lista));
    }
    registro *aux = (registro *)calloc(1, sizeof(registro));
    aux->valor = valor;

    if (v->adj->inicio == NULL)
    {
        v->adj->inicio = aux;
        v->adj->fim = aux;
    }else{
        v->adj->fim->prox = aux;
        v->adj->fim = aux;
    }
}
