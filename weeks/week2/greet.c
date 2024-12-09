#include <stdio.h>


int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *name = argv[1];
        printf("Hello, %s", name);
    } else if (argc == 1){
        printf("What is your name? ");
        char name[100];
        fgets(name, 100, stdin);
        printf("Hello, %s\n", name);
    } else {
        return 1;
    }
    return 0;
}