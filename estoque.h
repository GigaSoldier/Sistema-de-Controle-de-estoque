#ifndef ESTOQUE_H
#define ESTOQUE_H

// Constantes integradas
#define MAX_ITENS 50            // Aluno 1
#define ESTOQUE_MINIMO 5        // Aluno 2
#define TAXA_PADRAO 0.10        // Aluno 3 (atualizado de 0.05 para 0.10)
#define TAXA_DESCONTO 0.05      // Aluno 4
#define TAXA_JUROS 0.08         // Aluno 5

// Estrutura do Produto com novos campos de Aluno 1 e Aluno 2
typedef struct {
    int id;
    char codigo_barras[20];     // Aluno 1
    char categoria[20];         // Aluno 2
    char nome[30];
    float preco;
    int quantidade;
} Produto;

// Protótipos das Funções
void exibir_menu(void);
void listar_produtos(Produto lista[], int total);
float calcular_total(Produto lista[], int total);
float aplicar_desconto(float total);  // Aluno 4
float aplicar_juros(float total);     // Aluno 5

#endif