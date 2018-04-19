#include "stdafx.h"

studentai::studentai(std::istream& is)
{
	readStudent(is);
}

std::istream& studentai::readStudent(std::istream& fd)
{
	studentai temp;
	std::string p, v;
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
	temp.setEgz(temp.paz().vector::at(s));
	return fd;
}