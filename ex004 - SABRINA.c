#include <stdio.h>

void converterParaBase(float numeroDecimal, int base) {
    // Array de caracteres para representar valores maiores que 9 (A-F)
    char caracteres[] = "0123456789ABCDEF";
    char resultado[64]; // Buffer para armazenar o resultado da conversão
    int indice = 0; // Índice para o buffer

    // Tratamento para o caso de número 0
    if (numeroDecimal == 0.0) {
        printf("0");
        return;
    }

    // Conversão
    while (numeroDecimal > 0.0) {
        int resto = (int)(numeroDecimal * base) % base; // Obtém o resto da divisão
        resultado[indice++] = caracteres[resto]; // Armazena o caractere correspondente
        numeroDecimal = (numeroDecimal * base) - resto; // Atualiza o número decimal
    }

    // Imprime o resultado na ordem correta (reversa)
    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", resultado[i]);
    }
}

int main() {
    float numeroDecimal;
    int base;

    // Solicita o número decimal
    printf("Digite um número decimal: ");
    scanf("%f", &numeroDecimal);

    // Solicita a base de conversão
    printf("Digite a base de conversão (entre 2 e 16): ");
    scanf("%d", &base);

    // Verifica se a base está dentro do intervalo permitido
    if (base < 2 || base > 16) {
        printf("Base inválida. Deve estar entre 2 e 16.\n");
        return 1; // Código de erro
    }

    // Chama a função de conversão
    printf("Número convertido para a base %d: ", base);
    converterParaBase(numeroDecimal, base);
    printf("\n");

    return 0;
}