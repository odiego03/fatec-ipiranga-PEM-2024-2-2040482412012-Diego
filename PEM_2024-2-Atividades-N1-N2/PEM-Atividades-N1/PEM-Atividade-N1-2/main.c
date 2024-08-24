#include <stdio.h>
//Diego Silva De Oliveira
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
    do {
        printf("Qual é a %dª nota? ", i + 1);
        scanf("%f", &notas[i]);

        if (notas[i] < 0 || notas[i] > 10) {
            printf("Nota inválida. Por favor, insira uma nota entre 0 e 10.\n");
        }

    } while (notas[i] < 0 || notas[i] > 10);
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
