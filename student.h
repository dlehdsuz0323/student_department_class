#pragma once
#include <string>

using namespace std;

enum STUDENT_Affiliation
{
	NATURAL = 1,
	LIBERAL,
	TOTAL
};

class student
{
protected:
	STUDENT_Affiliation Affiliation;

	string name;
	int kor;
	int eng;
	int math;
	int math2;
	int history;
	int total;
	int avr;

public:
	void input(int Affiliation);
	void output();
	virtual void output_Affiliation() = 0;

	virtual void load(FILE *file);
	virtual void save(FILE *file);

	student();
	~student();
};

/*
	-
*/