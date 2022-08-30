#ifndef __MATOPS_H__
#define __MATOPS_H__

void printMat(float *M, unsigned int N);
void MultRowScl(float *M, unsigned int Row, float Alpha, unsigned int N);
void UpperR(float *M, unsigned int N);
void GaussJordan(float *M, unsigned int N);
void getAnswer(float *M, float *S, unsigned int N);

#endif
