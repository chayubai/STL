#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <string>
#include <fstream>
//����ݽ�������
	//- �ṩ�˵��������û�����
	//- ���ݽ��������̽��п���
	//- ���ļ��Ķ�д����

class SpeechManager
{
public:
	SpeechManager();

	void show_Menu();//�ṩ�˵��������û�����

	//�˳�ϵͳ
	void exitSystem();
	
	~SpeechManager();

	//��ŵ�һ�ֱ���ѡ�ֵı�� ����  12��
	vector<int> v1;

	//��ŵ�һ�ֽ���ѡ�ֱ�� ����  6��
	vector<int> v2;

	//���ʤ��ǰ����ѡ�ֱ�� ����  3��
	vector<int> vVictory;

	//ע�⣺������һ���������������С������ͨ������������С����

	//��ű�� �Լ���Ӧ�� ����ѡ�� ���� key�����ظ�
	map<int, Speaker> m_Speaker;

	//��¼��������
	int m_Index;

	//��ʼ������������
	void initSpeech();

	//����ѡ�֣�����ѡ�ַ������Ϊ0
	void createSpeaker();

	void startSpeech();//���ݽ������������̽��п���

	//��ǩ
	void speechDraw();
	
	//����
	void speechContest();

	//��ʾ�������
	void showScore();

	//���ļ��Ķ�д����
	//�����¼
	void saveRecord();

	//���ؼ�¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool fileIsEmpty = true;

	//�����¼������
	map<int, vector<string>> m_Record;//key �ڼ��� value �ַ�����¼��Ϣ

	//��ʾ�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();
};