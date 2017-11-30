#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(int argc, char **argv){
	uint8_t R, G, B;
	uint8_t Y, Cb, Cr;

	scanf("%u %u %u", &Y, &Cb, &Cr);

	R = floor(Y + 1.402 * (Cr - 128) + 0.5);
	G = floor(Y - (0.344136 * (Cb - 128)) - (0.714136 * (Cr - 128)) + 0.5);
	B = floor(Y + (1.772 * (Cb - 128)) + 0.5);

	printf("%u %u %u\n", R, G, B);
}