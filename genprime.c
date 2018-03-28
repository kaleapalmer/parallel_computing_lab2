#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N; //number
int t; //threads

void get_input(number, threads) {
    N = number;
    t = threads;
}

int main(int argc, char *argv[]) {


    //TRY RUNNING THIS IS LINUX APPLE IS A LITTLE BITCH
    //check if command line inputs are valid
    if (argc != 2) {
        printf("the number of arguments it %d\n", argc);
        printf("the inputs are %d and %d\n", argv[1], argv[2] );
        printf("input: N (2 < N <= 10,000) and t (t < 100)\n");
        exit(1);
    }

    //set N and t to global varibles
    N = argv[0];
    t = argv[1];

    printf("%d %d", N, t);


    

}