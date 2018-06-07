#include "viterbi.h"



void DisplayAnswer() {
	printf("\n\nAnswer:\n");
	for (int i = 0; i < 10; i++) printf("%d ", binary[i]);
}

int main() {
	time_t start, end;
	clock_t cstart, cend;

	start = time(NULL);
	cstart = clock();

	int right = 0;
	for (int i = 0; i < 1000; i++) {
		CreatData();
		TestMin();
		for (int i = 0; i < 10; i++) {
			if (binary[i] == X[i]) right++;
		}
		//DisplayX();
		//DisplayAnswer();
	}

	double accuracy = right / 100;
	
	end = time(NULL);
	cend = clock();
	printf("\n暴力方法运行时间: %dms\n", cend - cstart);
	printf("暴力方法准确性 = %.2f%%\n", accuracy);

	start = time(NULL);
	cstart = clock();

	right = 0;
	for (int i = 0; i < 1000; i++) {
		CreatData();
		vStart();
		vTempY();
		for (int i = 0; i < 10; i++) {
			if (XX[i] == X[i]) right++;
		}
		//DisplayX();
		//DisplayViterbi();
	}
	accuracy = right / 100;

	end = time(NULL);
	cend = clock();
	printf("\n维特比方法运行时间: %dms\n", cend - cstart);
	printf("维特比方法准确性 = %.2f%%\n", accuracy);


	system("pause");
	return 0;
}