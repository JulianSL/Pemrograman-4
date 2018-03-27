#include <iostream>
#include <math.h>
#include <string.h>
#include "Segitiga.h"
#include "Persegi.h"
#include "Lingkaran.h"

using namespace std;

int main(){
	Segitiga mySegitiga(4,2);
	Persegi myPersegi(3);
	Lingkaran myLingkaran(7);
	
	cout<<"Luas Segitiga : "<<mySegitiga.getArea()<<endl;
	cout<<"Keliling Segitiga : "<<mySegitiga.getKeliling();
	
	cout<<"Luas Persegi : "<<myPersegi.getArea()<<endl;
	cout<<"Keliling Persegi : "<<myPersegi.getKeliling();
	
	cout<<"Luas lingkaran : "<<myLingkaran.getArea()<<endl;
	cout<<"Keliling lingkaran : "<<myLingkaran.getKeliling();
}

