#include "../common/def.h"

#define LED_DDR     DDRD
#define LED_PORT    PORTD   // 출력 할때는 PORT
#define BUTTON_DDR  DDRG
#define BUTTON_PIN PING    // 입력 받을때는 PIN

#define BUTTON_ON       0
#define BUTTON_OFF      1
#define BUTTON_TOGGLE   2

enum {PUSHED, RELEASED};    // 열거형(연속형), 중간에 변수(정수) 설정 시, 다음 변수는 설정 하지 않으면 설정한 정수 +1
enum
{
    NO_ACT,
    ACT_PUSH,
    ACT_RELEASE
};

typedef struct
{
    volatile uint8_t *ddr;      // DDR 주소 -> 포인터
    volatile uint8_t *pin;      // PORT 처럼 PIN의 주솟갑 가져옴. -> 포인터
    uint8_t           btnPin;   // PIN번호
    uint8_t           prevState;// 핀 상태
}BUTTON;


void buttonInit(BUTTON *btn, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t buttonGetState(BUTTON *btn);