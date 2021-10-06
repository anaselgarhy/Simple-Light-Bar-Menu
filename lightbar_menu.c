#include <stdio.h>
#include <windows.h>
#include <conio.h>

void draw_box(void);
void gotoxy(int x,int y);


void main(void)
{
    // Hide cursor
    ShowConsoleCursor(0);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    short int pos=1;
    char ch;

   draw_box();
    do{
        SetConsoleTextAttribute(hConsole , 15); // or 00001111
        gotoxy(40, 11); printf("1|Add a new record            ");
        gotoxy(40, 12); printf("2|Update a new record         ");
        gotoxy(40, 13); printf("3|Delete an existing record   ");
        gotoxy(40, 14); printf("4|Exit                        ");
        printf("\n");

        switch(pos){
            case 1:
            SetConsoleTextAttribute(hConsole , 240); // or 11110000
            gotoxy(40, 11); printf("1|Add a new record            ");
            break;
            case 2:
            SetConsoleTextAttribute(hConsole , 240); // or 11110000
            gotoxy(40, 12); printf("2|Update a new record         ");
            break;
            case 3:
            SetConsoleTextAttribute(hConsole , 240); // or 11110000
            gotoxy(40, 13); printf("3|Delete an existing record   ");
            break;
            case 4:
            SetConsoleTextAttribute(hConsole , 240); // or 11110000
            gotoxy(40, 14); printf("4|Exit                        ");
            break;

        }

        ch = getch();
        //Navigation with arrow buttons
        if(ch == -32)
        {
            ch = getch();
            if(ch == 72)
            {
                // up
                pos--;
                if(pos == 0) pos=4;
            }
            else if(ch == 80)
            {
                //down
                pos++;
                if(pos == 5) pos=1;
            }

        }
    }while(1);


}
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void ShowConsoleCursor(short showFlag)
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = (showFlag == 0)? 100:0;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void draw_box(void)
{
    int i, n;
    gotoxy(39, 10);
    printf("%c", 201); // code ╔ in ASCII
    for(i=0; i<30; i++)
        printf("%c", 205); // code ═ in ASCII
    printf("%c", 187); // code ╗ in ASCII
    for(i=0, n=11; i < 4; i++, n++){
        gotoxy(39, n);
        printf("%c", 186); // code ║ in ASCII
        for(int i=0; i<30; i++)
            printf("%c", 32); // code space in ASCII
        printf("%c", 186); // code ║ in ASCII
    }
    gotoxy(39, 15);
        printf("%c", 200); // code ╚ in ASCII
        for(int i=0; i<30; i++)
            printf("%c", 205); // code ═ in ASCII
        printf("%c", 188); // code ╝ in ASCII

}



















