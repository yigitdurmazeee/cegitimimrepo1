#include <stdio.h>
extern void change_system_clock(int system_clock);
extern int ozeldosya;

void dosya2fonksiyonum(void) {
    
    ozeldosya = 30;
    change_system_clock(50);
}