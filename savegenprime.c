#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int N; //number
int t; //threads
int *prime; //array to hold prime numbers

double t_start = 0.0;
double tend = 0.0; 
double ttaken;

void get_inputs(int argc, char *argv[]);
void calculate_prime();
void write_file();

int main(int argc, char *argv[]) {

  
    //check and set the command line inputs
    get_inputs(argc, argv);

    printf("Starting the Parallel Part\n");
    printf("There are %d threads\n", t);

    omp_set_num_threads(t);
    #pragma omp parallel
    {
        printf("This is thread number %d\n", omp_get_thread_num());
        //printf( "Hello, World!\n" );
    }

    //crosses out the multiples
    calculate_prime();

    
    //print prime number array and write to file 
    write_file();
}

void get_inputs(int argc, char *argv[]){
    if (argc != 3) {
        printf("input: N (2 < N <= 10,000) and t (t < 100)\n");
        exit(1);
    } 

    N = strtol(argv[1], NULL, 10);
    t = strtol(argv[2], NULL, 10);

    //check if N is in range
    if (!(N > 2) || !(N <= 100000)) {
        printf("N (2 < N <= 10,000)\n");
        exit(1);
    }

    //check if t is in range
    else if (!(t > 0) || !(t < 100) ) {
        printf("t (t < 100)\n");
        exit(1);
    }

    //allocate prime array and set numbers
    prime = (int*)malloc((N-1) * sizeof(int));
    for (int i = 0; i < N-1; i++) {
        prime[i] = i + 2;
    }
}

void calculate_prime() {
    t_start = omp_get_wtime(); 

    int multiple;

    omp_set_num_threads(t);

    #  pragma omp parallel for num_threads(t)
    for (int i = 2; i <= ((N+1)/2); i++) {
        
        multiple = i;
        
        //if number is crossed out dont search for its multiples
        if (prime[i-2] == 0) {
            continue;
        }

        //search through array for multiples
        for (int j = multiple-1; j < N-1; j++) {
            //printf("%d\n", prime[j]);
            if (prime[j] % multiple == 0 && prime[j]!=0) {
                prime[j] = 0;
            }
        }
    }

    ttaken = omp_get_wtime() - t_start;
    printf("Time take for the main part: %f\n", ttaken);
}

void write_file() {
    char output[100] = "";
    sprintf(output, "%d.txt", N);
    FILE *fp = fopen(output, "w");
    if (!fp) {
        printf("Cannot create the file %s\n", output);
        exit(1);
    }

    //find the prime ranks
    int rank = 1;
    int difference;
    int lastPrime = 2;
    for (int i = 0; i < (N-1); i++) {
        if (prime[i] != 0) {
            if (i == 0) {
                difference = 0;
            }
            else {
                difference = prime[i] - lastPrime;
            }
            fprintf(fp, "%d, %d, %d\n", rank, prime[i], difference);
         
            rank++;
            lastPrime = prime[i];
        }
    }
    fclose(fp);
}
