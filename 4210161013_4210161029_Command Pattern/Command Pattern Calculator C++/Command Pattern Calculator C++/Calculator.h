#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

class Calculator {
public:
	Calculator() {
		current = 0;
	}
	int current;
	void add(int _x) {
		current += _x;
		cout << "hasil : " << current << endl;
	}
	void substract(int _x) {
		current -= _x;
		cout << "hasil : " << current << endl;
	}
	void divide(int _x) {
		current = current / _x;
		cout << "hasil : " << current << endl;
	}
	void multiply(int _x) {
		current = current * _x;
		cout << "hasil : " << current << endl;
	}
};


