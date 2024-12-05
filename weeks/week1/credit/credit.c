#include <stdio.h>
#include <string.h>

int isDigit(char d) { return (d >= '0') && (d <= '9'); }

void stripNonDigits(char *number) {
    int i = 0;
    int j = 0;
    int origLength = strlen(number);

    while(j < origLength) {
        if (isDigit(number[j])) {
            number[i] = number[j];
            i++;
            j++;
        }else {
            j++;
        }
    }
    number[i] = '\0';
}

int sumOfDigits(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a = a / 10;
    }
    return sum;
}

int isEven(int a){ return (a + 1) % 2; }

int passesChecksum(const char *number) {
    int length = strlen(number);

    // if length is odd, odd indexed digits get multiplied by 2
    int lengthEven = isEven(length);
    int sum = 0;
    for(int i=0; i < length; i++){
        int digit = number[i] - '0';

        if (lengthEven){
            if (isEven(i)){
                sum += sumOfDigits(digit * 2);
            } else {
                sum += digit;
            }
        } else {
            if (isEven(i)){
                sum += digit;
            } else {
                sum += sumOfDigits(digit * 2);
            }
        }
    }
    return (sum % 10) == 0;
}

int possiblyMastercard(const char *number) {
    int length = strlen(number);
    return (length == 16) && (number[0] == '5') && (number[1] >= '1') && (number[1] <= '5');
}
int possiblyAmex(const char *number) {
    int length = strlen(number);
    return (length == 15) && (number[0] == '3') && ((number[1] == '4') || (number[1] == '7'));
}

int possiblyVisa(const char *number) {
    int length = strlen(number);
    return ((length == 13) || (length == 16)) && (number[0] == '4');
}

int isNumberValid(const char *number) {
    // Expects number to only contain digits in 0-9
    // Assumes no leading 0s

    return possiblyMastercard(number) || possiblyAmex(number) || possiblyVisa(number);
}

int main(void){
    char number [100] = "";
    do {
        printf("Number: ");
        fgets(number, 100, stdin);
        stripNonDigits(number);
    } while (!isNumberValid(number));
    
    printf("Current number: %s \n", number);
    if (!passesChecksum(number)){
        printf("INVALID\n");
        return 0;
    }

    if (possiblyMastercard(number))
        printf("MASTERCARD\n");
    else if (possiblyAmex(number))
        printf("AMEX\n");
    else if (possiblyVisa(number))
        printf("VISA\n");
    else
        printf("INVALID\n");
}
