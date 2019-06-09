#include "value.h"
#include "Plist.h"

using std::make_shared;

int main() {
	Plist list;
	std::shared_ptr<value> o1, o2, o3, o4,o5,o6;
	o1 = std::make_shared<Integer>(42);
	o2 = std::make_shared<Integer>(73);
	o3 =std::make_shared<Double>(365.25);
	o4 = std::make_shared<Double>(3.14);
	o5 =std::make_shared<Str>("good");
	o6 =std::make_shared<Str>("boy");
	list.print();
	list.add(o1);
	list.add(o2);
	list.add(o3);
	list.add(o4);
	std::cout <<"has o6?  "<< list.has(o6) << std::endl;
	list.add(o5);
	list.add(o6);
	std::cout << "has o6?  " << list.has(o6) << std::endl;
	list.print();
	list.drop(o6);
	std::cout << "has o6?  " << list.has(o6) << std::endl;
	list.print();

	return 0;
}