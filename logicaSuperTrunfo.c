#include <stdio.h>
#include <string.h>

int main() {

    // Variáveis da primeira carta (Cidade 1)
    char estado1;
    char codigo1[3];
    char cidade1[50];
    unsigned long int populacao1 = 0; 
    float area1 = 0;
    float pib1 = 0;
    int turismo1 = 0;
    float densipop1;
    float pibpercap1;
    float superPoder1;

    // Variáveis da segunda carta (Cidade 2)
    char estado2;
    char codigo2[3];
    char cidade2[50];
    unsigned long int populacao2 = 0;
    float area2 = 0;
    float pib2 = 0;
    int turismo2 = 0;
    float densipop2;
    float pibpercap2;
    float superPoder2;

    // Cadastro Carta 1
    printf("Cadastro da Carta 1\n\n");
    printf("Insira a letra do estado (de A a H): ");
    scanf(" %c", &estado1);
    printf("Insira o código da cidade (de 01 a 04): ");
    scanf("%2s", codigo1);
    printf("Insira o nome da cidade: ");
    scanf(" %49[^\n]", cidade1);
    printf("Insira a populacao total de habitantes: ");
    scanf("%lu", &populacao1);
    printf("Insira tamanho da area da cidade (km²): ");
    scanf("%f", &area1);
    printf("Insira o PIB da cidade (bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Insira a quantidade de pontos turisticos: ");
    scanf("%d", &turismo1);

    // Cadastro Carta 2
    printf("\nCadastro da Carta 2\n\n");
    printf("Insira a letra do estado (de A a H): ");
    scanf(" %c", &estado2);
    printf("Insira o código da cidade (de 01 a 04): ");
    scanf("%2s", codigo2);
    printf("Insira o nome da cidade: ");
    scanf(" %49[^\n]", cidade2);
    printf("Insira a populacao total de habitantes: ");
    scanf("%lu", &populacao2);
    printf("Insira tamanho da area da cidade (km²): ");
    scanf("%f", &area2);
    printf("Insira o PIB da cidade (bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Insira a quantidade de pontos turisticos: ");
    scanf("%d", &turismo2);

    // Cálculos Adicionais - Adicionando verificação para evitar divisão por zero, caso Área ou População seja 0.

    if (area1 > 0) {
        densipop1 = (float) populacao1 / area1;
    } else {
        densipop1 = 0.0f;
    }
    
    if (populacao1 > 0) {
        pibpercap1 = (float) pib1 / populacao1;
    } else {
        pibpercap1 = 0.0f;
    }

    if (area2 > 0) {
        densipop2 = (float) populacao2 / area2;
    } else {
        densipop2 = 0.0f;
    }

    if (populacao2 > 0) {
        pibpercap2 = (float) pib2 / populacao2;
    } else {
        pibpercap2 = 0.0f;
    }

    // Cálculo do Super Poder
    superPoder1 = (float) populacao1 + area1 + pib1 + turismo1 + pibpercap1 + (densipop1 > 0 ? (1.0f / densipop1) : 0.0f);
    superPoder2 = (float) populacao2 + area2 + pib2 + turismo2 + pibpercap2 + (densipop2 > 0 ? (1.0f / densipop2) : 0.0f);


    // Exibição dos Dados Coletados
    
    printf("\n\n=== Resumo das Cartas Cadastradas ===\n");
    printf("------------------------------------\n");
    
    printf("=== Carta 1: %s ===\n", cidade1);
    printf("  População: %lu\n", populacao1);
    printf("  Área: %.2f km²\n", area1);
    printf("  PIB: %.2f bi\n", pib1);
    printf("  Pontos Turísticos: %d\n", turismo1);
    printf("  Densidade Populacional: %.2f hab/km²\n", densipop1);
    printf("  PIB per Capita: %.2f reais\n", pibpercap1);
    
    printf("\n=== Carta 2: %s ===\n", cidade2);
    printf("  População: %lu\n", populacao2);
    printf("  Área: %.2f km²\n", area2);
    printf("  PIB: %.2f bi\n", pib2);
    printf("  Pontos Turísticos: %d\n", turismo2);
    printf("  Densidade Populacional: %.2f hab/km²\n", densipop2);
    printf("  PIB per Capita: %.2f reais\n", pibpercap2);
    printf("------------------------------------\n");

    // Lógica da Comparação
    
    // Escolha: POPULAÇÃO (Maior valor vence)
    
    const char *atributo_comparado = "População";
    
    // Exibição dos valores para a comparação
    
    printf("\n\n=== Comparação de Cartas ===\n");
    printf("Atributo Escolhido: %s (Maior valor vence)\n\n", atributo_comparado);
    printf("Carta 1 - %s (%c): %lu\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%c): %lu\n", cidade2, estado2, populacao2);
    
    printf("\nResultado: ");

    // Estrutura de Decisão

    if (populacao1 > populacao2) {
        printf("Carta 1 (%s) VENCEU!\n", cidade1);
    } 
    else if (populacao2 > populacao1) {
        printf("Carta 2 (%s) VENCEU!\n", cidade2);
    } 
    else {
        printf("EMPATE! Os valores de %s são iguais.\n", atributo_comparado);
    }

    return 0;
}