#include <iostream>
#include <math.h>
#include <string.h>
#include "Segitiga.h"

using namespace std;

int Segitiga::getArea(){
	int area = (alas * tinggi)/2;
	return area;
}

int Segitiga::getKeliling(){
	int sisiMiring = sqrt(pow(alas/2,2)*pow(tinggi,2));
	int keliling = alas + (sisiMiring*2);
	return keliling;
}

int main(){
	Segitiga mySegitiga(4,2);
	
	cout<<"Luas Segitiga : "<<mySegitiga.getArea()<<endl;
	cout<<"Keliling Segitiga : "<<mySegitiga.getKeliling();
}
