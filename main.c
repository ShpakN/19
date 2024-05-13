#include <stdio.h>
#include <stdlib.h>

char squareMatrixColumns(FILE *f, FILE *g) {
    int n, **a, i, j;

    // Чтение матриц, и запись их по столбцам в новый файл

    while (!feof(f)) {
        fscanf(f, "%d", &n);

        // Выделение памяти
        a = (int **) malloc(n * sizeof(int *));
        for (i = 0; i < n; i++) {
            a[i] = (int *) malloc(n * sizeof(int));
        }

        // Чтение матрицы
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fscanf(f, "%d", &a[i][j]);
            }
        }

        // Запись транспонированой матрицы
        fprintf(g, "%d", n);
        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                fprintf(g, " %d", a[i][j]);
            }
        }
        fprintf(g, "\n");

        // Освобождение памяти
        for (i = 0; i < n; i++) {
            free(a[i]);
        }
        free(a);
    }

    fclose(f);
    fclose(g);
    printf("Матрицы переписаны в файл столбцы.txt\n");
}




int main() {
    FILE *f;
    FILE *g;

    f = fopen("Строки матрицы.txt", "r");
    g = fopen("Столбцы матрицы.txt", "w");

    squareMatrixColumns(f, g);


    return 0;
}
