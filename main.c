#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>

char squareMatrixColumns(FILE *f, FILE *g) {
    int n, **a, i, j;

    while (!feof(f)) {
        fscanf(f, "%d", &n);

        a = (int **) malloc(n * sizeof(int *));
        for (i = 0; i < n; i++) {
            a[i] = (int *) malloc(n * sizeof(int));
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                fscanf(f, "%d", &a[i][j]);
            }
        }

        fprintf(g, "%d", n);
        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                fprintf(g, " %d", a[i][j]);
            }
        }
        fprintf(g, "\n");

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


char writingArithmeticExpression(FILE *f) {
    char s[6];
    float a[6];
    char o[3];
    int i, k = 0;

    fscanf(f, "%s", s);
    fclose(f);

    for (i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[i] = s[i] - '0';
        } else {
            k++;
            o[k] = s[i];
        }
    }

    for (i = 0; i < k; i++) {
        switch (o[i]) {
            case '*':
                a[i * 2] = a[i * 2] * a[i * 2 + 1];
                a[i * 2 + 1] = a[i * 2];
                break;
            case '/':
                a[i * 2] = a[i * 2] / a[i * 2 + 1];
                a[i * 2 + 1] = a[i * 2];
                break;
        }
    }

    for (i = 0; i < k; i++) {
        switch (o[i]) {
            case '+':
                a[i * 2] = a[i * 2] + a[i * 2 + 1];
                a[i * 2 + 1] = a[i * 2];
                break;
            case '-':
                a[i * 2] = a[i * 2] - a[i * 2 + 1];
                a[i * 2 + 1] = a[i * 2];
                break;
        }
    }

    f = fopen("c:\\in.txt", "a");
    fprintf(f, "\n");
    fprintf(f, "%.4f", a[2]);
    fclose(f);
}


char sequenceOfCharacters(FILE *f4, FILE *f42) {
    int N = 32;
    char buffer[N];
    int count = 0;
    char *word = NULL;
    if ((f4 = fopen("text.txt", "r")) == NULL) {
        printf("Error read file");
        exit(0);
    }


    while (!feof(f4)) {
        count = 0;
        fgets(buffer, N, f4);

        for (int i = 0; i < strlen(buffer); i++) {

            if (buffer[i] != '\n') {
                count++;
            }
            if (buffer[i] == '\n') {


                word = (char *) malloc((count + 1) * sizeof(char));
                for (int j = 0; j < count + 1; j++) {
                    word[j] = buffer[(i - count) + j];

                }
                word[count] = '\0';

                char *ptr = strchr(word, (int) f42);
                if (ptr == NULL) {
                    puts(word);
                } else continue;

            }


        }
    }


    fclose(f4);
    fclose(f42);
}


char longestWordInString(FILE *f5, FILE *f52) {
    int MAXLINE = 1024;
    char line[MAXLINE];
    char* ptr;
    char* p;
    char* x;
    int len = 0;

    if ((f52 == NULL) || (f5 == NULL)) {
        printf("Error read file");
        return 1;
    }

    while (!feof(f5)) {
        len = 0;
        if ((ptr = fgets(line, MAXLINE, f5)) == NULL)
            break;

        p = strtok(ptr, " ,.");
        while (p != NULL) {
            if (len < strlen(p)) {
                len = strlen(p);
                x = p;
            }
            p = strtok(NULL, " ,.");
        }

        fputs(x, f52);
        if(x[len-1] != '\n')
            fputc('\n', f52);
    }
    fclose(f5);
    fclose(f52);
}

int main() {
    FILE *f1 = fopen("Строки матрицы.txt", "r");
    FILE *g1 = fopen("Столбцы матрицы.txt", "w");
    FILE *f2 = fopen("Вещественные числа.txt", "r");
    FILE *g2 = fopen("Вещественные числа с плавающей запятой.txt", "w");
    FILE *f3 = fopen("c:\\in.txt", "r");
    FILE *f4 = fopen("f4.txt", "r");
    FILE *f42 = fopen("данная последовательность символов.txt", "w");
    FILE *f5 = fopen("f5.txt", "r");
    FILE *f52 = fopen("самое длинное слово в строке.txt", "w");

    squareMatrixColumns(f1, g1);
    eachFloatingPointNumber(f2, g2);
    writingArithmeticExpression(f3);
    sequenceOfCharacters(f4, f42);
    longestWordInString(f5, f52);

    return 0;
}
