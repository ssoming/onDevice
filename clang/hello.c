#include <stdio.h>
#include <string.h>
#include <stdatomic.h>

struct test
{
    int c;
};

int add_one(int *a)     //콜바이레퍼런스
{
    *a += 1;
    return 0;
}

int main()
{
    struct test t;
    struct test *pt = &t;

    pt -> c = 0;        //pt가 가리키는 구조체 변수의 멤버인 c의 값을 0으로

    add_one(&t.c);
    printf("t.c : %d\n", t.c);

    add_one(&pt->c);
    printf("t.c: %d\n",t.c);
}






// struct test
// {
//     int c;
//     int *pointer;
// };

// int main()
// {
//     struct test t;
//     struct test *pt = &t;

//     int i = 0;

//     t.pointer = &i;     // t의 멤버인 포인터는 i를 가리킨다.
//     *t.pointer = 3;     // t의 멤버인 포인터가 가리키는 변수 값이 3

//     printf("i: %d\n", i);

//     /* ->가 *보다 우선순위가 빠름
//     (pt가 가리키는 구조체 변수의 포인터 멤버)가 가리키는 변수 값을 4로 바꿈.
//     */
//     *pt->pointer = 4;
//     printf("i: %d\n", i);
// }




// struct test
// {
//     int a;
//     int b;
// };

// int main()
// {
//     struct test st;     //구조체 타입을 가진 변수
//     struct test *ptr;   //구조체 X. 포인터(8바이트)

//     ptr = &st;      //일반 변수 주소 넣듯이 구조체 변수 주소에 대입

//     //st.a = 1;
//     //(*ptr).a = 1;   //연산자 우선순위로 인해 괄호 사용
//     //(*ptr).b = 2;
//     ptr->a = 3;
//     ptr->b = 4;

//     printf("st의 멤버 a의 값: %d\n", st.a);
//     printf("st의 멤버 b의 값: %d\n", st.b);
// }



// struct contact
// {
//     char name[20];
//     char phone[20];
//     int ringtone;   //벨소리 0~9
// };

// int main()
// {
//     struct contact ct = {"김석진", "01011112222", 0};  //배열처럼 초기화
//     struct contact ct1 = {0}, ct2={0};

//     ct.ringtone = 5;    //ct에서 벨소리 5로 변경
//     strcpy(ct.phone, "01022223333");

//     printf("이    름: %s\n", ct.name);
//     printf("전화번호: %s\n", ct.phone);
//     printf("벨 소 리: %d\n",ct.ringtone);

// }




// /**
//  * @brief 구조체
//  * 서로 다른 데이터형의 변수들의 연속된 메모리의 유한 집합
//  * 사용자 데이터형을 만듦
//  * class가 구조체에서 파생됨
//  */

// struct human    //human 이라는 구조체 정의
// {
//     int age;    //나이 멤버 정의
//     int height; //키
//     int weight; //몸무게
// };


// int main()
// {
//     struct human info;  //구조체 변수 선언
    
//     //초기화 작업
//     info.age = 99;      // . : 구조체 멤버에 접근
//     info.height = 200;
//     info.weight = 100;

//     printf("info 정보\n");
//     printf("나이: %d\n", info.age);
//     printf("키: %d\n", info.height);
//     printf("몸무게: %d\n", info.weight);
// }


// int main()
// {
//     int *arr[3] = {1, 2, 3};
//     int *p = arr;

//     for(int i = 0; i < 3 ; i++)
//     {
//         printf("p = %p, ",p);

//         printf("*p = %d\n", *p++);   // *(p++)
//         // printf("*p = %d\n", (*p)++);
//     }
// }

// int main()
// {
//     int arr[3] = {1, 2, 3};
//     int *parr = arr;
//     //int *parrl = &arr[0];

//     printf("arr의 정체: %p \n", arr);
//     printf("arr[0]의 주소: %p \n", &arr[0]);

//     // 배열의 이름이 첫번째 원소를 가르키는 포인터는 아니다. 
//     // 배열의 이름이 배열의 주소를 가지고 있다. 

