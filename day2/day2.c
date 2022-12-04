#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int shapeScore(char, int);
int elfShapeScore(char);
int winLose(char);

int main(int argc, char **argv)
{
    double time = 0.0;
    char elfChoice, myChoice;
    char *fname = "day2.txt";
    char buf[256];
    int totScore, elfShape;
    FILE *file;

    clock_t begin = clock();

    if(!(file = fopen(fname, "r")))
    {
        printf("Can't open file %s\n", fname);
        return 1;
    }



    while(fgets(buf, 256, file) != NULL)
    {
        sscanf(buf, "%c %c", &elfChoice, &myChoice);
        elfShape = elfShapeScore(elfChoice);
        totScore += (winLose(myChoice) + shapeScore(myChoice, elfShape));
    }

    printf("My total score: %d\n", totScore);

    fclose(file);

    clock_t end = clock();

    time += (double)(end-begin) / CLOCKS_PER_SEC;

    printf("Elapsed time: %f seconds\n", time);

    return 0;
}

int elfShapeScore(char c)
{
    int finScore = 0;
    switch (c)
    {
        case 'A':
            return 1;
            break;
        case 'B':
            return 2;
            break;
        case 'C':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

int shapeScore(char c, int elfScore)
{
    switch (c)
    {
        case 'X':
            elfScore -= 1;
            break;
        case 'Y':
            /*do nothing*/
            break;
        case 'Z':
            elfScore += 1;
            break;
        default:
            return 0;
            break;
    }

    if(elfScore <= 0)
    {
        return 3;
    }
    else if(elfScore > 3)
    {
        return 1;
    }
    else
    {
        return elfScore;
    }
}

int winLose(char c)
{
    switch (c)
    {
        case 'X':
            return 0;
            break;
        case 'Y':
            return 3;
            break;
        case 'Z':
            return 6;
            break;
        default:
            return 0;
            break;
    }
}