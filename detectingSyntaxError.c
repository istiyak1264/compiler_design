#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char idList[MAX_SIZE][50];
int idIndex = 0;

int isDup(char *val)
{
    for (int j = 0; j < idIndex; j++)
    {
        if (strcmp(idList[j], val) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void pushId(char *val, int ln)
{
    if (isDup(val))
    {
        printf("Duplicate identifier at line %d: %s\n", ln, val);
    }
    else
    {
        strcpy(idList[idIndex], val);
        idIndex++;
    }
}

int main()
{
    FILE *fp;
    char buf[50];
    int ln = 1;

    int openB = 0, closeB = 0;
    int openP = 0, closeP = 0;
    int ifCnt = 0, elseCnt = 0;

    fp = fopen("input.txt", "r");
    if (!fp)
    {
        printf("File not found\n");
        return 0;
    }

    while (fscanf(fp, "%s", buf) != EOF)
    {

        if (strcmp(buf, "{") == 0)
        {
            openB++;
        }
        else if (strcmp(buf, "}") == 0)
        {
            closeB++;
            if (closeB > openB)
            {
                printf("Misplaced '}' at line %d\n", ln);
            }
        }

        if (strcmp(buf, "(") == 0)
        {
            openP++;
        }
        else if (strcmp(buf, ")") == 0)
        {
            closeP++;
            if (closeP > openP)
            {
                printf("Misplaced ')' at line %d\n", ln);
            }
        }

        if (strcmp(buf, "if") == 0)
        {
            ifCnt++;
        }

        if (strcmp(buf, "else") == 0)
        {
            elseCnt++;
            if (elseCnt > ifCnt)
            {
                printf("Unmatched else at line %d\n", ln);
            }
        }

        if (strcmp(buf, ";") == 0)
        {
            char tmp[50];
            fscanf(fp, "%s", tmp);
            if (strcmp(tmp, ";") == 0)
            {
                printf("Duplicate token ';' at line %d\n", ln);
            }
        }

        if (buf[0] >= 'a' && buf[0] <= 'z')
        {
            if (strcmp(buf, "int") &&
                strcmp(buf, "float") &&
                strcmp(buf, "double") &&
                strcmp(buf, "if") &&
                strcmp(buf, "else") &&
                strcmp(buf, "return"))
            {

                pushId(buf, ln);
            }
        }

        if (strchr(buf, '\n'))
        {
            ln++;
        }
    }

    if (openB != closeB)
    {
        printf("Unbalanced curly braces\n");
    }

    if (openP != closeP)
    {
        printf("Unbalanced parentheses\n");
    }

    fclose(fp);
    return 0;
}