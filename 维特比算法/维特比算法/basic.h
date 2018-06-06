#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define h0 0.8
#define h1 0.4
#define h2 0.2
#define column 10
#define row 12

double H[row][column] = { 0 };
double W[row];
int X[column];
double Y[row];
int binary[10];
double YY[row];
int XX[column] = { 0 };

void CreatH() {
	for (int col = 0; col < 10; col++) {
		H[col][col] = h0;
		H[col + 1][col] = h1;
		H[col + 2][col] = h2;
	}
}

void CreatW() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < row; i++) W[i] = ((double)(rand() % 10)) / 10;
}

void DisplayH() {
	printf("\n\nH:\n\n");
	for (int r = 0; r < row; r++) {
		for (int col = 0; col < column; col++) {
			printf("%.2f ", H[r][col]);
		}
		printf("\n");
	}
}

void DisplayW() {
	printf("\n\nW:\n\n");
	for (int i = 0; i < row; i++) {
		printf("%.2f ", W[i]);
	}
}

void CreatX() {
	srand((unsigned)clock());
	for (int i = 0; i < column; i++) {
		int temp = ((double)(rand() % 10));
		if (temp >= 5) X[i] = 1;
		else X[i] = -1;
	}
}

void DisplayX() {
	printf("\nX:\n");
	for (int i = 0; i < column; i++) {
		printf("%d ", X[i]);
	}
}

void CreatY() {
	for (int r = 0; r < row; r++) {
		double sum = 0;
		for (int col = 0; col < column; col++) {
			sum += H[r][col] * X[col];
		}
		Y[r] = sum + W[r];
	}
}

void DisplayY() {
	printf("\n\nY:\n\n");
	for (int i = 0; i < row; i++) {
		printf("%.2f ", Y[i]);
	}
}

void TempY() {
	for (int r = 0; r < row; r++) {
		double sum = 0;
		for (int col = 0; col < column; col++) {
			sum += H[r][col] * binary[col];
		}
		YY[r] = Y[r] - sum;//就是Y - HX
	}
}

double MinDistance() {
	double sum = 0;
	for (int i = 0; i < row; i++) {
		sum += pow(YY[i], 2);
	}
	return sum;//返回某个情况下的
}

void TTT(int n) {
	int i = 9;
	for (int j = 0; j < 10; j++) binary[j] = 0;
	while (n) {
		binary[i--] = n % 2;
		n /= 2;
	}
}

void TestMin() {
	int order = 0;
	double minmin = 100;
	for (int j = 0; j < 1024; j++) {
		TTT(j);
		for (int i = 0; i < 10; i++) {
			if (binary[i] == 0) binary[i] = -1;
		}
		TempY();
		double temp = MinDistance();
		if (minmin > temp) {
			minmin = temp;
			order = j;
		}
	}
	TTT(order);
	for (int i = 0; i < 10; i++) {
		if (binary[i] == 0) binary[i] = -1;
	}
}


