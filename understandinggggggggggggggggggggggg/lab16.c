#include <stdio.h>
#include <stdint.h>

int count_set_bits(const void *data, size_t size) {
    int count = 0;
    const unsigned char *bytes = (const unsigned char *)data;

    for (size_t i = 0; i < size; ++i) {
        unsigned char byte = bytes[i];
        while (byte) {
            count += byte & 1;
            byte >>= 1;
        }
    }

    return count;
}

void print_bits(const void *data, size_t size) {
    const unsigned char *bytes = (const unsigned char *)data;

    for (size_t i = 0; i < size; ++i) {
        unsigned char byte = bytes[i];

        for (int j = 7; j >= 0; --j) {
            printf("%d", (byte >> j) & 1);
        }

        printf(" "); 
    }

    printf("\n");
}

int main() {
    long input_long;
    double input_double;

    printf("Input long: ");
    scanf("%ld", &input_long);

    printf("Input double: ");
    scanf("%lf", &input_double);

    int bits_long = count_set_bits(&input_long, sizeof(input_long));
    int bits_double = count_set_bits(&input_double, sizeof(input_double));

    printf("\nbits in long - %ld:\n", input_long);
    print_bits(&input_long, sizeof(input_long));
    printf("count of 1: %d\n", bits_long);

    printf("\nbits in double - %.10g:\n", input_double);
    print_bits(&input_double, sizeof(input_double));
    printf("count of 1: %d\n", bits_double);

    return 0;
}
