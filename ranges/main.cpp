#include "Range.h"
int main(){
	Range dogi;
	int r1[2] = { 1,2 };
	int r2[2] = { 3,8 };

	int r3[2] = { 8,20 };
	int r4[2] = { 50,80 }; 
	int r5[2] = { 20,50 };
	int r6[2] = { 80,100 };
	int r7[2] = { 0,1 };
	dogi.Add(r1);
	dogi.Add(r2);
	dogi.Add(r3);
	dogi.Add(r4);
	dogi.Add(r5);
	dogi.Add(r6);
	dogi.Add(r7);
	dogi.print();
	dogi.find(10);
	dogi.find(110);
	dogi.print();
	return 0;



}