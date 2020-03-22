#include <iostream>
#include "Liberal_Arts.h"
#include "student.h"

using namespace std;

Liberal_Arts::Liberal_Arts()
{
	Affiliation = LIBERAL;
}

void Liberal_Arts::Liberal_Arts_input()
{
	student::input(LIBERAL);
	cout << "역사 성적을 입력하세요" << endl;
	cin >> history;
	math2 = NULL;
}

void Liberal_Arts::output_Affiliation()
{
	total = kor + eng + math + history;
	avr = total / 4;

	cout << "\t" << total << "\t" << avr << endl;
}

void Liberal_Arts::save(FILE *file)
{
	fprintf(file, "%d\n", Affiliation);
	student::save(file);
	fprintf(file, "%d  ", math2);
	fprintf(file, "%d  ", history);
	fprintf(file, "\n");
}

void Liberal_Arts::load(FILE *file)
{
	student::load(file);
	fscanf(file, "%d  ", &math2);
	fscanf(file, "%d  ", &history);
}

Liberal_Arts::~Liberal_Arts()
{
}
