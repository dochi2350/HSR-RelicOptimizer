#include <stdio.h>

#include "relic.h"

struct Relic relics[1505];
int relic_number;

FILE *fp;

void Read_relic() {
    FILE *fp;
    fp = fopen("relic.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    fscanf(fp, "%d", &relic_number);
    for(int i = 1; i <= relic_number; i++) {
        fscanf(fp, "%s", relics[i].type);
        fscanf(fp, "%s", relics[i].part);
        fscanf(fp, "%d", &relics[i].level);
        fscanf(fp, "%s", relics[i].mainoption);
        fscanf(fp, "%lf", &relics[i].suboption_atk);
        fscanf(fp, "%lf", &relics[i].suboption_atkp);
        fscanf(fp, "%lf", &relics[i].suboption_def);
        fscanf(fp, "%lf", &relics[i].suboption_defp);
        fscanf(fp, "%lf", &relics[i].suboption_hp);
        fscanf(fp, "%lf", &relics[i].suboption_hpp);
        fscanf(fp, "%lf", &relics[i].suboption_spd);
        fscanf(fp, "%lf", &relics[i].suboption_breakeff);
        fscanf(fp, "%lf", &relics[i].suboption_effrate);
        fscanf(fp, "%lf", &relics[i].suboption_effres);
        fscanf(fp, "%lf", &relics[i].suboption_critrate);
        fscanf(fp, "%lf", &relics[i].suboption_critdmg);
    }

    printf("There are %d relics uploaded.\n", relic_number);
    fclose(fp);
}

void Relic_add() {
    system("cls");
    printf("유물 추가\n");

    relic_number++;
    printf("유물 종류\n");
    printf("1.  혹한 밀림의 사냥꾼\n");
    printf("2.  밤낮의 경계를 나는 매\n");
    printf("3.  스트리트 격투왕\n");
    printf("4.  유성을 쫓는 괴도\n");
    printf("5.  흔적을 남기지 않은 과객\n");
    printf("6.  돌이삭과 동행하는 거너\n");
    printf("7.  눈보라에 맞서는 철위대\n");
    printf("8.  별처럼 빛나는 천재\n");
    printf("9.  정토 교황의 팔라딘\n");
    printf("10. 뇌전을 울리는 밴드\n");
    printf("11. 용암 단조의 화장\n");
    printf("12. 황무지의 도적, 황야인\n");
    printf("13. 장수를 원하는 제자\n");
    printf("14. 가상공간을 누비는 메신저\n");
    printf("15. 우주 봉인 정거장\n");
    printf("16. 불로인의 선주\n");
    printf("17. 도적국 탈리아\n");
    printf("18. 생명의 바커 공\n");
    printf("19. 범은하 상사\n");
    printf("20. 천체 차분기관\n");
    printf("21. 축성가의 벨로보그\n");
    printf("22. 회전을 멈춘 살소토\n");
    printf("23. 뭇별 경기장\n");
    printf("24. 부러진 용골\n");
    printf("숫자로 입력해주세요 : ");

    int what_relic_type;
    scanf("%d", &what_relic_type);
    system("cls");
    switch(what_relic_type) {
        case 1:
            printf("혹한 밀림의 사냥꾼\n");
            strcpy(relics[relic_number].type, "hunter");
            break;
        
        case 2:
            printf("밤낮의 경계를 나는 매\n");
            strcpy(relics[relic_number].type, "eagle");
            break;
        
        case 3:
            printf("스트리트 격투왕\n");
            strcpy(relics[relic_number].type, "boxing");
            break;
        
        case 4:
            printf("유성을 쫓는 괴도\n");
            strcpy(relics[relic_number].type, "theif");
            break;
        
        case 5:
            printf("흔적을 남기지 않은 과객\n");
            strcpy(relics[relic_number].type, "passerby");
            break;
        
        case 6:
            printf("돌이삭과 동행하는 거너\n");
            strcpy(relics[relic_number].type, "gunner");
            break;
        
        case 7:
            printf("눈보라에 맞서는 철위대\n");
            strcpy(relics[relic_number].type, "guard");
            break;
        
        case 8:
            printf("별처럼 빛나는 천재\n");
            strcpy(relics[relic_number].type, "genius");
            break;
        
        case 9:
            printf("정토 교황의 팔라딘\n");
            strcpy(relics[relic_number].type, "paladin");
            break;
        
        case 10:
            printf("뇌전을 울리는 밴드\n");
            strcpy(relics[relic_number].type, "band");
            break;
        
        case 11:
            printf("용암 단조의 화장\n");
            strcpy(relics[relic_number].type, "firesmith");
            break;
        
        case 12:
            printf("황무지의 도적, 황야인\n");
            strcpy(relics[relic_number].type, "desert");
            break;
        
        case 13:
            printf("장수를 원하는 제자\n");
            strcpy(relics[relic_number].type, "longlive");
            break;
        
        case 14:
            printf("가상공간을 누비는 메신저\n");
            strcpy(relics[relic_number].type, "messenger");
            break;
        
        case 15:
            printf("우주 봉인 정거장\n");
            strcpy(relics[relic_number].type, "station");
            break;
        
        case 16:
            printf("불로인의 선주\n");
            strcpy(relics[relic_number].type, "ageless");
            break;
        
        case 17:
            printf("도적국 탈리아\n");
            strcpy(relics[relic_number].type, "talia");
            break;
        
        case 18:
            printf("생명의 바커 공\n");
            strcpy(relics[relic_number].type, "barker");
            break;
        
        case 19:
            printf("범은하 상사\n");
            strcpy(relics[relic_number].type, "galactic");
            break;
        
        case 20:
            printf("천체 차분기관\n");
            strcpy(relics[relic_number].type, "differentiator");
            break;
        
        case 21:
            printf("축성가의 벨로보그\n");
            strcpy(relics[relic_number].type, "belobog");
            break;
        
        case 22:
            printf("회전을 멈춘 살소토\n");
            strcpy(relics[relic_number].type, "salsotto");
            break;
        
        case 23:
            printf("뭇별 경기장\n");
            strcpy(relics[relic_number].type, "manystars");
            break;
        
        case 24:
            printf("부러진 용골\n");
            strcpy(relics[relic_number].type, "keel");
            break;

        default:
            printf("Error\n");
            return -25;
    }

    printf("유물 부위\n");
    printf("1. 머리\n");
    printf("2. 팔\n");
    printf("3. 몸통\n");
    printf("4. 다리\n");
    printf("5. 구체\n");
    printf("6. 매듭\n");
    printf("숫자로 입력해주세요 : ");

    int what_relic_part;
    scanf("%d", &what_relic_part);
    system("cls");
    switch(what_relic_part) {
        case 1:
            printf("머리\n");
            strcpy(relics[relic_number].part, "head");
            break;
        
        case 2:
            printf("팔\n");
            strcpy(relics[relic_number].part, "hand");
            break;
        
        case 3:
            printf("몸통\n");
            strcpy(relics[relic_number].part, "body");
            break;
        
        case 4:
            printf("다리\n");
            strcpy(relics[relic_number].part, "feet");
            break;
        
        case 5:
            printf("구체\n");
            strcpy(relics[relic_number].part, "sphere");
            break;
        
        case 6:
            printf("매듭\n");
            strcpy(relics[relic_number].part, "rope");
            break;

        default:
            printf("Error\n");
            return -7;
    }

    printf("유물 레벨 : ");
    scanf("%d", &relics[relic_number].level);
    system("cls");
    if(relics[relic_number].level < 1 || relics[relic_number].level > 15) {
        printf("Error\n");
        return -16;
    }
    printf("%d레벨\n", relics[relic_number].level);

    printf("유물 주옵션\n");
    printf("1. 공격력\n");
    printf("2. 공퍼\n");
    printf("3. 방퍼\n");
    printf("4. 체력\n");
    printf("5. 체퍼\n");
    printf("6. 치확\n");
    printf("7. 치피\n");
    printf("8. 치유량보너스\n");
    printf("9. 효과명중\n");
    printf("10. 속도\n");
    printf("11. 물리피증\n");
    printf("12. 화염피증\n");
    printf("13. 얼음피증\n");
    printf("14. 번개피증\n");
    printf("15. 바람피증\n");
    printf("16. 양자피증\n");
    printf("17. 허수피증\n");
    printf("18. 격특\n");
    printf("19. 에충\n");
    printf("숫자로 입력해주세요 : ");

    int what_relic_mainoption;
    scanf("%d", &what_relic_mainoption);
    system("cls");
    printf("주옵션 : ");
    switch(what_relic_mainoption) {
        case 1:
            printf("공격력\n");
            strcpy(relics[relic_number].mainoption, "atk");
            break;
        
        case 2:
            printf("공퍼\n");
            strcpy(relics[relic_number].mainoption, "atkp");
            break;
        
        case 3:
            printf("방퍼\n");
            strcpy(relics[relic_number].mainoption, "defp");
            break;
        
        case 4:
            printf("체력\n");
            strcpy(relics[relic_number].mainoption, "hp");
            break;
        
        case 5:
            printf("체퍼\n");
            strcpy(relics[relic_number].mainoption, "hpp");
            break;
        
        case 6:
            printf("치확\n");
            strcpy(relics[relic_number].mainoption, "critrate");
            break;
        
        case 7:
            printf("치피\n");
            strcpy(relics[relic_number].mainoption, "critdmg");
            break;
        
        case 8:
            printf("치유량보너스\n");
            strcpy(relics[relic_number].mainoption, "healboost");
            break;
        
        case 9:
            printf("효과명중\n");
            strcpy(relics[relic_number].mainoption, "effrate");
            break;
        
        case 10:
            printf("속도\n");
            strcpy(relics[relic_number].mainoption, "spd");
            break;
        
        case 11:
            printf("물리피증\n");
            strcpy(relics[relic_number].mainoption, "phydmg");
            break;
        
        case 12:
            printf("화염피증\n");
            strcpy(relics[relic_number].mainoption, "firedmg");
            break;
        
        case 13:
            printf("얼음피증\n");
            strcpy(relics[relic_number].mainoption, "icedmg");
            break;
        
        case 14:
            printf("번개피증\n");
            strcpy(relics[relic_number].mainoption, "lightdmg");
            break;
        
        case 15:
            printf("바람피증\n");
            strcpy(relics[relic_number].mainoption, "winddmg");
            break;
        
        case 16:
            printf("양자피증\n");
            strcpy(relics[relic_number].mainoption, "quantumdmg");
            break;
        
        case 17:
            printf("허수피증\n");
            strcpy(relics[relic_number].mainoption, "voiddmg");
            break;
        
        case 18:
            printf("격특\n");
            strcpy(relics[relic_number].mainoption, "breakeff");
            break;
        
        case 19:
            printf("에충\n");
            strcpy(relics[relic_number].mainoption, "energy");
            break;

        default:
            printf("Error\n");
            return -20;
    }

    printf("1. 공격력\n");
    printf("2. 공퍼\n");
    printf("3. 방어력\n");
    printf("4. 방퍼\n");
    printf("5. 체력\n");
    printf("6. 체퍼\n");
    printf("7. 속도\n");
    printf("8. 격특\n");
    printf("9. 효과명중\n");
    printf("10. 효과저항\n");
    printf("11. 치확\n");
    printf("12. 치피\n");
    for(int i = 1; i <= 4; i++) {
        printf("유물 부옵션 %d\n", i);
        printf("숫자로 입력해주세요 : ");

        int what_relic_suboption;
        scanf("%d", &what_relic_suboption);

        printf("유물 부옵션 %d 수치 : ", i);
        double what_relic_suboption_value;
        scanf("%lf", &what_relic_suboption_value);

        switch(what_relic_suboption) {
            case 1:
                relics[relic_number].suboption_atk = what_relic_suboption_value;
                break;
            
            case 2:
                relics[relic_number].suboption_atkp = what_relic_suboption_value;
                break;
            
            case 3:
                relics[relic_number].suboption_def = what_relic_suboption_value;
                break;
            
            case 4:
                relics[relic_number].suboption_defp = what_relic_suboption_value;
                break;
            
            case 5:
                relics[relic_number].suboption_hp = what_relic_suboption_value;
                break;
            
            case 6:
                relics[relic_number].suboption_hpp = what_relic_suboption_value;
                break;
            
            case 7:
                relics[relic_number].suboption_spd = what_relic_suboption_value;
                break;
            
            case 8:
                relics[relic_number].suboption_breakeff = what_relic_suboption_value;
                break;
            
            case 9:
                relics[relic_number].suboption_effrate = what_relic_suboption_value;
                break;
            
            case 10:
                relics[relic_number].suboption_effres = what_relic_suboption_value;
                break;
            
            case 11:
                relics[relic_number].suboption_critrate = what_relic_suboption_value;
                break;
            
            case 12:
                relics[relic_number].suboption_critdmg = what_relic_suboption_value;
                break;

            default:
                printf("Error\n");
                return -13;
        }
    }

    fp = fopen("relic.txt", "a");
    fprintf(fp, "\n%s %s %d %s %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf %.1lf", relics[relic_number].type, relics[relic_number].part, relics[relic_number].level, relics[relic_number].mainoption, relics[relic_number].suboption_atk, relics[relic_number].suboption_atkp, relics[relic_number].suboption_def, relics[relic_number].suboption_defp, relics[relic_number].suboption_hp, relics[relic_number].suboption_hpp, relics[relic_number].suboption_spd, relics[relic_number].suboption_breakeff, relics[relic_number].suboption_effrate, relics[relic_number].suboption_effres, relics[relic_number].suboption_critrate, relics[relic_number].suboption_critdmg);
    fclose(fp);
    fp = fopen("relic.txt", "r+");
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, "%d", relic_number);
    fclose(fp);
}


void Delete_relic() {
    system("cls");
    printf("유물 삭제\n");
}

void Search_relic() {
    system("cls");
    printf("유물 검색\n");
}

void Modify_relic() {
    system("cls");
    printf("유물 수정\n");
}

void Relic_list() {
    system("cls");
    printf("유물 목록\n");
    
    for(int i = 1; i <= relic_number; i++) {
        printf("ID. %d : %s %s+%d(%s", i, Relic_translate(relics[i].type), Relic_translate(relics[i].part), relics[i].level, Relic_translate(relics[i].mainoption));
        printf("%.1lf)\n", floor(Calculate_mainoption(relics[i].mainoption, relics[i].level) * 10) / 10);
    }
}