//     printf("바이트 크기(arr): %d\n", sizeof(arr));
//     printf("바이트 크기(parr): %d\n", sizeof(parr));
//     /*
//     C언어에서의 배열 이름이 sizeof 연산자는 주소값연산자(&)와 같이 사용할 때의 경우를 제외하면
//     배열의 이름을 사용할 때, 암묵적으로 첫번째 원소를 가르키는 포인터 타입으로 변환됨.
//     */ 
// }


// int main()
// {
//     int a;
//     int *pa = &a;

//     int *pb;

//     *pa = 3;
//     pb = pa;

//     printf("pa가 가리키고 있는 곳 : %p\n", pa);
//     printf("pa가 가리키고 있는 곳의 값 : %d\n", *pa);
//     printf("pb가 가리키고 있는 곳 : %p\n", pb);
//     printf("pb가 가리키고 있는 곳의 값 : %d\n", *pb);
// }


// int main()
// {
//     int a;
//     char c;
//     double d;

//     int *pa = &a;
//     char *pc = &c;
//     double *pd = &d;

//     printf("pa의 값 %p \n", pa);
//     printf("pa + 1 의 값: %p\n\n", pa +1);

//     printf("pc의 값 %p \n", pc);
//     printf("pc + 1 의 값: %p\n\n", pc +1);

//     printf("pd의 값 %p \n", pd);
//     printf("pd + 1 의 값: %p\n\n", pd +1);
// }


// int main()
// {
//     int a, b;
//     int *ptr;

//     ptr = &a;
//     *ptr = 2;
//     printf("ptr의 값: %p | ptr이 가르키는 곳의 값: %d\n", ptr, *ptr);

//     ptr = &b;
//     *ptr = 5;
//     printf("ptr의 값: %p | ptr이 가르키는 곳의 값: %d\n", ptr, *ptr);
// }


// int main()
// {
//     int *p;     //포인터 p 선언
//     int a;      //변수 a 선언

//     p = &a;     //포인터에 a의 주소값 대입
//     a = 2;

//     printf("포인터 p에 들어있는 값: %p\n", p);
//     printf("변수 a의 주소값: %p\n", &a);
//     printf("\na의 값: %d\n", a);
//     printf("*p의 값: %d\n", *p);
// }



//2차원 배열

// int main()
// {
//     int arr2[3][3] =        //행 생략가능, 열 생략 불가능
//     {
//         {1, 4, 6}, 
//         {8, 5, 2}, 
//         {7, 9, 5}
//     };

//     printf("1행 1열 : %d |", arr2[0][0]);
//     printf("1행 2열 : %d |", arr2[0][1]);
//     printf("1행 3열 : %d \n", arr2[0][2]);
//     printf("2행 1열 : %d |", arr2[1][0]);
//     printf("2행 2열 : %d |", arr2[1][1]);
//     printf("2행 3열 : %d \n", arr2[1][2]);
//     printf("3행 1열 : %d |", arr2[2][0]);
//     printf("3행 2열 : %d |", arr2[2][1]);
//     printf("3행 3열 : %d \n", arr2[2][2]);
// }



// int main()
// {
//     int decimal;
//     int binary[20] = {0};

//     int position = 0;

//     printf("2진수로 변환 할 10진수를 입력하시오.: ");
//     scanf("%d", &decimal);

//     while (1)
//     {
//         binary[position] = decimal % 2; //입력받은 10진수를 2로 나눠서 나머지를 배열에 저장
//         decimal = decimal /2 ;          //2로 나눈 몫 저장
        
//         position++;

//         if(decimal ==0)
//         {
//             break;      //몫이 0이면 반복문 끝냄
//         }
//     }
//     //나머지인 배열을 역순으로 출력
//     for(int i = position-1; i >= 0; i--)
//     {
//         printf("%d", binary[i]);
//     }
//     printf("\n");
    
// }



// #define MAX 30

// int main()
// {
//     char sentence[MAX] = {0};
//     char key;

