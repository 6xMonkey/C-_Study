#include<iostream>
#include "string"
using namespace std;
#define MAX 1000   //定义通讯录最大可以存1000

//显示功能面板
void showMenu()   
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
	cout << "请输入功能数字：";
}

//定义联系人结构体
struct Person  
{
	string name;         //姓名
	int sex;             //性别
	string phoneNumber;  //电话
	string address;      //住址
};

//定义通讯录结构体
struct addressbook
{
	Person adbook[MAX];   //定义通讯录
	int adbooksize;		  //通讯录现有人数
};

//1、添加联系人函数
void addPerson(struct addressbook * abs)
{
	cout << "请输入联系人信息" << endl;
	cout << "姓名：";
	cin >> abs->adbook[abs->adbooksize].name;

	cout << "性别：" << endl << "1--男" << endl << "2--女" << endl;;
	cin >> abs->adbook[abs->adbooksize].sex;

	cout << "电话：";
	cin >> abs->adbook[abs->adbooksize].phoneNumber;

	cout << "地址：";
	cin >> abs->adbook[abs->adbooksize].address;

	abs->adbooksize++;

	cout << "录入新的联系人成功！" << endl;

}



//2、显示联系人函数
void showadbook(struct addressbook * abs)
{
	if (abs->adbooksize == 0)
	{
		cout << "通讯录为空！！！    " << endl;
		cout << "请按照功能添加联系人" << endl;
	}
	else
	{ 
		for (int i = 0; i < abs->adbooksize; i++)
		{
		cout << "姓名：" << abs->adbook[i].name
			 << "   性别：" << (abs->adbook[i].sex==1?"男":"女")
			 << "   电话：" << abs->adbook[i].phoneNumber
			 << "   住址：" << abs->adbook[i].address << endl;
		}
	}

}

//3、删除联系人函数
void delPerson(struct addressbook * abs,string delname)
{
	int temp = 0;  //标记是否找到联系人
	for (int i = 0; i < abs->adbooksize; i++)
	{ 
		if (abs->adbook[i].name == delname)
		{
			temp = 1;  //要删除的联系人已经找到
			for (int j = i; j < abs->adbooksize - 1; j++)
			{
				abs->adbook[j] = abs->adbook[j + 1];
			}
			abs->adbooksize--;
		}
	}
	cout << (temp == 1 ? "联系人已经找到并删除!!!" :"联系人未找到!!!") << endl;

}



//4、查找联系人函数
void searchPerson(struct addressbook * abs, string searchname)
{
	int temp = 0;  //标记是否找到联系人
	for (int i = 0; i < abs->adbooksize; i++)
	{
		if (abs->adbook[i].name == searchname)
		{
			temp = 1;  //要删除的联系人已经找到
			cout << "姓名：" << abs->adbook[i].name
				<< "   性别：" << (abs->adbook[i].sex == 1 ? "男" : "女")
				<< "   电话：" << abs->adbook[i].phoneNumber
				<< "   住址：" << abs->adbook[i].address << endl;
		}
	}
	cout << (temp == 1 ? "联系人信息输出完毕！！！" : "联系人未找到!!!") << endl;

}

//5、修改联系人
void modPerson(struct addressbook * abs, string modname)
{
	{
		int temp = 0;  //标记是否找到联系人
		for (int i = 0; i < abs->adbooksize; i++)
		{
			if (abs->adbook[i].name == modname)
			{
				temp = 1;  //要修改的联系人已经找到
				cout << modname << "的已经找到,请输入新的信息！！！" << endl;
				cout << "姓名：";
				cin >> abs->adbook[i].name;

				cout << "性别：" << endl << "1--男" << endl << "2--女" << endl;
				cin >> abs->adbook[i].sex;

				cout << "电话：";
				cin >> abs->adbook[i].phoneNumber;

				cout << "住址：";
				cin >> abs->adbook[i].address;

				cout << "信息修改完毕！如下：" << endl;

				cout << "姓名：" << abs->adbook[i].name
					 << "   性别：" << (abs->adbook[i].sex == 1 ? "男" : "女")
					 << "   电话：" << abs->adbook[i].phoneNumber
					 << "   住址：" << abs->adbook[i].address ;
			}
		}
		cout << (temp == 1 ? "": "联系人未找到!!!") << endl;

	}


}



//通讯录管理系统，主函数
int main()
{
	int select = 0;  //记录输入的选项
	//初始化通讯录
	addressbook abs;
	abs.adbooksize = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		
		switch(select)
		{
		//添加联系人
		case 1:
			addPerson(&abs);
			break;
		//显示通讯录所有人员
		case 2:
			showadbook(&abs);
			break;
		//删除联系人
		case 3:
		{	string delname;
			cout << "请输入需要删除的联系人姓名：";
			cin >> delname;
			delPerson(&abs, delname);
			break;
		}
		//4、查找联系人
		case 4:
		{	string searchname;
			cout << "请输入需要查找的联系人姓名：";
			cin >> searchname;
			searchPerson(&abs, searchname);
			break;
		}
		case 5:
		{	string modname;
			cout << "请输入联系人姓名：";
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
			cout << "输入错误，请重新输入：" << endl;
			break;
		}

		system("pause");
		system("cls");  //刷新界面

	}
	system("pause");
	return 0;
}
