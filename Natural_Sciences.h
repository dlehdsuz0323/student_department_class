#pragma once
#include "student.h"

class Natural_Sciences : public student
{
public:
	void Natural_Sciences_input();

	virtual void output_Affiliation();
	virtual void save(FILE *file);
	virtual void load(FILE *file);

	Natural_Sciences();
	~Natural_Sciences();
};

