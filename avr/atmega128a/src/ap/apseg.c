// #include "apseg.h"
// #include "../driver/button.h"
// // #include "../driver/led.h"


// BUTTON btnOn;
// BUTTON btnOff;
// BUTTON btnTog;

// void apInit()
// {
//     buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
//     buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
//     buttonInit(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);
// }
// void apMain()
// {
//     uint8_t FND_Number[] = 
//     {
//         0x3F, 0x06, 0x5B, 0x4F, 0x66, 
//         0x6D, 0x7D, 0x27, 0x7F, 0x67
//     };
    
//     DDRF = 0xff;
//     PORTF = 0x3F;
    
//     int count = 0;
//     int flag = 0;

//     while (1)
//     {
//         if(buttonGetState(&btnOn) == ACT_RELEASE)
//         {
//             flag = 1;
//             // count = (count + 1) % 10; 
//             // PORTF = FND_Number[count];
//         }
//         else if(buttonGetState(&btnOff) == ACT_RELEASE)
//         {
//             flag = 0;
//         }
//         else if(buttonGetState(&btnTog) == ACT_RELEASE)
//         {
//             count = 0;
//             flag = 0;
//             PORTF = FND_Number[count];
//         }

//         if(flag)
//         {
//             PORTF = FND_Number[count];
//             count = (count + 1) % 10;
//             _delay_ms(300);
//         }
//     }
// }


