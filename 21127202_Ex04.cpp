#include <iostream>
#include "A04.h"

using namespace std;

int main()
{
	DList numa,numb;
	Input(numa, numb);
	SList s;
	Sum(numa, numb, s);
	Output(s);
	return 0;
}