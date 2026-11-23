#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

struct Packet
{
    uint32_t crc           :2;
    uint32_t status        :1;
    uint32_t payload       :12;     
    uint32_t bat           :3;
    uint32_t sensor        :3;
    uint32_t longAddr      :8;
    uint32_t shortAddr     :2;
    uint32_t addrMode      :1;
};

int main(void)
{
    uint32_t packetvalue;
    printf("Paketi gir (hex): ");
    scanf("%" SCNx32, &packetvalue);

    struct Packet paket;
    paket.crc = (packetvalue >> 0) & 0x3;
    paket.status = (packetvalue >> 2) & 0x1;
    paket.payload = (packetvalue >> 3) & 0xFFF;
    paket.bat = (packetvalue >> 15) & 0x7;
    paket.sensor = (packetvalue >> 18) & 0x7;
    paket.longAddr = (packetvalue >> 21) & 0xFF;
    paket.shortAddr = (packetvalue >> 29) & 0x3;
    paket.addrMode = (packetvalue >> 31) & 0x1;


    printf("crc       : %#x\n", paket.crc);
    printf("status    : %#x\n", paket.status);
    printf("payload   : %#x\n", paket.payload);
    printf("bat       : %#x\n", paket.bat);
    printf("sensor    : %#x\n", paket.sensor);
    printf("longAddr  : %#x\n", paket.longAddr);
    printf("shortAddr : %#x\n", paket.shortAddr);
    printf("addrMode  : %#x\n", paket.addrMode);

    printf("Struct boyutu: %zu bayt\n", sizeof(paket));

    return 0;
}

/*
union adress
{
    uint16_t shortaddr;  // bu tür yapılar sadece birbirleri yerine geçen ve aynı anda asla kullanılmayacak yapılarda kullanılır.
    
    uint32_t longaddr;
    

}

*/