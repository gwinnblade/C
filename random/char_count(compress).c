#include <stdio.h>
#include <string.h>

void rle_compress(const char *src, char *dst) {
	int c = 1;
	char *ptr = dst;
	
	for(int i = 0; src[i]; i++){
		if (src[i] == src[i+1]){
			c++;
		} else {
			*ptr++ = src[i];
			if (c>1) {
				sprintf(ptr, "%d", c);
				ptr += strlen (ptr);
			}
			c = 1;
		}
	}
	*ptr = '\0';
}

int main () {
	const char *src = "AAAABBDDDDDDDUUUUU";
	char dst[100];
	rle_compress(src, dst);
	printf("%s\n", dst);
	return 0;
}
