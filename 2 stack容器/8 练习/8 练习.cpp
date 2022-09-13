#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

//multimap 案例
//公司今天招聘了 5 个员工（ABCDE），5 名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过 Multimap 进行信息的插入 保存 显示，使用Multimap的key可以相同，即部门可以相同
//分部门显示员工信息 显示全部员工信息

//实现步骤
//1. 创建5名员工，放到vector中
//2. 遍历vector容器，取出每个员工，进行随机分组
//3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
//4. 分部门显示员工信息

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门
#define ALL_DEPATMENT 4 //所有部门

//员工类
class person {
public:
	string name; //员工姓名
	int age; //员工年龄
	double salary; //员工工资
	string tele; //员工电话
};

//创建5个员工
void CreatePerson(vector<person>& vlist) {

	string seed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		person p;
		p.name = "员工";
		p.name += seed[i];
		p.age = rand() % 30 + 20;
		p.salary = rand() % 10000 + 10000;//rand() % 10000 == [0-9999] 10000  - 19999
		p.tele = "010-8888888";
		//将员工放入容器中
		vlist.push_back(p);
	}
}

//5名员工分配到不同的部门
void PersonByGroup(vector<person>& vlist, multimap<int, person>& plist) {

	int operate = -1; //用户的操作

	for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++) {

		cout << "当前员工信息:" << endl;
		cout << "姓名：" << it->name << " 年龄:" << it->age << " 工资:" << it->salary << " 电话：" << it->tele << endl;
		cout << "请对该员工进行部门分配(1 销售部门, 2 研发部门, 3 财务部门):" << endl;
		scanf("%d", &operate);

		while (true) {

			if (operate == SALE_DEPATMENT) {  //将该员工加入到销售部门
				plist.insert(make_pair(SALE_DEPATMENT, *it));
				break;
			}
			else if (operate == DEVELOP_DEPATMENT) {
				plist.insert(make_pair(DEVELOP_DEPATMENT, *it));
				break;
			}
			else if (operate == FINACIAL_DEPATMENT) {
				plist.insert(make_pair(FINACIAL_DEPATMENT, *it));
				break;
			}
			else {
				cout << "您的输入有误，请重新输入(1 销售部门, 2 研发部门, 3 财务部门):" << endl;
				scanf("%d", &operate);
			}
		}
	}
	cout << "员工部门分配完毕!" << endl;
	cout << "***********************************************************" << endl;

}
enum{CAIWU,RENLI,YANFA};
void setGroup(vector<person>& vlist, multimap<int, person>& plist) {

	for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++) {

		//随机产生部门编号 0 1 2 
		int dId = rand() % 3;
		//将员工分到multimap容器中
		//key部门 value具体员工
		plist.insert(make_pair(dId, *it));
	}
}
void show(multimap<int,person> &plist)
{
	cout << "财务部门员工信息如下：" << endl;
	//0 A 0 B  1 C  2 D 2 E
	multimap<int, person>::iterator pos = plist.find(CAIWU);//find，根据key查找，如果找到，返回该元素的迭代器
	int num = plist.count(CAIWU);//统计该部门人员个数
	int index = 0;
	for (; pos != plist.end(), index < num; pos++, index++)
	{
		cout << "姓名：" << pos->second.name << " 年龄:" << pos->second.age << " 工资:" << pos->second.salary << " 电话：" << pos->second.tele << endl;
	}

	cout << "人力部门员工信息如下：" << endl;
	//0 A 0 B  1 C  2 D 2 E
	pos = plist.find(RENLI);
	num = plist.count(RENLI);//统计该部门人员个数
	index = 0;
	for (; pos != plist.end(), index < num; pos++, index++)
	{
		cout << "姓名：" << pos->second.name << " 年龄:" << pos->second.age << " 工资:" << pos->second.salary << " 电话：" << pos->second.tele << endl;
	}

	cout << "研发部门员工信息如下：" << endl;
	//0 A 0 B  1 C  2 D 2 E
	pos = plist.find(YANFA);
	num = plist.count(YANFA);//统计该部门人员个数
	index = 0;
	for (; pos != plist.end(), index < num; pos++, index++)
	{
		cout << "姓名：" << pos->second.name << " 年龄:" << pos->second.age << " 工资:" << pos->second.salary << " 电话：" << pos->second.tele << endl;
	}
}

//打印员工信息
void printList(multimap<int, person>& plist, int myoperate) {

	if (myoperate == ALL_DEPATMENT) {
		for (multimap<int, person>::iterator it = plist.begin(); it != plist.end(); it++) {
			cout << "姓名：" << it->second.name << " 年龄:" << it->second.age << " 工资:" << it->second.salary << " 电话：" << it->second.tele << endl;
		}
		return;
	}

	multimap<int, person>::iterator it = plist.find(myoperate);
	int depatCount = plist.count(myoperate);
	int num = 0;
	if (it != plist.end()) {
		while (it != plist.end() && num < depatCount) {
			cout << "姓名：" << it->second.name << " 年龄:" << it->second.age << " 工资:" << it->second.salary << " 电话：" << it->second.tele << endl;
			it++;
			num++;
		}
	}
}

//根据用户操作显示不同部门的人员列表
void ShowPersonList(multimap<int, person>& plist, int myoperate) {

	switch (myoperate)
	{
	case SALE_DEPATMENT:
		printList(plist, SALE_DEPATMENT);
		break;
	case DEVELOP_DEPATMENT:
		printList(plist, DEVELOP_DEPATMENT);
		break;
	case FINACIAL_DEPATMENT:
		printList(plist, FINACIAL_DEPATMENT);
		break;
	case ALL_DEPATMENT:
		printList(plist, ALL_DEPATMENT);
		break;
	}
}

//用户操作菜单
void PersonMenue(multimap<int, person>& plist) {

	int flag = -1;
	int isexit = 0;
	while (true) {
		cout << "请输入您的操作((1 销售部门, 2 研发部门, 3 财务部门, 4 所有部门, 0退出)：" << endl;
		scanf("%d", &flag);

		switch (flag)
		{
		case SALE_DEPATMENT:
			ShowPersonList(plist, SALE_DEPATMENT);
			break;
		case DEVELOP_DEPATMENT:
			ShowPersonList(plist, DEVELOP_DEPATMENT);
			break;
		case FINACIAL_DEPATMENT:
			ShowPersonList(plist, FINACIAL_DEPATMENT);
			break;
		case ALL_DEPATMENT:
			ShowPersonList(plist, ALL_DEPATMENT);
			break;
		case 0:
			isexit = 1;
			break;
		default:
			cout << "您的输入有误，请重新输入!" << endl;
			break;
		}

		if (isexit == 1) {
			break;
		}
	}

}

int main() {

	srand((unsigned int)time(NULL));//也可以包含time.h和stdlib.h

	vector<person>  vlist; //创建的5个员工 未分组，也可以用list容器

	//1、创建5个员工
	CreatePerson(vlist);

	//测试：
	/*for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++)
	{
		cout << "姓名：" << it->name << " 年龄：" << it->age 
			<< " 工资：" <<it->salary << "电话："<< it->tele << endl;
	}*/

	multimap<int, person> plist; //保存分组后员工信息，头文件都是#include <map>

	//2、5名员工分配到不同的部门
	//PersonByGroup(vlist, plist);
	setGroup(vlist, plist);

	//3、根据用户输入显示不同部门员工信息列表 或者 显示全部员工的信息列表
	//PersonMenue(plist);
	show(plist);

	return 0;
}
