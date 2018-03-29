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

    int multiple = 2;
    printf("printing the array\n");
   
    for (int i = 2; i <= ((N+1)/2); i++) {
        multiple = i;
        printf("the mutiple is %d\n", i);
        printf("the number in the array is %d\n", prime[i-2]);
        if (prime[i-2] == 0) {
            printf("continued\n");
            continue;
        }
        printf("searching the array with the multiple %d\n", multiple);
        for (int j = 0; j < N-1; j++) {
            if ((prime[j] % multiple == 0 && prime[j] != multiple) && prime[j]!=0) {
                prime[j] = 0;
            }
        }
        multiple += 1;
    }

    printf("the prime numbers from 2 to %d: \n", N);
    for (int i = 0; i < (N-1); i++) {
        if (prime[i] != 0) {
            printf("%d\n", prime[i]);
        }
    }

}

void get_inputs(int argc, char *argv[]){
    if (argc != 3) {
        printf("input: N (2 < N <= 10,000) and t (t < 100)\n");
        exit(1);
    } 

    N = strtol(argv[1], NULL, 10);
    t = strtol(argv[2], NULL, 10);

    //check if N is in range
    if (!(N > 2) || !(N <= 10000)) {
        printf("N (2 < N <= 10,000)\n");
        exit(1);
    }

    //check if t is in range
    else if (!(t > 0) || !(t < 100) ) {
        printf("t (t < 100)\n");
        exit(1);
    }
    //assign command line argument to varibles
    printf("N is %d and t is %d\n", N, t);

    //allocate prime array and set numbers
    prime = (int*)malloc((N-1) * sizeof(int));
    for (int i = 0; i < N-1; i++) {
        prime[i] = i + 2;
    }
}
