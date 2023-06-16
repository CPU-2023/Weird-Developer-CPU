#include "blue_night_in_jeju.h"
#include "modules.h"


int blue_night_in_jeju_main() {
    init();
    while (1) {
        BtitleDraw();
        int menuCode = BmenuDraw();
        if (menuCode == 0) {
            // 게임시작
            start();

        }
        else if (menuCode == 1) {
            // 게임정보
            BinfoDraw();
        }
        else if (menuCode == 2) {
            // 게임 종료
            return 0;
        }
        system("cls");
    }

    return 0;
}


int BkeyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}

void BtitleDraw() {
    int x = 17, y = 3;


    gotoxy(x, y++); printf(" _______  ___      __   __  _______    __    _  ___   _______  __   __  _______");
    gotoxy(x, y++); printf("|  _    ||   |    |  | |  ||       |  |  |  | ||   | |       ||  | |  ||       |");
    gotoxy(x, y++); printf("| |_|   ||   |    |  | |  ||    ___|  |   |_| ||   | |    ___||  |_|  ||_     _|");
    gotoxy(x, y++); printf("|       ||   |    |  |_|  ||   |___   |       ||   | |   | __ |       |  |   |");
    gotoxy(x, y++); printf("|  _   | |   |___ |       ||    ___|  |  _    ||   | |   ||  ||       |  |   |");
    gotoxy(x, y++); printf("| |_|   ||       ||       ||   |___   | | |   ||   | |   |_| ||   _   |  |   | ");
    gotoxy(x, y++); printf("|_______||_______||_______||_______|  |_|  |__||___| |_______||__| |__|  |___| ");

    gotoxy(x, y++); printf("		 ___   __    _        ___  _______      ___  __   __             ");
    gotoxy(x, y++); printf("		|   | |  |  | |      |   ||       |    |   ||  | |  |      ");
    gotoxy(x, y++); printf("		|   | |   |_| |      |   ||    ___|    |   ||  | |  |          ");
    gotoxy(x, y++); printf("		|   | |       |      |   ||   |___     |   ||  |_|  |       ");
    gotoxy(x, y++); printf("		|   | |  _    |   ___|   ||    ___| ___|   ||       |     ");
    gotoxy(x, y++); printf("		|   | | | |   |  |       ||   |___ |       ||       |     ");
    gotoxy(x, y++); printf("		|___| |_|  |__|  |_______||_______||_______||_______|   ");




    x = 17, y = 17;
    gotoxy(x, y);

}

void Binit() {
    system("mode con:cols=120 lines=30 | title Snake Game");

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}

void BinfoDraw() {
    int x = 25, y = 5;
    system("cls");
    printf("\n\n");


    gotoxy(x, y++); printf("========================= [♥조작법♥]=========================");
    // gotoxy(x, y++); printf("|															  |");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("            이동 : W, S, A, D(위, 아래, 왼쪽, 오른쪽)         ");
    gotoxy(x, y++); printf("			선택 : 스페이스바                                 ");
    gotoxy(x, y++); printf("	    스페이스바를 누르면 메인화면으로 이동합니다.		  ");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("===============================================================");
    gotoxy(x, y++);

    gotoxy(x, y++); printf("========================[ ♥게임 방법♥]=======================");
    // gotoxy(x, y++); printf("|															   |");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("   		        벽에 닿으면 죽어요!   		   	              ");
    gotoxy(x, y++); printf("	             먹이 5개까지 먹으면 성공!                     ");
    gotoxy(x, y++); printf("	  스페이스바를 누르면 메인화면으로 이동합니다.	    	  ");
    gotoxy(x, y++);
    gotoxy(x, y++); printf("===============================================================");
    gotoxy(x, y++);
    // gotoxy(x, y++); printf("		    [ Developed by : 김민서 / 고은 / 김서연 ]		   ");



    while (1) {
        if (BkeyControl() == SUBMIT) {
            break;
        }
    }
}

int BmenuDraw() {
    int x = 53, y = 20;
    gotoxy(x - 2, y); printf("> 게 임 시 작");
    gotoxy(x, y + 1); printf("게 임 정 보");
    gotoxy(x, y + 2); printf("게 임 종 료");

    while (1) {
        int n = BkeyControl();
        switch (n) {
        case UP: {
            if (y > 20) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }

        case DOWN: {
            if (y < 22) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 20;
        }
        }
    }


}


