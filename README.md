# ft_printf
## 코드 작성 전 알아야할 사항
1. 로직 생각해보기
   1. printf 함수에서 구현하는 사항과 구현을 따라하지 말아야할 사항에 대해서 인지 후, 학습하기.
2. 가변인자에 대해서 공부하기
3. 팔만코딩경 확인하면서 코딩하기
4. libft 사용 시, Makefile 사용방법과 설정해주기.
----
### 진행과정
23. 12. 4(Mon)
1. 장훈이한테 가변 인자 및  기본적인 동작 설명 받음 -> 이해한대로, 일단 값을 잘 받아오는지 확인하자!
----
23. 12. 8(Fri)
1. 가변 인자로 받은 값을 인식하여, 어떤 메소드를 활용할 것인지 결정하고 해당 메소드가 원본 printf함수와 동일하게 동작할 수 있도록 코드 작성하기.
----
23. 12. 11(Mon)
1. 포멧 지정자에 따라 실행될 함수들 작성 거의 완성
2. 기본적인 가변인자 사용법과 고정인자 가변인자 등에 대한 설명 상현이형 한테 받음! (한달만에 봄;)
3. 남은 함수들 먼저 구현하고, 포맷 지정자에 따른 분기 함수 작성하기
4. 그 이후, 오류 고쳐가는 식으로 마무리 하기
----
23. 12. 18(Mon)
1. ft_printf 본 함수와 format_branch 함수에서 parse 하는 방법이 복잡해서 오류가 발생했음.
-> 브랜치에 보내기 전, 파싱을 한 후 값들을 보내줘, 정상적으로 작동하는 것을 확인했다.
2. %u 구현하지 않아서 터졌는데, 함수 구현 후 정상적으로 작동했다.
-> paco 통과 (Mandantory part)
3. paco -s 결과 재귀함수를 사용하는 포멧 지정자에서 오류가 발생하는 것을 확인했다.
-> 현재 %d 의 재귀함수를 수정하고 있어, 한 재귀함수를 해결하면 연쇄적으로 정상적으로 실행될 것이다.
4. 처음 %%c 의 경우 ft_printf에서 포멧 지정자와 겹쳐, 기대와 다르게 작동했으나, '%'를 기준으로
있는 경우 없는 경우 분기를 나눠 정상적으로 작동하도록 해결했다.

## ft_printf 가변인자 개념 공부
int printf(const char *format, ...)

format 문자열 상수 -> 서식 문자열이라 부름
두 번째 이후의 인수에 타입과 인수 이름이 명시되어 있지 않으며 대신 생략 기호(ellipsis)인 ... 이 적혀있음.
생략 기호는 컴파일러에게 이후의 인수에 대해서는 개수와 타입을 점검하지 않도록 한다.
=> 이 기호에 의해 가변 인수를 사용할 수 있다.
컴파일러는 이 후의 인수에 대해선 타입, 개수에 상관 없이 그대로 함수에 넘겨준다.
대신 전달된 인수의 정확한 타입을 판별하여 꺼내쓰는 것은 함수가 알아서 해야한다.

생략 기호 이전에 전달되는 인수 -> 고정 인수
printf 함수의 경우 format 인수가 고정 인수
고정 인수 -> 원형의 타입과 개수가 분명히 명시, 원형대로 정확하게 전달해야한다.
printf의 첫 번째 인수는 반드시 const char * 타입의 서식 문자열이어야 한다.
그 다음인 두 번째 인수부터 가변인수

## va_list va_ptr
함수로 전달되는 인수들은 스택이라는 기억 장소에 저장.
함수는 스택에서 인수를 꺼내 씀. 스택에 있는 인수를 읽을 때 포인터 연산을 해야하는데 현재 읽고 있는 번지를 기억하기 위해 va_list 형의 포인터 변수 하나가 필요.
va_list 타입은 char *형으로 정의.
가변 인수를 읽기 위한 포인터 변수 선언

## 	va_start(va_ptr, 마지막 고정인수)
가변 인수를 읽기 위한 준비
va_ptr 포인터 변수가 첫 번째 가변 인수를 가리키도록 초기화
첫 번째 가변 인수의 번지를 조사하기 위해 마지막 고정 인수를 전달해줘야함.
va_start 내부에서 마지막 고정 인수 다음 번지로 va_ptr를 맞춤.
이후부터 va_ptr 내부에서는 마지막 고정 인수 다음 번지로 포인터를 맞춰, 순서대로 가변 인수를 읽을 수 있다.

## va_arg(va_ptr, 인수 타입)
가변 인수를 실제로 읽는 명령
va_start가 va_ptr를 첫 번째 가변 인수 번지로 맞춤.
va_ptr 위치에 있는 값을 읽기만 하면 된다.
단, va_ptr번지에 있는 값이 어떤 타입인지를 알아야 함. 두 번째 인수로 읽고자 하는 값의 타입을 지정해줘야함.
va_ptr 위치에 정수 값을 읽고자 한다면, va_arg(va_ptr, int)를 호출.
-> 변수형에 따라서 변수형을 넣어주면 된다.
이 명령은 va_ptr 위치에서 타입에 맞는 값을 읽어 리턴, va_ptr를 다음 가변 인수 위치로 옮겨줌.
va_arg를 반복적으로 호출, 전달된 가변 인수를 순서대로 읽을 수 있다.

## va_end(va_ptr)
가변 인수를 다 읽은 후 뒷 정리를 하고, 실제로 없어도 전혀 지장 없음
이 명령이 필요한 이유 -> 호환성
플랫폼에 따라 가변 인수를 읽은 후, 뒷처리를 해줘야 할 필요가 있다.
인텔 계열의 CPU에선 va_end가 아무 일을 하지 않는다.
다른 플랫폼이나 미래의 환경, va_end가 중요한 역할을 할 수 있으므로 호환성을 위해선 관례적으로 넣어주는 게 좋다.

----
## format 처리하다가 궁금했던 문제점
### format_pointer
피신 기간에도 메모리 주소를 16진수로 찍는 방법을 몰랐어서 C02 마지막 문제를 못 했었는데, 그저 pointer를 16진수로 변환 후, 맨 처음에 0x를 붙혀주면 됐다.
---
### format_hex
메모리 주소를 찍는 방법을 그대로 이용하되, 0x를 안붙힌다. 양수 16진수 값은 잘나왔지만 음수 16진수가 잘 안나왔다. 메모리 주소를 출력하기 위해선 메모리 주소를 받기 위해 unsigned long long 형을 사용했는데, 사실상 16진수 출력은 그럴 필요가 없었던 것이다.\
구글에 검색한 결과 제대로 된 값이 없어 Chat GPT를 사용해서 해결했는데, 결국 시스템 상과 일반적으로 음수 16진수 값을 구할 땐, 보수화를 통해 구하기 때문에 값을 unsigned int 형으로 캐스팅을 한 후, 16진수를 구하는 방법으로 해결를 하는 점을 학습했다.\
 해당 지식 학습 후, 코드를 수정하여 원형 printf()함수와 동일하게 나오는 것을 확인했다.