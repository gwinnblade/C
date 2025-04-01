#include <stdio.h>

enum color
{
	RED,
	GREEN,
	BLUE
};
int main(void)
{
	enum color myColor = RED;
	switch(myColor)
	{
		case RED:
			printf("RED");
			break;
		case GREEN:
			printf("GREEN");
			break;
		case BLUE:
			printf("BLUE");
			break;
	}
	return 0;
}
