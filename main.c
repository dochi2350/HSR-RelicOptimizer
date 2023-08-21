#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include <math.h>

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
    double suboption_breakeff;
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
    else if(!strcmp(name, "breakeff")) return "격특";
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

double Calculate_mainoption(char *mainoption, int level) {
    double atk[20] = {56.448, 76.2048, 95.9616, 115.7184, 135.4752, 155.232, 174.9888, 194.7456, 214.5024, 234.2592, 254.016, 273.7728, 293.5296, 313.2864, 333.0432, 352.8};
    double atkp[20] = {6.912, 9.3312, 11.7504, 14.1696, 16.5888, 19.008, 21.4272, 23.8464, 26.2656, 28.6848, 31.104, 33.5232, 35.9424, 38.3616, 40.7808, 43.2};
    double defp[20] = {8.64, 11.664, 14.688, 17.712, 20.736, 23.76, 26.784, 29.808, 32.832, 35.856, 38.88, 41.904, 44.928, 47.952, 50.976, 54};
    double hp[20] = {112.896, 152.4096, 191.9232, 231.4368, 270.9504, 310.464, 349.9776, 389.4912, 429.0048, 468.5184, 508.032, 547.5456, 587.0592, 626.5728, 666.0864, 705.6};
    double hpp[20] = {6.912, 9.3312, 11.7504, 14.1696, 16.5888, 19.008, 21.4272, 23.8464, 26.2656, 28.6848, 31.104, 33.5232, 35.9424, 38.3616, 40.7808, 43.2};
    double critrate[20] = {5.184, 6.9984, 8.8128, 10.6272, 12.4416, 14.256, 16.0704, 17.8848, 19.6992, 21.5136, 23.328, 25.1424, 26.9568, 28.7712, 30.5856, 32.4};
    double critdmg[20] = {10.368, 13.9968, 17.6256, 21.2544, 24.8832, 28.512, 32.1408, 35.7696, 39.3984, 43.0272, 46.656, 50.2848, 53.9136, 57.5424, 61.1712, 64.8};
    double healboost[20] = {5.5296, 7.465, 9.4004, 11.3358, 13.2712, 15.2066, 17.142, 19.0774, 21.0128, 22.9482, 24.8836, 26.819, 28.7544, 30.6898, 32.6252, 34.5606};
    double effrate[20] = {6.912, 9.3312, 11.7504, 14.1696, 16.5888, 19.008, 21.4272, 23.8464, 26.2656, 28.6848, 31.104, 33.5232, 35.9424, 38.3616, 40.7808, 43.2};
    double spd[20] = {4.032, 5.432, 6.832, 8.232, 9.632, 11.032, 12.432, 13.832, 15.232, 16.632, 18.032, 19.432, 20.832, 22.232, 23.632, 25.032};
    double elementdmg[20] = {6.2208, 8.3981, 10.5754, 12.7527, 14.93, 17.1073, 19.2846, 21.4619, 23.6392, 25.8165, 27.9938, 30.1711, 32.3484, 34.5257, 36.703, 38.8803};
    double breakeff[20] = {10.368, 13.9968, 17.6256, 21.2544, 24.8832, 28.512, 32.1408, 35.7696, 39.3984, 43.0272, 46.656, 50.2848, 53.9136, 57.5424, 61.1712, 64.8};
    double energy[20] = {3.1104, 4.199, 5.2876, 6.3762, 7.4648, 8.5534, 9.642, 10.7306, 11.8192, 12.9078, 13.9964, 15.085, 16.1736, 17.2622, 18.3508, 19.4394};
    
    if(!strcmp(mainoption, "atk")) return atk[level];
    else if(!strcmp(mainoption, "atkp")) return atkp[level];
    else if(!strcmp(mainoption, "defp")) return defp[level];
    else if(!strcmp(mainoption, "hp")) return hp[level];
    else if(!strcmp(mainoption, "hpp")) return hpp[level];
    else if(!strcmp(mainoption, "critrate")) return critrate[level];
    else if(!strcmp(mainoption, "critdmg")) return critdmg[level];
    else if(!strcmp(mainoption, "healboost")) return healboost[level];
    else if(!strcmp(mainoption, "effrate")) return effrate[level];
    else if(!strcmp(mainoption, "spd")) return spd[level];
    else if(!strcmp(mainoption, "phydmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "firedmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "icedmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "lightdmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "winddmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "quantumdmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "voiddmg")) return elementdmg[level];
    else if(!strcmp(mainoption, "breakeff")) return breakeff[level];
    else if(!strcmp(mainoption, "energy")) return energy[level];

    else return 0;
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
        fscanf(fp, "%lf", &relics[i].suboption_breakeff);
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
                    printf("ID. %d : %s %s+%d(%s", i, Relic_translate(relics[i].type), Relic_translate(relics[i].part), relics[i].level, Relic_translate(relics[i].mainoption));
                    printf("%.1lf)\n", floor(Calculate_mainoption(relics[i].mainoption, relics[i].level) * 10) / 10);
                }

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