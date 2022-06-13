#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/* Napisati program u kome se citaju podaci o radnicima iz postojece datoteke radnici.txt i kreira niz
struktura tipa radnik (ime, prezime, broj godina radnog staža, stepen strucne spreme i plata), a zatim
štampa:
- ukupan broj radnika u datoteci,
- prosjecna plata radnika,
- broj radnika koji imaju više od 5 godina radnog staža,
- imena radnika sa najvišim stepenom strucne spreme,
- spisak radnika sortiranih po imenima.
*/
struct Radnik{
	string ime;
	string prezime;
	int brGodRadnogStaza;
	int stepenStrucneSpreme;
	float plata;
};
int main(){
	Radnik radnicii[20];
	Radnik radnik;
	int broj=0, br=0, strSprema=0;
	float suma=0, prosjecnaPlata=0;
	ifstream ulaz("radnici.txt");
	if(!ulaz){
		cout << "Datoteka ne postoji!" << endl;
	}else{
		while(ulaz >> radnik.ime >> radnik.prezime >> radnik.brGodRadnogStaza >> radnik.stepenStrucneSpreme >> radnik.plata){
			radnicii[broj] = radnik;
			suma+=radnicii[broj].plata;
			prosjecnaPlata = suma/broj;
			if(radnicii[broj].brGodRadnogStaza>5) br++;
			if(radnicii[broj].stepenStrucneSpreme>strSprema) strSprema=radnicii[broj].stepenStrucneSpreme;
			broj++;
		}
	}
	ulaz.close();
	cout << "Ukupan broj radnika u datoteci: " << broj << endl;
	cout << "Prosjecna plata radnika iznosi: " << prosjecnaPlata << endl;
	cout << "Broj radnika koji imaju vise od 5 godina radnog staza: " << br << endl;
	cout << "Imena radnika sa najvisim stepenom strucne spreme: " << endl;
	for(int i=0; i<broj; i++){
		if(radnicii[i].stepenStrucneSpreme==strSprema){
			cout << radnicii[i].ime << endl;
		}
	}
	cout << endl;
	for(int i=0; i<broj; i++){
		for(int j=i; j<broj; j++){
			for(int k=0; k<radnicii[i].ime.length(); k++){    
				if(int(tolower(radnicii[i].ime[k]))>int(tolower(radnicii[j].ime[k]))){ // provjera da li je ascii karakter prvog imena veci od ascii karaktera drugog imena, imena prebacujem u mala slova
					swap(radnicii[i], radnicii[j]);
					break;    // ako su karakteri isti, taj korak se preskace
				}else{
					if(int(tolower(radnicii[i].ime[k]))==int(tolower(radnicii[j].ime[k]))) continue; // ako nije nema potrebe za zamjenom ta dva imena
					else break; // izlaz iz petlje za j-tu recenicu
				}
			}
		}
	}
	cout << "\tSpisak radnika sortiranih po imenima: " << endl;
	cout << endl;
	for(int i=0; i<broj; i++){
		cout << "Ime i prezime radnika: " << radnicii[i].ime << " " << radnicii[i].prezime << endl;
		cout << "Staz radnika: " << radnicii[i].brGodRadnogStaza << endl;
		cout << "Stepen strucne spreme radnika: " << radnicii[i].stepenStrucneSpreme << endl;
		cout << "Plata radnika: " << radnicii[i].plata << endl;
		cout << endl;
	}
	return 0;
}
