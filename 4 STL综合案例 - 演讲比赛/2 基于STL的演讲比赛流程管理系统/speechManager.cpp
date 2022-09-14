#include "speechManager.h"

SpeechManager::SpeechManager()
{
	//初始化属性
	this->initSpeech();
	//创建选手
	this->createSpeaker();

    //获取往届记录
    this->loadRecord();
}

void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::initSpeech()
{
	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;//注意这里初始置为1，每轮的得分需要下标 - 1

    //将记录的容量清空，下一次使用
    this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        for (int i = 0; i < 2; i++)
        {
            sp.m_Score[i] = 0;
        }

        //12名选手编号 存放到v1容器中
        this->v1.push_back(i + 10001);

        //选手编号 以及对应的选手 存放到map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    //第一轮比赛
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();//会显示一个菜单界面

    //第二轮比赛

    this->m_Index++;

    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示最终结果
    this->showScore();//会显示一个菜单界面
    //4、比赛完后，自动保存记录
    this->saveRecord();

    //由于没有退出程序，构造函数只会调用一次，当不退出程序进行比赛
    //当上一届比赛完后，还行继续比赛
    //重置比赛 进行下一轮比赛
    //初始化属性
    this->initSpeech();
    //创建选手
    this->createSpeaker();
    //获取往届记录
    this->loadRecord();//如果不加载进来，在当前程序未退出时，就不能获取往届记录

    cout << "本届比赛完毕！"<<endl;
    system("pause");
    system("cls");
}

void SpeechManager::speechDraw()
{
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
    cout << "---------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
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
    cout << "------------- 第" << this->m_Index << "轮正式比赛开始：------------- " << endl;

    multimap<double, int, greater<int>> groupScore; //临时容器，保存key分数 value 选手编号

    int num = 0; //记录人员数，6个为1组

    vector <int> v_Src;   //比赛的人员容器
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else if(this->m_Index == 2)
    {
        v_Src = v2;
    }

    //遍历所有参赛选手
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
    {
        num++;

        //评委打分
        deque<double>d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000 小数
            //cout << score << " ";
            d.push_back(score);
        }
        //cout << endl;

        sort(d.begin(), d.end(), greater<double>());				//排序
        //greater<double>()可以不加，默认小到大
        d.pop_front();												//去掉最高分
        d.pop_back();												//去掉最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
        double avg = sum / (double)d.size();//整数/小数 = 小数							//获取平均分

        //每个人平均分，放入map容器中
        //cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
        //设置每一轮的分数
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;//*it == <int>编号

        //6个人一组，用临时容器保存
        groupScore.insert(make_pair(avg, *it));
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次：" << endl;
            //显示每一轮的信息
            for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
            {
                cout << "编号: " << it->second << " 姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
            }

            int count = 0;
            //取前三名，放入下一个容器中
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
    cout << "------------- 第" << this->m_Index << "轮比赛完毕  ------------- " << endl;
    system("pause");
}

void SpeechManager::showScore()
{
    cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;
    vector<int>v;
    if (this->m_Index == 1)
    {
        v = v2;//不需要设置v.size(v2.size())
    }
    else if(this->m_Index == 2)
    {
        v = vVictory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号：" << *it << " 姓名： " << m_Speaker[*it].m_Name << " 得分： " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;

    system("pause");
    system("cls");
    this->show_Menu();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 用输出的 和追加方式打开文件  -- 写文件

    //将冠亚季，每个人数据写入到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
    {
        //第二轮的信息放入文件中，m_Score[1第2轮的成绩
        ofs << *it << ","
            << m_Speaker[*it].m_Score[1] << ",";// 将第二轮最终成绩写入文件中，.csv文件，在用记事本打开时，每个数据是以逗号隔开
    }
    ofs << endl;

    //关闭文件
    ofs.close();

    cout << "记录已经保存" << endl;

    //默认文件状态为空或不存在，保存完后需要更改文件状态不为空
    this->fileIsEmpty = false;//如果没有这一行，将会导致文件有记录，但是显示文件为空
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

    //文件不存在
    if (!ifs.is_open())
    {
        this->fileIsEmpty = true;
        //cout << "文件不存在！" << endl;
        ifs.close();
        return;
    }

    //文件为空
    char ch;
    ifs >> ch;//读取了一个字符，判断是否文件为空
    if (ifs.eof())
    {
        //cout << "文件为空!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty = false;

    ifs.putback(ch); //将上面读取的单个字符放回去

    string data;//将文件中的数据读取变为字符串
    int index = 0;//第几届
    while (ifs >> data)
    {
        //cout << data << endl;
        //10002，86.675，10009，81.3，10007，78.55，
        vector<string> v;//存放6个字符串的容器

        int pos = -1;//查到“，”位置的变量
        int start = 0;

        while (true)
        {
            pos = data.find(",", start); //从0开始查找 ','
            if (pos == -1)
            {
                break; //找不到break返回
            }
            string tmp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
            v.push_back(tmp);//将截取的所有字符串存入vector容器中
            start = pos + 1;
        }

        this->m_Record.insert(make_pair(index, v));//注意：index为0开始，打印时需要+1
        index++;
    }

    ifs.close();

   /*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
    {
        cout << "第" << it->first << "届" << " 冠军编号：" << it->second[0] << " 分数：" << it->second[1] << endl;
    }*/
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)//查看记录时，判断文件状态，或者加一个loadRecord函数
    {
        cout << "文件为空或文件不存在！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i++)
        {//注意i+1为保存，仍i = 0，显示的都是字符串
            cout << "第" << i + 1 << "届 " <<
                "冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
                "亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
                "季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
        }
        //map<int, vector<string>> m_Record;
        //key = int value = vector<string>
        //m[key] = value  m_Record[i] == vector<string> 
        //vector容器可以随机访问，v[0]....
    }
    
    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    //注意：清空前，判断文件是否为空和文件是否存在

    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        //打开模式 ios::trunc 如果存在，删除文件并重新创建
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        //初始化属性
        this->initSpeech();//防止当前比赛的一些变量还有值，比如：记录容器还有内容，程序未退出，清空了还可以显示记录

        //创建选手
        this->createSpeaker();

        //获取往届记录
        this->loadRecord();//由于重新重建新文件，再加载一遍，当再次查记录时，就什么都没有了

        cout << "清空成功！" << endl;

        //清空记录，fileIsEmpty也改为true，不需要加，因为loadRecord会判断为空后置为true
        //this->fileIsEmpty = true;
    }

    system("pause");
    system("cls");
}