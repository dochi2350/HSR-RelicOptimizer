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
    if(!strcmp(name, "hunter")) return "Ȥ�� �и��� ��ɲ�";
    else if(!strcmp(name, "eagle")) return "�㳷�� ��踦 ���� ��";
    else if(!strcmp(name, "boxing")) return "��Ʈ��Ʈ ������";
    else if(!strcmp(name, "theif")) return "������ �Ѵ� ����";
    else if(!strcmp(name, "passerby")) return "������ ������ ���� ����";
    else if(!strcmp(name, "gunner")) return "���̻�� �����ϴ� �ų�";
    else if(!strcmp(name, "guard")) return "������ �¼��� ö����";
    else if(!strcmp(name, "genius")) return "��ó�� ������ õ��";
    else if(!strcmp(name, "paladin")) return "���� ��Ȳ�� �ȶ��";
    else if(!strcmp(name, "band")) return "������ �︮�� ���";
    else if(!strcmp(name, "firesmith")) return "��� ������ ȭ��";
    else if(!strcmp(name, "desert")) return "Ȳ������ ����, Ȳ����";
    else if(!strcmp(name, "longlive")) return "����� ���ϴ� ����";
    else if(!strcmp(name, "messenger")) return "��������� ����� �޽���";
    
    else if(!strcmp(name, "station")) return "���� ���� ������";
    else if(!strcmp(name, "ageless")) return "�ҷ����� ����";
    else if(!strcmp(name, "talia")) return "������ Ż����";
    else if(!strcmp(name, "barker")) return "������ ��Ŀ ��";
    else if(!strcmp(name, "galactic")) return "������ ���";
    else if(!strcmp(name, "differentiator")) return "õü ���б��";
    else if(!strcmp(name, "belobog")) return "�༺���� ���κ���";
    else if(!strcmp(name, "salsotto")) return "ȸ���� ���� �����";
    else if(!strcmp(name, "manystars")) return "���� �����";
    else if(!strcmp(name, "keel")) return "�η��� ���";

    else if(!strcmp(name, "head")) return "�Ӹ�";
    else if(!strcmp(name, "hand")) return "��";
    else if(!strcmp(name, "body")) return "����";
    else if(!strcmp(name, "feet")) return "�ٸ�";
    else if(!strcmp(name, "sphere")) return "��ü";
    else if(!strcmp(name, "rope")) return "�ŵ�";

    else if(!strcmp(name, "atk")) return "���ݷ�";
    else if(!strcmp(name, "atkp")) return "����";
    else if(!strcmp(name, "def")) return "����";
    else if(!strcmp(name, "defp")) return "����";
    else if(!strcmp(name, "hp")) return "ü��";
    else if(!strcmp(name, "hpp")) return "ü��";
    else if(!strcmp(name, "spd")) return "�ӵ�";
    else if(!strcmp(name, "breakeff")) return "��Ư";
    else if(!strcmp(name, "effrate")) return "ȿ������";
    else if(!strcmp(name, "effres")) return "ȿ������";
    else if(!strcmp(name, "critrate")) return "ġȮ";
    else if(!strcmp(name, "critdmg")) return "ġ��";
    else if(!strcmp(name, "phydmg")) return "��������";
    else if(!strcmp(name, "firedmg")) return "ȭ������";
    else if(!strcmp(name, "icedmg")) return "��������";
    else if(!strcmp(name, "lightdmg")) return "��������";
    else if(!strcmp(name, "winddmg")) return "�ٶ�����";
    else if(!strcmp(name, "quantumdmg")) return "��������";
    else if(!strcmp(name, "voiddmg")) return "�������";
    else if(!strcmp(name, "energy")) return "����";
    else if(!strcmp(name, "healboost")) return "ġ�������ʽ�";

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
                system("cls");
                printf("���� �߰�\n");

                relic_number++;
                printf("���� ����\n");
                printf("1.  Ȥ�� �и��� ��ɲ�\n");
                printf("2.  �㳷�� ��踦 ���� ��\n");
                printf("3.  ��Ʈ��Ʈ ������\n");
                printf("4.  ������ �Ѵ� ����\n");
                printf("5.  ������ ������ ���� ����\n");
                printf("6.  ���̻�� �����ϴ� �ų�\n");
                printf("7.  ������ �¼��� ö����\n");
                printf("8.  ��ó�� ������ õ��\n");
                printf("9.  ���� ��Ȳ�� �ȶ��\n");
                printf("10. ������ �︮�� ���\n");
                printf("11. ��� ������ ȭ��\n");
                printf("12. Ȳ������ ����, Ȳ����\n");
                printf("13. ����� ���ϴ� ����\n");
                printf("14. ��������� ����� �޽���\n");
                printf("15. ���� ���� ������\n");
                printf("16. �ҷ����� ����\n");
                printf("17. ������ Ż����\n");
                printf("18. ������ ��Ŀ ��\n");
                printf("19. ������ ���\n");
                printf("20. õü ���б��\n");
                printf("21. �༺���� ���κ���\n");
                printf("22. ȸ���� ���� �����\n");
                printf("23. ���� �����\n");
                printf("24. �η��� ���\n");
                printf("���ڷ� �Է����ּ��� : ");

                int what_relic_type;
                scanf("%d", &what_relic_type);
                system("cls");
                switch(what_relic_type) {
                    case 1:
                        printf("Ȥ�� �и��� ��ɲ�\n");
                        strcpy(relics[relic_number].type, "hunter");
                        break;
                    
                    case 2:
                        printf("�㳷�� ��踦 ���� ��\n");
                        strcpy(relics[relic_number].type, "eagle");
                        break;
                    
                    case 3:
                        printf("��Ʈ��Ʈ ������\n");
                        strcpy(relics[relic_number].type, "boxing");
                        break;
                    
                    case 4:
                        printf("������ �Ѵ� ����\n");
                        strcpy(relics[relic_number].type, "theif");
                        break;
                    
                    case 5:
                        printf("������ ������ ���� ����\n");
                        strcpy(relics[relic_number].type, "passerby");
                        break;
                    
                    case 6:
                        printf("���̻�� �����ϴ� �ų�\n");
                        strcpy(relics[relic_number].type, "gunner");
                        break;
                    
                    case 7:
                        printf("������ �¼��� ö����\n");
                        strcpy(relics[relic_number].type, "guard");
                        break;
                    
                    case 8:
                        printf("��ó�� ������ õ��\n");
                        strcpy(relics[relic_number].type, "genius");
                        break;
                    
                    case 9:
                        printf("���� ��Ȳ�� �ȶ��\n");
                        strcpy(relics[relic_number].type, "paladin");
                        break;
                    
                    case 10:
                        printf("������ �︮�� ���\n");
                        strcpy(relics[relic_number].type, "band");
                        break;
                    
                    case 11:
                        printf("��� ������ ȭ��\n");
                        strcpy(relics[relic_number].type, "firesmith");
                        break;
                    
                    case 12:
                        printf("Ȳ������ ����, Ȳ����\n");
                        strcpy(relics[relic_number].type, "desert");
                        break;
                    
                    case 13:
                        printf("����� ���ϴ� ����\n");
                        strcpy(relics[relic_number].type, "longlive");
                        break;
                    
                    case 14:
                        printf("��������� ����� �޽���\n");
                        strcpy(relics[relic_number].type, "messenger");
                        break;
                    
                    case 15:
                        printf("���� ���� ������\n");
                        strcpy(relics[relic_number].type, "station");
                        break;
                    
                    case 16:
                        printf("�ҷ����� ����\n");
                        strcpy(relics[relic_number].type, "ageless");
                        break;
                    
                    case 17:
                        printf("������ Ż����\n");
                        strcpy(relics[relic_number].type, "talia");
                        break;
                    
                    case 18:
                        printf("������ ��Ŀ ��\n");
                        strcpy(relics[relic_number].type, "barker");
                        break;
                    
                    case 19:
                        printf("������ ���\n");
                        strcpy(relics[relic_number].type, "galactic");
                        break;
                    
                    case 20:
                        printf("õü ���б��\n");
                        strcpy(relics[relic_number].type, "differentiator");
                        break;
                    
                    case 21:
                        printf("�༺���� ���κ���\n");
                        strcpy(relics[relic_number].type, "belobog");
                        break;
                    
                    case 22:
                        printf("ȸ���� ���� �����\n");
                        strcpy(relics[relic_number].type, "salsotto");
                        break;
                    
                    case 23:
                        printf("���� �����\n");
                        strcpy(relics[relic_number].type, "manystars");
                        break;
                    
                    case 24:
                        printf("�η��� ���\n");
                        strcpy(relics[relic_number].type, "keel");
                        break;

                    default:
                        printf("Error\n");
                        return -25;
                }

                printf("���� ����\n");
                printf("1. �Ӹ�\n");
                printf("2. ��\n");
                printf("3. ����\n");
                printf("4. �ٸ�\n");
                printf("5. ��ü\n");
                printf("6. �ŵ�\n");
                printf("���ڷ� �Է����ּ��� : ");

                int what_relic_part;
                scanf("%d", &what_relic_part);
                system("cls");
                switch(what_relic_part) {
                    case 1:
                        printf("�Ӹ�\n");
                        strcpy(relics[relic_number].part, "head");
                        break;
                    
                    case 2:
                        printf("��\n");
                        strcpy(relics[relic_number].part, "hand");
                        break;
                    
                    case 3:
                        printf("����\n");
                        strcpy(relics[relic_number].part, "body");
                        break;
                    
                    case 4:
                        printf("�ٸ�\n");
                        strcpy(relics[relic_number].part, "feet");
                        break;
                    
                    case 5:
                        printf("��ü\n");
                        strcpy(relics[relic_number].part, "sphere");
                        break;
                    
                    case 6:
                        printf("�ŵ�\n");
                        strcpy(relics[relic_number].part, "rope");
                        break;

                    default:
                        printf("Error\n");
                        return -7;
                }

                printf("���� ���� : ");
                scanf("%d", &relics[relic_number].level);
                system("cls");
                if(relics[relic_number].level < 1 || relics[relic_number].level > 15) {
                    printf("Error\n");
                    return -16;
                }
                printf("%d����\n", relics[relic_number].level);

                printf("���� �ֿɼ�\n");
                printf("1. ���ݷ�\n");
                printf("2. ����\n");
                printf("3. ����\n");
                printf("4. ü��\n");
                printf("5. ü��\n");
                printf("6. ġȮ\n");
                printf("7. ġ��\n");
                printf("8. ġ�������ʽ�\n");
                printf("9. ȿ������\n");
                printf("10. �ӵ�\n");
                printf("11. ��������\n");
                printf("12. ȭ������\n");
                printf("13. ��������\n");
                printf("14. ��������\n");
                printf("15. �ٶ�����\n");
                printf("16. ��������\n");
                printf("17. �������\n");
                printf("18. ��Ư\n");
                printf("19. ����\n");
                printf("���ڷ� �Է����ּ��� : ");

                int what_relic_mainoption;
                scanf("%d", &what_relic_mainoption);
                system("cls");
                switch(what_relic_mainoption) {
                    case 1:
                        printf("���ݷ�\n");
                        strcpy(relics[relic_number].mainoption, "atk");
                        break;
                    
                    case 2:
                        printf("����\n");
                        strcpy(relics[relic_number].mainoption, "atkp");
                        break;
                    
                    case 3:
                        printf("����\n");
                        strcpy(relics[relic_number].mainoption, "defp");
                        break;
                    
                    case 4:
                        printf("ü��\n");
                        strcpy(relics[relic_number].mainoption, "hp");
                        break;
                    
                    case 5:
                        printf("ü��\n");
                        strcpy(relics[relic_number].mainoption, "hpp");
                        break;
                    
                    case 6:
                        printf("ġȮ\n");
                        strcpy(relics[relic_number].mainoption, "critrate");
                        break;
                    
                    case 7:
                        printf("ġ��\n");
                        strcpy(relics[relic_number].mainoption, "critdmg");
                        break;
                    
                    case 8:
                        printf("ġ�������ʽ�\n");
                        strcpy(relics[relic_number].mainoption, "healboost");
                        break;
                    
                    case 9:
                        printf("ȿ������\n");
                        strcpy(relics[relic_number].mainoption, "effrate");
                        break;
                    
                    case 10:
                        printf("�ӵ�\n");
                        strcpy(relics[relic_number].mainoption, "spd");
                        break;
                    
                    case 11:
                        printf("��������\n");
                        strcpy(relics[relic_number].mainoption, "phydmg");
                        break;
                    
                    case 12:
                        printf("ȭ������\n");
                        strcpy(relics[relic_number].mainoption, "firedmg");
                        break;
                    
                    case 13:
                        printf("��������\n");
                        strcpy(relics[relic_number].mainoption, "icedmg");
                        break;
                    
                    case 14:
                        printf("��������\n");
                        strcpy(relics[relic_number].mainoption, "lightdmg");
                        break;
                    
                    case 15:
                        printf("�ٶ�����\n");
                        strcpy(relics[relic_number].mainoption, "winddmg");
                        break;
                    
                    case 16:
                        printf("��������\n");
                        strcpy(relics[relic_number].mainoption, "quantumdmg");
                        break;
                    
                    case 17:
                        printf("�������\n");
                        strcpy(relics[relic_number].mainoption, "voiddmg");
                        break;
                    
                    case 18:
                        printf("��Ư\n");
                        strcpy(relics[relic_number].mainoption, "breakeff");
                        break;
                    
                    case 19:
                        printf("����\n");
                        strcpy(relics[relic_number].mainoption, "energy");
                        break;

                    default:
                        printf("Error\n");
                        return -20;
                }

                printf("1. ���ݷ�\n");
                printf("2. ����\n");
                printf("3. ����\n");
                printf("4. ����\n");
                printf("5. ü��\n");
                printf("6. ü��\n");
                printf("7. �ӵ�\n");
                printf("8. ��Ư\n");
                printf("9. ȿ������\n");
                printf("10. ȿ������\n");
                printf("11. ġȮ\n");
                printf("12. ġ��\n");
                for(int i = 1; i <= 4; i++) {
                    printf("���� �οɼ� %d\n", i);
                    printf("���ڷ� �Է����ּ��� : ");

                    int what_relic_suboption;
                    scanf("%d", &what_relic_suboption);

                    printf("���� �οɼ� %d ��ġ : ", i);
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
                printf("���� ����\n");
                break;

            case 3:
                system("cls");
                printf("���� �˻�\n");
                break;

            case 4:
                system("cls");
                printf("���� ����\n");
                break;

            case 5:
                system("cls");
                printf("���� ���\n");
                
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