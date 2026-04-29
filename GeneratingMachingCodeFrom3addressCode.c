#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tempReg = 0;

void trim(char *s) {
    int i = 0, j = 0;
    while (s[i]) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
            s[j++] = s[i];
        i++;
    }
    s[j] = '\0';
}

void generate(char *line) {
    char left[10], op1[10], op2[10], op;
    int i = 0, j = 0, k = 0;

    trim(line);
    if (strlen(line) == 0) return;

    while (line[i] != '=' && line[i] != '\0') {
        left[j++] = line[i++];
    }
    left[j] = '\0';

    if (line[i] == '\0') return;
    i++;

    j = 0;
    while (line[i] && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/') {
        op1[j++] = line[i++];
    }
    op1[j] = '\0';

    op = line[i++];

    j = 0;
    while (line[i]) {
        op2[j++] = line[i++];
    }
    op2[j] = '\0';

    printf("%s = %s%c%s\n", left, op1, op, op2);
    printf("MOV R%d,%s\n", tempReg, op1);

    if (op == '+')
        printf("ADD R%d,%s\n", tempReg, op2);
    else if (op == '-')
        printf("SUB R%d,%s\n", tempReg, op2);
    else if (op == '*')
        printf("MUL R%d,%s\n", tempReg, op2);
    else if (op == '/')
        printf("DIV R%d,%s\n", tempReg, op2);

    printf("MOV %s,R%d\n\n", left, tempReg);
    tempReg++;
}

int main() {
    FILE *fp = fopen("input2.txt", "r");
    char line[100];

    if (!fp) {
        printf("File not found\n");
        return 1;
    }

    printf("----------------------------------------------------------\n");
    printf(" Statement Target Code\n");
    printf("----------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp)) {
        generate(line);
    }

    fclose(fp);
    return 0;
}