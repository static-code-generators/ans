#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>

int main(int argc, char **argv){
	uint8_t R, G, B;
	uint8_t Y, Cb, Cr;

	scanf("%u %u %u", &R, &G, &B);

	Y = floor(0 + (0.299 * R) + (0.587 * G) + (0.114 * B) + 0.5);
	Cb = floor(128 - (0.168736 * R) - (0.331264 * G) + (0.5 * B) + 0.5);
	Cr = floor(128 + (0.5 * R) - (0.418688 * G) - (0.081312 * B) + 0.5);

	printf("%u %u %u\n", Y, Cb, Cr);

	return 0;
}