//     printf("30자 내 문자를 입력하세요: ");
//     for(int i = 0; i<MAX; i++)
//     {
//         scanf("%c", &sentence[i]);
//         if(sentence[i] == '\n')
//         {
//          sentence[i] = '\0';        // \0: null문자. 마지막에 들어가면 문자열로 인식함.
//          break;   
//         }
//     }
//     printf("찾을 문자를 입력하시오: ");
//     scanf("%c", &key);
//     for(int i = 0; i < MAX; i++)
//     {
//         if(sentence[i] == key)
//         {
//             printf("%d 번째에서 찾았습니다 \n", i+1);
//         }
//     }

// }

// int main()
// {
//     int arr[] = {55, 66, 77, 15, 44, 33, 15};
//     int size;
//     int key;
//     int flag;

//     size = sizeof(arr)/sizeof(arr[0]);

//     printf("arr = ");
//     for(int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     printf("찾을 키 값: ");
//     scanf("%d", &key);

//     for(int i = 0; i<size; i++)
//     {
//         if(arr[i] == key)
//         {
//             printf("찾은 원소의 인덱스: %d\n", i);
//             flag = 1;
//         }
//     }
//     if(!flag)
//     {
//         printf("찾는 원소가 없습니다..\n");
//     }
// }






// int main()
// {
//     int arr[5]= {0};
//     int sum = 0, avg = 0;

//     for(int i = 0; i <5; i++)
//     {
//         printf("%d번째 학생의 점수를 입력: ", i+1);
//         scanf("%d", &arr[i]);
//     }
//     for(int i = 0; i <5; i++)
//     {
//         sum += arr[i];      //sum = sum + arr[i]
//     }
//     avg = sum/5;

//     printf("전체 평균: %d\n", avg);

//     for(int i = 0; i < 5; i++)
//     {
//         printf("%d번째 학생 점수: ", i+1);
//         if(arr[i]>= avg)
//         {
//             printf("합  격\n");
//         }
//         else{
//             printf("불합격\n");
//         }
//     }
// }


// int main()
// {
//     int i = 5;
//     char c = 'A';

//     printf("변수 i의 주솟값: %p\t i의 값: %d\n", &i, i);
//     printf("변수 C의 주솟값: %p\t c의 값: %d\n", &c, c);

// }


// int add(int a, int b) {return a+b;}
// int main()
// {
//     int arr[ARR_SIZE]={0};

//     arr[0] = 5;
//     arr[1] = arr[0]+10;             //배열의 요소를 수식으로 사용
//     arr[2] = add(arr[0], arr[1]);   //배열의 요소를 함수의 인자로 사용

//     printf("정수값 2개를 입력하시오 : ");
//     scanf("%d %d", &arr[3], &arr[4]);

//     for(int i = 0; i < ARR_SIZE ; i++)
//     {
//         printf("%d  ", arr[i]);
//     }
//     printf("\n\n");
// }


// /**
//  * @brief 
//  * 
//  */

// int main()
// {
//     int i = 1;
//     int arr[5] = {0};

//     arr[i] = 3;
//     arr[i+1] = 4;
//     arr[i+2] = 5;

//     for(int i = 0; i < 5; i++)
//     {
//         printf("배열의 %d번째 요소: %d \n", i, arr[i]);
//     }
// }



// #define a 10

// int b = 10;

// //배열 선언. 배열도 단 한번 초기화 가능
// int arrVar[10];      //배열 크키가 10인 정수형 변수
// int arrVar[a];      //배열의 크키에 매크로 상수 가능
// int arrVar[b];      //배열의 크기에 변수수로 정의된 값 불가
// int arrVar[];      //배열의 크기는 공란으로 가능

// int main()
// {
//     int arr[5];         //배열의 크기가 5인 배열 선언
//     int byteSize = 0;   //지역변수 선언과 동시에 초기화. 배열의 바이트 크키 저장할 변수 선언
//     int size = 0;       //배열의 크기 저장할 변수

