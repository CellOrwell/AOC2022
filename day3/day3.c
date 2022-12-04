#include <stdio.h>
#include <string.h>

int getPriority(char);
int getPriorityOfPackage(char *, int, int, int);
int isIn(char *, int, char);

int main(int argc, char **argv)
{
    FILE *file;
    char *fname = "day3.txt";
    char buf[256], groupStr[256];
    int length, totPriority = 0, groupCount=0;
    int pos[3];

    if(!(file=fopen(fname, "r")))
    {
        fprintf(stderr, "Can't open file\n");
        return 1;
    }

    while(fgets(buf, 256, file) != NULL)
    {
        if(groupCount < 3)
        {
            if(groupCount == 0)
            {
                pos[0] = 0;
            }
            else
            {
                pos[groupCount] = strlen(groupStr) - 1;
            }
            groupStr[strlen(groupStr)-1] = '\0';
            strcat(groupStr, buf);
            groupCount++;
        }
        
        if(groupCount == 3)
        {
            totPriority += getPriorityOfPackage(groupStr, pos[0], pos[1], pos[2]);
            groupCount = 0;
            strcpy(groupStr, "");
        }
    }

    printf("Total priority = %d\n", totPriority);

    fclose(file);
}

int getPriorityOfPackage(char str[256], int pos0, int pos1, int pos2)
{
    int i,j,k,mid,total = 0,brokeNum=0;
    char broke[256];

    for(i=0; i<pos1; i++)
    {
        for(j=pos1; j<pos2; j++)
        {
            for(k=pos2; k<strlen(str); k++)
            {
                if(str[i] == str[j] && str[j] == str[k] && (isIn(broke, brokeNum, str[i]) == 1))
                {
                    total += getPriority(str[i]);
                    broke[brokeNum] = str[i];
                    brokeNum++;
                }
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