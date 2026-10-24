#include <stdio.h>

void mostrarVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int lerArquivo(int v[]) {
    int n= 0;
    FILE *arq = fopen("dados.txt", "r");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    while (n < 100 && fscanf(arq, "%d", &v[n]) == 1){
        n++;
    }

    fclose(arq);
    return n;
}

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
    }
}

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        int t = v[i];
        v[i] = v[menor];
        v[menor] = t;
    }
}

void merge(int v[], int ini, int meio, int fim) {
    int tmp[100];
    int i = ini, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
    }
    while (i <= meio) tmp[k++] = v[i++];
    while (j <= fim) tmp[k++] = v[j++];

    for (i = 0; i < k; i++) {
        v[ini + i] = tmp[i];
    }
}

void mergeSort(int v[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(v, ini, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, ini, meio, fim);
    }
}

void quickSort(int v[], int ini, int fim) {
    if (ini < fim) {
        int pivo = v[fim];
        int i = ini - 1;

        for (int j = ini; j < fim; j++) {
            if (v[j] < pivo) {
                i++;
                int t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
        }

        int t = v[i + 1];
        v[i + 1] = v[fim];
        v[fim] = t;

        int p = i + 1;
        quickSort(v, ini, p - 1);
        quickSort(v, p + 1, fim);
    }
}

void salvarArquivo(char nome[], int v[], int n) {
    FILE *saida = fopen(nome, "w");
    
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de gravação.\n", nome);
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(saida, "%d\n", v[i]);
    }

    fclose(saida);
}

void ordenar(int v[], int n) {
    int op;

    printf("Escolha o algoritmo:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Merge Sort\n");
    printf("5 - Quick Sort\n");
    printf("Opcao: ");
    scanf("%d", &op);

    switch (op) {
        case 1: printf("Bubble escolhido\n"); bubbleSort(v, n); break;
        case 2: printf("Insertion escolhido\n"); insertionSort(v, n); break;
        case 3: printf("Selection escolhido\n"); selectionSort(v, n); break;
        case 4: printf("Merge escolhido\n"); mergeSort(v, 0, n - 1); break;
        case 5: printf("Quick escolhido\n"); quickSort(v, 0, n - 1); break;
        default:
            printf("Opcao invalida.\n");
            return;
    }

    printf("Vetor ordenado: ");
    mostrarVetor(v, n);

    salvarArquivo("ordenado.txt", v, n);
    printf("Arquivo ordenado.txt criado!\n");
}

void alterarValor() {
    int v[100];
    int n = lerArquivo(v);
    int pos, novo;

    if (n == 0) return;

    printf("Valores atuais: ");
    mostrarVetor(v, n);

    printf("Posicao a alterar (1 a %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Posicao invalida.\n");
        return;
    }

    printf("Novo valor: ");
    scanf("%d", &novo);

    v[pos - 1] = novo;
    salvarArquivo("dados.txt", v, n);
    printf("dados.txt atualizado!\n");

    ordenar(v, n);
}

void criarArquivo() {
    int n, valor;
    FILE *arq = fopen("dados.txt", "w");

    if (arq == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    printf("Quantos valores deseja gravar (1 a 100)? ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Quantidade invalida.\n");
        fclose(arq);
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        fprintf(arq, "%d\n", valor);
    }

    fclose(arq);
    printf("Arquivo dados.txt criado!\n");
}

int main() {
    int vetor[100];
    int resp;

    int n = lerArquivo(vetor);
    if (n == 0) return 1;

    printf("Valores lidos do arquivo:\n");
    mostrarVetor(vetor, n);

    ordenar(vetor, n);

    printf("\nDeseja alterar algum valor? (1 - Sim, 0 - Nao): ");
    scanf("%d", &resp);
 
    while (resp == 1) {
        alterarValor();
 
        printf("\nDeseja alterar novamente? (1 - Sim, 0 - Nao): ");
        scanf("%d", &resp);
    }

    return 0;
    
}