//지렁이를 구현할 이중연결리스트 구조체
#pragma pack(push,1)
typedef struct _WORM
{
    int x;   //x좌표
    int y;   //y좌표
    char direction;   //진행방향
    struct _WORM* next;   //다음노드주소
    struct _WORM* before;//이전노드주소
}WORM, * pWORM;

//아이템을 구현할 단일연결리스트 구조체
typedef struct _ITEM
{
    int x;
    int y;
    int itemType;
    int itemNo;
    struct _ITEM* next;
}ITEM, * pITEM;
#pragma pack(pop)

//커서를 일정 좌표로 이동
/*
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = x + LEFT_MARGIN;//가로세로 비율을 맞추기 위해서 가로의 좌표는 2배
    Pos.Y = y + TOP_MARGIN;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
*/

//게임영역출력
void PrintField()
{
    for (int i = 1; i < FIELD_WIDTH; i++)
    {
        gotoxy(i, 0);
        printf("─");
        gotoxy(i, FIELD_HEIGHT);
        printf("─");
    }

    for (int i = 1; i < FIELD_HEIGHT; i++)
    {
        gotoxy(0, i);
        printf("│");
        gotoxy(FIELD_WIDTH, i);
        printf("│");
    }
    gotoxy(0, 0);
    printf("┌");
    gotoxy(0, FIELD_HEIGHT);
    printf("└");
    gotoxy(FIELD_WIDTH, 0);
    printf("┐");
    gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
    printf("┘");
}

//지렁이를 늘리는 함수(이중연결리스트의 테일쪽에 노드 추가)
void AddWorm(pWORM wormTailNode)
{
    pWORM newNode = malloc(sizeof(WORM));
    pWORM temp = wormTailNode->next;

    //새 노드의 주솟값 이어주기;
    newNode->before = wormTailNode;
    newNode->next = wormTailNode->next;
    wormTailNode->next = newNode;
    newNode->next->before = newNode;
    newNode->direction = temp->direction;
    newNode->x = temp->x;
    newNode->y = temp->y;
    switch (temp->direction)
    {
    case LEFT:
        newNode->x = newNode->x + 1;
        break;
    case RIGHT:
        newNode->x = newNode->x - 1;
        break;
    case UP:
        newNode->y = newNode->y + 1;
        break;
    case DOWN:
        newNode->y = newNode->y - 1;
        break;
    default:
        break;
    }


}

//연결리스트를 받아서 지렁이 출력
void PrintWorm(pWORM wormTailNode, pWORM wormHeadNode)
{
    pWORM curr = wormTailNode->next;
    while (curr != wormHeadNode)
    {
        gotoxy(curr->x, curr->y);
        printf("O");
        curr = curr->next;
    }
}

//게임점수 출력
void PrintScore(int score)
{
    gotoxy(FIELD_WIDTH + 3, 3);
    printf("Score : %d점", score);
    gotoxy(FIELD_WIDTH + 3, 5);
    printf("종료하려면 Q를 누르세요");
    gotoxy(FIELD_WIDTH + 3, 7);
    printf("조작은 화살표키로");
}

//웜이 지나간 자리 지우기
void ClearWorm(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
}

//웜 움직이기 
void MoveSnake(pWORM wormTailNode, pWORM wormHeadNode)
{
    pWORM curr;

    curr = wormTailNode->next;
    while (curr != NULL && curr != wormHeadNode->before)
    {
        curr->x = curr->next->x;
        curr->y = curr->next->y;
        curr = curr->next;
    }
    curr = wormHeadNode->before;
    if (curr->direction == LEFT)
    {
        curr->x--;
    }
    else if (curr->direction == RIGHT)
    {
        curr->x++;
    }
    else if (curr->direction == UP)
    {
        curr->y--;
    }
    else if (curr->direction == DOWN)
    {
        curr->y++;
    }
}


