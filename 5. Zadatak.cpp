#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/* Napisati program u kome se citaju podaci o klijentima iz postojece datoteke klijenti.txt i kreira niz
struktura tipa klijent (ime, prezime, mjesto, telefonski broj i posljednji racun), a zatim štampa:
- ukupan broj klijenata,
prosjecan racun za posljednji mjesec,
broj klijenata iz Zenice,
ime i broj klijenata sa najvecim racunom,
spisak klijenata sortiranih po prezimenu.
*/
struct Klijenti{
	char ime[20];
	string prezime;
	char mjesto[20];
	char telefonskiBroj[9];
	float posljednjiRacun;
};
int main(){
	Klijenti klijent[20];
	Klijenti temp;
	int broj=0, br=0;
	float najveciRacun=0, suma=0;
	ifstream ulaz("klijenti.txt");
	if(!ulaz){
		cout << "Datoteka ne postoji!" << endl;
	}else{
		while(ulaz >> temp.ime >> temp.prezime >> temp.mjesto >> temp.telefonskiBroj >> temp.posljednjiRacun){
			klijent[broj]=temp;
			suma+=klijent[broj].posljednjiRacun;
			if(klijent[broj].posljednjiRacun>najveciRacun) najveciRacun=klijent[broj].posljednjiRacun;
				broj++;
	    }
	}
	ulaz.close();
	cout << "Ukupan broj klijenata iznosi: " << broj << endl;
	cout << "Prosjecan racun za posljednji mjesec: " << suma/broj << endl;
	cout << "\n\tBrojevi telefona klijenata iz Zenice: " << endl;
	cout << endl;
	for(int i=0; i<broj; i++){
		if(!strcmp(klijent[i].mjesto, "Zenica")){
			cout << "Broj telefona je: " << klijent[i].telefonskiBroj << endl;
		}
	}
	cout << "\n\tIme i broj telefona osobe sa najvecim racunom: " << endl;
	cout << endl;
	for(int i=0; i<broj; i++){
			if(klijent[i].posljednjiRacun==najveciRacun){
				cout << "Ime: " << klijent[i].ime << endl;
				cout << "Broj: " << klijent[i].telefonskiBroj << endl;
			}
	}
	cout << endl;
	for(int i=0; i<broj; i++){
		for(int j=i; j<broj; j++){
			for(int k=0; k<klijent[i].prezime.length(); k++){
				if(int(tolower(klijent[i].prezime[k]))>int(tolower(klijent[j].prezime[k]))){
					swap(klijent[i], klijent[j]);
					break;
				}else if(int(tolower(klijent[i].prezime[k]))==int(tolower(klijent[j].prezime[k]))) continue;
				else break;
			}
		}
    }
	cout << "\n\tSortirani klijenti po prezimenu: " << endl;
	cout << endl;
	for(int i=0; i<broj; i++){
		cout << "Prezime: " << klijent[i].prezime << endl;
		cout << "Ime: " << klijent[i].ime << endl;
		cout << "Mjesto: " << klijent[i].mjesto << endl;
		cout << "Broj telefona: " << klijent[i].telefonskiBroj << endl;
		cout << "Posljednji racun: " << klijent[i].posljednjiRacun << endl;
		cout << endl;
	}
	return 0;
}
