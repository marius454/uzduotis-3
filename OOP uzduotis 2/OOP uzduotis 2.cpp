// OOP uzduotis 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std::chrono;

bool acompare(studentai lhs, studentai rhs) { return lhs.pavarde < rhs.pavarde; }

void vectorveiksmai(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd);
void listveiksmai(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd);
void dequeveiksmai(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd);

int main()
{
	unsigned short int nr;
	std::cout << "pasirinkite:" << std::endl;
	std::cout << "1) ivesti duomenis is klaviaturos" << std::endl;
	std::cout << "2) nuskaityti duomenys is failo (kursiokai.txt)" << std::endl;
	std::cin >> nr;

	for (unsigned int k = 0; k < 3; k++) {
		auto start = high_resolution_clock::now();
		std::vector<studentai> stud;
		std::list<studentai> stud1;
		std::deque<studentai> stud2;

		unsigned int m = 0, nd = 0;

		
		if (nr == 1)
		{
			std::cout << "iveskite kiek bus vedama mokiniu: ";
			try {
				std::cin >> m;
			}
			catch (const std::exception& e)
			{
				std::cerr << "tai nera skaicius";
			};

			std::cout << "iveskite kiek bus vedama nd pazymiu: ";
			try {
				std::cin >> nd;
			}
			catch (const std::exception& e)
			{
				std::cerr << "tai nera skaicius";
			};
			stud.reserve(m);
			for (unsigned int i = 0; i < m; i++)
			{
				studentai temp;
				std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) pavarde: ";
				std::cin >> temp.pavarde;
				std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) varda: ";
				std::cin >> temp.vardas;
				std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) " << nd << " namu darbu pazymius:" << std::endl;
				for (unsigned int j = 0; j < nd; j++)
				{
					unsigned short int a;
					int test = 0;
					do
					{
						try {
						std::cin >> a;
						}
						catch (const std::exception& e)
						{
							std::cerr << "tai nera skaicius";
						};
						if (a > 10)
						{
							std::cout << "ivestas pazymys nera tarp 0 ir 10 bandykite dar karta: ";
						}
						else
						{
							test++;
							temp.paz.push_back(a);
						}

					} while (test == 0);
					
				}
				std::cout << "iveskite " << i + 1 << "-ojo mokinio egzamino bala: ";
				int test = 0;
				do
				{
					std::cin >> temp.egz;
					if (temp.egz > 10)
					{
						std::cout << "ivestas egzamino balas nera tarp 0 ir 10 bandykite dar karta: ";
					}
					else test++;

				} while (test == 0);
				if (k == 0)
					stud.push_back(temp);
				else if (k == 1)
					stud1.push_back(temp);
				else
					stud2.push_back(temp);
				start = high_resolution_clock::now();
			}
		}
		else
		{

			std::ifstream fd("kursiokai.txt");
			if (!fd)
			{
				std::cerr << "failas kursiokai.txt neegzistuoja" << std::endl;
				return 0;
			}
			while (!fd.eof())
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
					if (a <= 10)
						temp.paz.push_back(a);
					else
						std::cerr << "skaicius nera tarp 0 ir 10 todel bus praleidziamas";
				}
				temp.egz = temp.paz.back();
				if (k == 0)
					stud.push_back(temp);
				else if (k == 1)
					stud1.push_back(temp);
				else
					stud2.push_back(temp);
			}
			fd.close();
		}


		if (k == 0)
		{
			vectorveiksmai(stud, nr, nd);
		}
		else if (k == 1)
		{
			listveiksmai(stud1, nr, nd);
		}
		else
		{
			dequeveiksmai(stud2, nr, nd);
		}
		auto end = high_resolution_clock::now();
		std::cout << duration<double>(end - start).count() << "s\n";
	}
	return 0;
}

