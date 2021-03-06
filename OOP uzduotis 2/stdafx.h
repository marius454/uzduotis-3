// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <list>
#include <deque>
#include <random>

//class studentai
//{
//private:
//	std::string vardas_, pavarde_;
//	std::vector<int> paz_;
//	int egz_;
//	double vid_;
//	double med_;
//public:
//	studentai() : egz_(0) { }
//
//	void setEgz(int egz) { egz_ = egz; }
//	int egz() const { return egz_; }
//
//	void setFirstN(std::string vardas) { vardas_ = vardas; }
//	std::string vardas() const { return vardas_; }
//
//	void setLastN(std::string pavarde) { pavarde_ = pavarde; }
//	std::string pavarde() const { return pavarde_; }
//
//	void setVid(double vid) { vid_ = vid; }
//	double vid() const { return vid_; }
//
//	void setMed(double med) { med_ = med; }
//	double med() const { return med_; }
//
//	void setPaz(int nd) { paz_.vector::push_back(nd); }
//	std::vector<int> paz() const { return paz_ ; }
//
//	friend std::ostream& operator<< (std::ostream&, studentai&);
//	
//	bool operator<(studentai& t) { return pavarde_ < t.pavarde(); }
//	bool operator>(studentai& t) { return !operator<(t) ; }
//
//	bool operator==(studentai& t) { return pavarde_ == t.pavarde(); }
//	bool operator!=(studentai& t) { return !operator==(t); }
//};

//class zmogus
//{
//protected:
//	std::string vardas_;
//	std::string pavarde_;
//public:
//	zmogus() : vardas_(""), pavarde_("") {}
//
//	void setFirstN(std::string vardas) { vardas_ = vardas; }
//	std::string vardas() const { return vardas_; }
//
//	void setLastN(std::string pavarde) { pavarde_ = pavarde; }
//	std::string pavarde() const { return pavarde_; }
//
//};
#include <type_traits>
class zmogus
{
protected:
	std::string vardas_;
	std::string pavarde_;
	zmogus() : vardas_(""), pavarde_("") { }
	zmogus(std::string v, std::string pv) : vardas_(v), pavarde_(pv) {}
public:
	virtual void setFirstN(std::string) { }
	virtual std::string vardas() const = 0;

	virtual void setLastN(std::string ) { }
	virtual std::string pavarde() const = 0;

};
static_assert(std::is_abstract<zmogus>(), "concrete_class ought to be abstract.");

class studentai : public zmogus
{
private:
	std::vector<int> paz_;
	int egz_;
	double vid_;
	double med_;
public:
	studentai() : zmogus{"",""}, egz_(0) { }
	studentai(std::string v, std::string pv, int egz, std::vector<int> paz) : zmogus{v,pv}, egz_(0), paz_(paz) { }

	void setFirstN(std::string vardas) { vardas_ = vardas; }
	std::string vardas() const { return vardas_; }

	void setLastN(std::string pavarde) { pavarde_ = pavarde; }
	std::string pavarde() const { return pavarde_; }

	void setEgz(int egz) { egz_ = egz; }
	int egz() const { return egz_; }

	void setVid(double vid) { vid_ = vid; }
	double vid() const { return vid_; }

	void setMed(double med) { med_ = med; }
	double med() const { return med_; }

	void setPaz(int nd) { paz_.vector::push_back(nd); }
	std::vector<int> paz() const { return paz_; }

	friend std::ostream& operator<< (std::ostream&, studentai&);

	bool operator<(studentai& t) { return pavarde_ < t.pavarde(); }
	bool operator>(studentai& t) { return !operator<(t); }

	bool operator==(studentai& t) { return pavarde_ == t.pavarde(); }
	bool operator!=(studentai& t) { return !operator==(t); }
};

void vectorveiksmai(studentai& stud, size_t nd, int nr);

void isvedimas(std::vector<studentai>& stud);

bool acompare(studentai lhs, studentai rhs) { return lhs.pavarde() < rhs.pavarde(); }

bool maziau(studentai a) { return a.vid() < 6; }
bool daugiau(studentai a) { return a.vid() >= 6; }

void failu_kurimas(size_t m);



// TODO: reference additional headers your program requires here
