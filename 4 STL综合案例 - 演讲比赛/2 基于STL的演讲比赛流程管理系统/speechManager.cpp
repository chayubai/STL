#include "speechManager.h"

SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();

    //��ȡ�����¼
    this->loadRecord();
}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;//ע�������ʼ��Ϊ1��ÿ�ֵĵ÷���Ҫ�±� - 1

    //����¼��������գ���һ��ʹ��
    this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "ѡ��";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }

        //12��ѡ�ֱ�� ��ŵ�v1������
        this->v1.push_back(i + 10001);

        //ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    //��һ�ֱ���
    //1����ǩ
    this->speechDraw();
    //2������
    this->speechContest();
    //3����ʾ�������
    this->showScore();//����ʾһ���˵�����

    //�ڶ��ֱ���

    this->m_Index++;

    //1����ǩ
    this->speechDraw();
    //2������
    this->speechContest();
    //3����ʾ���ս��
    this->showScore();//����ʾһ���˵�����
    //4����������Զ������¼
    this->saveRecord();

    //����û���˳����򣬹��캯��ֻ�����һ�Σ������˳�������б���
    //����һ�������󣬻��м�������
    //���ñ��� ������һ�ֱ���
    //��ʼ������
    this->initSpeech();
    //����ѡ��
    this->createSpeaker();
    //��ȡ�����¼
    this->loadRecord();//��������ؽ������ڵ�ǰ����δ�˳�ʱ���Ͳ��ܻ�ȡ�����¼

    cout << "���������ϣ�"<<endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechDraw()
{
    cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
    cout << "---------------------" << endl;
    cout << "��ǩ���ݽ�˳�����£�" << endl;
    if (this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else if(this->m_Index == 2)
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::speechContest()
{
    cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;

    multimap<double, int, greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��

    int num = 0; //��¼��Ա����6��Ϊ1��

    vector <int> v_Src;   //��������Ա����
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else if(this->m_Index == 2)
    {
        v_Src = v2;
    }

    //�������в���ѡ��
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;

        //��ί���
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000 С��
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;

        sort(d.begin(), d.end(), greater<double>());				//����
        //greater<double>()���Բ��ӣ�Ĭ��С����
        d.pop_front();												//ȥ����߷�
        d.pop_back();												//ȥ����ͷ�

        double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
        double avg = sum / (double)d.size();//����/С�� = С��							//��ȡƽ����

        //ÿ����ƽ���֣�����map������
        //cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
        //����ÿһ�ֵķ���
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;//*it == <int>���

        //6����һ�飬����ʱ��������
        groupScore.insert(make_pair(avg, *it));
        if (num % 6 == 0)
        {
            cout << "��" << num / 6 << "С��������Σ�" << endl;
            //��ʾÿһ�ֵ���Ϣ
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "���: " << it->second << " ������ " << this->m_Speaker[it->second].m_Name << " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }

            int count = 0;
            //ȡǰ������������һ��������
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);
                }
                else if(this->m_Index == 2)
                {
                    vVictory.push_back((*it).second);
                }
            }

            groupScore.clear();

            cout << endl;
        }
    }
    cout << "------------- ��" << this->m_Index << "�ֱ������  ------------- " << endl;
    system("pause");
}

void SpeechManager::showScore()
{
    cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
    vector<int>v;
    if (this->m_Index == 1)
    {
        v = v2;//����Ҫ����v.size(v2.size())
    }
    else if(this->m_Index == 2)
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;

    system("pause");
    system("cls");
    this->show_Menu();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // ������� ��׷�ӷ�ʽ���ļ�  -- д�ļ�

    //�����Ǽ���ÿ��������д�뵽�ļ���
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        //�ڶ��ֵ���Ϣ�����ļ��У�m_Score[1��2�ֵĳɼ�
        ofs << *it << ","
            << m_Speaker[*it].m_Score[1] << ",";// ���ڶ������ճɼ�д���ļ��У�.csv�ļ������ü��±���ʱ��ÿ���������Զ��Ÿ���
    }
    ofs << endl;

    //�ر��ļ�
    ofs.close();

    cout << "��¼�Ѿ�����" << endl;

    //Ĭ���ļ�״̬Ϊ�ջ򲻴��ڣ����������Ҫ�����ļ�״̬��Ϊ��
    this->fileIsEmpty = false;//���û����һ�У����ᵼ���ļ��м�¼��������ʾ�ļ�Ϊ��
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

    //�ļ�������
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        //cout << "�ļ������ڣ�" << endl;
        ifs.close();
        return;
    }

    //�ļ�Ϊ��
    char ch;
    ifs >> ch;//��ȡ��һ���ַ����ж��Ƿ��ļ�Ϊ��
    if (ifs.eof())
    {
        //cout << "�ļ�Ϊ��!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //�ļ���Ϊ��
    this->fileIsEmpty = false;

    ifs.putback(ch); //�������ȡ�ĵ����ַ��Ż�ȥ

    string data;//���ļ��е����ݶ�ȡ��Ϊ�ַ���
    int index = 0;//�ڼ���
    while (ifs >> data)
    {
        //cout << data << endl;
        //10002��86.675��10009��81.3��10007��78.55��
        vector<string> v;//���6���ַ���������

        int pos = -1;//�鵽������λ�õı���
        int start = 0;

        while (true)
        {
            pos = data.find(",", start); //��0��ʼ���� ','
            if (pos == -1)
            {
                break; //�Ҳ���break����
            }
            string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
            v.push_back(tmp);//����ȡ�������ַ�������vector������
            start = pos + 1;
        }

        this->m_Record.insert(make_pair(index, v));//ע�⣺indexΪ0��ʼ����ӡʱ��Ҫ+1
        index++;
    }

    ifs.close();

   /*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
    {
        cout << "��" << it->first << "��" << " �ھ���ţ�" << it->second[0] << " ������" << it->second[1] << endl;
    }*/
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)//�鿴��¼ʱ���ж��ļ�״̬�����߼�һ��loadRecord����
    {
        cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i++)
        {//ע��i+1Ϊ���棬��i = 0����ʾ�Ķ����ַ���
            cout << "��" << i + 1 << "�� " <<
                "�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
                "�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
                "������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
        }
        //map<int, vector<string>> m_Record;
        //key = int value = vector<string>
        //m[key] = value  m_Record[i] == vector<string> 
        //vector��������������ʣ�v[0]....
    }
    
    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    //ע�⣺���ǰ���ж��ļ��Ƿ�Ϊ�պ��ļ��Ƿ����

    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //��ģʽ ios::trunc ������ڣ�ɾ���ļ������´���
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        //��ʼ������
        this->initSpeech();//��ֹ��ǰ������һЩ��������ֵ�����磺��¼�����������ݣ�����δ�˳�������˻�������ʾ��¼

        //����ѡ��
        this->createSpeaker();

        //��ȡ�����¼
        this->loadRecord();//���������ؽ����ļ����ټ���һ�飬���ٴβ��¼ʱ����ʲô��û����

        cout << "��ճɹ���" << endl;

        //��ռ�¼��fileIsEmptyҲ��Ϊtrue������Ҫ�ӣ���ΪloadRecord���ж�Ϊ�պ���Ϊtrue
        //this->fileIsEmpty = true;
    }

    system("pause");
    system("cls");
}