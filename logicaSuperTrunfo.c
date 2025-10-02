#include <stdio.h>
#include <string.h>

// Definição das constantes para os atributos (torna o código mais legível)
#define POPULACAO 1
#define AREA 2
#define PIB 3
#define TURISMO 4
#define DENSIDADE 5
#define PIBCAPITA 6
#define SUPERPODER 7

// Protótipos de funções (Opcional, mas boa prática para organizar)
int get_attribute_info(int escolha, const char **nome, float *val1, float *val2, int *menor_vence, 
                       unsigned long int pop1, float area_c1, float pib_c1, int tur1, float dens1, float pibcap1, float super1,
                       unsigned long int pop2, float area_c2, float pib_c2, int tur2, float dens2, float pibcap2, float super2);


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

    
    // --- Início do Cadastro
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
    // --- Fim do Cadastro ---


    // === CÁLCULOS ADICIONAIS ===
    densipop1 = (area1 > 0) ? (float) populacao1 / area1 : 0.0f;
    pibpercap1 = (populacao1 > 0) ? pib1 / populacao1 : 0.0f;
    densipop2 = (area2 > 0) ? (float) populacao2 / area2 : 0.0f;
    pibpercap2 = (populacao2 > 0) ? pib2 / populacao2 : 0.0f;

    superPoder1 = (float) populacao1 + area1 + pib1 + turismo1 + pibpercap1 + (densipop1 > 0 ? (1.0f / densipop1) : 0.0f);
    superPoder2 = (float) populacao2 + area2 + pib2 + turismo2 + pibpercap2 + (densipop2 > 0 ? (1.0f / densipop2) : 0.0f);

    // === EXIBIÇÃO DE DADOS ===
    
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
    // ... (restante da exibição)
    printf("  1. População: %lu\n", populacao2);
    printf("  2. Área: %.2f km²\n", area2);
    printf("  3. PIB: %.2f bi\n", pib2);
    printf("  4. Pontos Turísticos: %d\n", turismo2);
    printf("  5. Densidade Populacional: %.2f hab/km²\n", densipop2);
    printf("  6. PIB per Capita: %.2f reais\n", pibpercap2);
    printf("  7. Super Poder: %.2f\n", superPoder2);
    printf("------------------------------------\n");


    // === LÓGICA DE COMPARAÇÃO COM DOIS ATRIBUTOS ===
    
    int escolha1 = 0;
    int escolha2 = 0;
    
    // Variáveis para armazenar as informações do ATRIBUTO 1
    const char *nome1 = NULL;
    float val1_c1 = 0, val1_c2 = 0;
    int menor_vence1 = 0;
    
    // Variáveis para armazenar as informações do ATRIBUTO 2
    const char *nome2 = NULL;
    float val2_c1 = 0, val2_c2 = 0;
    int menor_vence2 = 0;
    
    // Pontuação de cada carta (1 ponto por rodada ganha)
    int pontos_c1 = 0;
    int pontos_c2 = 0;
    
    // --- ESCOLHA DO PRIMEIRO ATRIBUTO ---
    
    while (escolha1 < 1 || escolha1 > 7) {
        printf("\n\n=== Escolha o 1º Atributo de Comparação (1-7) ===\n");
        printf("1. População (Maior vence)\n2. Área (Maior vence)\n3. PIB (Maior vence)\n4. Pontos Turísticos (Maior vence)\n");
        printf("5. Densidade Demográfica (MENOR VENCE)\n6. PIB per Capita (Maior vence)\n7. Super Poder (Maior vence)\n");
        printf("Escolha: ");
        scanf("%d", &escolha1);
        if (escolha1 < 1 || escolha1 > 7) {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    
    // Carrega dados do 1º atributo
    if (!get_attribute_info(escolha1, &nome1, &val1_c1, &val1_c2, &menor_vence1,
                            populacao1, area1, pib1, turismo1, densipop1, pibpercap1, superPoder1,
                            populacao2, area2, pib2, turismo2, densipop2, pibpercap2, superPoder2)) {
        printf("Erro ao carregar o 1º atributo.\n");
        return 1;
    }


    // --- ESCOLHA DO SEGUNDO ATRIBUTO ---
    
    while (escolha2 < 1 || escolha2 > 7 || escolha2 == escolha1) {
        printf("\n\n=== Escolha o 2º Atributo de Comparação (Diferente do 1º) ===\n");
        
        // Imprime apenas as opções que não foram a ESCOLHA 1
        if (escolha1 != POPULACAO) printf("1. População (Maior vence)\n");
        if (escolha1 != AREA) printf("2. Área (Maior vence)\n");
        if (escolha1 != PIB) printf("3. PIB (Maior vence)\n");
        if (escolha1 != TURISMO) printf("4. Pontos Turísticos (Maior vence)\n");
        if (escolha1 != DENSIDADE) printf("5. Densidade Demográfica (MENOR VENCE)\n");
        if (escolha1 != PIBCAPITA) printf("6. PIB per Capita (Maior vence)\n");
        if (escolha1 != SUPERPODER) printf("7. Super Poder (Maior vence)\n");
        
        printf("Escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 < 1 || escolha2 > 7) {
            printf("Opção inválida. Tente novamente.\n");
        } else if (escolha2 == escolha1) {
            printf("O atributo '%s' já foi escolhido. Escolha outro.\n", nome1);
        }
    }
    
    // Carrega dados do 2º atributo
    if (!get_attribute_info(escolha2, &nome2, &val2_c1, &val2_c2, &menor_vence2,
                            populacao1, area1, pib1, turismo1, densipop1, pibpercap1, superPoder1,
                            populacao2, area2, pib2, turismo2, densipop2, pibpercap2, superPoder2)) {
        printf("Erro ao carregar o 2º atributo.\n");
        return 1;
    }
    
    
    // COMPARACÃO E PONTUAÇÃO ---
    printf("\n\n-------------------------------------------------------\n");
    printf("1ª RODADA: Comparando o atributo: %s\n", nome1);
    printf("C1 (%s): %.2f | C2 (%s): %.2f. Regra: %s vence.\n", 
           cidade1, val1_c1, cidade2, val1_c2, menor_vence1 ? "Menor" : "Maior");

    if (val1_c1 == val1_c2) {
        printf("Resultado: EMPATE na %s.\n", nome1);
    } else {
        // Operador Ternário para pontuação:
        int c1_vence = (menor_vence1) ? (val1_c1 < val1_c2) : (val1_c1 > val1_c2);
        
        if (c1_vence) {
            pontos_c1++;
            printf("Resultado: CARTA 1 (%s) vence a rodada! Pontos C1: %d\n", cidade1, pontos_c1);
        } else {
            pontos_c2++;
            printf("Resultado: CARTA 2 (%s) vence a rodada! Pontos C2: %d\n", cidade2, pontos_c2);
        }
    }

    // --- COMPARACÃO E PONTUAÇÃO ---
    printf("\n-------------------------------------------------------\n");
    printf("2ª RODADA: Comparando o atributo: %s\n", nome2);
    printf("C1 (%s): %.2f | C2 (%s): %.2f. Regra: %s vence.\n", 
           cidade1, val2_c1, cidade2, val2_c2, menor_vence2 ? "Menor" : "Maior");

    if (val2_c1 == val2_c2) {
        printf("Resultado: EMPATE na %s.\n", nome2);
    } else {
        // Operador Ternário para pontuação:
        int c1_vence = (menor_vence2) ? (val2_c1 < val2_c2) : (val2_c1 > val2_c2);
        
        if (c1_vence) {
            pontos_c1++;
            printf("Resultado: CARTA 1 (%s) vence a rodada! Pontos C1: %d\n", cidade1, pontos_c1);
        } else {
            pontos_c2++;
            printf("Resultado: CARTA 2 (%s) vence a rodada! Pontos C2: %d\n", cidade2, pontos_c2);
        }
    }
    
    // --- RESULTADO FINAL (SOMA E EMPATE) ---
    printf("\n=======================================================\n");
    printf("PLACARES FINAIS (Soma dos Atributos)\n");
    printf("Carta 1 (%s): %d ponto(s)\n", cidade1, pontos_c1);
    printf("Carta 2 (%s): %d ponto(s)\n", cidade2, pontos_c2);
    printf("-------------------------------------------------------\n");

    if (pontos_c1 > pontos_c2) {
        printf("VENCEDOR FINAL: CARTA 1 (%s)!\n", cidade1);
    } else if (pontos_c2 > pontos_c1) {
        printf("VENCEDOR FINAL: CARTA 2 (%s)!\n", cidade2);
    } else {
        printf("RESULTADO FINAL: EMPATE GERAL! (Placar %d x %d)\n", pontos_c1, pontos_c2);
    }
    printf("=======================================================\n");


    return 0;
}

// === FUNÇÃO AUXILIAR PARA CARREGAR DADOS DO ATRIBUTO ===
int get_attribute_info(int escolha, const char **nome, float *val1, float *val2, int *menor_vence, 
                       unsigned long int pop1, float area_c1, float pib_c1, int tur1, float dens1, float pibcap1, float super1,
                       unsigned long int pop2, float area_c2, float pib_c2, int tur2, float dens2, float pibcap2, float super2) 
{
    // Define a regra padrão (Maior vence)
    *menor_vence = 0; 
    
    switch (escolha) {
        case POPULACAO:
            *nome = "População";
            *val1 = (float)pop1;
            *val2 = (float)pop2;
            break;
        case AREA:
            *nome = "Área";
            *val1 = area_c1;
            *val2 = area_c2;
            break;
        case PIB:
            *nome = "PIB";
            *val1 = pib_c1;
            *val2 = pib_c2;
            break;
        case TURISMO:
            *nome = "Pontos Turísticos";
            *val1 = (float)tur1;
            *val2 = (float)tur2;
            break;
        case DENSIDADE:
            *nome = "Densidade Demográfica";
            *val1 = dens1;
            *val2 = dens2;
            *menor_vence = 1; // REGRA ESPECIAL: Menor vence
            break;
        case PIBCAPITA:
            *nome = "PIB per Capita";
            *val1 = pibcap1;
            *val2 = pibcap2;
            break;
        case SUPERPODER:
            *nome = "Super Poder";
            *val1 = super1;
            *val2 = super2;
            break;
        default:
            return 0; // Opção inválida
    }
    return 1; // Sucesso
}