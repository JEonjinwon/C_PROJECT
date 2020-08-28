/*--------------------------------------------------------------------------------------------------------------

�� ���α׷��� ������ ���� ���۵Ǿ����ϴ�.

*���α׷��� ����ϱ� ���� c����̺꿡 gametxt.txt������ �־�� �˴ϴ�*

TEMPROJECT.C
���� ���α׷�

��μ� + ������
1560006 + 1560050

--------------------------------------------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



#define MAX   10
#define count 10
#define RIGHT 77    //�������� ��
#define LEFT  75    //������ ��
#define DOWN  80    //�Ʒ��� ��
#define UP    72    //���� ��
#define END   27    // ESC�� ��


#define SCISSOR 1 // ���� 
#define ROCK 2 // ���� 
#define PAPER 3 // �� 

//����ü ���
struct student
{
	char producer[100];
	char producername1[100];
	int  producernumber1;
	char producername2[100];
	int  producernumber2;
	

};


//   �ܺκ����� ���� �迭�� �����  
int puzzle[MAX][MAX];
//  ���� �迭�� ���� 0�� ���� ��ġ   
int current_x;
int current_y;
int length;  
// n*n ��Ŀ��� n�� ���ڸ� length �� �����ϸ� ����� ��踦 �˻��ϴµ��̿��Ѵ� 
int difficult; 
// ���ڸ� ���� �� for���� �� �� ���� ������ �����Ѵ�
void name1(void);
// 9��
void number_level(void);
//������ ���̵� ����
void number_intro(void);
//���α׷��� �����Ѵ�
int dowhile(void);
//�ݺ��� �����Ѵ�
void number_first(void); 
// ������ �̿��Ͽ� ������ �ʱ�ȭ �Ѵ�
void number_key(int key);
// ����Ű�� �̿��Ͽ� ���ڸ� �̵���Ų��
int number_check(void); 
// �̵���Ų ������ ���ĵǾ����� Ȯ���ϴ�.
void number_finish(void);
//������ ������ �˸���
void number_size(void);
//������ ũ�⸦ �����Ѵ�
void regame(void);
//����
void numgameplay(void);
//���� ����
void number_game(void);
//���ڰ��ӱ�ɸ���
void number1(void);
//���ڰ��� �Ѽ���

void finger_game(void);
//������������ɸ���
void finger_gameplay(void);
//���������� ����
void finger(void);
//�������������� ���ڷ� ��ȯ
void finger_intro(void);
//���������� �����ϴ��Լ�
int inputNumber ( void );
//���� �Է¹޴� �Լ�
int finger_computer ( int playerNumber ); 
//���������� ��ǻ�Ͱ��� �޴��Լ�
void printMenu ( int win, int lose, int draw ); 
//���ھ��

void menu (void);
//����ó���� ������ ����

int producer_title(void);
//����ü�� �������� ������ �Է�

void main(void)
{


   name1();  //���α׷� �Ұ��ϴ� �Լ�

   producer_title();//����ü�� �������� ������ ������

   menu();          //���� ó���� ������ ������

   finger_game();   // ���� ���� �� ���� 
   
   number_game();   // ���� ���� 


}


//�������������������������������������������������α׷��� �Ұ��ϴ� �Լ�����������������������������������������������

void name1(void)


{
   printf("\n");
   printf("\n");
   printf("              TERMPROJECT  \n");
   printf("\n");
   printf("\n");
   printf("������������������������������������������������������������\n");
   printf("��                                                        ��\n");
   printf("��         * ���� ���� ��                                 ��\n");
   printf("��                                                        ��\n");
   printf("��         * ���ڰ���                                     ��\n");
   printf("��                                                        ��\n");
   printf("��         * ������ : ������ + ��μ�                     ��\n");
   printf("��                                                        ��\n");
   printf("��         * �й� : 1560050 1560006                       ��\n");
   printf("��                                                        ��\n");
   printf("������������������������������������������������������������\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");  
   
   
   system("pause");
   system("cls");
}


//�������������������������������������������������� ���� ���Ӧ���������������������������������������������

//���ڰ����� ����� ���� �Լ�

void number_game(void)
{

   number_intro();

   number1();

   number_size();

   number_level();
   
   number_first();

   dowhile();

}


//���ڰ����� ������ �˷��ִ� �Լ�

void number_intro(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n"); 
   printf("                   *���� ���� ����                                        \n");
   printf("\n");
   printf("������������������������������������������������������������������������������\n");
   printf("��                                                                          ��\n");
   printf("��                                                                          ��\n");
   printf("��                  * ������ : ������ + ��μ�                              ��\n");
   printf("��                                                                          ��\n");
   printf("��                  * ���� ���� : 2015 . 11.9 ~~ 11.29                      ��\n");
   printf("��                                                                          ��\n");
   printf("��                  * �й� : 1560050 1560006                                ��\n");
   printf("��                                                                          ��\n");
   printf("������������������������������������������������������������������������������\n");
   printf("\n");
   printf("                 ������ ���� �մϴ� : ENTER\n");
   printf("\n");
   
    system("pause");
    system("cls");
}


//���ڰ��� �����Ҷ� ����

void number1(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("       ���ڰ��� \n");
   printf("\n");
   printf("��������������������������������������������������������������������������\n");
   printf("��                                                                      ��\n");
   printf("��      *1���� �����ϴ� �����Դϴ�.                                     ��\n"); 
   printf("��      *3x3���� 9x9���� ũ�⸦ �����Ҽ� �ֽ��ϴ�.                      ��\n");
   printf("��                                                                      ��\n");
   printf("��         ex) 3x3                                                      ��\n");
   printf("��            ������������������                                        ��\n");
   printf("��            ��              ��                                        ��\n");
   printf("��            ��     1 2 3    ��                                        ��\n");
   printf("��            ��     4 5 6    ��                                        ��\n");
   printf("��            ��     7 8 0    ��                                        ��\n");
   printf("��            ��              ��                                        ��\n");
   printf("��            ������������������                                        ��\n");
   printf("��                                                                      ��\n");
   printf("��      *1���� 9���� ���̵��� �� �� �ֽ��ϴ�.                         ��\n");
   printf("��                                                                      ��\n");
   printf("��                                                                      ��\n");
   printf("��������������������������������������������������������������������������\n");
   printf("\n");
   printf("                 ������ ���� �մϴ� : ENTER\n");
   printf("\n");
   printf("\n");


   system("pause");
   system("cls");



}

//���ڰ����� ũŰ�� ���ϴ� �Լ�

void number_size(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                  ������ ũ�⸦ ������.  \n");
   printf("\n");
   printf("��������������������������������������������������������������������������\n");
   printf("��                                                                      ��\n");
   printf("��                n x n �����Դϴ�.                                     ��\n");  
   printf("��                                                                      ��\n");
   printf("��                ũ�⸦ �����ϼ���. (�� x �� ����)                     ��\n");
   printf("��                                                                      ��\n");
   printf("��                �� 3 x 3 ~~~ 9 x 9 �߿� �����մϴ�.                   ��\n");
   printf("��                                                                      ��\n");
   printf("��������������������������������������������������������������������������\n");
   printf("\n");
   printf("                 3 ~~ 9 ������ ���ڸ� �Է��ϼ��� : ");

   scanf("%d",&length);
   
   system("cls");
}


//���ڰ����� ���̵��� �����ϴ� �Լ�


void number_level(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                  ������ ���̵��� �Է��ϼ���.\n");
   printf("��������������������������������������������������������������������������\n");
   printf("��                                                                      ��\n");
   printf("��                ���̵��� �Է��ϼ���.                                  ��\n");
   printf("��                                                                      ��\n");
   printf("��                �� 1 ~~~ 9 �߿� ���� ���� �մϴ�.                     ��\n");
   printf("��                                                                      ��\n");
   printf("��������������������������������������������������������������������������\n");
   printf("\n");
   printf("                 1 ~~ 9 ������ ���ڸ� �Է��ϼ��� : ");
   
   scanf("%d",&difficult);
   printf("\nENTER�� �����ּ���");
   printf("\n");
   printf("\n");
    
   
   system("cls");
}


//���ڰ����� ���� �˷��ִ� �Լ�

void number_finish(void)
{
   system("cls");
   
   
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("��������������������������������������������������������������������������\n");
   printf("��                                                                      ��\n");
   printf("��        ������ �����̽��ϴ�.                                          ��\n");
   printf("��                                                                      ��\n");
   printf("��        �����ϼ̽��ϴ�.                                               ��\n");
   printf("��                                                                      ��\n");
   printf("��        ������ �ٽ� �Ͻ÷��� �ƹ�Ű�� ��������.                       ��\n");
   printf("��                                                                      ��\n");
   printf("��������������������������������������������������������������������������\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("������ : ������ + ��μ�\n");
   printf("\n");
   printf("\n");

   system("pause");
   system("cls");
   
   regame();
   
   printf("\n");
   printf("\n");
   

}

//���ڰ����� �ٽ� ������ �����ϴ� �Լ�

void regame(void)
{
   printf("\n");
   printf("\n");
   printf("������ : ������ + ��μ�\n");
   printf("\n");
   printf("\n");
   printf("��������������������������������������������������������������������������\n");
   printf("��                                                                      ��\n");
   printf("��        ������ �ٽ� �����մϴ�.                                       ��\n");
   printf("��                                                                      ��\n");
   printf("��        ��Ģ�� ���� ���� �մϴ�.                                      ��\n");
   printf("��                                                                      ��\n");
   printf("��          0�� ��ĭ�� ��Ÿ���ϴ�.                                      ��\n");
   printf("��          ����Ű�� ����Ͽ� �÷��� �մϴ�.                            ��\n");
   printf("��          ������ �����ϰ� �����ø� esc�� �����ּ���.                  ��\n");
   printf("��          ���� ������ �ٷ� ������� ����˴ϴ�.                       ��\n");
   printf("��                                                                      ��\n");
   printf("��                                                                      ��\n");
   printf("��������������������������������������������������������������������������\n");
   printf("\n");
   printf("\n");
}

//

int dowhile(void)
{
   do
   {

      number_key( getch() );// getch�� �Է¹��� ���ڸ� ȭ�鿡 �������� ������ ����Ű�� ���� Ư�� ���ڵ� �Է¹���.
                      // getch�� getchar�� �޸� ���͸� �Է� ���� �ʾƵ� �ȴ�.
      count;

   }

   while ( number_check() );
 
   return 0;
}


//���ڰ����� �ʱ� ����� �ִ� �Լ� 

void number_first(void)
{
   int i, j; // ��ȯ�� ���� ����
   int x1, y1 , x2, y2; // �� ���� ���ڸ� �������� ����
   int temp; // ������ ���� �� ���Ǵ� �ӽ� ����

//����迭�� ���� �ʱⰪ �ֱ�

   current_x = 0;
   current_y = 0;

   // for���� �� �� ������ ������ ���Ŀ� 0���� ���ʴ�� ���ڰ� ä������
   
   for (i=0; i<length; i++) 
      for (j=0; j < length; j++)
            puzzle[i][j] = j + i * length;

// rand()�Լ��� �̿��Ͽ� x1,y1,x2,y2�� ������ ���ڰ� �߻��ϵ��� �Ѵ�
// �� ���� ��ǥ�� length�� ���� �������� �̿��Ͽ� ������ ������ length ���� ���� ���� �������� �Ѵ�.

//���� �迭 ���� 

   for (i=0; i < difficult; i++)
   {
  
//�����Լ��� ���� ���

      x1 = rand() % length;
      y1 = rand() % length;
      x2 = rand() % length;
      y2 = rand() % length;
      

      temp = puzzle[y1][x1];
      puzzle[y1][x1] = puzzle[y2][x2];
      puzzle[y2][x2] = temp;


      // 0�� ���� ���� ��ǥ�� �׻� ����͸��ϱ� ���Ͽ� ���� �̵� ��Ų ���� 0 �̸� current_x�� current_y���� �ٲ۴� 
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



//  ����迭�� �ʱⰪ ���  
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


//���ڰ��� �����Լ�

void numgameplay(void)
{
   printf("\n");
   printf("\n");
   printf("\n");
   printf("������������������������������������������������\n");
   printf("��                                            ��\n");
   printf("��         ���� ����                          ��\n");
   printf("��                                            ��\n");
   printf("�� 1���� ���ڸ� ������� �����ϴ� �����Դϴ�. ��\n");
   printf("��                                            ��\n");
   printf("�� ������ ������ ���� ���� �����ϴ�         ��\n");
   printf("�� 0�� ��ĭ�� ��Ÿ���ϴ�                      ��\n");
   printf("�� ����Ű�� ����Ͽ� �÷��� �մϴ�            ��\n");
   printf("�� ������ �����ϰ� �����ø� esc�� �����ּ���. ��\n");
   printf("�� ���� ������ �ٷ� ������� ����˴ϴ�.      ��\n");
   printf("��                                            ��\n");
   printf("������������������������������������������������\n");
   printf("\n");
   printf("\n");
}


// ����Ű�� �����̰� �Է¹޴� �Լ� 

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
               printf("���� ���� ������ �׸� �մϴ�.");
            printf("\n");
               
            number_finish();
            
   }

   puzzle[current_y][current_x] = 0;


// ����迭 ���
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

//����迭�� ������ ���ĵǾ����� üũ

   for (i=0; i < length; i++)
     
	   for (j=0; j < length; j++)
         
		  if (puzzle[i][j] != j+i*length)
           
			 return 1;
  
   return 0;
}



// �������������������������������������������������� ���� �� ���Ӧ���������������������������������������������

//���� ���� �� ������ ���� �Լ�

void finger_game(void)
{
   finger_intro();

   finger_gameplay();
    
   finger();

}


//���� ���� �� ������ �����ϴ� �Լ�

void finger_gameplay(void)
{
   printf("\n");
   printf("\n");
   printf("          ���������� ���� ����\n");
   printf("\n");
   printf("\n");
   printf("������������������������������������������������\n");
   printf("��                                            ��\n");
   printf("�� ���� ����                                  ��\n");
   printf("��                                            ��\n");
   printf("�� 1���� ������ �����Դϴ�.                   ��\n");
   printf("�� 2���� ������ �����Դϴ�.                   ��\n");
   printf("�� 3���� ������ ���Դϴ�.                     ��\n");
   printf("�� 4���� ������ ���� �������� �Ѿ� ���ϴ�.    ��\n");
   printf("��                                            ��\n");
   printf("������������������������������������������������\n");
   printf("\n");
   printf("\n");
   printf("  ����Ϸ��� �����ּ��� : ENTER  \n");
   printf("\n");
   printf("\n");


   system("pause");
   system("cls");
}



//������������ 1,2,3,���� �Է¹ް� 4�� ������������ �ѱ�� �Լ� 

void finger(void)
{
   int inputNum = 0; 
   //< �¸� �й� ���º� 
   int winNumber = 0; 
   int loseNumber = 0; 
   int drawNumber = 0; 
   //< ���� ���� 
   int result = 0; 
   //< �õ� ������ 
 

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



//���������������� �����ϴ� �Լ�

void finger_intro(void)
{  
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                   ���� ���� �� ����                                     \n");
   printf("\n");
   printf("����������������������������������������������������������������������������\n");
   printf("��                                                                        ��\n");
   printf("��                                                                        ��\n");
   printf("��                 *������ : ������ + ��μ�                              ��\n");
   printf("��                                                                        ��\n");
   printf("��                 *���� ���� : 2015 . 11.9 ~~ 11.29                      ��\n");
   printf("��                                                                        ��\n");
   printf("��                 *�й� : 1560050 1560006                                ��\n");
   printf("��                                                                        ��\n");
   printf("����������������������������������������������������������������������������\n");
   printf("\n");
   printf("                 ������ ���� �մϴ� : ENTER\n");
   printf("\n");
   printf("\n");

   system("pause");
   system("cls");

}


//���������� ���� �ٽ��ϴ� �Լ�
int inputNumber ( void ) 
{ 
   int number = 0; 
   while ( number <= 0 || number > 4 ) 
   { 
      printf("\n �Է� ���ּ���. : " ); 
      scanf("%d", &number );

       system("cls");

      if  (number <= 0 || number > 4 ) 
      { 
       printf("\n");
       printf("\n");
       printf("         �߸� �Է� �ϼ̽��ϴ�.\n"); 
       printf("\n");
       printf("\n");
       printf("         ������ �ٽ� �����մϴ�.\n");
       printf("\n");
       printf("\n");
       printf("������������������������������������������������\n");
       printf("��                                            ��\n");
       printf("�� ���� ����                                  ��\n");
       printf("��                                            ��\n");
       printf("�� 1���� ������ �����Դϴ�.                   ��\n");
       printf("�� 2���� ������ �����Դϴ�.                   ��\n");
       printf("�� 3���� ������ ���Դϴ�.                     ��\n");
       printf("�� 4���� ������ ���� �������� �Ѿ� ���ϴ�.    ��\n");
       printf("��                                            ��\n");
       printf("������������������������������������������������\n");
       printf("\n");
       printf("\n");
      } 
   } 
   
   return number; 
} 



//��ǻ���� �������������� �޴� �Լ�

int finger_computer ( int playerNumber ) 
{ 
   int computer = (rand()%3) + 1; 
   
   switch ( playerNumber ) 
   { 
      case SCISSOR: 
      { 
       printf("\n");
       printf("\n");   
       printf("   ���� ��Ȳ\n");
       printf("������������������������������������������\n");
       printf("��                                      ��\n");
       printf("������� : ����                         ��\n"); 
       switch ( computer ) 
         { 
            case SCISSOR: 
            { 
               printf("����ǻ�� : ����                         ��\n");  
               printf("�����º�                                ��\n"); 
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
               return 3; 
            } 
            break; 
            case ROCK: 
            { 
               printf("����ǻ�� : ����                         ��\n"); 
               printf("���й�                                  ��\n");
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
               return 2; 
            } 
            break; 
            case PAPER: 
            { 
               printf("����ǻ�� : ��                           ��\n"); 
               printf("���¸�                                  ��\n");
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
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
       printf("   ���� ��Ȳ\n");
       printf("������������������������������������������\n");
       printf("��                                      ��\n");
       printf("������� : ����                         ��\n" ); 
         switch ( computer ) 
         { 
            case SCISSOR: 
            { 
               printf("����ǻ�� : ����                         ��\n"); 
               printf("���¸�                                  ��\n"); 
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
               return 1; 
            } 
            break; 
            case ROCK: 
            { 
               printf("����ǻ�� : ����                         ��\n"); 
               printf("�����º�                                ��\n"); 
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
            return 3; 
            } 
            break; 
            case PAPER: 
            { 
               printf("����ǻ�� : ��                           ��\n"); 
               printf("���й�                                  ��\n"); 
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
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
       printf("   ���� ��Ȳ\n");
       printf("������������������������������������������\n");
       printf("��                                      ��\n");
       printf("������� : ��                           ��\n" ); 
         switch ( computer ) 
         { 
            case SCISSOR: 
            { 
               printf("����ǻ�� : ����                         ��\n");  
               printf("���й�                                  ��\n"); 
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
               return 2; 
            } 
            break; 
            case ROCK: 
            { 
               printf("����ǻ�� : ����                         ��\n");  
               printf("���¸�                                  ��\n"); 
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
               return 1; 
            } 
            break; 
            case PAPER: 
            { 
               printf("����ǻ�� : ��                           ��\n"); ; 
               printf("�����º�                                ��\n");  
               printf("��                                      ��\n");
               printf("������������������������������������������\n");
               return 3; 
            } 
            break; 
         } 
      } 
      break; 
   } 
} 


//���������������� ���ھ �����ִ� �Լ�

void printMenu ( int win, int lose, int draw ) 
{ 
   printf("\n");
   printf("                           ���� ���� �� ����\n");
   printf("\n");
   printf("����������������������������������������������������������������������������\n");
   printf("��                                                                        ��\n");  
   printf("��                          ��������� ���ھ�                             ��\n" ); 
   printf("��                                                                        ��\n");  
   printf("��              �¸� : %-2d       �й� : %-2d       ���º� : %-2d               ��\n", win, lose, draw ); 
   printf("��                                                                        ��\n");  
   printf("��               1. ����   2. ����   3. ��   4. ������������ �̵�         ��\n" ); 
   printf("��                                                                        ��\n");  
   printf("����������������������������������������������������������������������������\n");

} 




//----------------------------���� ó�� �ؽ�Ʈ -----------------------------------------------------------------


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
			    printf("����������������������������������������������������������������������������\n");
				printf("��                                                                        ��\n"); 
				printf("��          ������ �÷��� �Ͻø� ���� ����� �����ϴ�.                    ��\n");
				printf("��                                                                        ��\n"); 
				printf("��          ���� ����� �������ø� ENTER�� �����ּ���.                    ��\n");
				printf("��                                                                        ��\n"); 
				printf("����������������������������������������������������������������������������\n"); 
				printf("\n");
				printf("\n");
				printf("\n");
			   
			 
				char fname[];
				printf("�̸�: \n");
				scanf("%s\n"&fname);


				fwrite("fnamn", strlen("fname"),100,fstream);
			
				
			
				printf("\n");
				printf("\n");
				printf("            FBI warring\n");
				printf("\n");
				printf("����������������������������������������������������������������������������\n");
				printf("��                                                                        ��\n");
				printf("��          c����̺� gametxt.txt ���Ͽ� ���� ����� ���ҽ��ϴ�.          ��\n");
				printf("��                                                                        ��\n"); 
				printf("����������������������������������������������������������������������������\n"); 
				printf("\n");
				printf("\n");
				printf("\n");
		

				system("pause");
				system("cls");

			}	
		
			fclose(fstream);

		

} 


//-------------------------------------����ü�� �̿��� ������ �Ұ�-----------------------------------------------------

int producer_title(void)
{
	struct student s1;
	

	strcpy(s1.producer, "����� ����������հ��к�");
	strcpy(s1.producername1, "������");
	s1.producernumber1 = 1560050;
	strcpy(s1.producername2, "��μ�");
	s1.producernumber2 = 1560006;


	printf("\n");
	printf("\n");
	printf("              ���α׷� ������ \n");
	printf("\n");
    printf("\n");
	printf("������������������������������������������������������������������\n");
	printf("��                                                              ��\n");
	printf("��                *�Ҽ� : %s             ��\n",s1.producer);
	printf("��                                                              ��\n");
	printf("��                *�̸� : %s                                ��\n", s1.producername1);                 
	printf("��                *�й� : %d                               ��\n", s1.producernumber1);
	printf("��                                                              ��\n");
	printf("��                *�̸� : %s                                ��\n", s1.producername2);
	printf("��                *�й� : %d                               �� \n", s1.producernumber2);	
	printf("��                                                              ��\n");
    printf("������������������������������������������������������������������\n");
	printf("\n");
    printf("\n");

	system("pause");
    system("cls");


	return 0;

}
