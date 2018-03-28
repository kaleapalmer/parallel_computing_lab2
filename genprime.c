#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
void get_input(char *inputs[]) {
    N = inputs[1];
    t = inputs[2];
    printf("the arguments are %s and %s", N, t);
}
*/
int main(int argc, char *argv[]) {
    int N; //number
    int t; //threads

    //check if command line inputs are valid
    if (argc != 2) {
        printf("the number of arguments is %d\n", argc);
        printf("the inputs are %s and %s\n", argv[1], argv[2]);
        printf("input: N (2 < N <= 10,000) and t (t < 100)\n");
        N = strtol(argv[1], NULL, 10);
        t = strtol(argv[2], NULL, 10);
        printf("the arguments are %d and %d\n", N, t);
        exit(1);
    }

}