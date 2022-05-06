#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BITS 8
#define MAX_NUMBER ((1 << MAX_BITS) - 1)

void usage() {
	printf("Usage:\n");
	printf("\tbits number\n");
}

void number_limit() {
	printf("Error:\n");
	printf("\tYou number needs to be between 0 and %d\n", MAX_NUMBER);
}

void print_bits_big(int n) {
	int i = 0;
	char* bits = (char*) malloc(MAX_BITS * sizeof(char));
	for (; n>0 && i < MAX_BITS; n = n >> 1, i++) {
		if (n & 1) bits[i] = '1';
		else bits[i] = '0';
	}
	for (;i < MAX_BITS; i++) bits[i] = '0';
	printf("Big Endian:\n\t%s\n\n", bits);
}

void print_bits_little(int n) {
	int i = MAX_BITS - 1;
	char* bits = (char*) malloc(MAX_BITS * sizeof(char));
	for (; n>0 && i>=0; n = n >> 1, i--) {
		if (n & 1) bits[i] = '1';
		else bits[i] = '0';
	}
	for (;i >= 0; i--) bits[i] = '0';
	printf("Little Endian:\n\t%s\n\n", bits);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		usage();
		return 1;
	}

	if (!strcmp(argv[1], "--help") ||
			!strcmp(argv[1], "-h")) {
		usage();
		return 0;
	}
	
	int n = atoi(argv[1]);

	if (n < 0 || n > MAX_NUMBER) {
		number_limit();
		return 1;
	}

	printf("Bits of the number %d in:\n\n", n);
	print_bits_big(n);
	print_bits_little(n);

	return 0;
}
