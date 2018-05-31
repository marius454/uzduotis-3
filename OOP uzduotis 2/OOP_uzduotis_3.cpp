// OOP uzduotis 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <gtest/gtest.h>

using namespace std::chrono;

TEST(studentai, structure_vardas_test)
{
	studentai test;
	test.setFirstN("vardenis") ;

	EXPECT_EQ("vardenis", test.vardas());
};

TEST(studentai, structure_operator_test)
{
	studentai test1;
	studentai test2;
	test1.setLastN("Pavardenis");
	test2.setLastN("zPavardenis");

	EXPECT_TRUE(test1 < test2);
};



int main(int argc, char* argv[])
{
pradzia:
	unsigned int nr = 0;
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
		size_t sk = 0;
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

	std::vector<studentai> stud;

	size_t m = 0, nd = 0;
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
		for (size_t i = 0; i < m; i++)
		{
			studentai temp;
			std::string p, v;
			std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) pavarde: ";
			std::cin >> p;
			temp.setLastN(p);
			std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) varda: ";
			std::cin >> v;
			temp.setFirstN(v);
			std::cout << "iveskite " << i + 1 << "-ojo mokinio(es) " << nd << " namu darbu pazymius:" << std::endl;
			for (size_t j = 0; j < nd; j++)
			{
				unsigned int a;
				int test = 0;
				do {
					std::cin >> a;

					bad = std::cin.fail();
					if (bad || a > 10)
						std::cout << "Tai nera skaicius arba skaicius nera tarp 0 ir 10, bandykite dar karta: " << std::endl;
					std::cin.clear();
					std::cin.ignore(10, '\n');
				} while (bad || a > 10);
				bad = false;
				temp.setPaz(a);
			}
			std::cout << "iveskite " << i + 1 << "-ojo mokinio egzamino bala: ";
			do {
				unsigned short e;
				std::cin >> e;
				temp.setEgz(e);

				bad = std::cin.fail();
				if (bad || temp.egz() > 10)
					std::cout << "Tai nera skaicius arba skaicius nera tarp 0 ir 10, bandykite dar karta: " << std::endl;
				std::cin.clear();
				std::cin.ignore(10, '\n');
			} while (bad || temp.egz() > 10);
			bad = false;

			stud.push_back(temp);
			vectorveiksmai(stud[i], nd, nr);
		}
	}
	auto start = high_resolution_clock::now();
	if (nr == 2)
	{
		start = high_resolution_clock::now();
		std::ifstream fd("kursiokai.txt");
		if (!fd)
		{
			std::cerr << "failas kursiokai.txt neegzistuoja" << std::endl;
			return 0;
		}
		unsigned int iter = 0;
		while (!fd.eof())
		{
			std::string p, v;
			studentai temp;
			fd >> p;
			fd >> v;
			temp.setLastN(p);
			temp.setFirstN(v);
			std::string str;
			getline(fd, str);
			std::istringstream is(str);
			unsigned short a;
			int s = 0;
			while (is >> a)
			{
				temp.setPaz(a);
				s++;
			}
			temp.setEgz(temp.paz().at(s - 1));
			stud.push_back(temp);
			vectorveiksmai(stud[iter], nd, nr);
			iter++;
		}
		fd.close();
	}
	isvedimas(stud);
	if (nr == 2)
	{
		std::cout << "Programa uztruko:" << std::endl;
	
		auto end = high_resolution_clock::now();
		std::cout << duration<double>(end - start).count() << "s\n";
	}


	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}
