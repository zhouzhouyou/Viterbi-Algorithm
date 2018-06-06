#include "basic.h"

//≥ı ºªØXX[0]
void vStart() {
	double temp1, temp2;
	temp1 = pow((Y[0] - H[0][0]), 2);
	temp2 = pow((Y[0] + H[0][0]), 2);
	if (temp1 < temp2) XX[0] = 1;
	else XX[0] = -1;
}

void vTempY() {
	double temp1, temp2;
	for (int i = 1; i < column; i++) {
		double t1 = 0, t2 = 0;
		XX[i] = 1;
		for (int rr = 0; rr < row; rr++) {
			for (int col = 0; col < column; col++)
				t1 += H[rr][col] * XX[col];
		}
		temp1 =  pow((Y[i] - t1), 2);

		XX[i] = -1;
		for (int rr = 0; rr < row; rr++) {
			for (int col = 0; col < column; col++)
				t2 += H[rr][col] * XX[col];
		}
		temp2 = pow((Y[i] - t2), 2);
		if (temp1 < temp2) XX[i] = 1;
	}
}

void DisplayViterbi() {
	printf("\nThe answer by Viterbi is:\n");
	for (int i = 0; i < column; i++) printf("%d ", XX[i]);
}