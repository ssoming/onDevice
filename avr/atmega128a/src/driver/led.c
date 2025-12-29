#include "led.h"

/**
 * @brief 헤더파일에서 정의된 함수 작성
 * 
 * @param led 
 */

// LED 초기화 함수
void ledInint(LED *led)
{
    // 넘겨받는 구조체형 포인터를 이용해서 포트 초기화
    // 출력=> (DDRD 를 사용해서 비트를 1로 설정)

    //*(led->port - 1) = *(led->port - 1) | (1 << led->pinNumber);
    *(led->port - 1) |= (1 << led->pinNumber);
    // DDR레지스터는 PORT레지스터보다 주소가 1낮게 위치하므로
    // led라는 데이터 맴버 port가 가지고 있는 값 == 주소
    // 주소에서 1을 뺌으로 DDR을 가르키게 됨 == (led->port - 1) -> *를 붙여서 가리키는 곳의 내용물을 의미
    // (led->port - 1)를 이용해서 PORT에서 DDR로 접근
    // (1 << led->pinNumber)와 or연산을 통해서 지정된 포트를 출력으로 설정
}

// LED On 함수
void ledOn(LED *led)
{
    *(led->port) |= (1 << led-> pinNumber);
}

// LED Off 함수
void ledOff(LED *led)
{
    *(led->port) &= ~(1 << led->pinNumber);
}