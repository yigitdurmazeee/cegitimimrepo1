#include <stdio.h>

void scan2(void);

int main(void){
    char fname[30], lname[30];

    printf("Ad ve soyadini gir: ");
    scanf("%29s %29s", fname, lname);
    printf("Senin adin %s %s\n", fname, lname);

    scan2();
    return 0;
}

void scan2(void){
    char name[50];

    printf("Tam adini gir (bosluklu olabilir): ");
    scanf(" %49[^\n]", name); //\n karakterine kadar yazar
    printf("Senin adin %s\n", name);
}