//     byteSize = sizeof(arr); //sizeof(): 변수의 크기를 바이트 단위로 반환
//     printf("배열의 바이트 크기: %d \n", byteSize);

//     size = sizeof(arr) / sizeof(arr[0]);
//     printf("배열의 크기: %d \n", size);

//     for(int i = 0; i < size; i++)
//     {
//         arr[i] = i;
//     }

//     printf("배열의 각 요소: ");
//     for(int i = 0; i < size; i++)
//     {
//         printf("%d  ", arr[i]);
//     }
//     printf("\n\n");
//}







// /**
//  * @brief 변수의 유효 범위
//  * 지역변수, 전역변수, 정적변수, 레지스터변수
//  */
// void local();       //함수 원형 선언
// void staticVar();   //함수 원형 선언

// int main()
// {
//     for(int i = 0; i<3; i++)
//     {
//         local();
//         staticVar();
//     }
// }

// void local()
// {
//     int count = 1;
//     printf("local 함수가 %d 번째 호출되었음. \n", count);
//     count++;
// }

// void staticVar()
// {
//     static int stacticCount = 1;    //정적변수 초기화
//     printf("StaticVar 힘수가 %d 번째 호출되었음. \n", stacticCount);
//     stacticCount++;
// }




// void local();
// int var;

// int main()
// {
//     printf("전역변수 var의 값: %d \n", var);
//     int i = 5;
//     int var = 10;
//     printf("main함수 내의 지역변수 var의 값: %d \n", var);

//     if(i<10)
//     {
//         local();
//         printf("if 문 내의 지역변수 var의값: %d \n", var);  //지역 변수에 접근
//     }
//     printf("현재 변수 var 값: %d \n", var);
// }

// void local()
// {
//     int var = 20;
//     printf("local()함수 내의 변수 var의 값은 %d \n", var);

// }



// //지역변수
// void local();       // 함수 원형 선언

// int main()
// {
//     int i = 5;
//     int var = 10;
//     printf("main함수 내의 지역변수 var의 값: %d \n", var);

//     if(i<10)
//     {
//         local();
//         int var = 30;
//         printf("if 문 내의 지역변수 var의값: %d \n", var);
//     }
//     printf("현재 지역변수 var 값: %d \n", var);
// }

// void local()
// {
//     int var = 20;
//     printf("local()함수 내의 지역변수 var의 값은 %d \n", var);

// }




// void add(int x, int y);

// int main()
// {
//     int a, b, sum;  // 3개의 int형의 지역 변수 선언
//     a = 3;
//     b = 5;

//     sum = add(a, b);  //sum이라는 변수에 add함수를 호출하면서 a, b 넘겨주고 리턴값 대입

//     printf("a와b의 합은? %d \n", sum);
// }
// void add(int x, int y)
// {
// }


// int print_hello(); //함수의 원형선언

// int main()
// {
//     printf("함수를 부르기 \n");
//     print_hello();

//     printf("함수를 또 부르기 \n");
//     print_hello();
// }

// int print_hello()
// {
//     printf("Hello World!!\n");
//     return 0;
// }



// /**
//  * @brief for 문
//  * 
//  */

// int main()
// {
//     int i, j;
//     for(i = 0; i < 5; i++)
//     {
//         for (j = 0; j <= i; j++)
//             printf("*");
//         printf("\n");
//     }    
//     for(i = 4; i > 0 ; i--)
//     {
//         for (j = 0; j < i; j++)
//             printf("*");
//         printf("\n");
//     } 
// }


// /**
//  * @brief 반복문
//  * 
//  */

// int main()
// {
//     int weight = 80;
//     int count = 0;

//     while (weight > 70)
//     {
//         printf("운동으로 1kg 뺍시다.\n");
//         printf("현재 몸무게: %d 운동한 날: %d\n", weight, count);
//         weight--;
//         count++;
//     }
//     printf("고생하셨습니다.");
//     printf("%d일 운동하셨습니다.\n", count);
    
// }



