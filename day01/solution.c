#include <stdio.h>      // printf(), scanf()를 사용하기 위한 헤더
#include <limits.h>     // INT_MIN(가장 작은 int 값)을 사용하기 위한 헤더

// 가장 큰 수와 두 번째로 큰 수를 찾는 함수
void FindSecondMax(int num[], int size)
{
    int first;              // 가장 큰 수를 저장할 변수
    int second;             // 두 번째로 큰 수를 저장할 변수
    int second_max_index;   // 두 번째로 큰 수의 인덱스를 저장할 변수
    int i;                  // 반복문에서 사용할 변수

    // 배열의 크기가 2보다 작으면 비교가 불가능
    if (size < 2)
    {
        printf("배열의 크기가 2 미만입니다.\n");
        return;             // 함수 종료
    }

    // 가장 큰 수와 두 번째 큰 수를 가장 작은 정수값으로 초기화
    first = INT_MIN;
    second = INT_MIN;

    // 아직 두 번째 큰 수를 찾지 못했으므로 -1로 초기화
    second_max_index = -1;

    // 배열을 처음부터 끝까지 검사
    for (i = 0; i < size; i++)
    {
        // 현재 값이 가장 큰 수보다 크다면
        if (num[i] > first)
        {
            // 기존 가장 큰 수를 두 번째 큰 수로 저장
            second = first;

            // 현재 값을 가장 큰 수로 저장
            first = num[i];

            // 현재 위치를 두 번째 큰 수의 위치로 저장
            // (나중에 second가 갱신되면 다시 변경됨)
            second_max_index = i;
        }

        // 현재 값이
        // 1. 두 번째 큰 수보다 크고
        // 2. 가장 큰 수와는 다른 값이라면
        else if (num[i] > second && num[i] != first)
        {
            // 두 번째 큰 수를 변경
            second = num[i];

            // 두 번째 큰 수의 위치 저장
            second_max_index = i;
        }
    }

    // second가 아직도 INT_MIN이면
    // 서로 다른 두 번째 큰 수를 찾지 못한 경우
    if (second == INT_MIN)
    {
        printf("두 번째로 큰 서로 다른 값이 없습니다.\n");
    }
    else
    {
        // 결과 출력
        printf("가장 큰 수 : %d\n", first);
        printf("두 번째로 큰 수 : %d\n", second);
        printf("두 번째로 큰 수의 인덱스 : %d\n", second_max_index);
    }
}

int main()
{
    int num[10];    // 최대 10개의 정수를 저장할 배열
    int n;          // 입력받을 배열의 크기
    int i;          // 반복문 변수

    // 배열 크기 입력
    printf("배열의 크기(최대 10) : ");
    scanf("%d", &n);

    // 입력 범위 확인
    if (n < 1 || n > 10)
    {
        printf("잘못된 크기입니다.\n");
        return 0;
    }

    // 배열 값 입력 안내
    printf("%d개의 정수를 입력하세요.\n", n);

    // 배열에 정수 입력
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    // 가장 큰 수와 두 번째 큰 수를 찾는 함수 호출
    FindSecondMax(num, n);

    return 0;   // 프로그램 정상 종료
}
