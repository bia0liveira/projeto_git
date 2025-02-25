#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int contador = 0;

void adicionarProduto() {
    if (contador >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("Digite o ID do produto: ");
    scanf("%d", &produtos[contador].id);
    getchar();

    printf("Digite o nome do produto: ");
    fgets(produtos[contador].nome, 50, stdin);
    strtok(produtos[contador].nome, "\n");

    printf("Digite o preco do produto: ");
    scanf("%f", &produtos[contador].preco);

    contador++;
    printf("Produto adicionado com sucesso!\n");
}

void listarProdutos() {
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de produtos:\n");
    for (int i = 0; i < contador; i++) {
        printf("ID: %d | Nome: %s | Preco: R$%.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
}

void buscarProduto() {
    int id;
    printf("Digite o ID do produto para buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado:\nID: %d | Nome: %s | Preco: R$%.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void removerProduto() {
    int id, i, encontrado = 0;
    printf("Digite o ID do produto para remover: ");
    scanf("%d", &id);

    for (i = 0; i < contador; i++) {
        if (produtos[i].id == id) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < contador - 1; j++) {
            produtos[j] = produtos[j + 1];
        }
        contador--;
        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\nSistema de Gerenciamento de Produtos\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto por ID\n");
        printf("4. Remover Produto\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                buscarProduto();
                break;
            case 4:
                removerProduto();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
