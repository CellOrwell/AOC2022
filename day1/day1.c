#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void moveNum(int array[3][2], int elfNum, int elfCal, int pos)
{
    int i;

    for(i=pos; i<3; i++)
    {
        if(array[i][1] < elfCal)
        {
            moveNum(array, array[i][0], array[i][1], i);
            array[i][0] = elfNum;
            array[i][1] = elfCal;
            break;
        }
    }
}


int main(int argc, char **argv)
{
    FILE *file;
    char fileName[256], buf[256];
    int elfNum = 1, totCals = 0, curCal, finCal=0;
    int elfMax[3][2] = {{0,0},{0,0},{0,0}};
    int i;
    strcpy(fileName, "day1.txt");

    if(!(file = fopen(fileName, "r")))
    {
        printf("Can't open file %s\n", fileName);
        return 1;
    }

    while(fgets(buf, 256, file) != NULL)
    {
        if(strcmp(buf, "\n") == 0)
        {
            for(i = 0; i < 3; i++)
            {
                if(elfMax[i][1] < totCals)
                {
                    moveNum(elfMax, elfMax[i][0], elfMax[i][1], i);
                    elfMax[i][0] = elfNum;
                    elfMax[i][1] = totCals;
                    break;
                }
            }
            elfNum += 1;
            totCals = 0;
        }
        else
        {
            curCal = atoi(buf);
            totCals += curCal;
        }
    }

    for(i=0; i<3; i++)
    {
        printf("Elf %d has max cals %d\n", elfMax[i][0], elfMax[i][1]);
        finCal += elfMax[i][1];
    }

    printf("Total cals: %d", finCal);


    fclose(file);
}