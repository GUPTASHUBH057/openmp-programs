/*
To run the program:

1. gcc -fopenmp prog.c -o prog
2. ./prog

*/


#include<stdio.h>
#include<omp.h>

#define N 2000000

int main(){


int arr[N];
double t1,t2;
int tid, num;
int i;

for(i=0;i<N;i++){

	arr[i] = 1;

}

int sum  = 0;
t1 = omp_get_wtime();

#pragma omp parallel default(shared)
{

int psum = 0;

#pragma omp for
for(i=0;i<N;i++){
	psum+=arr[i];
}

#pragma omp critical
sum+=psum;

}
t2 = omp_get_wtime();

printf("sum is %d and time is %g\n",sum,t2-t1);


return 0;
}
