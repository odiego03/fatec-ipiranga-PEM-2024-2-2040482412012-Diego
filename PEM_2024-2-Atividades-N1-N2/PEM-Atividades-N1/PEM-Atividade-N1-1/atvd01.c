// Criador do Código: Diego Silva De Oliveira
#include <stdio.h>

int main() {
    int qntn;

    while (1) {
        printf("Qual é a quantidade de notas da matéria (0 para encerrar): ");
        scanf("%d", &qntn);

        if (qntn == 0) { 
            printf("Encerrando programa...\n");
            return 0;
        }

        if (qntn < 3) {
            printf("Erro: O número de notas deve ser no mínimo 3 para remover a maior e a menor.\n");
            printf("----------------------------------------------------------------------------\n");
        } else {
            float notas[qntn];
            float soma = 0.0;

            for (int i = 0; i < qntn; i++) {
                printf("Qual é a %dª nota? ", i + 1);
                scanf("%f", &notas[i]);
            }

            float nmaior = notas[0];
            float nmenor = notas[0];

            printf("As notas foram: ");
            for (int i = 0; i < qntn; i++) {
                printf("%.2f ", notas[i]);
            }
            printf("\n");

            for (int i = 0; i < qntn; i++) {
                if (notas[i] > nmaior) {
                    nmaior = notas[i];
                }
                if (notas[i] < nmenor) {
                    nmenor = notas[i];
                }
                soma += notas[i];
            }

            soma = soma - nmenor - nmaior;

            printf("A média das notas excluindo a maior e a menor é: %.2f\n", soma);
            printf("----------------------------------------------------------------------------\n");
        }
    }
}
