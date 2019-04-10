#include <iostream>
#include <algorithm>
class Rational {
private:
	int num;
	int denom;
public:
	Rational() {
		num = 0;
		denom = 1;
	}
	;
	Rational(int n, int d) {
		
		num = n;
		denom = d;
		Sokrach();
	};
	void Znak() {
		if (denom < 0) {
			num = -num;
			denom = -denom;
		}
		if (denom == 0) {
			std::cout << "denom Error";
		}
		
	}
	void Sokrach() {
		
		
		int nod = std::abs(std::min(num,denom));
		
		for (int i = 2; i<=nod; i++) {
			
			if (num!=0&&num%i == 0 && denom%i == 0) {
				num = num / i;
				denom = denom / i;
				nod = nod / i;
				i = i - 1;
			}

		}
		
		
	}

	Rational(const Rational & z); // îá¤çàòåëüíî ññûëêà (&)òê èíà÷å áóäåò ïîñòî¤ííî âûçûâàòüñ¤ ýòîò  ìåòîä èç çà íåîáõîäèìîñòè êîïèðîâàíè¤ êîïèðîâàíè¤, const ÷òîáû îáúåêò íå èçìåíèëñ¤
	int getNum() const { return num; }
	int getDenom() const { return denom; }


	Rational operator = (const Rational & orig) {// îáú¤âëåíèå îïåðàòîðà ñíàðóæè êëàññà
		//std::cout << num << " " << denom;
		num = orig.num;
		denom = orig.denom;
		Sokrach();
		return Rational(num, denom);
	}
	Rational operator++() {
		num = num + denom;
		return Rational(num, denom);
	} //(++c) äë¤ êàêîé òî èç ôîðì èíêðåìåíòà ïî¤âë¤åòñ¤ ôåéêîâà¤ ïåðåìåííà¤
	Rational operator++(int) {
		
		num += denom;
		return Rational(num, denom);
	}; //(c++) äë¤ êàêîé òî èç ôîðì èíêðåìåíòà ïî¤âë¤åòñ¤ ôåéêîâà¤ ïåðåìåííà¤
	Rational operator-(Rational &second) {
		int numb1, denom1;
		numb1 = (num*second.denom - second.num*denom);
		denom1 = second.denom*denom;
		Znak();
		Sokrach();
		return Rational(numb1, denom1);
		//return *this;
	}
	Rational operator+(Rational &second) {
		int numb1, denom1;
		numb1 = (num*second.denom + second.num*denom);
		denom1 = second.denom*denom;
		Znak();
		
		return Rational(numb1, denom1);
	}
	Rational operator*(Rational &second) {
		int numb1, denom1;
		numb1 = (num*second.num);
		denom1 = second.denom*denom;
		
		return Rational(numb1, denom1);
	}
	Rational operator/ ( Rational  &second) {
		int numb1, denom1;
		numb1 = (num*second.denom);
		denom1 = (second.num*denom);
		
		Znak();
		return Rational(numb1, denom1);
	}
	Rational operator +=(Rational &r) {
		num = (num*r.denom + denom * r.num);
		denom = denom * r.denom;
		
		return Rational(num, denom);
	}
	Rational operator -=(Rational &r) {
		num = (num*r.denom - denom * r.num);
		denom = denom * r.denom;
		
		return Rational(num, denom);
	}
	Rational operator *=(Rational &r) {
		num = (num*r.num);
		denom = denom * r.denom;
		
		return Rational(num, denom);
	}
	Rational operator /=(Rational &r) {
		num = (num*r.denom);
		denom = denom * r.num;
		
		Znak();
		return Rational(num, denom);
	}
};
/*
ostream & operator<< (std::ostream &os, const Rational r) {
	os << r.num << "/" << r.denom;
	return os;
}
*/
int main() {
	Rational a = Rational(2, 16);
	Rational b = Rational(1, 4);
	Rational c ;
	c=a/b;
	//c=b-a;
	std::cout << c.getNum() << "/" << c.getDenom();
	return 0;
}
