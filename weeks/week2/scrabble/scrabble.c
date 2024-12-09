#include <stdio.h>
#include <string.h>
#include <ctype.h>


const int MAX_STRLEN = 100;
const int charScores[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};


int score(const char *text) {
    const int length = strlen(text);

    int totalScore = 0;
    for(int i = 0; i < length; i++) {
        if(!isalpha(text[i])) continue;
        char c = tolower(text[i]);
        int idxInAlphabet = c - 'a';
        totalScore += charScores[idxInAlphabet];
    }

    return totalScore;
}

int main(void) {
    char p1Input[MAX_STRLEN];
    char p2Input[MAX_STRLEN];

    // Get the inputs:
    printf("Player 1: ");
    fgets(p1Input, MAX_STRLEN, stdin);
    printf("Player 2: ");
    fgets(p2Input, MAX_STRLEN, stdin);

    int score1 = score(p1Input);
    int score2 = score(p2Input);

    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
    return 0;
}