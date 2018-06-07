#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define h0 0.8
#define h1 0.4
#define h2 0.2
#define column 10
#define row 12

extern double H[row][column];
extern double W[row];
extern int X[column];
extern double Y[row];
extern int binary[10];
extern double YY[row];
extern int XX[column];

void CreatH();

void CreatW();

void DisplayH();

void DisplayW();

void CreatX();

void DisplayX();

void CreatY();

void DisplayY();

void TempY();

double MinDistance();

void TTT(int n);

void TestMin();

void CreatData();


