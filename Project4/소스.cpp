#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	int sum;
	double average;
	int grade;
public:
	Student(string name,int middle, int final,int grade) : name(name)
	{
		this->sum = middle+ final;
		this->average = (double)sum / 2;
		this->grade = grade;
	}
	int get_sum()
	{
		return sum;
	}
	int get_grade() { return grade; }
	void set_grade(int grade)
	{
		this->grade = grade;
	}
	void ShowData()
	{
		cout << name << "   " << sum << "   " << average << "    "<<grade<<"    ";
		for (int i = 0; i < (sum / 10); i++)
			cout << "*";
		cout << endl;
	}

};

class Print
{
private:
	int idx;
	Student* stud[10];
public:
	Print()
	{
		string name;
		int middle, final;
		idx = 0;
		for (int i = 0; i < 10; i++)
		{
			cout << "�̸�: "; cin >> name;
			cout << "�߰����: "; cin >> middle;
			cout << "�⸻���: "; cin >> final;
			if (name=="end")
				break;
			stud[i] = new Student(name, middle, final,i+1);
			idx++;
		}
	}
	void ShowAllData()
	{
		cout << "                    �߰���� ���� �� ����"<<endl;
		cout << "  ��ȣ    �̸�    �հ�   ���   ����       ���� �׷���"<<endl;
		cout << "-------------------------------------------------------" << endl;
		sort();
		for (int i = 0; i < idx; i++)
		{
			cout << "  " << i + 1 << "    ";
			stud[i]->ShowData();
		}
		cout << "-------------------------------------------------------" << endl;
		cout << "           �� �ο���: " << idx << endl;

	}
	void sort()
	{
		int copy;
		for (int i = 0; i < idx; i++)
		{
			for (int j = 0; j < idx; j++)
			{
				if (stud[i]->get_sum() > stud[j]->get_sum() && stud[i]->get_grade() > stud[j]->get_grade())
				{
					copy = stud[i]->get_grade();
					stud[i]->set_grade(stud[j]->get_grade());
					stud[j]->set_grade(copy);
				}

			}
		}
	}
};

int main()
{
	Print pt;
	pt.ShowAllData();
	return 0;
}