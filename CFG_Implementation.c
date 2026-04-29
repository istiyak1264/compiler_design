#include <stdio.h>
#include <string.h>

char str[100];
int i = 0, f = 0;

void X();

void A() {
    if(str[i] == 'a') {
        i++;
        X();
        if(str[i] == 'd') {
            i++;
            f = 1;
        }
    }
}

void X() {
    if(str[i]=='b' && str[i+1]=='b') {
        i+=2;
        X();
    }
    else if(str[i]=='b' && str[i+1]=='c') {
        i+=2;
        X();
    }
}

int main() {
    printf("Enter string: ");
    scanf("%s", str);

    A();

    if(f && str[i]=='\0')
        printf("Valid\n");
    else
        printf("Invalid\n");
}