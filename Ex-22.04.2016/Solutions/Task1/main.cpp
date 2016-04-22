#include "Vehicle.h"
#include <iostream>
using namespace std;

int main()
{
	Car a("model", 120, "ff1234cc", "Toyota");
	a.print();
	Bicycle b("model2", 3141, 4, "as4234dd", "neznam");
	b.print();

	return 0;
}
