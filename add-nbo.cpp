#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "usage : add-nbo <file1> <file2>\n");
		exit(1);
	}

	FILE *fp1 = fopen(argv[1], "r");
	FILE *fp2 = fopen(argv[2], "r");

	uint32_t num1, num2;
	fread(&num1, sizeof(uint32_t), 1, fp1);
	fread(&num2, sizeof(uint32_t), 1, fp2);

	fclose(fp1);
	fclose(fp2);

	uint32_t xnum1 = ntohl(num1);
	uint32_t xnum2 = ntohl(num2);
	uint32_t result = xnum1 + xnum2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", xnum1, xnum1, xnum2, xnum2, result, result);
	return 0;
}
