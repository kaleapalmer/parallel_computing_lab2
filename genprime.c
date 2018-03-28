#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N; //number
int t; //threads
int *prime; //array to hold prime numbers

void get_inputs(int argc, char *argv[]);


int main(int argc, char *argv[]) {

    //check and set the command line inputs
    get_inputs(argc, argv);

    //set an array equal to N elements


   for (int i = 0; i < N; i++) {
        printf("the index and number is %d and %d", i, prime[i]);
    }

}








void get_inputs(int argc, char *argv[]){
    if (argc != 3) {
        printf("input: N (2 < N <= 10,000) and t (t < 100)\n");
        exit(1);
    }
    //assign command line argument to varibles
    N = strtol(argv[1], NULL, 10);
    t = strtol(argv[2], NULL, 10);
    printf("N is %d and t is %d\n", N, t);

    //allocate prime array and set numbers
    prime = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        prime[i] = i + 1;
    }
}
