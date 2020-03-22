#include <iostream>
#include "Natural_Sciences.h"
#include "student.h"

using namespace std;

Natural_Sciences::Natural_Sciences()
{
	Affiliation = NATURAL;
}

void Natural_Sciences::Natural_Sciences_input()
{
	student::input(NATURAL);
	cout << "수학II 성적을 입력하세요" << endl;
	cin >> math2;
	history = NULL;
}

void Natural_Sciences::output_Affiliation()
{
	total = kor + eng + math + math2;
	avr = total / 4;

	cout << "\t" << total << "\t" << avr << endl;
}

void Natural_Sciences::save(FILE * file)
{
	fprintf(file, "%d\n", Affiliation);
	student::save(file);
	fprintf(file, "%d  ", math2);
	fprintf(file, "%d  ", history);
	fprintf(file, "\n");
}

void Natural_Sciences::load(FILE *file)
{
	student::load(file);
	fscanf(file, "%d  ", &math2);
	fscanf(file, "%d  ", &history);
}

Natural_Sciences::~Natural_Sciences()
{
}
