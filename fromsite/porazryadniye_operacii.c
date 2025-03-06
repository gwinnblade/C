#include <stdio.h>
// �������� ���������, ������� ������ 1-� � 2-� ���� �����.
// ��������, ����� 13 � �������� ������� ����� 0b01101.
// � ���������� ���� �������� 0b01011 ��� ����� 11 � ���������� �������. 
// ������ ����� ���� ������ ������ (�� ������� �������� � �������) ������� � ����.  
int main()
{
    unsigned char data = 0b1101;
    unsigned char bit_1 = (data >> 1) & 1;
    unsigned char bit_2 = (data >> 2) & 1;
    unsigned char xor_of_bit = bit_1 ^ bit_2;
    unsigned char result = data ^ (xor_of_bit << 1 | xor_of_bit << 2);
    printf("Result: %d", result);
    return 0;
}
