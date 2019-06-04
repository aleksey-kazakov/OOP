#include "node.h"
#include "tree.h"
int main() {
	Tree<int> dub;
	dub.add(5);
	dub.add(1542);
	dub.add(23);
	dub.add(42);
	dub.print(dub.get_root());
	dub.find(1643);

	return 0;
}