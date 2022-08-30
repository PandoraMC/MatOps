#include<stdio.h>
#include"MatOps.h"

void printMat(float *M, unsigned int N){
	printf("===============START=MATRIX===============\n");
	for(unsigned int i = 0; i < N; i++){
		for(unsigned int j = 0; j <= N; j++){
			printf("%.2e\t", *(M + i*(N + 1) + j));
		}
		printf("\n");
	}
	printf("================END=MATRIX================\n");
}

void MultRowScl(float *M, unsigned int Row, float Alpha, unsigned int N){
	for(unsigned int c = 0; c <= N; c++){
		*(M + Row*(N + 1) + c) *= Alpha;
	}
}

void UpperR(float *M, unsigned int N){
	for(unsigned int i = 0; i < N - 1; i++){
		float a = *(M + i*(N + 1) + i);
		for(unsigned int r = i + 1; r < N; r++){
			float d = *(M + r*(N + 1) + i);
			for(unsigned int c = 0; c <= N; c++){
				*(M + r*(N + 1) + c) -= *(M + i*(N + 1) + c)*d/a;
			}
		}
	}
}

void GaussJordan(float *M, unsigned int N){
	for(unsigned int i = 0; i < N; i++){
		float a = *(M + i*(N + 1) + i);
		for(unsigned int r = 0; r < N; r++){
			if(r != i){
				float d = *(M + r*(N + 1) + i);
				for(unsigned int c = 0; c <= N; c++){
					*(M + r*(N + 1) + c) -= *(M + i*(N + 1) + c)*d/a;
				}
			}
		}
	}
}

void getAnswer(float *M, float *S, unsigned int N){
	for(unsigned int i = 0; i < N; i++){
		*(S + i) = *(M + i*(N + 1) + N);
	}
}