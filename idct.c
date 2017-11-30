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

int main(){
	int input[8][8]; //Reconstructed DCT coeffecients

	double outputPixel[8][8];

	int a;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			scanf("%d", &a);
			input[i][j] = a;
		}
	}

	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){

			outputPixel[x][y] = 0;

			for(int u = 0; u < 8; u++){
				for(int v = 0; v < 8; v++){
					outputPixel[x][y] += alpha(u) * alpha(v) * input[u][v] * cosine(x, u) * cosine(y, v);  
				}
			}
		}
	}

	int out;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			out = floor(outputPixel[i][j] + 0.5) + 128; //round off + recenter it to range [0, 255]
			printf("%d ", out);	
		}
		printf("\n");
	}

	return 0;
}