#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int playerScore = 0;
    int dealerScore = 0;
    char choice;

    // 카드 덱 초기화
    int deck[40];
    for (int i = 0; i < 40; i++) {
        deck[i] = (i % 10) + 1;
    }

    // 카드 섞기
    for (int i = 0; i < 40; i++) {
        int j = rand() % 40;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // 플레이어와 딜러에게 카드 나누기
    playerScore += deck[0];
    dealerScore += deck[1];
    playerScore += deck[2];
    dealerScore += deck[3];

    printf("플레이어: %d\n", playerScore);
    printf("딜러: ?\n");

    // 플레이어에게 추가 카드 받을지 여부 묻기
    printf("카드를 더 받으시겠습니까? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') { // 반복문을 사용하여 중복 코드 제거

        playerScore += deck[playerScore / 10 + 4]; // 플레이어에게 추가 카드 주기
        printf("플레이어: %d\n", playerScore);
        printf("딜러: ?\n");

        if (playerScore > 21) {
            printf("플레이어 버스트! 딜러 승리!\n");
            return 0; // 버스트 시 종료
        }

        // 플레이어에게 추가 카드 받을지 여부 묻기
        printf("카드를 더 받으시겠습니까? (y/n): ");
        scanf(" %c", &choice);
    }

    // 딜러의 추가 카드 주기
    while (dealerScore < 17) {
        dealerScore += deck[dealerScore / 10 + 4];
    }
    // 게임 결과 출력
    printf("플레이어: %d\n", playerScore);
    printf("딜러: %d\n", dealerScore);

    if (playerScore > 21) {
        printf("플레이어 버스트! 딜러 승리!\n");
    }
    else if (dealerScore > 21) {
        printf("딜러 버스트! 플레이어 승리!\n");
    }
    else if (playerScore > dealerScore) {
        printf("플레이어 승리!\n");
    }
    else if (playerScore < dealerScore) {
        printf("딜러 승리!\n");
    }
    else {
        printf("무승부!\n");
    }

    // 게임 재시작 여부 확인
    printf("게임을 다시 플레이하시겠습니까? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // 게임 초기화 코드 추가
    }

    return 0;
}

