#include <iostream>
#include <string.h>
#include "Lingkaran.h"

using namespace std;

int Lingkaran::getArea(){
	int area = 3.14 * jari * jari;
	return area;
}

int Lingkaran::getKeliling(){
	int keliling = 3.14 * (jari * 2);
	return keliling;
}

int main(){
	Lingkaran myLingkaran(7);
	
	cout<<"Luas lingkaran : "<<myLingkaran.getArea()<<endl;
	cout<<"Keliling lingkaran : "<<myLingkaran.getKeliling();
}
