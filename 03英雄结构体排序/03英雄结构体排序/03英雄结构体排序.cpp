#include<iostream>
using namespace std;
#include "string"

struct Hero   //Ӣ�۽ṹ��
{
	string name;  //����
	int age;	 //����
	string sex;  //�Ա�
};

//ð������
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



//�����Ϣ
void printHero(struct Hero HeroArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "������"   << HeroArray[i].name
			 << "\t���䣺" << HeroArray[i].age
			 << "\t�Ա�" << HeroArray[i].sex << endl;
	}
}

int main()
{
	//1.����Ӣ�۽ṹ��

	struct Hero HeroArray[5] = 
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"}

	};
	int len = sizeof(HeroArray) / sizeof(HeroArray[0]);
	cout << "����ǰ��" << endl;

	printHero(HeroArray, len);

	//2.����ð�ݷ����������С��������
	bubbleSort(HeroArray, len);


	//3.�����Ϣ
	cout << "�����" << endl;

	printHero(HeroArray, len);



	system("pause");
	return 0;
}