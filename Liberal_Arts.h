#pragma once
#include "student.h"

class Liberal_Arts : public student
{
public:
	void Liberal_Arts_input();

	virtual void output_Affiliation();
	virtual void save(FILE *file);
	virtual void load(FILE *file);

	Liberal_Arts();
	~Liberal_Arts();
};