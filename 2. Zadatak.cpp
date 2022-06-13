#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/* Napisati program u kome se citaju podaci o apartmanima jedne turisticke agencije iz postojece datoteke
apartmani.txt i kreira niz struktura tipa apartman ( naziv, mjesto, broj kreveta, cijena), a zatim štampa:
- ukupan broj apartmana u datoteci,
- prosjecna cjena apartmana u toj agenciji,
- broj apartmana u mjestu Paralia,
- naziv apartmana za 2 osobe sa najmanjom cijenom,
- spisak apartmana sortiranih po cijeni.
*/
struct Apartmani{
	string naziv;
	string mjesto;
	int brojKreveta;
	float cijena;
};
int main(){
	Apartmani apartmani[20];
	int br=0, suma=0, j=0;
	float prosjecnaCijena=0;
	ifstream ulaz ("apartmani.txt");
	if(!ulaz){
		cout << "Datoteka ne postoji!" << endl;
	}else{
		Apartmani apartman;
		while(ulaz >> apartman.naziv >> apartman.mjesto >> apartman.brojKreveta >> apartman.cijena){
			apartmani[j]=apartman;
			suma+=apartmani[j].cijena;
			j++;
			prosjecnaCijena=suma/j;
		}
	}
	ulaz.close();
	cout << "Broj apartmana u datoteci je: " << j << endl;
	cout << "Prosjecna cijena apartmana: " << prosjecnaCijena << " KM" << endl;
	cout << "Broj apartmana u mjestu Paralia: ";
	for(int i=0; i<j; i++){
		if(!strcmp(apartmani[i].mjesto, "Paralia")) br++;
	}
	cout << br << endl;
	cout << "Naziv apartmana za 2 osobe s najmanjom cijenom: " << endl;
	for(int i=0; i<j; i++){
		if(apartmani[i].brojKreveta==2){
			cout << apartmani[i].naziv << endl;
		}
	}
	cout << endl;
	cout << "\tSortirani apartmani po cijeni: " << endl;
	for(int i=0; i<j; i++){
		for(int k=i; k<j; k++){
			if(apartmani[i].cijena>apartmani[k].cijena) swap(apartmani[i], apartmani[k]);
		}
	}
	cout << endl;
	for(int i=0; i<j; i++){
		cout << "Naziv apartmana: " << apartmani[i].naziv << endl;
		cout << "Mjesto na kojem se apartman nalazi: " << apartmani[i].mjesto << endl;
		cout << "Broj kreveta u apartmanu: " << apartmani[i].brojKreveta << endl;
		cout << "Cijena apartmana: " << apartmani[i].cijena << " KM" << endl;
		cout << endl;
	}
	return 0;
}
