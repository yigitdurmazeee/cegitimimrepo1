#include<stdio.h>

int main(){
    int yas= 0;

    printf("yasinizi giriniz: \n");
    scanf("%d", &yas);

    if(yas >= 18)
    {

        printf("oy kullanabilirsiniz");

    }
    else
    {
        printf("oy kullanmak icin daha gencsiniz\n");
    }
  
    return 0;
}

