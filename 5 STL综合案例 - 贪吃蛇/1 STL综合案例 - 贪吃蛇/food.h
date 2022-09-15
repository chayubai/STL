#pragma once
#include <iostream>
using namespace std;
#include "wall.h"
class Food {
public:
	int foodX, foodY;
	
	//设置食物
	void setFood();
	Wall& wall;//引用来维护wall，用于设置食物
	Food(Wall& temp);
};
