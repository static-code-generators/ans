#include <stdint.h>
#include <stdio.h>
#include <math.h>

double cosine(int a, int b){
	return cos((2 * a + 1) * b * M_PI * (1.0f / 16));
}

double alpha(int a){
	if (a == 0)
		return 1 / (2 *sqrt(2.0f));
	return 0.5;
}

int main(int argc, char **argv){
	int input[8 * 8];
	double DCTcoeff[8 * 8];
	int a;

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			scanf("%d", &a);	
			input[i * 8 + j] = a - 128; //shift to range centered at zero
		}
	}

	for(int u = 0; u < 8; u++){
		for(int v = 0; v < 8; v++){
			DCTcoeff[u * 8 + v] = 0;

			for(int x = 0; x < 8; x++){
				for(int y = 0; y < 8; y++){
					DCTcoeff[u * 8 + v] += input[x * 8 + y] * cosine(x, u) * cosine(y, v);  
				}
			}

			DCTcoeff[u * 8 + v] *= alpha(u) * alpha(v);
		}
	}

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			printf("%f ", DCTcoeff[i * 8 + j]);	
		}
		printf("\n");
	}

	return 0;
}