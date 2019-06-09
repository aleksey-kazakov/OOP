#pragma once
#include <vector>
#include <algorithm>
#include<iostream>
class Range {
public:
	void Add(int razm[2]) {
		count = 0;
		std::vector<int> raz;
		if (razm[0] <= razm[1]) {
			raz.push_back(razm[0]);
			raz.push_back(razm[1]);
		}
		else {
			raz.push_back(razm[1]);
			raz.push_back(razm[0]);
		}
		ranges.push_back(raz);
		
	}
	int find_itr(const int & a,int size_up,int size_low) {
		int size = (size_up + size_low);
		if ((size_up+size_low) % 2 == 1) {
			size = (size_up + size_low)+1 ;
		}
		int pop = size / 2;
		if ((a >= ranges_sort[(pop ) / 2][0]) && (a <= ranges_sort[(pop ) / 2][1])) {
				std::cout <<a<<" loacated in "<< ranges_sort[(pop ) / 2][0] << "  " << ranges_sort[(pop ) / 2][1] << std::endl;
				return 0;
		}
		if (a > ranges_sort[(pop) / 2][0]) {
			size_low = pop;
		}
		if (a < ranges_sort[(pop) / 2][1]) {
			size_up = pop;
		}
		if (size_up == size_low) {
			std::cout <<a<< " No ranges" << std::endl;
			return 0;
		}
		find_itr(a, size_up, size_low);

	}
	void find(int const& a ){
		if (count == 0) {
			ranges_sort = ranges;
			std::sort(ranges_sort.begin(), ranges_sort.end(), [](std::vector<int> const& a, std::vector<int> const& b) {return (a[0] >= b[1]); });
		}
		if (a > ranges_sort[0][1]) {
			std::cout <<a<< " NO range"<<std::endl;
			return;
		}
		if (a < ranges_sort[ranges_sort.size()-1][0]) {
			std::cout <<a<< " NO range"<<std::endl;
			return;
		}
		int size = ranges_sort.size();
		find_itr(a,  0, size);
		count = 1;
	
	
	}
	void print() {
		for (std::vector<int> i : ranges) {
			std::cout << i[0] << "  " << i[1] << std::endl;
		}
	}
private: 
	int count;
	std::vector<std::vector<int>> ranges;
	std::vector<std::vector<int>> ranges_sort;

};