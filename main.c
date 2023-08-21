#include <stdio.h>
#include <conio.h>

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
    double relic_suboption_atk[10];
    double relic_suboption_atkp[10];
    double relic_suboption_def[10];
    double relic_suboption_defp[10];
    double relic_suboption_hp[10];
    double relic_suboption_hpp[10];
    double relic_suboption_spd[10];
    double relic_suboption_break[10];
    double relic_suboption_effrate[10];
    double relic_suboption_effres[10];
    double relic_suboption_critrate[10];
    double relic_suboption_critdmg[10];
    
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

    for(int i = 0; i < relic_number; i++) {
        printf("%d %s %s %d %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", relic_id[i], relic_type[i], relic_part[i], relic_level[i], relic_mainoption[i], relic_suboption_atk[i], relic_suboption_atkp[i], relic_suboption_def[i], relic_suboption_defp[i], relic_suboption_hp[i], relic_suboption_hpp[i], relic_suboption_spd[i], relic_suboption_break[i], relic_suboption_effrate[i], relic_suboption_effres[i], relic_suboption_critrate[i], relic_suboption_critdmg[i]);
    }

    fclose(fp);

    printf("1. 유물 추가\n");
    printf("2. 유물 삭제\n");
    printf("3. 유물 검색\n");
    printf("4. 유물 수정\n");
    printf("5. 유물 목록\n");
    printf("6. 종료\n");

    int whattodo;
    whattodo = scanf("%d", &whattodo);

    if(whattodo == 1) {
        printf("유물 추가\n");
    } else if(whattodo == 2) {
        printf("유물 삭제\n");
    } else if(whattodo == 3) {
        printf("유물 검색\n");
    } else if(whattodo == 4) {
        printf("유물 수정\n");
    } else if(whattodo == 5) {
        printf("유물 목록\n");
    } else if(whattodo == 6) {
        printf("종료\n");
    } else {
        printf("잘못된 입력입니다.\n");
    }

    return 0;
}