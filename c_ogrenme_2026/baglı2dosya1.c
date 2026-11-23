#include <stdio.h>
    
    void dosya2fonksiyonum(void);

    static int ozeldosya;

    int main(){
    
        ozeldosya = 100;

        printf("ozeldosya = %d\n", ozeldosya );
        
        dosya2fonksiyonum();

        printf("ozeldosya = %d\n", ozeldosya );

        return 0;
    }
 /* bu kodlar çalışmayacak çünkü ozeldosya değişkeni static olarak tanımlanmış ve dosya2.c dosyasında extern olarak bildirilmiş */

 static void change_system_clock(int system_clock) {
        
        printf("System clock changed to: %d\n", system_clock);

    }
    /* bu fonksiyon sadece bu dosya içinde kullanılabilir */