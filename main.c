#include <stdio.h>
#include <string.h>
#include "estoque.h"

void exibir_menu(void) {
    printf("\n=== CONTROLE DE ESTOQUE ===\n");
    printf("1 - Listar produtos\n");
    printf("2 - Exibir total em estoque (com tributos)\n"); // Aluno 3
    printf("3 - Exibir total com desconto a vista\n");      // Aluno 4
    printf("4 - Exibir total a prazo (com juros)\n");        // Aluno 5
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void listar_produtos(Produto lista[], int total) {
    printf("\n--- Produtos Cadastrados ---\n");
    for (int i = 0; i < total; i++) {
        // Formatação integrada combinando id, codigo_barras (Aluno 1), categoria (Aluno 2) e quebra de linha
        printf("ID: %d | Cod: %s | Categoria: %s | Nome: %s | Preco: R$ %.2f | Qtd: %d\n", 
               lista[i].id, 
               lista[i].codigo_barras, 
               lista[i].categoria, 
               lista[i].nome, 
               lista[i].preco, 
               lista[i].quantidade);
    }
}

float calcular_total(Produto lista[], int total) {
    float soma = 0.0;
    for (int i = 0; i < total; i++) {
        // Correção do cálculo: multiplicação do preço unitário pela quantidade (Aluno 3)
        soma += lista[i].preco * lista[i].quantidade;
    }
    // Aplicação da TAXA_PADRAO atualizada sobre o valor total acumulado (Aluno 3)
    return soma + (soma * TAXA_PADRAO);
}

int main(void) {
    Produto estoque[MAX_ITENS]; // Utiliza MAX_ITENS = 50 (Aluno 1)
    int total_produtos = 2;

    // Inicialização do Produto 0
    estoque[0].id = 1;
    strcpy(estoque[0].codigo_barras, "7890001"); // Aluno 1
    strcpy(estoque[0].categoria, "Papelaria");    // Aluno 2
    strcpy(estoque[0].nome, "Caderno");
    estoque[0].preco = 15.50;
    estoque[0].quantidade = 10;

    // Inicialização do Produto 1
    estoque[1].id = 2;
    strcpy(estoque[1].codigo_barras, "7890002"); // Aluno 1
    strcpy(estoque[1].categoria, "Escritorio");   // Aluno 2
    strcpy(estoque[1].nome, "Caneta");
    estoque[1].preco = 3.00;
    estoque[1].quantidade = 50;

    int opcao = -1;
    while (opcao != 0) {
        exibir_menu();
        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                listar_produtos(estoque, total_produtos);
                break;
            case 2:
                printf("\nTotal em estoque: R$ %.2f\n", calcular_total(estoque, total_produtos));
                break;
            case 3: { // Aluno 4
                float total = calcular_total(estoque, total_produtos);
                float total_desconto = aplicar_desconto(total);
                printf("\nTotal a vista com desconto: R$ %.2f\n", total_desconto);
                break;
            }
            case 4: { // Aluno 5
                float total = calcular_total(estoque, total_produtos);
                float total_prazo = aplicar_juros(total);
                printf("\nTotal a prazo com juros: R$ %.2f\n", total_prazo);
                break;
            }
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }

    return 0;
}

// Função de desconto à vista de 5% (Aluno 4)
float aplicar_desconto(float total) {
    return total - (total * TAXA_DESCONTO);
}

// Função de juros a prazo de 8% (Aluno 5)
float aplicar_juros(float total) {
    return total + (total * TAXA_JUROS);
}