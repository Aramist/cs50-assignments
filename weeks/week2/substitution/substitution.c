#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyValid(const char *key) {
    int hitChars[26];

    for (int i = 0; i < 26; i++) {
        if (!isalpha(key[i])) {
            printf("All characters in the key must be letters.\n");
            return 0;
        }
        int idxInAlphabet = tolower(key[i]) - 'a';
        hitChars[idxInAlphabet] = 1;
    }

    for (int i = 0; i < 26; i++) {
        if (!hitChars[i]){ 
            printf("Key must contain each letter exactly once.\n");
            return 0;
        }
    }
    return 1;
}

void convert(char *plaintext, const char *key) {
    int length = strlen(plaintext);

    for(int i = 0; i < length; i++) {
        if (!isalnum(plaintext[i])) { continue; }
        int idxInKey = tolower(plaintext[i]) - 'a';
        if (isupper(plaintext[i])){
            plaintext[i] = toupper(key[idxInKey]);
        } else{
            plaintext[i] = tolower(key[idxInKey]);
        }
    }
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    const char *key = argv[1];
    if (strlen(key) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (!isKeyValid(key)) {
        return 1;
    }

    char plain[200];
    printf("Plaintext: ");
    fgets(plain, 200, stdin);

    convert(plain, key);
    printf("Ciphertext: %s\n", plain);
    return 0;
}