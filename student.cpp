#include "student.h"
#include <iostream>

using namespace std;

void student::input(int type)
{
		cout << "이름을 입력하세요" << endl;
		cin >> name;
		cout << "국어 성적을 입력하세요" << endl;
		cin >> kor;
		cout << "영어 성적을 입력하세요" << endl;
		cin >> eng;
		cout << "수학 성적을 입력하세요" << endl;
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
