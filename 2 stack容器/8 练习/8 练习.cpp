#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

//multimap ����
//��˾������Ƹ�� 5 ��Ա����ABCDE����5 ��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ�� Multimap ������Ϣ�Ĳ��� ���� ��ʾ��ʹ��Multimap��key������ͬ�������ſ�����ͬ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ

//ʵ�ֲ���
//1. ����5��Ա�����ŵ�vector��
//2. ����vector������ȡ��ÿ��Ա���������������
//3. ����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
//4. �ֲ�����ʾԱ����Ϣ

#define SALE_DEPATMENT 1 //���۲���
#define DEVELOP_DEPATMENT 2 //�з�����
#define FINACIAL_DEPATMENT 3 //������
#define ALL_DEPATMENT 4 //���в���

//Ա����
class person {
public:
	string name; //Ա������
	int age; //Ա������
	double salary; //Ա������
	string tele; //Ա���绰
};

//����5��Ա��
void CreatePerson(vector<person>& vlist) {

	string seed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		person p;
		p.name = "Ա��";
		p.name += seed[i];
		p.age = rand() % 30 + 20;
		p.salary = rand() % 10000 + 10000;//rand() % 10000 == [0-9999] 10000  - 19999
		p.tele = "010-8888888";
		//��Ա������������
		vlist.push_back(p);
	}
}

//5��Ա�����䵽��ͬ�Ĳ���
void PersonByGroup(vector<person>& vlist, multimap<int, person>& plist) {

	int operate = -1; //�û��Ĳ���

	for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++) {

		cout << "��ǰԱ����Ϣ:" << endl;
		cout << "������" << it->name << " ����:" << it->age << " ����:" << it->salary << " �绰��" << it->tele << endl;
		cout << "��Ը�Ա�����в��ŷ���(1 ���۲���, 2 �з�����, 3 ������):" << endl;
		scanf("%d", &operate);

		while (true) {

			if (operate == SALE_DEPATMENT) {  //����Ա�����뵽���۲���
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
				cout << "����������������������(1 ���۲���, 2 �з�����, 3 ������):" << endl;
				scanf("%d", &operate);
			}
		}
	}
	cout << "Ա�����ŷ������!" << endl;
	cout << "***********************************************************" << endl;

}
enum{CAIWU,RENLI,YANFA};
void setGroup(vector<person>& vlist, multimap<int, person>& plist) {

	for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++) {

		//����������ű�� 0 1 2 
		int dId = rand() % 3;
		//��Ա���ֵ�multimap������
		//key���� value����Ա��
		plist.insert(make_pair(dId, *it));
	}
}
void show(multimap<int,person> &plist)
{
	cout << "������Ա����Ϣ���£�" << endl;
	//0 A 0 B  1 C  2 D 2 E
	multimap<int, person>::iterator pos = plist.find(CAIWU);//find������key���ң�����ҵ������ظ�Ԫ�صĵ�����
	int num = plist.count(CAIWU);//ͳ�Ƹò�����Ա����
	int index = 0;
	for (; pos != plist.end(), index < num; pos++, index++)
	{
		cout << "������" << pos->second.name << " ����:" << pos->second.age << " ����:" << pos->second.salary << " �绰��" << pos->second.tele << endl;
	}

	cout << "��������Ա����Ϣ���£�" << endl;
	//0 A 0 B  1 C  2 D 2 E
	pos = plist.find(RENLI);
	num = plist.count(RENLI);//ͳ�Ƹò�����Ա����
	index = 0;
	for (; pos != plist.end(), index < num; pos++, index++)
	{
		cout << "������" << pos->second.name << " ����:" << pos->second.age << " ����:" << pos->second.salary << " �绰��" << pos->second.tele << endl;
	}

	cout << "�з�����Ա����Ϣ���£�" << endl;
	//0 A 0 B  1 C  2 D 2 E
	pos = plist.find(YANFA);
	num = plist.count(YANFA);//ͳ�Ƹò�����Ա����
	index = 0;
	for (; pos != plist.end(), index < num; pos++, index++)
	{
		cout << "������" << pos->second.name << " ����:" << pos->second.age << " ����:" << pos->second.salary << " �绰��" << pos->second.tele << endl;
	}
}

//��ӡԱ����Ϣ
void printList(multimap<int, person>& plist, int myoperate) {

	if (myoperate == ALL_DEPATMENT) {
		for (multimap<int, person>::iterator it = plist.begin(); it != plist.end(); it++) {
			cout << "������" << it->second.name << " ����:" << it->second.age << " ����:" << it->second.salary << " �绰��" << it->second.tele << endl;
		}
		return;
	}

	multimap<int, person>::iterator it = plist.find(myoperate);
	int depatCount = plist.count(myoperate);
	int num = 0;
	if (it != plist.end()) {
		while (it != plist.end() && num < depatCount) {
			cout << "������" << it->second.name << " ����:" << it->second.age << " ����:" << it->second.salary << " �绰��" << it->second.tele << endl;
			it++;
			num++;
		}
	}
}

//�����û�������ʾ��ͬ���ŵ���Ա�б�
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

//�û������˵�
void PersonMenue(multimap<int, person>& plist) {

	int flag = -1;
	int isexit = 0;
	while (true) {
		cout << "���������Ĳ���((1 ���۲���, 2 �з�����, 3 ������, 4 ���в���, 0�˳�)��" << endl;
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
			cout << "����������������������!" << endl;
			break;
		}

		if (isexit == 1) {
			break;
		}
	}

}

int main() {

	srand((unsigned int)time(NULL));//Ҳ���԰���time.h��stdlib.h

	vector<person>  vlist; //������5��Ա�� δ���飬Ҳ������list����

	//1������5��Ա��
	CreatePerson(vlist);

	//���ԣ�
	/*for (vector<person>::iterator it = vlist.begin(); it != vlist.end(); it++)
	{
		cout << "������" << it->name << " ���䣺" << it->age 
			<< " ���ʣ�" <<it->salary << "�绰��"<< it->tele << endl;
	}*/

	multimap<int, person> plist; //��������Ա����Ϣ��ͷ�ļ�����#include <map>

	//2��5��Ա�����䵽��ͬ�Ĳ���
	//PersonByGroup(vlist, plist);
	setGroup(vlist, plist);

	//3�������û�������ʾ��ͬ����Ա����Ϣ�б� ���� ��ʾȫ��Ա������Ϣ�б�
	//PersonMenue(plist);
	show(plist);

	return 0;
}
