#include <stdio.h>
#include <stdlib.h>

int main() {
	float lamda, **array;
	int size;
	
	printf("Input the number of uknowns: ");
	scanf("%d", &size);

	*array = (float *) malloc(size * sizeof(float));
	if (*array == NULL) {
		printf("Error allocating memmory!\n");
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		array[i] = (float *) malloc((size + 1) * sizeof(float));
		if (array[i] == NULL) {
			printf("Error allocating memmory!\n");
			exit(1);
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size + 1; j++) {
			printf("Input data for field a[%d][%d]: ", i+1, j+1);
			scanf("%f", &array[i][j]);
		}	
	}	

	// step 1
	for (int i = 0; i < size-1; i ++) {
		if(array[i][i] == 0) {
			printf("Mathematicall error\n");
			exit(1);
		}
		for (int j = i+1; j < size; j++) {
			lamda = array[j][i] / array[i][i];
			for (int k = 0; k < size + 1; k++) {
				array[j][k] -= lamda * array[i][k];
			}	
		}
	}

	// step 2
	array[size-1][size] = array[size-1][size]/array[size-1][size-1];
	array[size-1][size-1] = 1;

	for (int i = size-1; i >= 0; i--) {
		for (int j = i-1; j >= 0; j--) {
			lamda = array[j][i] / array[i][i];
			for (int k = 0; k < size + 1; k++) {
				array[j][k] -= lamda * array[i][k];
			}
		}
	}

	// final step
	for (int i = 0; i < size - 1; i++) {
		array[i][size] = array[i][size]/array[i][i];
	}
    
	// printing results
	printf("\n-----------------------------------------------------------------\n");
	printf("Answers:\n");
	for (int i = 0; i < size; i++) {
		printf("%.3f\n", array[i][size]);
	}

	for (int i = 0; i < size+1; i++) {
		free(array[i]);
	}
	free(*array);

	return 0;
}
