#include "student.h"
#include <iostream>

using namespace std;

void student::input(int type)
{
		cout << "�̸��� �Է��ϼ���" << endl;
		cin >> name;
		cout << "���� ������ �Է��ϼ���" << endl;
		cin >> kor;
		cout << "���� ������ �Է��ϼ���" << endl;
		cin >> eng;
		cout << "���� ������ �Է��ϼ���" << endl;
		cin >> math; 
}

void student::output()
{
	cout << name << "\t" << kor << "\t" << eng << "\t" << math << "\t" << math2 << "\t" << history;
}

void student::save(FILE *file)
{
		fprintf(file, "%s  %d  %d  %d  ",
			name.c_str(), kor, eng, math);
}

void student::load(FILE *file)
{
		char c_name[256];
		fscanf(file, "%s  %d  %d  %d  ",
			c_name, &kor, &eng, &math);
		name = c_name;
}

student::student()
{
}

student::~student()
{
}
