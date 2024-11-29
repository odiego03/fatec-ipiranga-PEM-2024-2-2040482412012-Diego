/*--------------------------------------------------------*

* Disciplina: Programaçao Estruturada e Modular *

*          Prof. Carlos Veríssimo                             *

*--------------------------------------------------------*

* Objetivo do Programa: ajustar programa que simula sistema de controle de estoque    *

* Data - 29/11/2024                                               * 

* Autor:  Diego Silva                                           *

*--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estrutura do produto
typedef struct {
    int ID;
    char nomeProd[50];
    int qntdEstoque;
    double valorProduto;
} Produto;

// Função para criar um produto
Produto* SetProduto(int ID, char* nomeProd, int qntdEstoque, double valorProduto) {
    Produto* prod = (Produto*)malloc(sizeof(Produto));
    if (prod != NULL) {
        prod->ID = ID;
        strcpy(prod->nomeProd, nomeProd);
        prod->qntdEstoque = qntdEstoque;
        prod->valorProduto = valorProduto;
    }
    return prod;
}


// Função para imprimir os detalhes de um produto
void imprimeProduto(Produto* prod) {
    if (prod != NULL) {
        printf("\n*--------------------------------*");
        printf("\n * Id: %d", prod->ID);
        printf("\n * Nome Produto: %s", prod->nomeProd);
        printf("\n * Quantidade Disponível: %d", prod->qntdEstoque);
        printf("\n * Preço/Valor: %.2f", prod->valorProduto);
        printf("\n*---------------------------------*");
    }
}


// Definição da função verificarID
bool verificarID(Produto* produtos[], int totalProdutos, int id) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            return true;
        }
    }
    return false;
}



// Função para incluir um novo produto
// Função para incluir um novo produto
void incluirProduto(Produto* produtos[], int* totalProdutos) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    
    // Entrada do ID com verificação de duplicidade
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    
    while (verificarID(produtos, *totalProdutos, id)) {
        printf("ID já existente. Digite outro ID: ");
        scanf("%d", &id);
    }
    novoProduto->ID = id;

    // Entrada e validação do nome/código
    char nome[100];
    printf("Digite o nome/código do produto: ");
    while (1) {
        scanf(" %[^\n]", nome);  // Usando " %[^\n]" para permitir espaços no nome
        if (strlen(nome) > 0) {  // Verifica se o nome não está vazio
            break;
        } else {
            printf("Nome não pode ser vazio. Digite o nome/código do produto: ");
        }
    }
    strcpy(novoProduto->nomeProd, nome);

    // Entrada de quantidade disponível com validação
    int quantidade;
    while (1) {
        printf("Digite a quantidade disponível: ");
        if (scanf("%d", &quantidade) != 1 || quantidade < 0) {
            printf("Quantidade inválida! Por favor, digite um número inteiro positivo.\n");
            while (getchar() != '\n');  // Limpa o buffer do teclado
        } else {
            novoProduto->qntdEstoque = quantidade;
            break;
        }
    }

    // Entrada e validação do preço
    double preco;
    while (1) {
        printf("Digite o preço do produto: ");
        if (scanf("%lf", &preco) != 1 || preco <= 0) {
            printf("Preço inválido! Por favor, digite um número positivo.\n");
            while (getchar() != '\n');  // Limpa o buffer do teclado
        } else {
            novoProduto->valorProduto = preco;
            break;
        }
    }

    // Adiciona o novo produto à lista
    produtos[*totalProdutos] = novoProduto;
    (*totalProdutos)++;

    printf("Produto cadastrado com sucesso!\n");
}




// Função para alterar um produto existente por ID
void alterarProduto(Produto* produtos[], int totalProdutos) {
    int id, novaQuantidade;
    double novoPreco;
    char novoNome[50];
    bool encontrado = false;

    printf("Digite o ID do produto que deseja alterar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]s", novoNome);
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &novaQuantidade);
            printf("Digite o novo valor do produto: ");
            scanf("%lf", &novoPreco);

            strcpy(produtos[i]->nomeProd, novoNome);
            produtos[i]->qntdEstoque = novaQuantidade;
            produtos[i]->valorProduto = novoPreco;
            printf("Produto alterado com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}



// Função para consultar um produto por Id
void consultarProdutoId(Produto* produtos[], int totalProdutos) {
    int id;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja consultar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            imprimeProduto(produtos[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para consultar um produto por codigo/nome
void consultarProdutoCodigo(Produto* produtos[], int totalProdutos) {
    char nome[50];
    bool encontrado = false;

    printf("Digite o nome/código do produto que deseja consultar: ");
    scanf(" %[^\n]s", nome); // Lê o nome com espaços

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i]->nomeProd, nome) == 0) { // Comparação por nome
            imprimeProduto(produtos[i]);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto com nome/código '%s' não encontrado.\n", nome);
    }
}

// Função para vender um produto
void venderProduto(Produto* produtos[], int* totalProdutos) {
    int id, quantidadeVendida;
    bool encontrado = false;

    // Solicita o ID do produto a ser vendido
    printf("Digite o ID do produto que deseja vender: ");
    scanf("%d", &id);

    // Solicita a quantidade a ser vendida
    printf("Digite a quantidade que deseja vender: ");
    scanf("%d", &quantidadeVendida);

    // Busca o produto pelo ID e verifica a quantidade disponível
    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            if (produtos[i]->qntdEstoque >= quantidadeVendida) {
                // Subtrai a quantidade vendida do estoque
                produtos[i]->qntdEstoque -= quantidadeVendida;
                printf("Venda realizada com sucesso! %d unidades de %s vendidas.\n", quantidadeVendida, produtos[i]->nomeProd);
                printf("Estoque restante: %d unidades.\n", produtos[i]->qntdEstoque);
            } else {
                printf("Erro: Não há estoque suficiente para a venda. Estoque disponível: %d\n", produtos[i]->qntdEstoque);
            }
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}


// Função para excluir um produto por ID
void excluirProduto(Produto* produtos[], int* totalProdutos) {
    int id;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            free(produtos[i]); // libera memória do produto
            for (int j = i; j < *totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*totalProdutos)--;
            printf("Produto excluído com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para imprimir todos os produtos
void imprimirDadosProd(Produto* produtos[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        for (int i = 0; i < totalProdutos; i++) {
            imprimeProduto(produtos[i]);
        }
    }
}

// Função para aplicar desconto ao produto
void aplicarDesconto(Produto* produtos[], int totalProdutos) {
    int id;
    double desconto;
    bool encontrado = false;

    printf("Digite o ID do produto para aplicar o desconto: ");
    scanf("%d", &id);
    printf("Digite o percentual de desconto (exemplo, para 10%%, digite 10): ");
    scanf("%lf", &desconto);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            produtos[i]->valorProduto *= (1 - desconto / 100.0);
            printf("Desconto aplicado com sucesso! Novo valor: %.2f\n", produtos[i]->valorProduto);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para exibir o menu
void exibirMenu() {
    printf("\nMenu de opções:\n");
    printf("1 - Incluir produto\n");
    printf("2 - Alterar produto por ID\n");
    printf("3 - Consultar produto por Código\n");
    printf("4 - Consultar produto por ID\n");
    printf("5 - Excluir produto\n");
    printf("6 - Imprimir todos os produtos\n");
    printf("7 - Aplicar desconto em produto\n");
    printf("8 - Verder produto\n");
    printf("9 - Sair\n");
    printf("Escolha uma opção: ");
}

// Função para obter a opção do menu
int obterOpcaoMenu() {
    int opcao;
    exibirMenu();
    scanf("%d", &opcao);
    return opcao;
}

// Função que gerencia o loop do menu
void executarMenu(Produto* produtos[], int* totalProdutos) {
    int opcao;
    while (1) {
        opcao = obterOpcaoMenu();  // Exibe o menu e recebe a opção

        switch (opcao) {
            case 1:
                incluirProduto(produtos, totalProdutos);
                break;
            case 2:
                alterarProduto(produtos, *totalProdutos);
                break;
            case 3:
                consultarProdutoCodigo(produtos, *totalProdutos);
                break;
            case 4:
                consultarProdutoId(produtos, *totalProdutos);
                break;
            case 5:
                excluirProduto(produtos, totalProdutos);
                break;
            case 6:
                imprimirDadosProd(produtos, *totalProdutos);
                break;
            case 7:
                aplicarDesconto(produtos, *totalProdutos);
                break;
            case 8:
                venderProduto(produtos, totalProdutos);
                break;
            case 9:
                printf("Saindo...\n");
                // Libera memória alocada
                for (int i = 0; i < *totalProdutos; i++) {
                    free(produtos[i]);
                }
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}


int main() {
    Produto* produtos[100]; 
    int totalProdutos = 0;  

    executarMenu(produtos, &totalProdutos); // Chama a função que executa o menu
    return 0;
        }