#pragma once

#include <iostream>
#include <string>
#include "Observer.h"

using namespace std;

class Player : virtual public Observer {
public:
	string name;
	Player() {};
	void update();
};