#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int main()
{
    FILE *fp = fopen("relic.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    int relic_number;
    int relic_id[1505];
    char relic_type[1505][100];
    char relic_part[1505][100];
    int relic_level[1505];
    char relic_mainoption[1505][100];
    double relic_suboption_atk[1500];
    double relic_suboption_atkp[1500];
    double relic_suboption_def[1500];
    double relic_suboption_defp[1500];
    double relic_suboption_hp[1500];
    double relic_suboption_hpp[1500];
    double relic_suboption_spd[1500];
    double relic_suboption_break[1500];
    double relic_suboption_effrate[1500];
    double relic_suboption_effres[1500];
    double relic_suboption_critrate[1500];
    double relic_suboption_critdmg[1500];
    
    fscanf(fp, "%d", &relic_number);
    for(int i = 0; i < relic_number; i++) {
        fscanf(fp, "%d", &relic_id[i]);
        fscanf(fp, "%s", relic_type[i]);
        fscanf(fp, "%s", relic_part[i]);
        fscanf(fp, "%d", &relic_level[i]);
        fscanf(fp, "%s", relic_mainoption[i]);
        fscanf(fp, "%lf", &relic_suboption_atk[i]);
        fscanf(fp, "%lf", &relic_suboption_atkp[i]);
        fscanf(fp, "%lf", &relic_suboption_def[i]);
        fscanf(fp, "%lf", &relic_suboption_defp[i]);
        fscanf(fp, "%lf", &relic_suboption_hp[i]);
        fscanf(fp, "%lf", &relic_suboption_hpp[i]);
        fscanf(fp, "%lf", &relic_suboption_spd[i]);
        fscanf(fp, "%lf", &relic_suboption_break[i]);
        fscanf(fp, "%lf", &relic_suboption_effrate[i]);
        fscanf(fp, "%lf", &relic_suboption_effres[i]);
        fscanf(fp, "%lf", &relic_suboption_critrate[i]);
        fscanf(fp, "%lf", &relic_suboption_critdmg[i]);
    }

    printf("There are %d relics uploaded.\n", relic_number);

    /* for(int i = 0; i < relic_number; i++) {
        printf("%d %s %s %d %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", relic_id[i], relic_type[i], relic_part[i], relic_level[i], relic_mainoption[i], relic_suboption_atk[i], relic_suboption_atkp[i], relic_suboption_def[i], relic_suboption_defp[i], relic_suboption_hp[i], relic_suboption_hpp[i], relic_suboption_spd[i], relic_suboption_break[i], relic_suboption_effrate[i], relic_suboption_effres[i], relic_suboption_critrate[i], relic_suboption_critdmg[i]);
    } */

    fclose(fp);

    while(1) {
        printf("1. 유물 추가\n");
        printf("2. 유물 삭제\n");
        printf("3. 유물 검색\n");
        printf("4. 유물 수정\n");
        printf("5. 유물 목록\n");
        printf("6. 종료\n");
        
        int pressed = getche();
        getche();
        switch(pressed) {
            case '1':
                system("cls");
                printf("유물 추가\n");
                break;
            case '2':
                system("cls");
                printf("유물 삭제\n");
                break;
            case '3':
                system("cls");
                printf("유물 검색\n");
                break;
            case '4':
                system("cls");
                printf("유물 수정\n");
                break;
            case '5':
                system("cls");
                printf("유물 목록\n");
                
                for(int i = 0; i < relic_number; i++) {
                   printf("%d %s %s %d %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", relic_id[i], relic_type[i], relic_part[i], relic_level[i], relic_mainoption[i], relic_suboption_atk[i], relic_suboption_atkp[i], relic_suboption_def[i], relic_suboption_defp[i], relic_suboption_hp[i], relic_suboption_hpp[i], relic_suboption_spd[i], relic_suboption_break[i], relic_suboption_effrate[i], relic_suboption_effres[i], relic_suboption_critrate[i], relic_suboption_critdmg[i]);
                }

                getch();
                break;
            case '6':
                return 6;
            default:
                system("cls");
                printf("잘못된 입력입니다.\n");
                break;
        }
        system("cls");
    }

    getch();
    return 0;
}