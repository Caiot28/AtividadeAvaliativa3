#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Produto{
    int codigo;
    char descricao[100];
    int quantidade;
    float valor;
    struct Produto *prox;
}Produto;

Produto* criarListaVazia(){
    return NULL;
}

Produto* criarProduto(){
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    if(novoProduto == NULL){
        printf("\nMemoria insuficiente");
        exit(EXIT_FAILURE);
    }
    novoProduto->prox = NULL;
    return novoProduto; 
}

Produto* adicionar(Produto *lista){
    Produto *novoProduto = criarProduto();
    printf("\nDigite a descricao: ");
    fgets(novoProduto->descricao, sizeof(novoProduto->descricao), stdin);
    fflush(stdin);

    printf("\nDigite a quantidade: ");
    scanf("%d", &novoProduto->quantidade);

    printf("\nDigite o valor: ");
    scanf("%f", &novoProduto->valor);

    srand(time(NULL)); 
    novoProduto->codigo = rand() % 200;

    if(lista == NULL){
        return novoProduto;

    } else {
        Produto *atual = lista;

        while (atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novoProduto;
        return lista;
    }
}

void mostrar(Produto *lista){
    if(lista == NULL){
        printf("\n");
        printf("Lista NULA");
        printf("\n");
        return;
    } else {
        Produto *atual = lista;
        while (atual != NULL){
            printf("\nCodigo: %d", atual->codigo);
            printf("\nDescricao: %s", atual->descricao);
            printf("Quantidade: %d", atual->quantidade);
            printf("\nValor: %.2f", atual->valor);
            printf("\n");
            atual = atual->prox;
        }
    }
}

Produto* buscarProduto(Produto *lista, int codBusca){
    if(lista == NULL){
        printf("\n");
        printf("Lista nula");
        printf("\n");
        return NULL;
    } else {
        Produto *atual = lista;
        while(atual != NULL){
            if(atual->codigo == codBusca){
            printf("\nCodigo: %d", atual->codigo);
            printf("\nDescricao: %s", atual->descricao);
            printf("Quantidade: %d", atual->quantidade);
            printf("\nValor: %.2f", atual->valor);
            printf("\n");
            return atual;
            }
            atual = atual->prox;
        }
        printf("\nProduto nao encontrado");
        return NULL;
    }
}

Produto* excluir(Produto *lista, int codBusca){
    Produto *anterior = NULL;
    Produto *atual = lista;

    while(atual != NULL && atual->codigo != codBusca){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual != NULL){
        if(anterior != NULL){  
            anterior->prox = atual->prox;

        } else { 
            lista = atual->prox;
        }
        free(atual);
        printf("Excluido com sucesso");
        printf("\n");
    } else {
        printf("\nProduto nao encontrado");
    }
    return lista;
}

main(){

    int opcao, codBusca;
    Produto *lista = criarListaVazia();
    Produto *encontrado;

    do{
        printf("\nDigite 1 para adicionar um produto.");
        printf("\nDigite 2 para mostrar todos os produtos.");
        printf("\nDigite 3 para buscar um produto pelo codigo.");
        printf("\nDigite 4 para excluir um produto.");
        printf("\nDigite 0 para sair.\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1:
                lista = adicionar(lista);
            break;

            case 2:
                mostrar(lista);
            break;

            case 3:
                printf("\nDigite o codigo para busca: ");
                scanf("%d", &codBusca);
                encontrado = buscarProduto(lista, codBusca);
            break;

            case 4:
                printf("\nDigite o codigo para excluir: ");
                scanf("%d", &codBusca);
                lista = excluir(lista, codBusca);
            break;

            case 0:
            break;
        }
    }while(opcao != 0);

}