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

class studentai
{
private:
	std::string vardas_, pavarde_;
	std::vector<int> paz_;
	int egz_;
	double vid_;
	double med_;
public:
	studentai() : egz_(0) { }
	studentai(std::istream& is);

	void setEgz(int egz) { egz_ = egz; }
	int egz() const { return egz_; }

	void setFirstN(std::string vardas) { vardas_ = vardas; }
	std::string vardas() const { return vardas_; }

	void setLastN(std::string pavarde) { pavarde_ = pavarde; }
	std::string pavarde() const { return pavarde_; }

	void setVid(int vid) { vid_ = vid; }
	double vid() const { return vid_; }

	void setMed(int med) { med_ = med; }
	double med() const { return med_; }

	void setPaz(int nd) { paz_.vector::push_back(nd); }
	std::vector<int> paz() const { return paz_ ; }

	std::istream& readStudent(std::istream&);

	void vectorveiksmai(double vid, double med, std::vector<int>& paz, unsigned short int egz);
};

void isvedimas(std::vector<studentai> stud);

bool acompare(studentai lhs, studentai rhs) { return lhs.pavarde() < rhs.pavarde(); }

bool maziau(studentai a) { return a.vid() < 6; }
bool daugiau(studentai a) { return a.vid() >= 6; }

void failu_kurimas(int m);

//void vectorveiksmai(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd);
//void listveiksmai(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd);
//void dequeveiksmai(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd);
//
//void vectorveiksmai2(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd);
//void listveiksmai2(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd);
//void dequeveiksmai2(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd);



// TODO: reference additional headers your program requires here
