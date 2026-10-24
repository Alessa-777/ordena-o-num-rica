#include <stdio.h>

int main() {
    int n, valor;
    FILE *arq = fopen("dados.txt", "w");

    if (arq == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    printf("Quantos valores deseja gravar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        fprintf(arq, "%d\n", valor);
    }

    fclose(arq);
    printf("Arquivo dados.txt criado!\n");
    
    return 0;
}
