#pragma once
#pragma once
#include<iostream>
using namespace std;

//选手类
class Speaker
{
public:
    string m_Name;  //姓名
    double m_Score[2]; //分数  12名选手最多有两轮得分，对于int类型当分数相同是不知道排名
};
