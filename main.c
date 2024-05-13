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


double doubleFixedPoint(char *S) {
    double sg = 1, n = 0, f = 0, p = 0.1;
    int i = 0, flgp = 0;
    char c;

    if (S[i] == '+')
        i++;
    else if (S[i] == '-') {
        sg = -1.0;
        i++;
    }

    while (S[i] != 0) {
        c = S[i++];

        if (c == '.')
            flgp = -1;
        else {
            if (flgp == 0)
                n = n * 10.0 + (double) (c - '0');
            else {
                f = f + (double) (c - '0') * p;
                p = p * 0.1;
            }
        }
    }
    return sg * (n + f);
}


char eachFloatingPointNumber(FILE *f1, FILE *g1) {
    char Buf[100], c;
    int i, ptrB;
    double z;

    if (f1 == NULL) {
        return -1;
    }
    if (g1 == NULL) {
        return -1;
    }
    for (i = 0; i < 100; i++) Buf[i] = 0;
    ptrB = 0;

    while (1) {
        c = getc(f1);
        if (c == EOF) break;

        if ((c == ' ') || (c == 10)) {
            if (ptrB > 0) {
                z = doubleFixedPoint(Buf);
                fprintf(g1, "%E\n", z);
                for (i = 0; i < 100; i++) Buf[i] = 0;
                ptrB = 0;
            }
        } else
            Buf[ptrB++] = c;
    }

    if (ptrB > 0) {
        z = doubleFixedPoint(Buf);
        fprintf(g1, "%E\n", z);
    }

    fclose(f1);
    fclose(g1);

    printf("OK!\n");
}

int main() {
    FILE *f;
    FILE *g;
    FILE *f1;
    FILE *g1;

    f = fopen("Строки матрицы.txt", "r");
    g = fopen("Столбцы матрицы.txt", "w");
    f1 = fopen("Вещественные числа.txt", "r");
    g1 = fopen("Вещественные числа с плавающей запятой.txt", "w");

    squareMatrixColumns(f, g);
    eachFloatingPointNumber(f1, g1);

    return 0;
}
