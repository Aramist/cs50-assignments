#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int wordCount(const char *text) {
    // Computes the number of words (space separated components) in a given
    // sample of text
    const int length = strlen(text);
    if (length == 0) { return 0; }

    int numWords = 1;
    for(int i = 0; i < length; i++) {
        if (isspace(text[i]) && text[i] != 10) {
            numWords += 1;
        }
    }
    return numWords;
}

int letterCount(const char *text) {
    const int length = strlen(text);
    int numLetters = 0;

    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            numLetters += 1;
        }
    }
    return numLetters;
}

int sentenceCount(const char *text) {
    const int length = strlen(text);
    int numSentences = 0;

    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            numSentences += 1;
    }
    return numSentences;
}

int approxGradeLevel(const char *text) {
    // Formula: index = 0.0588 * L - 0.296 * S - 15.8
    // L: # letters per 100 words
    // S: # num sentences per 100 word

    const int length = strlen(text);
    const float numWords = (float) wordCount(text);
    const float numLetters = (float) letterCount(text);
    const float numSentences = (float) sentenceCount(text);

    float scaleFactor = 100.0 / numWords;
    float func = numLetters * scaleFactor * 0.0588 - numSentences*scaleFactor*0.296 - 15.8;
    return (int)round(func);
}


int main(void) {
    // Start by getting the text
    char textSample[2000];
    printf("Text: ");
    fgets(textSample, 2000, stdin);

    int approxLevel = approxGradeLevel(textSample);
    if (approxLevel < 1) {
        printf("Before grade 1\n");
    }else if (approxLevel < 16) {
        printf("Grade %d\n", approxLevel);
    } else {
        printf("Grade 16+\n");
    }
}