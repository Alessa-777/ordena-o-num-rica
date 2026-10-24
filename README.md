# ordena-o-num-rica
Programa em C que grava, lê e ordena valores de arquivos (Bubble, Insertion, Selection, Merge e Quick Sort) e permite alterar um valor e reordenar.

# Atividade Avaliativa 03

Programa em C que une algoritmos de ordenação (Bubble, Insertion, Selection, Merge e Quick Sort) com manipulação de arquivos.

## Arquivos do projeto

### Códigos

- **`main.c`**: cria o arquivo `dados.txt`. Pergunta quantos valores serão gravados e quais são, e grava um por linha.
- **`leitura.c`**: lê o `dados.txt`, deixa escolher o algoritmo de ordenação, ordena e salva o resultado no `ordenado.txt`. Também permite alterar um valor do arquivo e reordenar.

### Arquivos de dados

- **`dados.txt`**: valores numéricos digitados no começo, desordenados (entrada do programa). Quando um valor é alterado, o arquivo é atualizado com a mudança.
- **`ordenado.txt`**: os mesmos valores já ordenados em ordem crescente. É atualizado a cada ordenação, inclusive depois de testar a alteração de valores.

## Como compilar e executar

1. Criar o arquivo de dados:

        gcc main.c -o programa
        programa

2. Ordenar e alterar valores:

        gcc leitura.c -o leitura
        leitura

## Funcionamento

1. O `main.c` grava os valores no `dados.txt`.
2. O `leitura.c` lê os valores e mostra na tela.
3. O usuário escolhe o algoritmo (1 a 5), e o programa ordena e salva no `ordenado.txt`.
4. O programa pergunta se o usuário quer alterar um valor. Se sim, pede a posição e o novo valor, atualiza o `dados.txt`, pergunta o algoritmo de novo e reordena.
