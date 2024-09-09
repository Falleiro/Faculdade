#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    struct lista *adj;
}vertice;

typedef struct lista{
    struct registro *incio;
    struct registro *fim;
}lista;

typedef struct registro{
    int valor;
    struct registro *proximo;
}registro;

int dfs(vertice *v, int raiz, int cor);
void inclui_adj(vertice *v, int valor);
int main(){
    int qtd_vertice, qtd_aresta, a, b;
    int is_bipartido = 1;
    scanf("%d %d", &qtd_vertice, &qtd_aresta);

    vertice *vertices;
    vertices = (vertice *)calloc(sizeof(vertice), qtd_vertice+1);

    for (int i = 0; i < qtd_aresta; i++)
    {
        scanf("%d %d", &a, &b);
        inclui_adj(&vertices[a],b);
        inclui_adj(&vertices[b],a);
    }

    int cor = 1;
    for (int i = 1; i <= qtd_vertice; i++)
    {
        if (vertices[i].visitado == 0)
        {
            if (!dfs(vertices, i, cor))
            {
                is_bipartido = 0;
                break;
            }
        }
    }
    if (is_bipartido)
    {
        printf("é bipartido\n");
    }else{
        printf("não é bipartido\n");
    }
    
    
    
    return 0;

}

int dfs(vertice *v, int raiz, int cor){
    v[raiz].visitado = cor;
    if (v[raiz].adj != NULL)
    {
        registro *aux = v[raiz].adj->incio;
        while (aux != NULL)
        {
            if (v[aux->valor].visitado == 0)
            {
                if (!dfs(v, aux->valor, -cor))
                {
                    return 0;
            }
            }else if(v[aux->valor].visitado == cor){
                return 0;
            }
            aux = aux->proximo;
        }
    }
    return 1;
}

void inclui_adj(vertice *v, int valor){
    if (v->adj == NULL)
    {
        v->adj = (lista *)calloc(sizeof(lista),1);
    }
    registro *aux = (registro *)calloc(sizeof(registro),1);
    aux->valor = valor;
    if (v->adj->incio == NULL)
    {
        v->adj->incio = aux;
        v->adj->fim = aux;
    }else{
        v->adj->fim->proximo = aux;
        v->adj->fim = aux;
    }
}