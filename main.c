#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>
#include <conio.h>

#define nq 3

char squareMatrixColumns(FILE *f, FILE *g) {
    int n, **a, i, j;

    while (!feof(f)) {

        a = (int **) malloc(n * sizeof(int *));
        for (i = 0; i < n; i++) {
            a[i] = (int *) malloc(n * sizeof(int));
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
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
    char *ptr;
    char *p;
    char *x;
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
        if (x[len - 1] != '\n')
            fputc('\n', f52);
    }
    fclose(f5);
    fclose(f52);
}


char structuresInDescendingOfDegrees(FILE *f6, FILE *f62) {
    int N = 32;
    char buffer[N];
    int count = 0;
    char *word = NULL;
    if ((f6 = fopen("text.txt", "r")) == NULL) {
        printf("Error read file");
        exit(0);
    }


    while (!feof(f6)) {
        count = 0;
        fgets(buffer, N, f6);

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

                char *ptr = strchr(word, (int) f62);
                if (ptr == NULL) {
                    (word)--;
                } else continue;

            }


        }
    }


    fclose(f6);
    fclose(f62);
}


char orderPositiveNegativeNumbers(FILE *f7) {
    long n, i;
    char *str, *buf;
    double *mass = (double *) malloc(sizeof(double));

    if (!(f7 = fopen("data.txt", "rb+")))
        printf("ERROR ACCESS to READ [data.txt]\r\n");
    else {
        fseek(f7, 0, SEEK_END);
        n = ftell(f7);
        fseek(f7, 0, SEEK_SET);

        if (!(str = (char *) malloc(n + 1)))
            printf("ERROR ALLOCATION MEMORY\r\n");
        else {
            fread(str, 1, n, f7);
            fclose(f7);
            str[n] = '\0';
            n = 0;
            buf = strtok(str, " ,\n");

            while (buf) {
                mass[n] = atof(buf);
                buf = strtok(NULL, " ,\n");
                mass = (double *) realloc((void *) mass, (1 + (n = n + 1)) * sizeof(double));
            }

            free(str);
            if (!(f7 = fopen("data.txt", "w")))
                printf("ERROR ACCESS to WRITE [data.txt]\r\n");
            else {
                for (i = 0; i < n; i++) {

                    if (mass[i] < 0) {
                        fprintf(f7, "%.3f ", mass[i]);
                        printf("%.3f ", mass[i]);
                    }
                }

                for (i = 0; i < n; i++) {

                    if (0 <= mass[i]) {
                        fprintf(f7, "%.3f ", mass[i]);
                        printf("%.3f ", mass[i]);
                    }
                }

                printf("\r\nWRITING DATA IN [data.txt] DONE\r\n");
            }
        }

        fclose(f7);
    }

    printf("Press any key to continue\r\n");

    getch();
}

typedef struct {
    int data[nq][nq];
} matrix;

char binaryFileSquareMatrices(FILE *f8) {
    matrix a;
    int m = 4;
    int n = 3;
    int i, j, k, t;
    for (k = 0; k < m; k++) {
        printf("Матрица %d\n", k + 1);
        for (i = 0; i < n; i++) {
        }
        fwrite(&a, sizeof(matrix), 1, f8);
    }

    rewind(f8);

    for (k = 0; k < m; k++) {
        fread(&a, sizeof(matrix), 1, f8);
        printf("Матрица %d\n", k + 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%4d", a.data[i][j]);
            }
            printf("\n");
        }

        t = 0;
        i = 1;

        while (i < n && t == 0) {
            j = 0;
            while (j < i && t == 0) {
                if (a.data[i][j] != a.data[j][i]) {
                    t = 1;
                }
                j++;
            }
            if (t == 0) {
                i++;
            }
            if (t == 1) {
                for (i = 1; i < n; i++) {
                    for (j = 0; j < i; j++) {
                        t = a.data[i][j];
                        a.data[i][j] = a.data[j][i];
                        a.data[j][i] = t;
                    }
                }
                fseek(f8, k * sizeof(matrix), SEEK_SET);
                fwrite(&a, sizeof(matrix), 1, f8);
            }
        }
    }

    rewind(f8);

    for (k = 0; k < m; k++) {
        fread(&a, sizeof(matrix), 1, f8);
        printf("Матрица %d\n", k + 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%4d", a.data[i][j]);
            }
            printf("\n");
        }
    }

    fclose(f8);

    return 0;
}


char informationAboutTeamMembers(FILE *f9, int n) {
    int N = 32;
    char buffer[N];
    int count = 0;
    char *word = NULL;
    if ((f9 = fopen("Информация о спортсменах.txt", "r")) == NULL) {
        printf("Error read file");
        exit(0);
    }


    while (!feof(f9)) {
        count = 0;
        fgets(buffer, N, f9);

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

                char *ptr = strchr(word, n);
                if (ptr != NULL) {
                    (word)++;
                } else continue;

            }


        }
    }


    fclose(f9);
}