//웜 리스트에 할당된 메모리를 순차로 해제
void FreeWormList(pWORM wormTailNode)
{
    pWORM curr;
    pWORM temp;
    curr = wormTailNode;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

//item 발생시키기
void CreateItem(pITEM itemNode, int* itemNo) {

    pITEM newItem = malloc(sizeof(ITEM));

    newItem->next = itemNode->next;
    newItem->itemNo = (*itemNo)++;
    itemNode->next = newItem;
    newItem->x = 3 + rand() % (FIELD_WIDTH - 3);
    newItem->y = 3 + rand() % (FIELD_HEIGHT - 3);
    newItem->itemType = ITEM_EXP;
}

//아이템 화면에 출력
void PrintItem(pITEM itemNode)
{
    pITEM curr = itemNode->next;
    while (curr != NULL)
    {
        gotoxy(curr->x, curr->y);
        printf("@");
        curr = curr->next;
    }
}

//리스트에서 itemNo의 위치를 찾아서 카운터를 리턴
int findItemNoInList(pITEM itemNode, int itemNo)
{
    int numberOfNode = 0;   //노드번호를 저장할 변수

    pITEM curr;      //노드사이를 움직일 포인터
    curr = itemNode->next;      //첫번째 데이터를 가지키는 주소를 curr에 할당

    while (curr != NULL)   //반복문을 돌리면서 찾는 데이터를 발견하면 노드번호를 리턴
    {
        numberOfNode++;
        if (itemNo == curr->itemNo)
        {
            return numberOfNode;
        }
        curr = curr->next;
    }

    return numberOfNode;
}


//아이템의 노드번호를 받아 그 번호의 노드를 삭제
void delItemFromList(pITEM itemNode, int targetNodeNumber)
{
    pITEM beforeTarget;      //제거할 노드의 앞노드
    pITEM target;      //제거할 노드

    int counter = 0;

    beforeTarget = itemNode;

    if (targetNodeNumber < 0)   // 0이 입력되면 FirstNode를 삭제하기 때문에 실행하지 않고 리턴
        return 0;

    //노드를 targetNodeNumber-1 만큼 이동시켜서 beforeTarget을 제거할 노드 앞으로 이동시킴
    while (counter < targetNodeNumber - 1)
    {
        beforeTarget = beforeTarget->next;
        counter = counter + 1;
    }

    //노드를 리스트에서 제거
    target = beforeTarget->next;
    beforeTarget->next = target->next;
    free(target);
}

//아이템(골뱅이)와 웜의 헤드가 만났는지 검사, 
//delItemNo는 먹은 아이템을 지우는 함수로 넘겨줄 변수
int CheckItemHit(pWORM wormHeadPointer, pITEM itemNode, int* delItemNo)
{
    pITEM curr;
    int nodeNo = 0;
    curr = itemNode->next;
    while (curr != NULL)
    {
        if (wormHeadPointer->x == curr->x && wormHeadPointer->y == curr->y)
        {
            if (curr->itemType == ITEM_EXP)
            {
                *delItemNo = curr->itemNo;
                return 1; //아이템 먹으면 1리턴
            }
        }
        nodeNo++;
        curr = curr->next;
    }
    return 0;//아이템을 안만나면 0
}

//아이템의 링크드 리스트 메모리 해제
void FreeItemList(pITEM itemNode)
{
    pITEM curr;
    pITEM temp;
    curr = itemNode;
    while (curr != NULL)
    {
        temp = curr->next;
        free(curr);
        curr = temp;
    }
}

//실행시 테스트용으로 만들어 놓은 아이템 생성 리스트 출력함수
/*
void PrintItemList(pITEM itemNode)
{
   pITEM curr;
   curr = itemNode->next;
   gotoxy( -LEFT_MARGIN, 2);
   while (curr != NULL)
   {
      printf("아이템번호 : %d\n", curr->itemNo);
      curr = curr->next;
   }
}
*/
int start()
{
    pWORM wormHeadNode = malloc(sizeof(WORM));//이중연결리스트 헤드노드
    pWORM wormTailNode = malloc(sizeof(WORM));//이중연결리스트 테일노드
    pWORM addWorm = malloc(sizeof(WORM));//첫번째 웜몸통
    pITEM itemNode = malloc(sizeof(ITEM));//아이템용 단일 연결리스트


    wormHeadNode->next = NULL;
    wormHeadNode->before = addWorm;
    addWorm->next = wormHeadNode;
    addWorm->before = wormTailNode;
    addWorm->x = FIELD_WIDTH / 2;
    addWorm->y = FIELD_HEIGHT / 2;
    addWorm->direction = RIGHT;
    wormTailNode->next = addWorm;
    wormTailNode->before = NULL;

    itemNode->next = NULL;
    itemNode->itemNo = -1;

    //지렁이 게임시작 지렁이 생성
    for (int i = 9; i > 0; i--)
        AddWorm(wormTailNode);

    //웜의 머리를 가리키는 포인터
    pWORM wormHeadPointer = addWorm;

    int score = 0;         //최초점수
    int itemCounter = 0;   //아이템 생성 한도 카운터
    char key;            //키입력받을 변수
    int delItemNo = 0;      //지울아이템넘버를 받을 변수초기화
    int itemNo = 10000;//아이템의 최초번호

    //아이템 생성 위치 난수 시드
    srand((unsigned int)time(NULL));

    system("cls");   //화면지우고
    PrintField();   //필드 출력


    while (1)
    {
        //테스트용 출력부분
        //gotoxy(-LEFT_MARGIN, 0);
        //printf("먹은 아이템 : %d\n",delItemNo);
        //PrintItemList(itemNode);

        if (_kbhit() != 0)
        {

            key = _getch();
            if (key == 'q' || key == 'Q')
            {
                printf("%c", key);
                break;
            }
            if (key == LEFT && wormHeadPointer->direction != RIGHT)
            {
                wormHeadPointer->direction = LEFT;
            }
            else if (key == RIGHT && wormHeadPointer->direction != LEFT)
            {
                wormHeadPointer->direction = RIGHT;
            }
            else if (key == UP && wormHeadPointer->direction != DOWN)
            {
                wormHeadPointer->direction = UP;
            }
            else if (key == DOWN && wormHeadPointer->direction != UP)
            {
                wormHeadPointer->direction = DOWN;
            }
        }

        //웜 지나간 자리 지우기
        ClearWorm(wormTailNode->next->x, wormTailNode->next->y);

        //웜 한칸씩 움직이기
        MoveSnake(wormTailNode, wormHeadNode);

        if (score >= 600) {
            system("cls");
            gotoxy(FIELD_WIDTH + 5, FIELD_HEIGHT + 5);
            printf("\n");
            printf("		 __    _  _______  _______  ______   ___      _______  _______ \n");
            printf("		|  |  | ||       ||       ||      | |   |    |       ||       |\n");
            printf("		|   |_| ||   _   ||   _   ||  _    ||   |    |    ___||  _____|\n");
            printf("		|       ||  | |  ||  | |  || | |   ||   |    |   |___ | |_____ \n");
            printf("		|  _    ||  |_|  ||  |_|  || |_|   ||   |___ |    ___||_____  |\n");
            printf("		| | |   ||       ||       ||       ||       ||   |___  _____| |\n");
            printf("		|_|  |__||_______||_______||______| |_______||_______||_______|\n");

            printf("		 _______  ______    _______    ______   _______  __    _  _______ \n");
            printf("		|   _   ||    _ |  |       |  |      | |       ||  |  | ||       |\n");
            printf("		|  |_|  ||   | ||  |    ___|  |  _    ||   _   ||   |_| ||    ___|\n");
            printf("		|       ||   |_||_ |   |___   | | |   ||  | |  ||       ||   |___ \n");
            printf("		|       ||    __  ||    ___|  | |_|   ||  |_|  ||  _    ||    ___|\n");
            printf("		|   _   ||   |  | ||   |___   |       ||       || | |   ||   |___ \n");
            printf("		|__| |__||___|  |_||_______|  |______| |_______||_|  |__||_______|\n");
            printf("");
            FreeWormList(wormTailNode);
            FreeItemList(itemNode);
            return 0;
        }
        //벽에 부딛히면 게임오버
        if (wormHeadPointer->x == 0 || wormHeadPointer->x == FIELD_WIDTH || wormHeadPointer->y == 0 || wormHeadPointer->y == FIELD_HEIGHT)
        {
            system("cls");
            gotoxy(FIELD_WIDTH + 5, FIELD_HEIGHT + 5);
            printf("\n");
            printf("			 _______  _______  __   __  _______    _______  __   __  _______  ______ \n");
            printf("			|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |\n");
            printf("			|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||\n");
            printf("			|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_\n");
            printf("			|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n");
            printf("			|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n");
            printf("			|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n");
            printf("						벽에 부딛혔습니다.");
            FreeWormList(wormTailNode);
            FreeItemList(itemNode);
            return 0;
        }

        //아이템을 생성
        while (itemCounter < ITEM_MAX)
        {
            CreateItem(itemNode, &itemNo);
            itemCounter++;
        }

        //아이템 먹었는지 확인
        if (CheckItemHit(wormHeadPointer, itemNode, &delItemNo))
        {
            AddWorm(wormTailNode);
            delItemFromList(itemNode, findItemNoInList(itemNode, delItemNo));
            score += 100;
            itemCounter--;
        }
        PrintItem(itemNode);
        PrintWorm(wormTailNode, wormHeadNode);
        PrintScore(score);
        Sleep(DELAYTIME);
    }

    FreeWormList(wormTailNode);
    FreeItemList(itemNode);

    return 0;
}


