#pragma once
#include <string>
#include <iostream> 
class value {
public:
	 virtual void print() {}
	  bool operator==(const value right) { return 0;	}

};
class Integer : public value {
public:
	Integer( const int & enter) :val(enter) {}
	void print() override {
		std::cout << val << std::endl;
	}
	bool operator==  ( const int right) {
		return (val == right);
	}
private:
	const int val;
};
class Double : public value {
public:
	Double(const double &enter) :val(enter) {}
	void print() override {
		std::cout << val << std::endl;
	}
	bool operator==  (const double right) {
		return (val == right);
	}
private:
	double val;
};
class Str : public value {
public:
	Str(std::string enter) :val(enter) {}
	void print() override {
		std::cout << val << std::endl;
	}
	bool operator== (const std::string right) {
		return (val == right);
	}
private:
	std::string val;
};
