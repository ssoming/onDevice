#include "./src/ap/ap.h"
// #include "./src/driver/fnd_1.h"

// int main()
// {
//     apInit();
//     apMain();
// }

ISR(INT7_vect)
{
    PORTD ^= 0xFF;
}


int main()
{
    sei();      // 전역 인터럽트 인에이블
    EICRB = 0x40;   // Riging Edge 에서 인터럽 발생
    EIMSK = 0x80;   // INT7 인에이블 
    DDRE &= ~(1<<7);

    DDRD = 0xff;

    while (1)
    {

    }
}

