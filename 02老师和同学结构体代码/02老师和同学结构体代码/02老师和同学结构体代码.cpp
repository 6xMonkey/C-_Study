#include <iostream>
using namespace std;
#include "string"
#include "ctime"


struct Student
{
	string sName;
	int score;
};

struct Teacher
{
	string tName; //��ʦ������
	struct Student studentArray[5];
};


void allocateSpace(struct Teacher teacher[], int len)
{
	for (int i = 0; i < len; i++)
	{
		string namepace = "ABCDEFG";
		teacher[i].tName = "Teacher_";
		teacher[i].tName += namepace[i];
		/*cout << teacher[i].tName << endl;*/
		for (int j = 0; j < 5; j++)
		{
			int temp = rand() % 41 + 60;  //60-100
			teacher[i].studentArray[j].sName = "student_";
			teacher[i].studentArray[j].sName += namepace[j];
			teacher[i].studentArray[j].score = temp;
		}

	}

}

//��ӡ��ʦ�ṹ��������Ϣ
void printTeachers(struct Teacher teacherArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ�����֣� " << teacherArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t������" << teacherArray[i].studentArray[j].sName << "�ɼ���"
				<< teacherArray[i].studentArray[j].score << endl;
		}

	}


}



int main()
{

	srand((unsigned int)time(NULL));
	//1.������ʦ��ѧ���ṹ��
	struct Teacher teacherArray[3];

	//2.����ʦ��ѧ���Ľṹ�帳ֵ
	int len = sizeof(teacherArray) / sizeof(teacherArray[0]);  //��ʦ�ĸ���

	allocateSpace(teacherArray, len);

	//3.��ӡ��ʦ��ѧ����Ԫ��

	printTeachers(teacherArray, len);

	system("pause");

	return 0;

}