void vectorveiksmai(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd)
{
	unsigned int m = 0, m1 = 0, m2 = 0;
	std::vector<studentai> less60;
	std::vector<studentai> more60;
	std::cout << "laikas naudojant vectorius: ";
	if (stud.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	m = stud.size();
	for (unsigned int i = 0; i < m; i++)
	{
		if (stud[i].paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = stud[i].paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + stud[i].paz.at(j);
		}
		stud[i].vid = 0.4*(sum / nd) + 0.6*stud[i].egz;
	}

	for (unsigned int i = 0; i < m; i++)
		std::sort(stud[i].paz.begin(), stud[i].paz.end() - 1);

	for (unsigned int i = 0; i < m; i++)
	{
		if (nr == 2) nd = stud[i].paz.size() - 1;
		if ((nd) % 2 != 0)
			stud[i].med = 0.4*stud[i].paz[nd / 2] + 0.6*stud[i].egz;
		else
		{
			double med = (stud[i].paz[nd / 2 - 1] + stud[i].paz[nd / 2]) / 2;
			stud[i].med = 0.4*med + 0.6*stud[i].egz;
		}
	}
	std::sort(stud.begin(), stud.end(), acompare);
	for (unsigned int i = 0; i < m; i++)
	{
		if (stud[i].vid >= 6) {
			more60.push_back(stud[i]);
			m1++;
		}
		else {
			less60.push_back(stud[i]);
			m2++;
		}
	}
	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (unsigned int i = 0; i < m1; i++)
	{
		fr << "			" << std::setw(20) << std::left << more60[i].pavarde << std::setw(20) << std::left << more60[i].vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << more60[i].vid << more60[i].med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (unsigned int i = 0; i < m2; i++)
	{
		fr << "			" << std::setw(20) << std::left << less60[i].pavarde << std::setw(20) << std::left << less60[i].vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << less60[i].vid << less60[i].med << std::endl;
	}
}

void listveiksmai(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd)
{
	std::cout << "laikas naudojant listus: ";
	unsigned int m = 0;
	if (stud1.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = (*it).paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + (*it).paz.at(j);
		}
		(*it).vid = 0.4*(sum / nd) + 0.6*(*it).egz;
	}

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
		std::sort((*it).paz.begin(), (*it).paz.end() - 1);

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if (nr == 2) nd = (*it).paz.size() - 1;
		if ((nd) % 2 != 0)
			(*it).med = 0.4*(*it).paz[nd / 2] + 0.6*(*it).egz;
		else
		{
			double med = ((*it).paz[nd / 2 - 1] + (*it).paz[nd / 2]) / 2;
			(*it).med = 0.4*med + 0.6*(*it).egz;
		}
	}
	stud1.sort(acompare);
	std::list<studentai> more60, less60;

	for (std::list<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).vid >= 6) {
			more60.push_back((*it));
		}
		else {
			less60.push_back((*it));
		}
	}
	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (std::list<studentai>::iterator it = more60.begin(); it != more60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (std::list<studentai>::iterator it = less60.begin(); it != less60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
}

void dequeveiksmai(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd)
{
	std::cout << "laikas naudojant dekus: ";
	unsigned int m = 0;
	if (stud1.size() == 0) { throw std::domain_error("studentu vektorius tuscias"); }
	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).paz.size() == 0) { throw std::domain_error("nd pazymiu vektorius tuscias"); }
		int sum = 0;
		if (nr == 2) nd = (*it).paz.size() - 1;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + (*it).paz.at(j);
		}
		(*it).vid = 0.4*(sum / nd) + 0.6*(*it).egz;
	}

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
		std::sort((*it).paz.begin(), (*it).paz.end() - 1);

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if (nr == 2) nd = (*it).paz.size() - 1;
		if ((nd) % 2 != 0)
			(*it).med = 0.4*(*it).paz[nd / 2] + 0.6*(*it).egz;
		else
		{
			double med = ((*it).paz[nd / 2 - 1] + (*it).paz[nd / 2]) / 2;
			(*it).med = 0.4*med + 0.6*(*it).egz;
		}
	}

	std::sort(stud1.begin(), stud1.end(), acompare);
	std::deque<studentai> more60, less60;

	for (std::deque<studentai>::iterator it = stud1.begin(); it != stud1.end(); ++it)
	{
		if ((*it).vid >= 6) {
			more60.push_back((*it));
		}
		else {
			less60.push_back((*it));
		}
	}
	std::ofstream fr("rezultatai.txt");
	fr << "			" << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	fr << "galvociai:" << std::endl;
	for (std::deque<studentai>::iterator it = more60.begin(); it != more60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
	fr << "vargsiukai:" << std::endl;
	for (std::deque<studentai>::iterator it = less60.begin(); it != less60.end(); ++it)
	{
		fr << "			" << std::setw(20) << std::left << (*it).pavarde << std::setw(20) << std::left << (*it).vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << (*it).vid << (*it).med << std::endl;
	}
}
