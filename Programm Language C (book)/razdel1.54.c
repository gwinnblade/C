/* ������� �����, ���� � �������� �� ������� ������ */
#include <stdio.h>
#define IN 1 /* ������ ����� */
#define OUT 0  /* ������� ����� */
main()

{
	int c, nLine, nWord, nChar, state;
	state = OUT;
	nLine = nWord = nChar = 0;
	while ((c = getchar()) != EOF) {
		++nChar;
		if (c == '\n')
			++nLine;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nWord;
		}
	}
	printf("%d %d %d \n", nLine, nWord, nChar);
}
