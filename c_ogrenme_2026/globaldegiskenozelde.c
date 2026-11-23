#include <stdio.h>
/*prototip fonksiyon */
    void fonksiyonum(void);

int main()
{
    fonksiyonum();
    fonksiyonum();
    fonksiyonum();
    fonksiyonum();
    fonksiyonum();
    fonksiyonum();
    fonksiyonum();
    fonksiyonum();
    return 0;

}

 void fonksiyonum (void){
    /*   bu fonksiyon dışında değer alamayan ama global olan değişken tanımlaması   */
    static int count = 0; 
    
    count = count+1;
    printf("count = %d\n", count );

}
