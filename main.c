#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <math.h>

#include "relic.h"

#include "relicfunction.c"
#include "menu.c"

struct Relic relics[1505];
int relic_number;

int main()
{
    Read_relic();

    while(1) {
        printf("1. ���� �߰�\n");
        printf("2. ���� ����\n");
        printf("3. ���� �˻�\n");
        printf("4. ���� ����\n");
        printf("5. ���� ���\n");
        printf("6. ����\n");
        
        int pressed;
        scanf("%d", &pressed);

        switch(pressed) {
            case 1:
                Relic_add();
                break;

            case 2:
                Delete_relic();
                break;

            case 3:
                Search_relic();
                break;

            case 4:
                Modify_relic();
                break;

            case 5:
                Relic_list();
                getch();
                break;

            case 6:
                return 6;

            default:
                system("cls");
                break;
        }
        system("cls");
    }

    getch();
    return 0;
}