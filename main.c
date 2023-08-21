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
    else if(!strcmp(name, "break")) return "��Ư";
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
                    printf("ID. %d : %s %s(%s)+%d\n", i, Relic_translate(relics[i].type), Relic_translate(relics[i].part), Relic_translate(relics[i].mainoption), relics[i].level);
                }

                getch();
                break;
            case 6:
                return 6;
            default:
                system("cls");
                printf("�߸��� �Է��Դϴ�.\n");
                break;
        }
        system("cls");
    }

    getch();
    return 0;
}