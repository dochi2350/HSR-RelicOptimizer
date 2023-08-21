#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

struct Relic {
    char type[100];
    char part[100];
    int level;
    char mainoption[100];
    double suboption_atk;
    double suboption_atkp;
    double suboption_def;
    double suboption_defp;
    double suboption_hp;
    double suboption_hpp;
    double suboption_spd;
    double suboption_break;
    double suboption_effrate;
    double suboption_effres;
    double suboption_critrate;
    double suboption_critdmg;
};

int Relic_translate(char *name) {
    if(!strcmp(name, "hunter")) return "혹한 밀림의 사냥꾼";
    else if(!strcmp(name, "eagle")) return "밤낮의 경계를 나는 매";
    else if(!strcmp(name, "boxing")) return "스트리트 격투왕";
    else if(!strcmp(name, "theif")) return "유성을 쫓는 괴도";
    else if(!strcmp(name, "passerby")) return "흔적을 남기지 않은 과객";
    else if(!strcmp(name, "gunner")) return "돌이삭과 동행하는 거너";
    else if(!strcmp(name, "guard")) return "눈보라에 맞서는 철위대";
    else if(!strcmp(name, "genius")) return "별처럼 빛나는 천재";
    else if(!strcmp(name, "paladin")) return "정토 교황의 팔라딘";
    else if(!strcmp(name, "band")) return "뇌전을 울리는 밴드";
    else if(!strcmp(name, "firesmith")) return "용암 단조의 화장";
    else if(!strcmp(name, "desert")) return "황무지의 도적, 황야인";
    else if(!strcmp(name, "longlive")) return "장수를 원하는 제자";
    else if(!strcmp(name, "messenger")) return "가상공간을 누비는 메신저";
    
    else if(!strcmp(name, "station")) return "우주 봉인 정거장";
    else if(!strcmp(name, "ageless")) return "불로인의 선주";
    else if(!strcmp(name, "talia")) return "도적국 탈리아";
    else if(!strcmp(name, "barker")) return "생명의 바커 공";
    else if(!strcmp(name, "galactic")) return "범은하 상사";
    else if(!strcmp(name, "differentiator")) return "천체 차분기관";
    else if(!strcmp(name, "belobog")) return "축성가의 벨로보그";
    else if(!strcmp(name, "salsotto")) return "회전을 멈춘 살소토";
    else if(!strcmp(name, "manystars")) return "뭇별 경기장";
    else if(!strcmp(name, "keel")) return "부러진 용골";

    else if(!strcmp(name, "head")) return "머리";
    else if(!strcmp(name, "hand")) return "팔";
    else if(!strcmp(name, "body")) return "몸통";
    else if(!strcmp(name, "feet")) return "다리";
    else if(!strcmp(name, "sphere")) return "구체";
    else if(!strcmp(name, "rope")) return "매듭";

    else if(!strcmp(name, "atk")) return "공격력";
    else if(!strcmp(name, "atkp")) return "공퍼";
    else if(!strcmp(name, "def")) return "방어력";
    else if(!strcmp(name, "defp")) return "방퍼";
    else if(!strcmp(name, "hp")) return "체력";
    else if(!strcmp(name, "hpp")) return "체퍼";
    else if(!strcmp(name, "spd")) return "속도";
    else if(!strcmp(name, "break")) return "격특";
    else if(!strcmp(name, "effrate")) return "효과명중";
    else if(!strcmp(name, "effres")) return "효과저항";
    else if(!strcmp(name, "critrate")) return "치확";
    else if(!strcmp(name, "critdmg")) return "치피";
    else if(!strcmp(name, "phydmg")) return "물리피증";
    else if(!strcmp(name, "firedmg")) return "화염피증";
    else if(!strcmp(name, "icedmg")) return "얼음피증";
    else if(!strcmp(name, "lightdmg")) return "번개피증";
    else if(!strcmp(name, "winddmg")) return "바람피증";
    else if(!strcmp(name, "quantumdmg")) return "양자피증";
    else if(!strcmp(name, "voiddmg")) return "허수피증";
    else if(!strcmp(name, "energy")) return "에충";
    else if(!strcmp(name, "healboost")) return "치유량보너스";

    else return "Error";
}

int main()
{
    FILE *fp = fopen("relic.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    
    int relic_number;
    struct Relic relics[1505];
    
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
        fscanf(fp, "%lf", &relics[i].suboption_break);
        fscanf(fp, "%lf", &relics[i].suboption_effrate);
        fscanf(fp, "%lf", &relics[i].suboption_effres);
        fscanf(fp, "%lf", &relics[i].suboption_critrate);
        fscanf(fp, "%lf", &relics[i].suboption_critdmg);
    }

    printf("There are %d relics uploaded.\n", relic_number);

    fclose(fp);

    while(1) {
        printf("1. 유물 추가\n");
        printf("2. 유물 삭제\n");
        printf("3. 유물 검색\n");
        printf("4. 유물 수정\n");
        printf("5. 유물 목록\n");
        printf("6. 종료\n");
        
        int pressed;
        scanf("%d", &pressed);

        switch(pressed) {
            case 1:
                system("cls");
                printf("유물 추가\n");
                break;
            case 2:
                system("cls");
                printf("유물 삭제\n");
                break;
            case 3:
                system("cls");
                printf("유물 검색\n");
                break;
            case 4:
                system("cls");
                printf("유물 수정\n");
                break;
            case 5:
                system("cls");
                printf("유물 목록\n");
                
                for(int i = 1; i <= relic_number; i++) {
                    printf("ID. %d : %s %s(%s)+%d\n", i, Relic_translate(relics[i].type), Relic_translate(relics[i].part), Relic_translate(relics[i].mainoption), relics[i].level);
                }

                getch();
                break;
            case 6:
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