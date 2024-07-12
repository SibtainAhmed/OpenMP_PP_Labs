
// Serial Code 

#include <omp.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {
	double dtime1;
	int inputImage[6][6] = {
		{1, 2, 3, 4, 5, 6},
		{7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18},
		{19, 20, 21, 22, 23, 24},
		{25, 26, 27, 28, 29, 30},
		{31, 32, 33, 34, 35, 36}
	};

	int kernel[3][3] = {
		{3, 4, 5},
		{6, 7, 8},
		{9, 10, 11}
	};

	int outputImage[6][6] = { 0 }; // This is a shorthand for setting all values of Array to 0


	dtime1 = omp_get_wtime();


	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5; j++) {
			int R1 = 0;
			for (int k = -1; k < 2; k++) {
				for (int m = -1; m < 2; m++) {
					R1 += inputImage[i + k][j + m] * kernel[k + 1][m + 1];
				}
			}
			outputImage[i][j] = R1;
		}
	}


	dtime1 = omp_get_wtime() - dtime1;


	cout << "Execution time of Serial code: " << dtime1 << " seconds" << endl;


	cout << "\nOutput Image:" << endl;
	for (int i = 0; i < 6; i++) {
		printf("\n\t| ");
		for (int j = 0; j < 6; j++) {
			cout << setw(5) << outputImage[i][j] << " ";
			printf("|");
		}
		cout << endl;
	}



	return 0;
}





#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> // for std::setw
#include <omp.h>

using namespace std;

int main() {
	double dtime1, dtime2, speedUp, Eff, cost;

	dtime1 = 0.0000015; //  1.50001e-06 seconds

	int inputImage[6][6] = {
		{1, 2, 3, 4, 5, 6},
		{7, 8, 9, 10, 11, 12},
		{13, 14, 15, 16, 17, 18},
		{19, 20, 21, 22, 23, 24},
		{25, 26, 27, 28, 29, 30},
		{31, 32, 33, 34, 35, 36}
	};

	int kernel[3][3] = {
		{3, 4, 5},
		{6, 7, 8},
		{9, 10, 11}
	};

	int outputImage[6][6] = { 0 };

	dtime2 = omp_get_wtime();

#pragma omp parallel for 
	for (int i = 1; i < 5; i++) {
	#pragma omp parallel for 
		for (int j = 1; j < 5; j++) {
			int R1 = 0;
			for (int k = -1; k < 2; k++) {
				for (int m = -1; m < 2; m++) {
					R1 += inputImage[i + k][j + m] * kernel[k + 1][m + 1];
				}
			}
			outputImage[i][j] = R1;
		}
	}

	dtime2 = omp_get_wtime() - dtime2;


	cout << "\nOutput Image using OpenMP:" << endl;
	for (int i = 0; i < 6; i++) {
		printf("\n\t| ");
		for (int j = 0; j < 6; j++) {
			cout << setw(5) << outputImage[i][j] << " ";
			printf("|");
		}
		cout << endl;
	}

	cout << "\nExecution time of OpenMP: " << dtime2 << " seconds" << endl;
	speedUp = dtime1 / dtime2;
	printf("SpeedUp = %f\n", speedUp);
	Eff = speedUp / omp_get_num_procs();
	printf("Efficiency = %f\n", Eff);
	cost = dtime2 * omp_get_num_procs();
	printf("cost = %f\n", cost);
	return 0;
}