// /**
//  * @brief 제어문
//  * 
//  */

// int main()
// {
//     int num;
//     printf("미세먼지 농도 선택\n");
//     printf("1. 매우 좋음\n");
//     printf("2. 좋음\n");
//     printf("3. 보통\n");
//     printf("4. 나쁨\n");
//     printf("5. 매우 나쁨\n");
//     scanf("%d", &num);

//     switch (num)        //반드시 정수여야 함. 
//     {
//     case 1:
//         printf("미세먼지 농도가 매우 좋음입니다. 마스크가 필요 없습니다.");
//         break;
//     case 2:
//         printf("미세먼지 농도가 좋음입니다. 마스크가 없어도 좋습니다..");
//         break;
//     case 3:
//         printf("미세먼지 농도가 보통입니다. 마스크가 있으면 좋습니다..");
//         break;
//     case 4:
//         printf("미세먼지 농도가 나쁨입니다. 마스크를 쓰는 것을 추천합니다.");
//         break;
//     case 5:
//         printf("미세먼지 농도가 매우 나쁨입니다. 마스크를 쓰십시오.");
//         break;
    
//     default:
//         printf("올바른 숫자를 입력하시오.");
//         break;
//     }
// }




// int main()
// {
//     int pm;
//     printf("미세먼지 농도를 입력하시오: \n");
//     scanf("%d", &pm);

//     //중첩문
//     if(pm > 0)
//     {
//         if(pm <= 30)
//         {
//             printf("미세먼지 농도가 좋음입니다. 마스크가 없어도 됩니다.");
//         }
//         else
//         {
//             if(pm <= 80)
//             {
//                 printf("미세먼지 농도가 보통입니다. 마스크 쓰는 것이 좋습니다. \n");
//             }
//             else
//             {
//                 printf("미세먼지 농도가 높습니다. 마스크를 쓰십시오.");
//             }
//         }
//     }
//     else
//     {
//         printf("올바른 농도를 입력하세요.");
//     }

// }





// int main()
// {
//    int num = 0;

//    printf("숫자 1개를 입력하세요: \n");
//    scanf("%d", &num);

//     if(num < 5)
//     {
//        printf("입력하신 숫자는 5보다 작습니다. \n");
//     }
//     else if(num > 5)
//        {
//            printf("입력하신 숫자는 5보다 큽니다. \n");
//        }
//     else
//         {
//            printf("입력하신 숫자는 5입니다. \n");
//         }

// //    {
// //        if(num > 5)
// //        {
// //            printf("입력하신 숫자는 5보다 큽니다. \n");
// //        }
// //        else
// //        {
// //            printf("입력하신 숫자는 5입니다. \n");
// //        }
// //     }

//     // if(num < 5)
//     // {
//     //     printf("입력하신 숫자는 5보다 작습니다. \n");
//     // }
//     // if(num > 5)
//     // {
//     //     printf("입력하신 숫자는 5보다 큽니다. \n");
//     // }
//     // if(num == 5)
//     // {
//     //     printf("입력하신 숫자는 5입니다. \n");
//     // }
// }






// /**
//  * @brief 데이터 형변환
//  * 
//  */
// int main()
// {
//     int a, b, c;
//     double avg;

//     printf("정수 3개를 입력하세요 : \n");
//     scanf("%d %d %d", &a, &b, &c);

//     avg = (double)(a + b + c)/3;
//     printf("평균: %f \n", avg);

// }




// /**
//  * @brief 비트 마스크
//  * 프로그램이 빠르게 동작, 메모리 사용량이 작음, 소스코드 직관적
//  * & 연산자는 특정 비트를 0으로 만듦
//  * | 연산자는 특정 비트를 1로 만듦
//  * ^ 연산자는 특정 비트를 반전시킴
//  */

// int main()
// {
//     // & 연산
//     // unsigned short data = 0x5678;       //0101 0110 0111 1000

