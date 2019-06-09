#pragma once
#include <iostream>
#include <vector> 
#include "value.h"
using std::shared_ptr;

class Plist {
public:
	Plist() {};
	std::vector<std::shared_ptr<value>> List;
	std::vector<std::shared_ptr<value>> give() {
		return List;
	}
	void add(shared_ptr<value>  enter) {
		List.push_back(enter);
	}
	bool has(shared_ptr<value>  enter){
		bool have_it = false;
		for (auto val : List) {
			if (enter == val) {
				have_it = true;
			}
		}
		return have_it;
	}
	void drop(shared_ptr<value> enter) {
		if (!has(enter)){
			std::cout << "error in search" << std::endl;
		}
		else { List.erase(std::find(List.begin(), List.end(), enter));
		}
	}
	void print() {
		for (auto i : List) {
			
			(*i).print();
		}
	}
};
