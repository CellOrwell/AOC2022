#include <stdio.h>
#include <string.h>

int getPriority(char);
int getPriorityOfPackage(char *, int);
int isIn(char *, int, char);

int main(int argc, char **argv)
{
    FILE *file;
    char *fname = "day3.txt";
    char buf[256];
    int length, totPriority = 0;

    if(!(file=fopen(fname, "r")))
    {
        fprintf(stderr, "Can't open file\n");
        return 1;
    }

    while(fgets(buf, 256, file) != NULL)
    {
        length = strlen(buf) - 1;
        totPriority += getPriorityOfPackage(buf, length);
        printf("%s, %d, %d\n", buf, length, getPriorityOfPackage(buf, length));
    }

    printf("Total priority = %d\n", totPriority);
}

int getPriorityOfPackage(char str[256], int len)
{
    int i,j,mid,total = 0,brokeNum=0;
    char broke[256];
    mid = len/2;

    for(i=0; i<mid; i++)
    {
        for(j=mid; j<len; j++)
        {
            if(str[i] == str[j] && (isIn(broke, brokeNum, str[i]) == 1))
            {
                total += getPriority(str[i]);
                broke[brokeNum] = str[i];
                brokeNum++;
            }
        }
    }
    return total;
}

int isIn(char str[256], int len, char c)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(str[i] == c)
        {
            return 0;
        }
    }
    return 1;
}


int getPriority(char c)
{
    int ascii = c;
    if((ascii >= 97) && (ascii <= 122))
    {
        return ascii-96;
    }
    else if((ascii >= 65) && (ascii <= 90))
    {
        return ascii-38;
    }
    else
    {
        return 0;
    }
}