#include<iostream>
using namespace std;
#include "string"

struct Hero   //英雄结构体
{
	string name;  //姓名
	int age;	 //年龄
	string sex;  //性别
};

//冒泡排序
void bubbleSort(struct Hero HeroArray[], int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (HeroArray[j].age > HeroArray[j + 1].age)
			{
				struct Hero temp = HeroArray[j];
				HeroArray[j] = HeroArray[j + 1];
				HeroArray[j + 1] = temp;

			}
		}
	}

}



//输出信息
void printHero(struct Hero HeroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "姓名："   << HeroArray[i].name
			 << "\t年龄：" << HeroArray[i].age
			 << "\t性别：" << HeroArray[i].sex << endl;
	}
}

int main()
{
	//1.创建英雄结构体

	struct Hero HeroArray[5] = 
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}

	};
	int len = sizeof(HeroArray) / sizeof(HeroArray[0]);
	cout << "排序前：" << endl;

	printHero(HeroArray, len);

	//2.利用冒泡法根据年龄从小到大排序
	bubbleSort(HeroArray, len);


	//3.输出信息
	cout << "排序后：" << endl;

	printHero(HeroArray, len);



	system("pause");
	return 0;
}