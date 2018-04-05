// OOP uzduotis 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std::chrono;
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

int main()
{
	pradzia:
	unsigned short int nr = 0;
	std::cout << "pasirinkite:" << std::endl;
	std::cout << "1) ivesti duomenis is klaviaturos" << std::endl;
	std::cout << "2) nuskaityti duomenis is failo (kursiokai.txt)" << std::endl;
	std::cout << "3) sugeneruoti faila kursiokai.txt su n mokiniu kurie turi po 5 nd pazymius" << std::endl;
	bool bad = false;
	do {
		std::cin >> nr;

		bad = std::cin.fail();
		if (bad || nr > 3 || nr == 0)
			std::cout << "Tai nera skaicius arba skaicius nera tarp 1 ir 3, bandykite dar karta: " << std::endl;
		std::cin.clear();
		std::cin.ignore(10, '\n');
	} while (bad);

	if (nr == 3)
	{
		std::cout << "iveskite n: ";
		unsigned long sk = 0;
		do {
			std::cin >> sk;

			bad = std::cin.fail();
			if (bad)
				std::cout << "Tai nera skaiciusa, bandykite dar karta: " << std::endl;
			std::cin.clear();
			std::cin.ignore(10, '\n');
		} while (bad);
		failu_kurimas(sk);
		goto pradzia;
	}

	for (unsigned int k = 0; k < 6; k++) {
		auto start = high_resolution_clock::now();
		std::vector<studentai> stud;
		std::list<studentai> stud1;
		std::deque<studentai> stud2;

		unsigned int m = 0, nd = 0;


		if (nr == 1)
		{
			std::cout << "iveskite kiek bus vedama mokiniu: ";
			bool bad = false;

			do {
				std::cin >> m;

				bad = std::cin.fail();
				if (bad)
					std::cout << "Tai nera skaicius, bandykite dar karta: " << std::endl;
				std::cin.clear();
				std::cin.ignore(10, '\n');
			} while (bad);
			bad = false;

			std::cout << "iveskite kiek bus vedama nd pazymiu: ";
			do {
				std::cin >> nd;

				bad = std::cin.fail();
				if (bad)
					std::cout << "Tai nera skaicius, bandykite dar karta: " << std::endl;
				std::cin.clear();
				std::cin.ignore(10, '\n');
			} while (bad);
			bad = false;

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
					do {
						std::cin >> a;

						bad = std::cin.fail();
						if (bad || a > 10)
							std::cout << "Tai nera skaicius arba skaicius nera tarp 0 ir 10, bandykite dar karta: " << std::endl;
						std::cin.clear();
						std::cin.ignore(10, '\n');
					} while (bad);
					bad = false;

				}
				std::cout << "iveskite " << i + 1 << "-ojo mokinio egzamino bala: ";
				do {
					std::cin >> temp.egz;

					bad = std::cin.fail();
					if (bad || temp.egz > 10)
						std::cout << "Tai nera skaicius arba skaicius nera tarp 0 ir 10, bandykite dar karta: " << std::endl;
					std::cin.clear();
					std::cin.ignore(10, '\n');
				} while (bad);
				bad = false;

				if (k == 0 || k == 3)
					stud.push_back(temp);
				else if (k == 1 || k == 4)
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
				if (k == 0 || k == 3)
					stud.push_back(temp);
				else if (k == 1 || k == 4)
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
		else if (k == 2)
		{
			dequeveiksmai(stud2, nr, nd);
		}
		if (k == 3)
		{
			vectorveiksmai2(stud, nr, nd);
		}
		else if (k == 4)
		{
			listveiksmai2(stud1, nr, nd);
		}
		else if (k == 5)
		{
			dequeveiksmai2(stud2, nr, nd);
		}
		auto end = high_resolution_clock::now();
		std::cout << duration<double>(end - start).count() << "s\n";
	}
	return 0;
}
