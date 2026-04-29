#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char line[100];

    fp = fopen("input1.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        char lhs[20], op1[20], op2[20], op3[20];
        char op[5];
        int i = 0, j = 0, k = 0;

        lhs[0] = op1[0] = op2[0] = op3[0] = op[0] = '\0';

        while (line[i] == ' ') i++;

        while (line[i] != '=' && line[i] != '\0') {
            lhs[j++] = line[i++];
        }
        lhs[j] = '\0';
        i++;

        j = 0;
        while (line[i] == ' ') i++;
        while (isalnum(line[i])) {
            op1[j++] = line[i++];
        }
        op1[j] = '\0';

        printf("LOAD %s\n", op1);

        while (line[i] != '\0' && line[i] != '\n') {
            while (line[i] == ' ') i++;

            if (line[i] == '+' || line[i] == '-' ||
                line[i] == '*' || line[i] == '/') {

                op[0] = line[i];
                op[1] = '\0';
                i++;

                j = 0;
                while (line[i] == ' ') i++;
                while (isalnum(line[i])) {
                    op2[j++] = line[i++];
                }
                op2[j] = '\0';

                if (op[0] == '+')
                    printf("ADD %s\n", op2);
                else if (op[0] == '-')
                    printf("SUB %s\n", op2);
                else if (op[0] == '*')
                    printf("MUL %s\n", op2);
                else if (op[0] == '/')
                    printf("DIV %s\n", op2);
            } else {
                i++;
            }
        }

        printf("STORE %s\n\n", lhs);
    }

    fclose(fp);
    return 0;
}