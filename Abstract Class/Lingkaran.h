#include <iostream>
#include <string.h>
#include "Shape.h"

using namespace std;

class Lingkaran:public Shape{
	private:
		float jari;
	public:
		Lingkaran(int _jari){
			jari = _jari;
		}
		int getArea();
		int getKeliling();
};

