#include <stdio.h>
#include <string.h>

void xor_crypt(char* str, const char* key) {
	size_t key_len = strlen(key);
	for (int i = 0; str[i]; i++) {
		str[i] ^= key[i % key_len];
	}
}

int main () {
	char text[] = "Secret message";
	const char* key = "key";
	printf("Original: %s\n", text);
	xor_crypt(text, key);
	printf("Encrypted: %s\n", text);
	xor_crypt(text, key);
	printf("Decrypted: %s\n", text);
	return 0;
}
