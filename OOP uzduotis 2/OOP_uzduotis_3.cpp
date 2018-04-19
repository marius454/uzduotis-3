// OOP uzduotis 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std::chrono;

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
	auto start = high_resolution_clock::now();
	std::vector<studentai> stud;

	unsigned int m = 0, nd = 0;
	//if (nr == 1)
	//{
	//	std::cout << "iveskite kiek bus vedama mokiniu: ";
	//	bool bad = false;

	//	do {
	//		std::cin >> m;

	//		bad = std::cin.fail();
	//		if (bad)
	//			std::cout << "Tai nera skaicius, bandykite dar karta: " << std::endl;
	//		std::cin.clear();
	//		std::cin.ignore(10, '\n');
	//	} while (bad);
	//	bad = false;

	//	std::cout << "iveskite kiek bus vedama nd pazymiu: ";
	//	do {
	//		std::cin >> nd;

	//		bad = std::cin.fail();
	//		if (bad)
	//			std::cout << "Tai nera skaicius, bandykite dar karta: " << std::endl;
	//		std::cin.clear();
	//		std::cin.ignore(10, '\n');
	//	} while (bad);
	//	bad = false;

	//	stud.reserve(m);
	//	for (unsigned int i = 0; i < m; i++)
	//	{
	//		studentai temp;
	//		std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) pavarde: ";
	//		std::cin >> temp.pavarde;
	//		std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) varda: ";
	//		std::cin >> temp.vardas;
	//		std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) " << nd << " namu darbu pazymius:" << std::endl;
	//		for (unsigned int j = 0; j < nd; j++)
	//		{
	//			unsigned short int a;
	//			int test = 0;
	//			do {
	//				std::cin >> a;

	//				bad = std::cin.fail();
	//				if (bad || a > 10)
	//					std::cout << "Tai nera skaicius arba skaicius nera tarp 0 ir 10, bandykite dar karta: " << std::endl;
	//				std::cin.clear();
	//				std::cin.ignore(10, '\n');
	//			} while (bad);
	//			bad = false;
	//			temp.paz.push_back(a);
	//		}
	//		std::cout << "iveskite " << i + 1 << "-ojo mokinio egzamino bala: ";
	//		do {
	//			std::cin >> temp.egz;

	//			bad = std::cin.fail();
	//			if (bad || temp.egz > 10)
	//				std::cout << "Tai nera skaicius arba skaicius nera tarp 0 ir 10, bandykite dar karta: " << std::endl;
	//			std::cin.clear();
	//			std::cin.ignore(10, '\n');
	//		} while (bad);
	//		bad = false;

	//			stud.push_back(temp);
	//			stud1.push_back(temp);
	//			stud2.push_back(temp);
	//			stud3.push_back(temp);
	//			stud4.push_back(temp);
	//			stud5.push_back(temp);
	//	}
	//}
	if (nr == 2)
	{
		std::ifstream fd("kursiokai.txt");
		if (!fd)
		{
			std::cerr << "failas kursiokai.txt neegzistuoja" << std::endl;
			return 0;
		}
		int iter = 0;
		while (!fd.eof())
		{
			stud.push_back(stud[iter].readStudent(fd));
			stud[iter].vectorveiksmai(stud[iter].vid(), stud[iter].med(), stud[iter].paz(), stud[iter].egz());
			iter++;
		}
		fd.close();
	}
	isvedimas(stud);

	//start = high_resolution_clock::now();


	/*auto end = high_resolution_clock::now();
	std::cout << duration<double>(end - start).count() << "s\n";*/
	return 0;
}
