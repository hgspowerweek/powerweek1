#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class cls_virtual
{
	virtual void foo() {};

	char a;
	double b;
	int c;
};

class cls_basic
{
	char a;
	double b;
	int c;
};

class cls_good_padding
{
	double b;
	int c;
	char a;
};

int main(int argc, char** argv)
{
	printf("Size Dynamic: %d\n", (int) sizeof(cls_virtual));
	printf("Size Basic: %d\n", (int) sizeof(cls_basic));
	printf("Size Good Padding: %d\n", (int) sizeof(cls_good_padding));
	return(0);
}
