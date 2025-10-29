#include<stdio.h>
#include<stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
}celula;

//Para implementação de lista encadeada sem cabeça, é necessário implementar ponteiros de ponteiros
//de modo que o ponteiro trazido via parâmetro traga o endereço de memória do primeiro elemento da lista
//para que o início da lista possa ser reposicionado caso o valor a ser procurado seja o primeiro
void *BuscaERemove1Elemento_ListaSemCabeca(int x, celula **lst){
    celula *p = *lst;
    celula *q = NULL;

    while (p != NULL && p->conteudo != x){
        q = p;
        p = p->seg;
    }

    if (p != NULL){
        if (q == NULL)
            *lst = p->seg; // removendo primeiro elemento da lista e apontando para o segundo elemento, caso seja o primeiro
        else
            q->seg = p->seg;

        printf("Elemento %d removido:\n", x);
        free(p);
        return 0;
    }

    printf("Elemento %d não encontrado:\n", x);
}

void *BuscaERemoveNElementos_ListaSemCabeca(int x, celula **lst){
    celula *p = *lst;
    celula *q = NULL;
    int flagEntrou;

    while (p != NULL){
        if (p->conteudo == x){
            flagEntrou = 1;
            celula *tmp = p;
            if (q == NULL)
                *lst = p->seg; // removendo primeiro elemento da lista e apontando para o segundo elemento, caso seja o primeiro
            else
                q->seg = p->seg;
            
            p = p->seg;
            free(tmp);
        }else{
            q = p;
            p = p->seg;
        }
    }
    
    if(flagEntrou)
        printf("Elemento %d removido em todas as ocorrencias:\n", x);
    else
        printf("Elemento %d não encontrado:\n", x);
}

//Nessa implementação de inserção, apliquei uma pilha com lista encadeada sem cabeça, 
//visto que o último elemento a ser digitado, foi o primeiro a ser inserido na estrutura 
void Insere(int y, celula **lst){
    celula *nova = malloc(sizeof(celula));
    if (!nova) {
        printf("Erro de alocação!\n");
        return;
    }

    nova->conteudo = y;
    nova->seg = *lst;
    *lst = nova;
}

void Imprima (celula *lst) {
    celula *p;
    for (p = lst; p != NULL; p = p->seg)
        printf("%d\n", p->conteudo);
}


int main() {
    celula *lst = NULL;
    int n = 0;
    int tmp;
    int resp;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &tmp);
        Insere(tmp, &lst);
    }

    printf("Digite o elemento a ser removido\n");
    scanf("%d", &tmp);

    printf("Deseja excluir todos os elementos ou apenas a primeira ocorrencia? [1=Todos/2=Primeira]\n");
    scanf("%d", &resp);
    if(resp == 1)
        BuscaERemoveNElementos_ListaSemCabeca(tmp, &lst);
    else if(resp == 2)
        BuscaERemove1Elemento_ListaSemCabeca(tmp, &lst);

    Imprima(lst);

    return 1;
}