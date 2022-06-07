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
	string tName; //老师的名字
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

//打印老师结构体所有信息
void printTeachers(struct Teacher teacherArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师的名字： " << teacherArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << teacherArray[i].studentArray[j].sName << "成绩："
				<< teacherArray[i].studentArray[j].score << endl;
		}

	}


}



int main()
{

	srand((unsigned int)time(NULL));
	//1.创建老师和学生结构体
	struct Teacher teacherArray[3];

	//2.给老师和学生的结构体赋值
	int len = sizeof(teacherArray) / sizeof(teacherArray[0]);  //老师的个数

	allocateSpace(teacherArray, len);

	//3.打印老师和学生的元素

	printTeachers(teacherArray, len);

	system("pause");

	return 0;

}