// stdafx.cpp : source file that includes just the standard includes
// OOP uzduotis 2.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
using namespace std::chrono;

void vectorveiksmai(double vid, double med, std::vector<int>& paz, unsigned short int egz)
{
	std::size_t nd = 0;
	std::vector<studentai> less60;
	std::vector<studentai> more60;
	std::cout << "laikas naudojant vectorius: ";
	int sum = 0;
	/*if (nr == 2)*/ nd = paz.size() - 1;
	for (unsigned int j = 0; j < nd; j++)
	{
		sum = sum + paz.at(j);
	}
	vid = 0.4*(sum / nd) + 0.6*egz;

	std::sort(paz.begin(), paz.end() - 1);

	/*if (nr == 2)*/ nd = paz.size() - 1;
	if ((nd) % 2 != 0)
		med = 0.4*paz[nd / 2] + 0.6*egz;
	else
	{
		double med = (paz[nd / 2 - 1] + paz[nd / 2]) / 2;
		med = 0.4*med + 0.6*egz;
	}
}

void isvedimas(std::vector<studentai> stud)
{
	unsigned int  m1 = 0, m2 = 0;
	//std::sort(stud.begin(), stud.end(), acompare);
	auto start = high_resolution_clock::now();

	std::vector<studentai> more60, less60;

	std::copy_if(stud.begin(), stud.end(), back_inserter(more60), maziau);
	std::copy_if(stud.begin(), stud.end(), back_inserter(less60), daugiau);

	auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";

	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (unsigned int i = 0; i < m1; i++)
	{
		fr << "			" << std::setw(20) << std::left << more60[i].pavarde() << std::setw(20) << std::left << more60[i].vardas() << std::setw(30);
		fr << std::fixed << std::setprecision(2) << more60[i].vid() << more60[i].med() << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (unsigned int i = 0; i < m2; i++)
	{
		fr << "			" << std::setw(20) << std::left << less60[i].pavarde() << std::setw(20) << std::left << less60[i].vardas() << std::setw(30);
		fr << std::fixed << std::setprecision(2) << less60[i].vid() << less60[i].med() << std::endl;
	}
	fr.close();
}

void failu_kurimas(int m)
{
	std::ofstream fk("kursiokai.txt");
	int n = 5;

	for (int i = 0; i < m; i++)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, 10);
		fk << "Pavarde" << i + 1 << " Vardas" << i + 1 << " ";
		for (int j = 0; j < n + 1; j++)
			fk << dist(mt) << " ";
		if (i != m - 1)
			fk << std::endl;
	}
	fk.close();
}


// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