//     // unsigned short msk1 = 0xf000;       // 1111 0000 0000 0000
//     // unsigned short msk2 = 0x0f00;       // 0000 1111 0000 0000
//     // unsigned short msk3 = 0x00f0;       // 0000 0000 1111 0000
//     // unsigned short msk4 = 0x000f;       // 0000 0000 0000 1111

//     // printf("결과1: %#.4x \n", data & msk1);
//     // printf("결과2: %#.4x \n", data & msk2);
//     // printf("결과3: %#.4x \n", data & msk3);
//     // printf("결과4: %#.4x \n", data & msk4);
//     //특정 비트를 뽑아낼 수 있다. 

//     // | 연산
//     unsigned short data = 0x0000;       //0101 0000 0000 1000

//     unsigned short msk1 = 0xf000;       // 1111 0000 0000 0000
//     unsigned short msk2 = 0x0f00;       // 0000 1111 0000 0000
//     unsigned short msk3 = 0x00f0;       // 0000 0000 1111 0000
//     unsigned short msk4 = 0x000f;       // 0000 0000 0000 1111

//     printf("결과1: %#.4x \n", data | msk1);
//     printf("결과2: %#.4x \n", data | msk2);
//     printf("결과3: %#.4x \n", data | msk3);
//     printf("결과4: %#.4x \n", data | msk4);
//     //특정 부분 변경 가능하다.
// }


// #include <stdio.h>

// /**
//  * @brief overflow/underflow
//  * 
//  */

// int main()
// {
//     char a;
//     a = 127;
//     printf("%d \n", a);
//     a += 1;
//     printf("%d \n", a);

//     char b;
//     b = -128;
//     printf("%d \n", b);
//     b -= 1;
//     printf("%d \n", b);


//     unsigned char c;
//     c = 255;
//     printf("%d \n", c);
//     c += 1;
//     printf("%d \n", c);

// }




// #include <stdio.h>

// /**
//  * @brief 변수 선언과 사용
//  * 변수 이름(식별자) 생성 규칙: 반드시 영문자, 숫자, _만 사용 가능.
//  * 첫 글자는 반드시 영문자 또는 _만 가능, 숫자X
//  * 대소문자 구별.
//  * C언어의 키워드(32개)는 식별자로 사용 불가능 
//  */

// /**
//  * @brief 카멜 표기법
//  * int manAge 단어 2개 이상 연결 시, 맨 앞의 오는 단어는 소문자로 시작/뒤에 오는 단어는 대문자
//  */

//  /**
//   * @brief 파스칼 표기법
//   * int ManAge 모든 단어를 대문자로 시작
//   */

// /**
//  * @brief 스네이크 표기법
//  * int man_age 단어 사이를 _로 연결
//  */

//  /**
//   * @brief 헝가리안 표기법
//   * 변수명 앞에 데이터 형을 붙이는 방식
//   * char ch1, string strName;
//   */

// /**
//  * @brief 변수의 초기화
//  * 초기화 하지 않은 변수 값은 쓰레기 값이다.
//  */
// int main()
// {
//     // int price;
//     // printf("%d \n", price);

//     //변수 선언과 동시에 초기화 
//     //변수 자료형이 같을 경우, 한 줄에 정리 가능
//     int amount = 0, pri40ce = 0, totalPrice = 0;

//     printf("amount = %d, price = %d \n", amount, price);

//     printf("수량을 입력하시오: ");
//     scanf("%d", &amount);

//     price = 1000;
//     totalPrice = amount * price;

//     printf("합계: %d원 \n", totalPrice);

// }



// #include <stdio.h>

// /**
//  * @brief 데이터형 크키 확인
//  * sizeof() : 연산자. 괄호 안에 있는 데이터 형의 크기를 바이트로 변환
//  * 
//  */

// int main()
// {
//     char ch;
//     int num;
//     double x;

//     printf("char형 바이트 크기: %d \n", sizeof(char));
//     printf("short형의 바이트 크기: %d \n", sizeof(short));
//     printf("long형의 바이트 크기: %d \n", sizeof(long));

