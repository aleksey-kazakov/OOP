#pragma once
#include <vector>
#include <iostream>
extern int sw = 1;
void Switch() {
	sw++;
}
class Tint;
class Time {
public:
	Time() {
		HH = 0;
		mm = 0;
		MM = 0;
		DD = 0;
		YYYY = 0;
	}
	Time(int  HHp, int mmp, int DDp,int MMp, int YYYYp) {
		HH = HHp;
		mm=mmp;
		MM=MMp;
		DD=DDp;
		YYYY = YYYYp;
		check();
	};
	void Print() {

		std::cout << HH << ":" << mm << " " << DD  << "/"
			<< MM<< "/" << YYYY << std::endl;
	}

	void check() { 

			if (mm < 0) {
				while (mm < 0) {
					mm = mm + 60;
					HH = HH - 1;
				}
			}
			if (HH< 0) {
				while (HH< 0) {
					HH = HH + 24;
					DD = DD - 1;
				}
			}
			if (DD < 0) {
				while (DD < 0) {
					DD= DD + 31;
					MM = MM - 1;
				}
			}
			if (MM< 0) {
				while (MM < 0) {
					MM = MM + 12;
					YYYY = YYYY - 1;
				}
			}
			if (int(mm / 60) != 0) {
				int per = mm / 60;
				HH = HH + per;
				mm = mm - 60 * per;


			}
			if (int(HH / 24) != 0) {
				int per = HH / 24;
				DD = DD + per;
				HH = HH - 24 * per;
			}
			if (int(DD / 31) != 0) {
				int per = DD / 31;
				MM = MM + per;
				DD = DD - 31 * per;
			}
			if (int(MM/ 12) !=0) {
				int per = MM / 12;
				YYYY = YYYY + per;
				MM =MM - 12 * per;
			}
	
	}

	
	int retHH() {
		return HH;
	}
	int retmm() {
		return mm;
	}
	int retMM() {
		return MM;
	}
	int retDD() {
		return DD;
	}
	int retYYYY() {
		return YYYY;
	}

	friend Tint;
private: 
	int HH;
	int mm;
	int MM;
	int DD;
	int YYYY;

	std::vector<int> date;
};
class Tint {
public:
	Tint() {
		HH = 0;
		mm = 0;
		MM = 0;
		DD = 0;
		YY = 0;
	}
	Tint(int mmp, int HHp, int DDp, int MMp, int YYp) {
		mm = mmp;
		HH = HHp;
		DD = DDp;
		MM = MMp;
		YY = YYp;
		check();
	}
	void check() {

		if (mm < 0) {
			while (mm < 0) {
				mm = mm + 60;
				HH = HH - 1;
			}
		}
		if (HH < 0) {
			while (HH < 0) {
				HH = HH + 24;
				DD = DD - 1;
			}
		}
		if (DD < 0) {
			while (DD < 0) {
				DD = DD + 31;
				MM = MM - 1;
			}
		}
		if (MM < 0) {
			while (MM < 0) {
				MM = MM + 12;
				YY = YY - 1;
			}
		}
		if (int(mm / 60) != 0) {
			int per = mm / 60;
			HH = HH + per;
			mm = mm - 60 * per;


		}
		if (int(HH / 24) != 0) {
			int per = HH / 24;
			DD = DD + per;
			HH = HH - 24 * per;
		}
		if (int(DD / 31) != 0) {
			int per = DD / 31;
			MM = MM + per;
			DD = DD - 31 * per;
		}
		if (int(MM / 12) != 0) {
			int per = MM / 12;
			YY = YY + per;
			MM = MM - 12 * per;
		}

	}

	void print() {
		std::cout << mm << " minutes, " << HH << " hours, " << DD << " days, " << MM
			<< " months, " << YY << " years ";

	}
	friend Time;
	int retHH() {
		return HH;
	}
	int retmm() {
		return mm;
	}
	int retMM() {
		return MM;
	}
	int retDD() {
		return DD;
	}
	int retYY() {
		return YY;
	}

private:
	int HH;
	int mm;
	int MM;
	int DD;
	int YY;

};
Time operator +(Time &T1, Tint &t2) {
	int HH = T1.retHH() + t2.retHH();
	int mm = T1.retmm() + t2.retmm();
	int MM = T1.retMM() + t2.retMM();
	int DD = T1.retDD() + t2.retDD();
	int YY = T1.retYYYY() + t2.retYY();
	return Time(HH,mm,MM,DD,YY);
}
Time operator -(Time &T1, Tint &t2) {
	int HH = T1.retHH() - t2.retHH();
	int mm = T1.retmm() - t2.retmm();
	int MM = T1.retMM() - t2.retMM();
	int DD = T1.retDD() - t2.retDD();
	int YY = T1.retYYYY() - t2.retYY();
	return Time(HH,mm,MM,DD,YY);
}
Tint operator -(Time &T1, Time &t2) {
	int HH = T1.retHH() - t2.retHH();
	int mm = T1.retmm() - t2.retmm();
	int MM = T1.retMM() - t2.retMM();
	int DD = T1.retDD() - t2.retDD();
	int YY = T1.retYYYY() - t2.retYYYY();
	return Tint(mm, HH, DD, MM, YY);

}
Tint operator -(Tint &T1, Tint &t2) {
	int HH = T1.retHH() - t2.retHH();
	int mm = T1.retmm() - t2.retmm();
	int MM = T1.retMM() - t2.retMM();
	int DD = T1.retDD() - t2.retDD();
	int YY = T1.retYY() - t2.retYY();
	return Tint(mm, HH, DD, MM, YY);

}
Tint operator +(Tint &T1, Tint &t2) {
	int mm = T1.retmm() + t2.retmm();
	int HH = T1.retHH() + t2.retHH();
	int MM = T1.retMM() + t2.retMM();
	int DD = T1.retDD() + t2.retDD();
	int YY = T1.retYY() + t2.retYY();
	return Tint(mm, HH, DD, MM, YY);

}
std::ostream& operator<< (std::ostream &out,Time& t) {
	if ((sw % 2) == 1) {
		out << t.retHH() << ":" << t.retmm() << " " << t.retDD() << "/"
			<< t.retMM() << "/" << t.retYYYY() << std::endl;
	}
	else {
		if (t.retHH() / 12 > 0) {
			out << (t.retHH() % 12) << ":" << t.retmm() << " PM " << t.retMM()
				<< "/" << t.retDD() << "/" << t.retYYYY()<<std::endl;
		}
		if (t.retHH() / 12 == 0) {
				out << (t.retHH() ) << ":" << t.retmm() << " AM " << t.retMM()
					<< "/" << t.retDD() << "/" << t.retYYYY()<<std::endl;
		}	
	}
	return out;
}
std::ostream& operator<< (std::ostream &out, Tint& t) {
	out << t.retmm() << " minutes, " << t.retHH() << " hours, " << t.retDD() << " days, " << t.retMM()
		<< " months, " << t.retYY() << " years "<<std::endl;
	return out;
}