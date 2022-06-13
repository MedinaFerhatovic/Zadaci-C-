#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/* Napisati program u kome se citaju podaci o proizvodima u jednoj prodavnici auto-djelova iz postojece
datoteke proizvodi.txt i kreira niz struktura tipa proizvod ( naziv, proizvoðac, cijena, kolicina),a zatim
štampa:
- ukupan broj proizvoda u datoteci,
- ukupna vrijednost svih proizvoda u prodavnici,
- spisak proizvoda cija je kolicina 0,
- broj proizvoda koje proizvodi FIAT,
- spisak proizvoda sortiranih po cjeni.
*/
struct Proizvodi{
	char naziv[50];
	char proizvodjac[50];
	float cijena;
	int kolicina;
};
int main(){
	Proizvodi proizvod[20];
	int suma=0, br=0, i=0;
	ifstream ulaz ("proizvodi.txt");
	if(!ulaz){
	    cout << "Datoteka ne postoji!" << endl;
	}else{
		Proizvodi proizvodi;
	    while(ulaz >> proizvodi.naziv >> proizvodi.proizvodjac >> proizvodi.cijena >> proizvodi.kolicina){
	    	proizvod[i]=proizvodi;
	        suma+=proizvod[i].cijena;
		    i++;
		}
	}
	ulaz.close();
	cout << "Broj proizvoda u datoteci je: " << i << endl;
	cout << "Cijena svih proizvoda iznosi: " << suma << " KM" << endl;
	cout << "Proizvodi cija je kolicina 0: " << endl;
	for(int j=0; j<i; j++){
		if(proizvod[j].kolicina==0){
			cout << proizvod[j].naziv << endl;
		}
	}
	cout << "Broj proizvoda koje proizvodi FIAT: ";
	for(int j=0; j<i; j++){
		if(!strcmp(proizvod[j].proizvodjac,"FIAT")) br++;
	}
	cout << br << endl;
	cout << endl;
	cout << "Sortirani proizvodi po cijeni: " << endl;
	for(int j=0; j<i; j++){
		for(int k=j; k<i; k++){
			if(proizvod[j].cijena>proizvod[k].cijena) swap(proizvod[j], proizvod[k]);
		}
	}
	cout << endl;
	for(int j=0; j<i; j++){
		cout << "Naziv proizvoda: " << proizvod[j].naziv << endl;
		cout << "Proizvodjac: " << proizvod[j].proizvodjac << endl;
		cout << "Cijena proizvoda: " << proizvod[j].cijena << endl;
		cout << "Kolicina proizvoda: " << proizvod[j].kolicina << endl;
		cout << endl;
	}
	return 0;
}
