#include "Timeone.h"

int main() {
	Time t1(13, 4, 27, 4, 1996);
	Time t2(40, 14, 5, 16, 1997);
	Tint t3;
	std::cout << t1;
	std::cout << t2;
	t3 = t2 - t1;
	std::cout << t3;
	Time t4 = t2 + t3;
	std::cout << t4;



	Switch();
	std::cout << t1;
	std::cout << t2;


}