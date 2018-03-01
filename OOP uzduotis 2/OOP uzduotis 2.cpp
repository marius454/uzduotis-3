// OOP uzduotis 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



int main()
{
	unsigned int m=0, nd, nr;
	std::ifstream fd("kursiokai.txt");
	if (!fd)
	{
		std::cout << "failas kursiokai.txt neegzistuoja" << std::endl;
		return 0;
	}
	std::ofstream fr("rezultatai.txt");
	std::vector<studentai> stud;
	std::cout << "pasirinkite:" << std::endl;
	std::cout << "1) ivesti duomenis is klaviaturos" << std::endl;
	std::cout << "2) nuskaityti duomenys is failo (kursiokai.txt)" << std::endl;
	std::cin >> nr;
	if (nr == 1)
	{
		std::cout << "iveskite kiek bus vedama mokiniu: ";
		std::cin >> m;
		std::cout << "iveskite kiek bus vedama nd pazymiu: ";
		std::cin >> nd;
		stud.reserve(m);
		for (unsigned int i = 0; i < m; i++)
		{
			studentai temp;
			std::cout << "iveskite " << i+1 << "-ojo mokinio(es) pavarde: ";
			std::cin >> temp.pavarde;
			std::cout << "iveskite " << i+1 << "-ojo mokinio(es) varda: ";
			std::cin >> temp.vardas;
			std::cout << "iveskite " << i+1 << "-ojo mokinio(es) " << nd << " namu darbu pazymius:" << std::endl;
			for (unsigned int j = 0; j < nd; j++)
			{
				unsigned short int a;
				std::cin >> a;
				assert(a <= 10);
				temp.paz.push_back(a);
			}
			std::cout << "iveskite " << i+1 << "-ojo mokinio egzamino bala: ";
			std::cin >> temp.egz;
			assert(temp.egz <= 10);
			stud.push_back(temp);
		}
	}
	else if (nr == 2)
	{
		
		while(!fd.eof())
		{
			m++;
			studentai temp;
			fd >> temp.pavarde;
			fd >> temp.vardas;
			std::string str;
			getline(fd, str);
			std::istringstream is(str);
			unsigned short a;
			while (is >> a)
			{
				assert(a <= 10);
				temp.paz.push_back(a);
			}
			temp.egz = temp.paz.back();
			assert(temp.egz <= 10);
			stud.push_back(temp);
		}
	}
	for (unsigned int i = 0; i < m; i++)
	{
		int sum = 0;
		if (nr == 2) nd = stud[i].paz.size();
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + stud[i].paz.at(j);
		}
		stud[i].vid = 0.4*(sum / nd) + 0.6*stud[i].egz;

	}
	for (unsigned int i = 0; i < m; i++)

	std::sort(stud[i].paz.begin(), stud[i].paz.end());

	for (unsigned int i = 0; i < m; i++)
	{
		if (nr == 2) nd = stud[i].paz.size();
		if ((nd) % 2 != 0)
			stud[i].med = 0.4*stud[i].paz[nd / 2] + 0.6*stud[i].egz;
		else
		{
			double med = (stud[i].paz[nd / 2 - 1] + stud[i].paz[nd / 2]) / 2;
			stud[i].med = 0.4*med + 0.6*stud[i].egz;
		}
	}
	for (unsigned int i = 0; i < m; i++)
		for (unsigned int j = i; j < m; j++)
		{
			studentai temp;
			if (stud[i].pavarde > stud[i].vardas)
			{
				temp = stud[i];
				stud[i] = stud[j];
				stud[j] = temp;
			}
		}
	fr << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	for (unsigned int i = 0; i < m; i++)
	{
		fr << std::setw(20) << std::left << stud[i].pavarde << std::setw(20) << std::left << stud[i].vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << stud[i].vid << stud[i].med << std::endl;
	}
	fd.close();
	fr.close();
	return 0;
}
