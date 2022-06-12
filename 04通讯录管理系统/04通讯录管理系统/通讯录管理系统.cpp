#include<iostream>
#include "string"
using namespace std;
#define MAX 1000   //����ͨѶ¼�����Դ�1000

//��ʾ�������
void showMenu()   
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
	cout << "�����빦�����֣�";
}

//������ϵ�˽ṹ��
struct Person  
{
	string name;         //����
	int sex;             //�Ա�
	string phoneNumber;  //�绰
	string address;      //סַ
};

//����ͨѶ¼�ṹ��
struct addressbook
{
	Person adbook[MAX];   //����ͨѶ¼
	int adbooksize;		  //ͨѶ¼��������
};

//1�������ϵ�˺���
void addPerson(struct addressbook * abs)
{
	cout << "��������ϵ����Ϣ" << endl;
	cout << "������";
	cin >> abs->adbook[abs->adbooksize].name;

	cout << "�Ա�" << endl << "1--��" << endl << "2--Ů" << endl;;
	cin >> abs->adbook[abs->adbooksize].sex;

	cout << "�绰��";
	cin >> abs->adbook[abs->adbooksize].phoneNumber;

	cout << "��ַ��";
	cin >> abs->adbook[abs->adbooksize].address;

	abs->adbooksize++;

	cout << "¼���µ���ϵ�˳ɹ���" << endl;

}



//2����ʾ��ϵ�˺���
void showadbook(struct addressbook * abs)
{
	if (abs->adbooksize == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�����    " << endl;
		cout << "�밴�չ��������ϵ��" << endl;
	}
	else
	{ 
		for (int i = 0; i < abs->adbooksize; i++)
		{
		cout << "������" << abs->adbook[i].name
			 << "   �Ա�" << (abs->adbook[i].sex==1?"��":"Ů")
			 << "   �绰��" << abs->adbook[i].phoneNumber
			 << "   סַ��" << abs->adbook[i].address << endl;
		}
	}

}

//3��ɾ����ϵ�˺���
void delPerson(struct addressbook * abs,string delname)
{
	int temp = 0;  //����Ƿ��ҵ���ϵ��
	for (int i = 0; i < abs->adbooksize; i++)
	{ 
		if (abs->adbook[i].name == delname)
		{
			temp = 1;  //Ҫɾ������ϵ���Ѿ��ҵ�
			for (int j = i; j < abs->adbooksize - 1; j++)
			{
				abs->adbook[j] = abs->adbook[j + 1];
			}
			abs->adbooksize--;
		}
	}
	cout << (temp == 1 ? "��ϵ���Ѿ��ҵ���ɾ��!!!" :"��ϵ��δ�ҵ�!!!") << endl;

}



//4��������ϵ�˺���
void searchPerson(struct addressbook * abs, string searchname)
{
	int temp = 0;  //����Ƿ��ҵ���ϵ��
	for (int i = 0; i < abs->adbooksize; i++)
	{
		if (abs->adbook[i].name == searchname)
		{
			temp = 1;  //Ҫɾ������ϵ���Ѿ��ҵ�
			cout << "������" << abs->adbook[i].name
				<< "   �Ա�" << (abs->adbook[i].sex == 1 ? "��" : "Ů")
				<< "   �绰��" << abs->adbook[i].phoneNumber
				<< "   סַ��" << abs->adbook[i].address << endl;
		}
	}
	cout << (temp == 1 ? "��ϵ����Ϣ�����ϣ�����" : "��ϵ��δ�ҵ�!!!") << endl;

}

//5���޸���ϵ��
void modPerson(struct addressbook * abs, string modname)
{
	{
		int temp = 0;  //����Ƿ��ҵ���ϵ��
		for (int i = 0; i < abs->adbooksize; i++)
		{
			if (abs->adbook[i].name == modname)
			{
				temp = 1;  //Ҫ�޸ĵ���ϵ���Ѿ��ҵ�
				cout << modname << "���Ѿ��ҵ�,�������µ���Ϣ������" << endl;
				cout << "������";
				cin >> abs->adbook[i].name;

				cout << "�Ա�" << endl << "1--��" << endl << "2--Ů" << endl;
				cin >> abs->adbook[i].sex;

				cout << "�绰��";
				cin >> abs->adbook[i].phoneNumber;

				cout << "סַ��";
				cin >> abs->adbook[i].address;

				cout << "��Ϣ�޸���ϣ����£�" << endl;

				cout << "������" << abs->adbook[i].name
					 << "   �Ա�" << (abs->adbook[i].sex == 1 ? "��" : "Ů")
					 << "   �绰��" << abs->adbook[i].phoneNumber
					 << "   סַ��" << abs->adbook[i].address ;
			}
		}
		cout << (temp == 1 ? "": "��ϵ��δ�ҵ�!!!") << endl;

	}


}



//ͨѶ¼����ϵͳ��������
int main()
{
	int select = 0;  //��¼�����ѡ��
	//��ʼ��ͨѶ¼
	addressbook abs;
	abs.adbooksize = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		
		switch(select)
		{
		//�����ϵ��
		case 1:
			addPerson(&abs);
			break;
		//��ʾͨѶ¼������Ա
		case 2:
			showadbook(&abs);
			break;
		//ɾ����ϵ��
		case 3:
		{	string delname;
			cout << "��������Ҫɾ������ϵ��������";
			cin >> delname;
			delPerson(&abs, delname);
			break;
		}
		//4��������ϵ��
		case 4:
		{	string searchname;
			cout << "��������Ҫ���ҵ���ϵ��������";
			cin >> searchname;
			searchPerson(&abs, searchname);
			break;
		}
		case 5:
		{	string modname;
			cout << "��������ϵ��������";
			cin >> modname;
			modPerson(&abs, modname);
			break;
		}
		case 6:
			abs.adbooksize = 0;
			break;
		case 0:
			system("pause");
			return 0;
			break;
		default:
			cout << "����������������룺" << endl;
			break;
		}

		system("pause");
		system("cls");  //ˢ�½���

	}
	system("pause");
	return 0;
}