struct base {
    char nameid[4];
    int k;
};

char releasedGoodsInAccordance(FILE *f10, FILE *f12, FILE *f13) {
    struct base s, d;
    int i, j, l, n, m;
    j = 0;
    l = 0;

    for (i = 0; i < n; i++) {
        fseek(f10, l * sizeof(struct base), SEEK_SET);
        fwrite(&s, sizeof(struct base), 1, f10);
        l++;
    }
    fclose(f10);

    for (i = 0; i < m; i++) {
        fseek(f12, j * sizeof(struct base), SEEK_SET);
        fwrite(&d, sizeof(struct base), 1, f12);
        j++;
    }
    fclose(f12);

    j = 0;
    l = 0;

    while (fread(&s, sizeof(struct base), 1, f10) == 1) {
        l++;
        while (fread(&d, sizeof(struct base), 1, f12) == 1) {
            j++;
            if (strcmp(s.nameid, d.nameid) == 0) {
                if (s.k != d.k) {
                    f13 = fopen("общая стоимость и количество.txt", "wb");
                    d.k = d.k - s.k;
                    fwrite(&d, sizeof(struct base), 1, f13);
                    fclose(f13);
                    fseek(f12, j * sizeof(struct base), SEEK_SET);
                } else {
                    fseek(f12, j * sizeof(struct base), SEEK_SET);
                }
            } else {
                f13 = fopen("общая стоимость и количество.txt", "wb");
                fwrite(&d, sizeof(struct base), 1, f13);
                fclose(f13);
                fseek(f12, j * sizeof(struct base), SEEK_SET);
            }
            fseek(f10, l * sizeof(struct base), SEEK_SET);
        }
    }

    fclose(f12);
    fclose(f10);

    f13 = fopen("общая стоимость и количество.txt", "rb");

    for (i = 0; i < m; i++) {
        fread(&d, sizeof(struct base), 1, f13);
        printf("%s\n", d.nameid);
        printf("%d\n", d.k);
    }

    fclose(f13);

    return 0;
}

void test_squareMatrixColumns() {
    FILE *f1 = fopen("Строки матрицы.txt", "r");
    FILE *g1 = fopen("Столбцы матрицы.txt", "w");
    squareMatrixColumns(f1, g1);
}


void test_eachFloatingPointNumber() {
    FILE *f2 = fopen("Вещественные числа.txt", "r");
    FILE *g2 = fopen("Вещественные числа с плавающей запятой.txt", "w");
    eachFloatingPointNumber(f2, g2);
}

void test_writingArithmeticExpression() {
    FILE *f3 = fopen("c:\\in.txt", "r");
    writingArithmeticExpression(f3);
}

void test_sequenceOfCharacters() {
    FILE *f4 = fopen("f4.txt", "r");
    FILE *f42 = fopen("данная последовательность символов.txt", "w");
    sequenceOfCharacters(f4, f42);
}


void test_longestWordInString() {
    FILE *f5 = fopen("f5.txt", "r");
    FILE *f52 = fopen("самое длинное слово в строке.txt", "w");
    longestWordInString(f5, f52);
}


void test_structuresInDescendingOfDegrees() {
    FILE *f6 = fopen("f6.txt", "r");
    FILE *f62 = fopen("outputf6", "w");
    structuresInDescendingOfDegrees(f6, f62);
}


void test_orderPositiveNegativeNumbers() {
    FILE *f7 = fopen("бинарный файл целых чисел.txt", "r");
    orderPositiveNegativeNumbers(f7);
}

void test_binaryFileSquareMatrices() {
    FILE *f8 = fopen("f8.txt", "wb");
    binaryFileSquareMatrices(f8);
}

void test_informationAboutTeamMembers() {
    FILE *f9 = fopen("Информация о спортсменах.txt", "r");
    informationAboutTeamMembers(f9, 5);
}

void test_releasedGoodsInAccordance() {
    FILE *f10 = fopen("наименование товара.txt", "r");
    FILE *f12 = fopen("цена единицы товара.txt", "r");
    FILE *f13 = fopen("общая стоимость и количество.txt", "r");
    releasedGoodsInAccordance(f10, f12, f13);
}

void test() {
    test_squareMatrixColumns();
    test_eachFloatingPointNumber();
    test_writingArithmeticExpression();
    test_sequenceOfCharacters();
    test_longestWordInString();
    test_structuresInDescendingOfDegrees();
    test_orderPositiveNegativeNumbers();
    test_binaryFileSquareMatrices();
    test_informationAboutTeamMembers();
    test_releasedGoodsInAccordance();

}

int main() {
    test();

    return 0;
}
