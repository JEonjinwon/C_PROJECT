/*--------------------------------------------------------------------------------------------------------------

이 프로그램은 과제를 위해 제작되었습니다.

*프로그램을 사용하기 전에 c드라이브에 gametxt.txt파일이 있어야 됩니다*

TEMPROJECT.C
게임 프로그램

김민성 + 전진원
1560006 + 1560050

--------------------------------------------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



#define MAX   10
#define count 10
#define RIGHT 77    //오른쪽의 값
#define LEFT  75    //왼쪽의 값
#define DOWN  80    //아래의 값
#define UP    72    //위의 값
#define END   27    // ESC의 값


#define SCISSOR 1 // 가위 
#define ROCK 2 // 바위 
#define PAPER 3 // 보 

//구조체 사용
struct student
{
	char producer[100];
	char producername1[100];
	int  producernumber1;
	char producername2[100];
	int  producernumber2;
	

};


//   외부변수로 퍼즐 배열을 만든다  
int puzzle[MAX][MAX];
//  퍼즐 배열의 숫자 0의 현재 위치   
int current_x;
int current_y;
int length;  
// n*n 행렬에서 n의 숫자를 length 로 저장하며 행렬의 경계를 검사하는데이용한다 
int difficult; 
// 숫자를 섞을 때 for문을 몇 번 돌릴 것인지 결정한다
void name1(void);
// 9조
void number_level(void);
//퍼즐의 난이도 설정
void number_intro(void);
//프로그램을 설명한다
int dowhile(void);
//반복을 수행한다
void number_first(void); 
// 정렬을 이용하여 퍼즐을 초기화 한다
void number_key(int key);
// 방향키를 이용하여 숫자를 이동시킨다
int number_check(void); 
// 이동시킨 퍼즐이 정렬되었는지 확인하다.
void number_finish(void);
//퍼즐의 성공을 알린다
void number_size(void);
//퍼즐의 크기를 선택한다
void regame(void);
//재경기
void numgameplay(void);
//게임 설명
void number_game(void);
//숫자게임기능모음
void number1(void);
//숫자게임 총설명

void finger_game(void);
//가위바위보기능모음
void finger_gameplay(void);
//가위바위보 설명
void finger(void);
//가위바위보값을 숫자로 변환
void finger_intro(void);
//가위바위보 시작하는함수
int inputNumber ( void );
//숫자 입력받는 함수
int finger_computer ( int playerNumber ); 
//가위바위보 컴퓨터값을 받는함수
void printMenu ( int win, int lose, int draw ); 
//스코어보드

void menu (void);
//파일처리로 접속을 저장

int producer_title(void);
//구조체로 개발자의 정보를 입력

void main(void)
{


   name1();  //프로그램 소개하는 함수

   producer_title();//규조체로 개발자의 정보를 보여줌

   menu();          //파일 처리로 접속을 저장함

   finger_game();   // 가위 바위 보 게임 
   
   number_game();   // 숫자 게임 


}


//───────────────────────프로그램을 소개하는 함수───────────────────────

void name1(void)


{
   printf("\n");
   printf("\n");
   printf("              TERMPROJECT  \n");
   printf("\n");
   printf("\n");
   printf("┌────────────────────────────┐\n");
   printf("│                                                        │\n");
   printf("│         * 가위 바위 보                                 │\n");
   printf("│                                                        │\n");
   printf("│         * 숫자게임                                     │\n");
   printf("│                                                        │\n");
   printf("│         * 개발자 : 전진원 + 김민성                     │\n");
   printf("│                                                        │\n");
   printf("│         * 학번 : 1560050 1560006                       │\n");
   printf("│                                                        │\n");
   printf("└────────────────────────────┘\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");  
   
   
   system("pause");
   system("cls");
}


//───────────────────────숫자 퍼즐 게임───────────────────────

//숫자게임의 기능을 묶은 함수

void number_game(void)
{

   number_intro();

   number1();

   number_size();

   number_level();
   
   number_first();

   dowhile();

}


//숫자게임의 시작을 알려주는 함수

void number_intro(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n"); 
   printf("                   *숫자 퍼즐 게임                                        \n");
   printf("\n");
   printf("┌─────────────────────────────────────┐\n");
   printf("│                                                                          │\n");
   printf("│                                                                          │\n");
   printf("│                  * 개발자 : 전진원 + 김민성                              │\n");
   printf("│                                                                          │\n");
   printf("│                  * 개발 일자 : 2015 . 11.9 ~~ 11.29                      │\n");
   printf("│                                                                          │\n");
   printf("│                  * 학번 : 1560050 1560006                                │\n");
   printf("│                                                                          │\n");
   printf("└─────────────────────────────────────┘\n");
   printf("\n");
   printf("                 게임을 시작 합니다 : ENTER\n");
   printf("\n");
   
    system("pause");
    system("cls");
}


//숫자게임 시작할때 설명

void number1(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("       숫자게임 \n");
   printf("\n");
   printf("┌───────────────────────────────────┐\n");
   printf("│                                                                      │\n");
   printf("│      *1부터 나열하는 게임입니다.                                     │\n"); 
   printf("│      *3x3부터 9x9까지 크기를 선택할수 있습니다.                      │\n");
   printf("│                                                                      │\n");
   printf("│         ex) 3x3                                                      │\n");
   printf("│            ┌───────┐                                        │\n");
   printf("│            │              │                                        │\n");
   printf("│            │     1 2 3    │                                        │\n");
   printf("│            │     4 5 6    │                                        │\n");
   printf("│            │     7 8 0    │                                        │\n");
   printf("│            │              │                                        │\n");
   printf("│            └───────┘                                        │\n");
   printf("│                                                                      │\n");
   printf("│      *1부터 9까지 난이도를 고를 수 있습니다.                         │\n");
   printf("│                                                                      │\n");
   printf("│                                                                      │\n");
   printf("└───────────────────────────────────┘\n");
   printf("\n");
   printf("                 게임을 시작 합니다 : ENTER\n");
   printf("\n");
   printf("\n");


   system("pause");
   system("cls");



}

//숫자게임의 크키를 정하는 함수

void number_size(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                  게임의 크기를 고르세요.  \n");
   printf("\n");
   printf("┌───────────────────────────────────┐\n");
   printf("│                                                                      │\n");
   printf("│                n x n 퍼즐입니다.                                     │\n");  
   printf("│                                                                      │\n");
   printf("│                크기를 선택하세요. (몇 x 몇 퍼즐)                     │\n");
   printf("│                                                                      │\n");
   printf("│                단 3 x 3 ~~~ 9 x 9 중에 가능합니다.                   │\n");
   printf("│                                                                      │\n");
   printf("└───────────────────────────────────┘\n");
   printf("\n");
   printf("                 3 ~~ 9 사이의 숫자를 입력하세요 : ");

   scanf("%d",&length);
   
   system("cls");
}


//숫자게임의 난이도를 선택하는 함수


void number_level(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                  게임의 난이도를 입력하세요.\n");
   printf("┌───────────────────────────────────┐\n");
   printf("│                                                                      │\n");
   printf("│                난이도를 입력하세요.                                  │\n");
   printf("│                                                                      │\n");
   printf("│                단 1 ~~~ 9 중에 선택 가능 합니다.                     │\n");
   printf("│                                                                      │\n");
   printf("└───────────────────────────────────┘\n");
   printf("\n");
   printf("                 1 ~~ 9 사이의 숫자를 입력하세요 : ");
   
   scanf("%d",&difficult);
   printf("\nENTER를 눌러주세요");
   printf("\n");
   printf("\n");
    
   
   system("cls");
}


//숫자게임의 끝을 알려주는 함수

void number_finish(void)
{
   system("cls");
   
   
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("┌───────────────────────────────────┐\n");
   printf("│                                                                      │\n");
   printf("│        게임이 끝나셨습니다.                                          │\n");
   printf("│                                                                      │\n");
   printf("│        수고하셨습니다.                                               │\n");
   printf("│                                                                      │\n");
   printf("│        게임을 다시 하시려면 아무키나 누르세요.                       │\n");
   printf("│                                                                      │\n");
   printf("└───────────────────────────────────┘\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("개발자 : 전진원 + 김민성\n");
   printf("\n");
   printf("\n");

   system("pause");
   system("cls");
   
   regame();
   
   printf("\n");
   printf("\n");
   

}

//숫자게임을 다시 시작을 설명하는 함수

void regame(void)
{
   printf("\n");
   printf("\n");
   printf("개발자 : 전진원 + 김민성\n");
   printf("\n");
   printf("\n");
   printf("┌───────────────────────────────────┐\n");
   printf("│                                                                      │\n");
   printf("│        게임을 다시 시작합니다.                                       │\n");
   printf("│                                                                      │\n");
   printf("│        규칙은 전과 동일 합니다.                                      │\n");
   printf("│                                                                      │\n");
   printf("│          0은 빈칸을 나타냅니다.                                      │\n");
   printf("│          방향키를 사용하여 플레이 합니다.                            │\n");
   printf("│          게임을 종료하고 싶으시면 esc를 눌러주세요.                  │\n");
   printf("│          게임 종료후 바로 재게임이 실행됩니다.                       │\n");
   printf("│                                                                      │\n");
   printf("│                                                                      │\n");
   printf("└───────────────────────────────────┘\n");
   printf("\n");
   printf("\n");
}

//

int dowhile(void)
{
   do
   {

      number_key( getch() );// getch는 입력받은 문자를 화면에 보여주지 않으며 방향키와 같은 특수 문자도 입력받음.
                      // getch는 getchar과 달리 엔터를 입력 받지 않아도 된다.
      count;

   }

   while ( number_check() );
 
   return 0;
}


//숫자게임의 초기 모양을 주는 함수 

void number_first(void)
{
   int i, j; // 순환을 위한 변수
   int x1, y1 , x2, y2; // 두 개의 숫자를 섞기위한 변수
   int temp; // 변수를 섞을 때 사용되는 임시 변수

//퍼즐배열에 숫자 초기값 넣기

   current_x = 0;
   current_y = 0;

   // for문을 두 번 돌리면 정방형 정렬에 0부터 차례대로 숫자가 채워진다
   
   for (i=0; i<length; i++) 
      for (j=0; j < length; j++)
            puzzle[i][j] = j + i * length;

// rand()함수를 이용하여 x1,y1,x2,y2를 임의의 숫자가 발생하도록 한다
// 두 수의 좌표를 length로 나눈 나머지를 이용하여 난수의 범위를 length 보다 작은 수가 나오도록 한다.

//퍼즐 배열 섞기 

   for (i=0; i < difficult; i++)
   {
  
//랜덤함수로 난수 사용

      x1 = rand() % length;
      y1 = rand() % length;
      x2 = rand() % length;
      y2 = rand() % length;
      

      temp = puzzle[y1][x1];
      puzzle[y1][x1] = puzzle[y2][x2];
      puzzle[y2][x2] = temp;


      // 0의 값을 갖는 좌표를 항상 모니터링하기 위하여 만약 이동 시킨 값이 0 이면 current_x와 current_y값을 바꾼다 
      if (puzzle[y1][x1]==0)
      {
         current_y = y1;
         current_x = x1;
      }
      else
      if (puzzle[y2][x2]==0)
        {
         current_y = y2;
         current_x = x2;
      }
   }



//  퍼즐배열의 초기값 출력  
   for (i=0; i<length; i++)
   {
      for (j=0; j < length; j++)
      {
            printf("%2d ",puzzle[i][j]);
      }
      printf("\n");
   }
  numgameplay();
   }


//숫자게임 설명함수

void numgameplay(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("┌──────────────────────┐\n");
   printf("│                                            │\n");
   printf("│         게임 설명                          │\n");
   printf("│                                            │\n");
   printf("│ 1부터 숫자를 순서대로 나열하는 게임입니다. │\n");
   printf("│                                            │\n");
   printf("│ 게임의 시작은 위의 모양과 같습니다         │\n");
   printf("│ 0은 빈칸을 나타냅니다                      │\n");
   printf("│ 방향키를 사용하여 플레이 합니다            │\n");
   printf("│ 게임을 종료하고 싶으시면 esc를 눌러주세요. │\n");
   printf("│ 게임 종료후 바로 재게임이 실행됩니다.      │\n");
   printf("│                                            │\n");
   printf("└──────────────────────┘\n");
   printf("\n");
   printf("\n");
}


// 방향키로 움직이게 입력받는 함수 

void number_key(int key)
{
   int i, j;


   switch(key)
   {
      case LEFT :
               if ( current_x < length-1 )
               {
                  puzzle[current_y][current_x] =
                  puzzle[current_y][current_x + 1];
                  current_x++;
               }
               break;


      case RIGHT : 
               if ( current_x > 0)
               {
                  puzzle[current_y][current_x] =
                  puzzle[current_y][current_x - 1];
                  current_x--;
               }
               break;


      case UP : 
               if ( current_y < length-1)
               {
                  puzzle[current_y][current_x] =
                  puzzle[current_y + 1][current_x];
                  current_y++;
               }
               break;


      case DOWN : 
               if ( current_y > 0)
               {
                  puzzle[current_y][current_x] =
                  puzzle[current_y - 1][current_x];
                  current_y--;
               }
               break;


      case END :
            printf("\n");
            printf("\n");
               printf("숫자 퍼즐 게임을 그만 합니다.");
            printf("\n");
               
            number_finish();
            
   }

   puzzle[current_y][current_x] = 0;


// 퍼즐배열 출력
   for (i=0; i<length; i++)
   {
      for (j=0; j < length; j++)
      {
            printf("%2d ",puzzle[i][j]);
      }
      printf("\n");
   }
	  printf("\n");
}


int number_check(void)
{
   int i, j;

//퍼즐배열의 값들이 정렬되었는지 체크

   for (i=0; i < length; i++)
     
	   for (j=0; j < length; j++)
         
		  if (puzzle[i][j] != j+i*length)
           
			 return 1;
  
   return 0;
}



// ───────────────────────가위 바위 보 게임───────────────────────

//가위 바위 보 게임을 묶은 함수

void finger_game(void)
{
   finger_intro();

   finger_gameplay();
    
   finger();

}


//가위 바위 보 게임을 설명하는 함수

void finger_gameplay(void)
{
   printf("\n");
   printf("\n");
   printf("          가위바위보 게임 설명\n");
   printf("\n");
   printf("\n");
   printf("┌──────────────────────┐\n");
   printf("│                                            │\n");
   printf("│ 게임 설명                                  │\n");
   printf("│                                            │\n");
   printf("│ 1번을 누를시 가위입니다.                   │\n");
   printf("│ 2번을 누를시 바위입니다.                   │\n");
   printf("│ 3번을 누를시 보입니다.                     │\n");
   printf("│ 4번을 누를시 다음 게음으로 넘어 갑니다.    │\n");
   printf("│                                            │\n");
   printf("└──────────────────────┘\n");
   printf("\n");
   printf("\n");
   printf("  계속하려면 눌러주세요 : ENTER  \n");
   printf("\n");
   printf("\n");


   system("pause");
   system("cls");
}



//가위바위보를 1,2,3,으로 입력받고 4를 다음게임으로 넘기는 함수 

void finger(void)
{
   int inputNum = 0; 
   //< 승리 패배 무승부 
   int winNumber = 0; 
   int loseNumber = 0; 
   int drawNumber = 0; 
   //< 승패 여부 
   int result = 0; 
   //< 시드 재정렬 
 

   while( inputNum != 4 ) 
   { 
      printMenu( winNumber, loseNumber, drawNumber ); 
      inputNum = inputNumber(); 

      if ( inputNum == 4 ) continue; 
  
     result = finger_computer ( inputNum ); 
      
     switch ( result ) 
      { 
         case 1: 
         { 
            winNumber++; 
         } 
         break; 
         case 2: 
         { 
            loseNumber++; 
         } 
         break; 
         case 3: 
         { 
            drawNumber++; 
         } 
         break; 
      } 
   } 
      
   
  
   return; 
} 



//가위바위보게임의 시작하는 함수

void finger_intro(void)
{  
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                   가위 바위 보 게임                                     \n");
   printf("\n");
   printf("┌────────────────────────────────────┐\n");
   printf("│                                                                        │\n");
   printf("│                                                                        │\n");
   printf("│                 *개발자 : 전진원 + 김민성                              │\n");
   printf("│                                                                        │\n");
   printf("│                 *개발 일자 : 2015 . 11.9 ~~ 11.29                      │\n");
   printf("│                                                                        │\n");
   printf("│                 *학번 : 1560050 1560006                                │\n");
   printf("│                                                                        │\n");
   printf("└────────────────────────────────────┘\n");
   printf("\n");
   printf("                 게임을 시작 합니다 : ENTER\n");
   printf("\n");
   printf("\n");

   system("pause");
   system("cls");

}


//가위바위보 게임 다시하는 함수
int inputNumber ( void ) 
{ 
   int number = 0; 
   while ( number <= 0 || number > 4 ) 
   { 
      printf("\n 입력 해주세요. : " ); 
      scanf("%d", &number );

       system("cls");

      if  (number <= 0 || number > 4 ) 
      { 
       printf("\n");
       printf("\n");
       printf("         잘못 입력 하셨습니다.\n"); 
       printf("\n");
       printf("\n");
       printf("         게임을 다시 설명합니다.\n");
       printf("\n");
       printf("\n");
       printf("┌──────────────────────┐\n");
       printf("│                                            │\n");
       printf("│ 게임 설명                                  │\n");
       printf("│                                            │\n");
       printf("│ 1번을 누를시 가위입니다.                   │\n");
       printf("│ 2번을 누를시 바위입니다.                   │\n");
       printf("│ 3번을 누를시 보입니다.                     │\n");
       printf("│ 4번을 누를시 다음 게음으로 넘어 갑니다.    │\n");
       printf("│                                            │\n");
       printf("└──────────────────────┘\n");
       printf("\n");
       printf("\n");
      } 
   } 
   
   return number; 
} 



//컴퓨터의 가위바위보값을 받는 함수

int finger_computer ( int playerNumber ) 
{ 
   int computer = (rand()%3) + 1; 
   
   switch ( playerNumber ) 
   { 
      case SCISSOR: 
      { 
       printf("\n");
       printf("\n");   
       printf("   게임 상황\n");
       printf("┌───────────────────┐\n");
       printf("│                                      │\n");
       printf("│사용자 : 가위                         │\n"); 
       switch ( computer ) 
         { 
            case SCISSOR: 
            { 
               printf("│컴퓨터 : 가위                         │\n");  
               printf("│무승부                                │\n"); 
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 3; 
            } 
            break; 
            case ROCK: 
            { 
               printf("│컴퓨터 : 바위                         │\n"); 
               printf("│패배                                  │\n");
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 2; 
            } 
            break; 
            case PAPER: 
            { 
               printf("│컴퓨터 : 보                           │\n"); 
               printf("│승리                                  │\n");
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
            return 1; 
            } 
            break; 
         } 
      } 
      break; 
      
     case ROCK: 
      {  
       printf("\n");
       printf("\n");
       printf("   게임 상황\n");
       printf("┌───────────────────┐\n");
       printf("│                                      │\n");
       printf("│사용자 : 바위                         │\n" ); 
         switch ( computer ) 
         { 
            case SCISSOR: 
            { 
               printf("│컴퓨터 : 가위                         │\n"); 
               printf("│승리                                  │\n"); 
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 1; 
            } 
            break; 
            case ROCK: 
            { 
               printf("│컴퓨터 : 바위                         │\n"); 
               printf("│무승부                                │\n"); 
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
            return 3; 
            } 
            break; 
            case PAPER: 
            { 
               printf("│컴퓨터 : 보                           │\n"); 
               printf("│패배                                  │\n"); 
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 2; 
            } 
            break; 
         } 
      } 
      break; 
     
     case PAPER: 
      {
       printf("\n");
         printf("\n");
       printf("   게임 상황\n");
       printf("┌───────────────────┐\n");
       printf("│                                      │\n");
       printf("│사용자 : 보                           │\n" ); 
         switch ( computer ) 
         { 
            case SCISSOR: 
            { 
               printf("│컴퓨터 : 가위                         │\n");  
               printf("│패배                                  │\n"); 
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 2; 
            } 
            break; 
            case ROCK: 
            { 
               printf("│컴퓨터 : 바위                         │\n");  
               printf("│승리                                  │\n"); 
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 1; 
            } 
            break; 
            case PAPER: 
            { 
               printf("│컴퓨터 : 보                           │\n"); ; 
               printf("│무승부                                │\n");  
               printf("│                                      │\n");
               printf("└───────────────────┘\n");
               return 3; 
            } 
            break; 
         } 
      } 
      break; 
   } 
} 


//가위바위보게임의 스코어를 보여주는 함수

void printMenu ( int win, int lose, int draw ) 
{ 
   printf("\n");
   printf("                           가위 바위 보 게임\n");
   printf("\n");
   printf("┌────────────────────────────────────┐\n");
   printf("│                                                                        │\n");  
   printf("│                          현재까지의 스코어                             │\n" ); 
   printf("│                                                                        │\n");  
   printf("│              승리 : %-2d       패배 : %-2d       무승부 : %-2d               │\n", win, lose, draw ); 
   printf("│                                                                        │\n");  
   printf("│               1. 가위   2. 바위   3. 보   4. 다음게임으로 이동         │\n" ); 
   printf("│                                                                        │\n");  
   printf("└────────────────────────────────────┘\n");

} 




//----------------------------파일 처리 텍스트 -----------------------------------------------------------------


void menu (void)
{

		
		FILE *fstream;
		fstream = fopen("C:\\gametxt.txt", "a+" );

		if (fstream)
			{
				printf("\n");
				printf("\n");
				printf("\n");
				printf("            FBI warring\n");
				printf("\n");
			    printf("┌────────────────────────────────────┐\n");
				printf("│                                                                        │\n"); 
				printf("│          게임을 플레이 하시면 접속 기록이 남습니다.                    │\n");
				printf("│                                                                        │\n"); 
				printf("│          접속 기록이 괜찮으시면 ENTER을 눌러주세요.                    │\n");
				printf("│                                                                        │\n"); 
				printf("└────────────────────────────────────┘\n"); 
				printf("\n");
				printf("\n");
				printf("\n");
			   
			 
				char fname[];
				printf("이름: \n");
				scanf("%s\n"&fname);


				fwrite("fnamn", strlen("fname"),100,fstream);
			
				
			
				printf("\n");
				printf("\n");
				printf("            FBI warring\n");
				printf("\n");
				printf("┌────────────────────────────────────┐\n");
				printf("│                                                                        │\n");
				printf("│          c드라이브 gametxt.txt 파일에 접속 기록이 남았습니다.          │\n");
				printf("│                                                                        │\n"); 
				printf("└────────────────────────────────────┘\n"); 
				printf("\n");
				printf("\n");
				printf("\n");
		

				system("pause");
				system("cls");

			}	
		
			fclose(fstream);

		

} 


//-------------------------------------구조체를 이용한 개발자 소개-----------------------------------------------------

int producer_title(void)
{
	struct student s1;
	

	strcpy(s1.producer, "목원대 정보통신융합공학부");
	strcpy(s1.producername1, "전진원");
	s1.producernumber1 = 1560050;
	strcpy(s1.producername2, "김민성");
	s1.producernumber2 = 1560006;


	printf("\n");
	printf("\n");
	printf("              프로그램 개발자 \n");
	printf("\n");
    printf("\n");
	printf("┌───────────────────────────────┐\n");
	printf("│                                                              │\n");
	printf("│                *소속 : %s             │\n",s1.producer);
	printf("│                                                              │\n");
	printf("│                *이름 : %s                                │\n", s1.producername1);                 
	printf("│                *학번 : %d                               │\n", s1.producernumber1);
	printf("│                                                              │\n");
	printf("│                *이름 : %s                                │\n", s1.producername2);
	printf("│                *학번 : %d                               │ \n", s1.producernumber2);	
	printf("│                                                              │\n");
    printf("└───────────────────────────────┘\n");
	printf("\n");
    printf("\n");

	system("pause");
    system("cls");


	return 0;

}
