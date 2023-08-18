#include <stdio.h>

int main()
{
    FILE *fp;
    char line[100];

    fp = fopen("relic.txt", "r");

    if (fp == NULL) {
        printf("relic.txt not found");
        return -1;
    }

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}