//     printf("변수 ch의 바이트 크기: %d \n", sizeof(ch));
//     printf("변수 num의 바이트 크기: %d \n", sizeof(num));
//     printf("변수 x의 바이트 크기: %d \n", sizeof(x));

// }


// #include <stdio.h>

// /**
//  * @brief scanf 연습
//  * 
//  */

// int main()
// {
//     char name[20];  //문자타입 변수를 배열 20칸 짜리로 선언
//     int age;        //정수형 변수 선언
//     char gender;    //문자형 변수 선언

//     printf("이름, 나이, 성별(M, F) 순으로 입력하시오. \n");
//     scanf("%s %d %c", name, &age, &gender);     //&: 주소 반환
//     printf("이 름 : %s \n", name);
//     printf("나 이 : %d \n", age);
//     printf("성 별 : %c \n", gender);
// }



// #include <stdio.h>

// /**
//  * @brief 문자폭 지정 연습, 정밀도 지정
//  * 
//  */

// int main()
// {
//     int num =12345;      //정수값 가진 변수 선언과 동시에 값 대입
//     float x = 12.34567;

//     printf("%d \n", num);
//     printf("%d \n", num*10);
//     printf("%d \n", num*100);
//     printf("%d \n", num*1000);

//     printf("%8d \n", num);
//     printf("%8d \n", num*10);
//     printf("%8d \n", num*100);
//     printf("%8d \n", num*1000);

//     printf("%8d \n", num*100000);   //문자 지정폭보다 큰 수 출력
//     printf("%08d \n", num);

//     printf("\n\n");     //단 구분

//     printf("%f\n", x);
//     printf("%.2f\n", x);    //소수 2자리 이하 출력
//     printf("%f\n", x);
// }



// #include <stdio.h>

// /**
//  * @brief 서식지정자 연습
//  * 
//  * @return int 
//  */
// int main()
// {
//     int num;    //정수형 변수 선언
//     float x;    //실수형 변수 선언
//     char c;     //문자 변수 선언

//     num = 123;
//     x = 1.23;
//     c= 'A';

//     //서식지정자는 출력값의 갯수하고 반드시 같아야 한다.

//     printf("%d, %X \n", num, num);
//     printf("%f, %e \n", x, x);
//     printf("%c \n", c);

//     return 0;
// }



// #include <stdio.h>

// void fun()
// {
//     printf("현재 함수: %s\n", __FUNCTION__);
// }

// int main()
// {
//     printf("컴파일 날짜 %s \n", __DATE__);
//     printf("컴파일 시간: %s \n", __TIME__);
//     printf("컴파일 날짜 요일 시간 %s \n", __TIMESTAMP__);
//     printf("라인 번호 %d \n", __LINE__);
//     fun();
//     printf("현재 소스 파일 위치: %s \n\n", __FILE__);
// }



// #include <stdio.h>

// #define NUM 10

// int main()
// {
// #ifdef NUM
//     printf("NUM은 %d 입니다.\n",NUM);
// #else 
//     printf("NUM은 정의되지 않앗습니다. \n");
// #endif

//     return 0;
// }


// #include <stdio.h>

// #define NUM 10

// int main()
// {
// #if NUM < 10
//     printf("NUM은 10보다 작다\n");
// #elif NUM > 10
//     printf("NUM은 10보다 크다\n");
// #else
//     printf("NUM은 10이다\n");
// #endif

// return 0;
// }



// #include <stdio.h>


// #define CLAC(x, y) ((x)+(y))

// int main()
// {
//     printf("%d \n", CLAC(10,20));
// }



// define 연습; 주석화 하고 싶은 부분 선택 후 ctrl /
// #include <stdio.h>

// #define APPLE 10
// #define NAME "사과"     // 쌍따옴표는 문자열, 따옴표는 문자


// int main()
// {
//     printf("%s %d개 가 있습니다. \n", NAME, APPLE);
//     /* 서식 지정자는 순서대로 구분한다.
//     c: 문자, s: 문자열, d: 숫자 */
//     return 0;
// }
