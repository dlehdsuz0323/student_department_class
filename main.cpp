#include <iostream>
#include <vector>
#include "student.h"
#include "Natural_Sciences.h"
#include "Liberal_Arts.h"

using namespace std;

void printMenu();

int main(void)
{
	vector<student*> STUDENT;

	int Liberal_stu_cur = 0;
	int Natural_stu_cur = 0;
	int cur = 0;
	int Fisrt_select = NULL;
		
	while (true)
	{
		printMenu();

		int inputNumber;
		cin >> inputNumber;

		switch (inputNumber)
		{
		case 1: //input
		{
			cout << "1. 이과 \t 2.문과" << endl;
			int number = 0;
			cin >> number;

			if (Fisrt_select == NULL)
			{
				Fisrt_select = number;
			}

			if (number == NATURAL)
			{
				Natural_Sciences* pNew = new Natural_Sciences();
				pNew->Natural_Sciences_input();
				STUDENT.push_back(pNew);
				
				Natural_stu_cur++;
			}

			else if (number == LIBERAL)
			{
				Liberal_Arts* pNew = new Liberal_Arts();
				pNew->Liberal_Arts_input();
				STUDENT.push_back(pNew);

				Liberal_stu_cur++;
			}
		}
		break;


		case 2: //output
		{
			cout << "name" << "\t" << "kor" << "\t" << "eng" << "\t" << "math" << "\t" << "mathII" << "\t" << "history"
				<< "\t" << "total" << "\t" << "avr " << endl;
			for (auto iter = STUDENT.begin(); iter != STUDENT.end(); iter++)
			{
				(*iter)->output();
				(*iter)->output_Affiliation();
			}
			cout << endl;
		}
				break;


		case 3: //save
		{
			FILE* file = fopen("student_department.txt", "w+");

			cur = Natural_stu_cur + Liberal_stu_cur;
			fprintf(file, "%d\n", cur);

			for (auto iter = STUDENT.begin(); iter != STUDENT.end(); iter++)
			{
				(*iter)->save(file);
			}
		}
			break;


		case 4: //load
		{
			FILE* file;
			file = fopen("student_department.txt", "r");

			if (file != NULL)
			{
				fscanf(file, "%d\n", &cur);

				for (int i = 0; i < cur; i++)
				{
					int Affiliation = 0;
					fscanf(file, "%d\n", &Affiliation);
					if (Affiliation == NATURAL)
					{
						Natural_Sciences* pNew = new Natural_Sciences();
						pNew->load(file);
						STUDENT.push_back(pNew);
					}
					else if (Affiliation == LIBERAL)
					{
						Liberal_Arts* pNew = new Liberal_Arts();
						pNew->load(file);
						STUDENT.push_back(pNew);
					}
				}
			}
			fclose(file);
		}
			break;


		case 5:
		{
			exit(0);
		}
			break;


		}
	}

	for (auto iter = STUDENT.begin(); iter != STUDENT.end(); iter++)
	{
		delete (*iter);
	}

	return 0;
}

void printMenu()
{
	cout << "1. Input" << endl;
	cout << "2. Output" << endl;
	cout << "3. Save" << endl;
	cout << "4. Load" << endl;
	cout << "5. Exit" << endl;
}