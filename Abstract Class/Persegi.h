#include <iostream>
#include <string.h>
#include "Shape.h"

using namespace std;

class Persegi:public Shape{
	private:
		float sisi;
	public:
		Persegi(int _sisi){
			sisi = _sisi;
		}
		int getArea();
		int getKeliling();
};

