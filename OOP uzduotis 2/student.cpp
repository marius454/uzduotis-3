// stdafx.cpp : source file that includes just the standard includes
// OOP uzduotis 2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
using namespace std::chrono;

std::ostream &operator<<(std::ostream& out, studentai& stud) 
{
	out << "			" << std::setw(20) << std::left << stud.pavarde() << std::setw(20) << std::left << stud.vardas() << std::setw(30)
		<< std::fixed << std::setprecision(2) << stud.vid() << stud.med() << std::endl;
	return out;
}

void vectorveiksmai(studentai& stud, size_t nd, int nr)
{
	double sum = 0;
	if (nr == 2) nd = stud.paz().size() - 1;
	for (auto j = 0; j < nd; j++)
	{
		sum = sum + stud.paz().at(j);
	}
	stud.setVid(0.4*(sum / nd) + 0.6*stud.egz());

	auto test = *(stud.paz().end()-1);

	std::vector<int> paz = stud.paz();
	std::sort(paz.begin(), paz.end()-1);

	if ((nd) % 2 != 0)
		stud.setMed(0.4*paz[nd / 2] + 0.6*stud.egz());
	else
	{
		double med = (paz[nd / 2 - 1] + paz[nd / 2]) / 2;
		stud.setMed(0.4*med + 0.6*stud.egz());
	}
}

void isvedimas(std::vector<studentai>& stud)
{

	std::vector<studentai>::iterator it = std::partition(stud.begin(), stud.end(), daugiau);

	std::vector<studentai> less60(it, stud.end());
	stud.erase(it, stud.end());

	std::sort(stud.begin(), stud.end(), acompare);
	std::sort(less60.begin(), less60.end(), acompare);

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (size_t i = 0; i < stud.size(); i++)
	{
		fr << stud[i];
	}
	fr << "vargsiukai:" << std::endl;
	for (size_t i = 0; i < less60.size(); i++)
	{
		fr << less60[i];
	}
	fr.close();
}

void failu_kurimas(size_t m)
{
	std::ofstream fk("kursiokai.txt");
	int n = 5;

	for (size_t i = 0; i < m; i++)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, 10);
		fk << "Pavarde" << i + 1 << " Vardas" << i + 1 << " ";
		for (size_t j = 0; j < n + 1; j++)
			fk << dist(mt) << " ";
		if (i != m - 1)
			fk << std::endl;
	}
	fk.close();
}


// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
