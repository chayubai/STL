#pragma once
#include<iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globalFile.h"
#include <string>

class OrderFile
{
public:

    //构造函数
    OrderFile();//用于初始化m_orderData和m_Size

    //更新预约记录
    void updateOrder();

    //记录所有预约信息的容器
    //记录的容器  key --- 记录的条数  value --- 具体记录的键值对信息
    map<int, map<string, string>> m_orderData;

    //预约记录条数
    int m_Size;
};
