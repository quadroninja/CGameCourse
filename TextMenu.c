#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>



enum EMenuItems {PLAY, SETTINGS, ABOUT, QUIT};

char *menu_items[] = {
    [PLAY]="Play!",
    [SETTINGS]="Settings",
    [ABOUT]="About",
    [QUIT]="Quit"
};




int main()
{

    char answer;
    int item = 0;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wColor = (1<<4) | 15;
    WORD dColor = (0<<4) | 15;

    char running = 1;
    while(running)
    {
        answer = _getch();
        system("cls");

        switch(answer) {
            case 80: item = (item + 1) % (sizeof(menu_items) / sizeof(char*)); break;
            case 72: item = (item - 1); break;
            case 13: break;
        }
        if (item < 0) item = 2;
        for (int i = PLAY; i <= QUIT; i++)
        {
            if (item == i)
                SetConsoleTextAttribute(hConsole, wColor);
            else
                SetConsoleTextAttribute(hConsole, dColor);
            printf("%s\n", menu_items[i]);
        }
        SetConsoleTextAttribute(hConsole, dColor);

    }
    return 0;
}
