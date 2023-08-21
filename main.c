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