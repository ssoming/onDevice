#include "../common/def.h"

/**
 * @brief 헤더파일
 * define, 함수 원형 선언으로 구성. 함수에서 사용할 데이터형(특히 구조체)가 있다면 헤더파일에 구조체 정의
 * 다른 소스파일에서 공통으로 사용해야할 변수가 있다면 여기에 정의
 * 
 */

#define LED_DDR     DDRD    // LED 입출력을 설정하는 DDR을 매크로 상수로 정의해서 사용
#define LED_PORT    PORTD   // DDR의 방향 설정 이후 PORT 제어를 위해 매크로 상수로 정의해서 사용

// LED 구조체 정의
typedef struct      // typedef << 재정의를 의미. => LED라는 구조체 재정의
{
    volatile uint8_t    *port;      // LED가 연결된 포트. 구조체 맴버로 포인터 선언(Volatile 이라는 최적화 방지 키워드 사용)
    uint8_t             pinNumber;  // LED가 연결된 핀번호. 구조체 멤버로 8비트 변수 선언
}LED;       // 구조체 이름 재정의함으로써 LED라는 사용자 정의 데이터형을 생성 


// 사용할 함수 원형 선언
void ledInint(LED *led);    // LED라는 사용자데이터형(구조체) 인자를 주솟값으로 넘겨줌(포인터)
void ledOn(LED *led);       
void ledOff(LED *led);
