#include <iostream>
#include <string.h>
#include "Shape.h"

using namespace std;

class Segitiga:public Shape{
	public:
		float alas;
		float tinggi;
		Segitiga(int _alas, int _tinggi){
			alas = _alas;
			tinggi = _tinggi;
		}
		int getArea();
		int getKeliling();
};
