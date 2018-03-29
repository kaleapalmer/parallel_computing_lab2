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
   
    for (int i = 0; i < ((N+1)/2 - 2); i++) {
        if (multiple > (N+1)/2){
            break;
        }
        for (int j = 0; j < N; j++) {
            if ((prime[j] % multiple == 0 && prime[j] != multiple) && prime[j]!=0) {
                printf("true with %d\n", prime[j]);
                prime[j] = 0;
            }
        }
        multiple += 1;
    }

    printf("the prime numbers from 2 to %d: \n", N);
    for (int i = 0; i < N; i++) {
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

    if (!(N > 2) || !(N <= 10000)) {
        printf("N (2 < N <= 10,000)\n");
        exit(1);
    }
    else if (!(t > 0) || !(t < 100) ) {
        printf("t (t < 100)\n");
        exit(1);
    }
    //assign command line argument to varibles
    printf("N is %d and t is %d\n", N, t);

    //allocate prime array and set numbers
    prime = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        prime[i] = i + 2;
    }
}
