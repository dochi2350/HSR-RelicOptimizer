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
    printf("�ֿɼ� : ");
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
}


void Delete_relic() {
    system("cls");
    printf("���� ����\n");
}

void Search_relic() {
    system("cls");
    printf("���� �˻�\n");
}

void Modify_relic() {
    system("cls");
    printf("���� ����\n");
}

void Relic_list() {
    system("cls");
    printf("���� ���\n");
    
    for(int i = 1; i <= relic_number; i++) {
        printf("ID. %d : %s %s+%d(%s", i, Relic_translate(relics[i].type), Relic_translate(relics[i].part), relics[i].level, Relic_translate(relics[i].mainoption));
        printf("%.1lf)\n", floor(Calculate_mainoption(relics[i].mainoption, relics[i].level) * 10) / 10);
    }
}