#include<stdio.h>
#include"MatOps.h"
#define N 3

#undef DEBUG

int main(int argN, char **argV){
	float Y[N][N + 1] = {	{6, 5, 4, 7},
							{3, 2, 1, 2},
							{7, 8, 0, -5}};
	float S[N];
#ifdef DEBUG
	printMat((float*)Y, N);
#endif
	GaussJordan((float*)Y, N);
	for(unsigned int r = 0; r < N; r++){
		MultRowScl((float*)Y, r, 1/Y[r][r], N);
	}
#ifdef DEBUG
	printMat((float*)Y, N);
#endif
	getAnswer((float*)Y, (float*)S, N);
	for(int i = 0; i < N; i++){
		printf("x%i = %f\n", i, S[i]);
	}
	return 0;
}
