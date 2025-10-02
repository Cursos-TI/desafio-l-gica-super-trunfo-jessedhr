#include <stdio.h>
#include <string.h>

int main() {

    // Variáveis da primeira carta (Cidade 1)
    char estado1[3];
    char cidade1[50];
    unsigned long int populacao1 = 0; 
    float area1 = 0;
    float pib1 = 0;
    int turismo1 = 0;
    float densipop1;
    float pibpercap1;
    float superPoder1;

    // Variáveis da segunda carta (Cidade 2)
    char estado2[3];
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
    printf("Insira o estado (UF): ");
    scanf("%2s", estado1);
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
    printf("Insira o estado (UF): ");
    scanf("%2s", estado2);
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

    // Cálculos Adicionais com proteção contra divisão por zero
    densipop1 = (area1 > 0) ? (float) populacao1 / area1 : 0.0f;
    pibpercap1 = (populacao1 > 0) ? pib1 / populacao1 : 0.0f;
    
    densipop2 = (area2 > 0) ? (float) populacao2 / area2 : 0.0f;
    pibpercap2 = (populacao2 > 0) ? pib2 / populacao2 : 0.0f;

    // Cálculo do Super Poder
    superPoder1 = (float) populacao1 + area1 + pib1 + turismo1 + pibpercap1 + (densipop1 > 0 ? (1.0f / densipop1) : 0.0f);
    superPoder2 = (float) populacao2 + area2 + pib2 + turismo2 + pibpercap2 + (densipop2 > 0 ? (1.0f / densipop2) : 0.0f);

    // Exibição dos Dados Coletados
    printf("\n\n=== Resumo das Cartas Cadastradas ===\n");
    printf("------------------------------------\n");
    
    printf("=== Carta 1: %s (%s) ===\n", cidade1, estado1);
    printf("  1. População: %lu\n", populacao1);
    printf("  2. Área: %.2f km²\n", area1);
    printf("  3. PIB: %.2f bi\n", pib1);
    printf("  4. Pontos Turísticos: %d\n", turismo1);
    printf("  5. Densidade Populacional: %.2f hab/km²\n", densipop1);
    printf("  6. PIB per Capita: %.2f reais\n", pibpercap1);
    printf("  7. Super Poder: %.2f\n", superPoder1);
    
    printf("\n=== Carta 2: %s (%s) ===\n", cidade2, estado2);
    printf("  1. População: %lu\n", populacao2);
    printf("  2. Área: %.2f km²\n", area2);
    printf("  3. PIB: %.2f bi\n", pib2);
    printf("  4. Pontos Turísticos: %d\n", turismo2);
    printf("  5. Densidade Populacional: %.2f hab/km²\n", densipop2);
    printf("  6. PIB per Capita: %.2f reais\n", pibpercap2);
    printf("  7. Super Poder: %.2f\n", superPoder2);
    printf("------------------------------------\n");

    // Lógica de comparação
    
    int escolha;
    const char *atributo_comparado = "";
    float valor1 = 0;
    float valor2 = 0;
    int menor_vence = 0;

    printf("\n\n=== Escolha o Atributo de Comparação ===\n");
    printf("1. População (Maior vence)\n");
    printf("2. Área (Maior vence)\n");
    printf("3. PIB (Maior vence)\n");
    printf("4. Pontos Turísticos (Maior vence)\n");
    printf("5. Densidade Demográfica (MENOR VENCE)\n"); // Regra especial
    printf("6. PIB per Capita (Maior vence)\n");
    printf("7. Super Poder (Maior vence)\n");
    printf("Escolha (1-7): ");
    
    
    if (scanf("%d", &escolha) != 1) {
        printf("Entrada inválida. Encerrando.\n");
        return 1;
    }

    switch (escolha) {
        case 1:
            atributo_comparado = "População";
            valor1 = (float)populacao1;
            valor2 = (float)populacao2;
            menor_vence = 0;
            break;
        case 2:
            atributo_comparado = "Área";
            valor1 = area1;
            valor2 = area2;
            menor_vence = 0;
            break;
        case 3:
            atributo_comparado = "PIB";
            valor1 = pib1;
            valor2 = pib2;
            menor_vence = 0;
            break;
        case 4:
            atributo_comparado = "Pontos Turísticos";
            valor1 = (float)turismo1;
            valor2 = (float)turismo2;
            menor_vence = 0;
            break;
        case 5:
            atributo_comparado = "Densidade Demográfica";
            valor1 = densipop1;
            valor2 = densipop2;
            menor_vence = 1; // REGRA: Menor valor vence
            break;
        case 6:
            atributo_comparado = "PIB per Capita";
            valor1 = pibpercap1;
            valor2 = pibpercap2;
            menor_vence = 0;
            break;
        case 7:
            atributo_comparado = "Super Poder";
            valor1 = superPoder1;
            valor2 = superPoder2;
            menor_vence = 0;
            break;
        default:
            printf("Opção inválida! O programa será encerrado.\n");
            return 0;
    }

    // Exibição dos valores para a comparação
    printf("\n\n=== Comparação de Cartas ===\n");
    printf("Atributo Escolhido: %s (%s vence)\n\n", 
           atributo_comparado, 
           menor_vence ? "Menor valor" : "Maior valor");
    

    if (escolha == 1) { 
        printf("Carta 1 - %s (%s): %lu\n", cidade1, estado1, (unsigned long int)valor1);
        printf("Carta 2 - %s (%s): %lu\n", cidade2, estado2, (unsigned long int)valor2);
    } else if (escolha == 4) { 
        printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, (int)valor1);
        printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, (int)valor2);
    } else { 
        printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor1);
        printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor2);
    }

    printf("\nResultado: ");

    // Lógica de Decisão Unificada (Implementando a regra do menor/maior)

    if (valor1 == valor2) {
        printf("EMPATE! Os valores de %s são iguais.\n", atributo_comparado);
    } else {

        if (menor_vence) {
            if (valor1 < valor2) {
                printf("Carta 1 (%s) VENCEU! (%.2f é menor que %.2f)\n", cidade1, valor1, valor2);
            } else {
                printf("Carta 2 (%s) VENCEU! (%.2f é menor que %.2f)\n", cidade2, valor2, valor1);
            }
        } 

        else { 
            if (valor1 > valor2) {
                printf("Carta 1 (%s) VENCEU! (%.2f é maior que %.2f)\n", cidade1, valor1, valor2);
            } else {
                printf("Carta 2 (%s) VENCEU! (%.2f é maior que %.2f)\n", cidade2, valor2, valor1);
            }
        }
    }

    return 0;
}