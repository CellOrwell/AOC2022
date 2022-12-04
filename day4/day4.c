#include <stdio.h>
#include <string.h>

int isFullyAbsorbed(int, int, int, int);

int main(int argc, char **argv)
{
    FILE *file;
    char *fName = "day4.txt";
    char buf[256];
    int lB1,lB2,uB1,uB2;

    int totFullAbs;

    if(!(file=fopen(fName, "r")))
    {
        fprintf(stderr, "Can't open file %s", fName);
    }

    while(fgets(buf, 256, file) != NULL)
    {
        printf("%s", buf);
        sscanf(buf, "%d-%d,%d-%d\n", &lB1, &uB1, &lB2, &uB2);

        totFullAbs += isFullyAbsorbed(uB1, uB2, lB1, lB2);
    }

    printf("Total full absorbed: %d\n", totFullAbs);

    fclose(file);
}

int isFullyAbsorbed(int ub1, int ub2, int lb1, int lb2)
{
    if((ub1 <= ub2) && (lb1 >= lb2))
    {
        printf("Yes\n");
        return 1;
    }
    if((ub2 <= ub1) && (lb2 >= lb1))
    {
        printf("Yes\n");
        return 1;
    }
    printf("No\n");
    return 0;
}