#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int shapeScore(char);
int hasWon(char, int);

int main(int argc, char **argv)
{
    char elfChoice, myChoice;
    char *fname = "day2.txt";
    char buf[256];
    int totScore, myShape;
    FILE *file;

    if(!(file = fopen(fname, "r")))
    {
        printf("Can't open file %s\n", fname);
        return 1;
    }



    while(fgets(buf, 256, file) != NULL)
    {
        sscanf(buf, "%c %c", &elfChoice, &myChoice);
        myShape = shapeScore(myChoice);
        totScore += (myShape + hasWon(elfChoice, myShape));
    }

    printf("My total score: %d\n", totScore);

    fclose(file);

    return 0;
}

int hasWon(char c, int score)
{
    int finScore = 0;
    switch (c)
    {
        case 'A':
            finScore = 3 * score;
            if (finScore > 6)
                finScore = 0;
            return finScore;
            break;
        case 'B':
            finScore = 3 * (score-1);
            return finScore;
            break;
        case 'C':
            finScore = 3 * (score-2);
            if (finScore < 0)
                finScore = 6;
            return finScore;
            break;
        default:
            return 0;
            break;
    }
}

int shapeScore(char c)
{
    switch (c)
    {
        case 'X':
            return 1;
            break;
        case 'Y':
            return 2;
            break;
        case 'Z':
            return 3;
            break;
        default:
            return 0;
            break;
    }
}