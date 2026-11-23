#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

union Packet
{
    uint32_t packetvalue;
    struct{
        uint32_t crc           :2;//lsb
        uint32_t status        :1;
        uint32_t payload       :12;     
        uint32_t bat           :3;
        uint32_t sensor        :3;
        uint32_t longAddr      :8;
        uint32_t shortAddr     :2;
        uint32_t addrMode      :1;//msb
    }packetFields;
};

int main(void)
{
    union Packet paket;
    printf("Paketi gir (hex): ");
    scanf("%" SCNx32, &paket.packetvalue);


    printf("crc       : %#x\n", paket.packetFields.crc);
    printf("status    : %#x\n", paket.packetFields.status);
    printf("payload   : %#x\n", paket.packetFields.payload);
    printf("bat       : %#x\n", paket.packetFields.bat);
    printf("sensor    : %#x\n", paket.packetFields.sensor);
    printf("longAddr  : %#x\n", paket.packetFields.longAddr);
    printf("shortAddr : %#x\n", paket.packetFields.shortAddr);
    printf("addrMode  : %#x\n", paket.packetFields.addrMode);

    printf("union boyutu: %zu bayt\n", sizeof(paket));

    return 0;
}

/*
union adress
{
    uint16_t shortaddr;  // bu tür yapılar sadece birbirleri yerine geçen ve aynı anda asla kullanılmayacak yapılarda kullanılır.
    uint32_t longaddr;   //aynı zamanda bit extraction için kullanılır
    
    

}

*/