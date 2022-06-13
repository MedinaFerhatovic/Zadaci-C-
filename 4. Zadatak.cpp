#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/* Napisati program u kome se citaju podaci o ucenicima iz postojece datoteke ucenici.txt i kreira niz
struktura tipa ucenik (ime, prezime, razred (1-4), uspjeh, prosjecna ocjena), a zatim štampa:
- ukupan broj ucenika u datoteci,
- broj ucenika 4. razreda,
- imena ucenika koji imaju odlican uspjeh,
- ime ucenika koji ima najbolju prosjecnu ocjenu,
- imena ucenika sortiranih po razredima.
*/
struct Ucenik{
	char ime[10];
	char prezime[20];
	int razred;
	char uspjeh[10];
	float prosjecnaOcjena;
};
int main(){
	Ucenik ucenik[20];
	Ucenik temp;
	int broj=0, br=0;
	float najveci=0;
	ifstream ulaz("ucenici.txt");
	if(!ulaz){
		cout << "Datoteka ne postoji!" << endl;
	}else{
		while(ulaz >> temp.ime >> temp.prezime >> temp.razred >> temp.uspjeh >> temp.prosjecnaOcjena){
			ucenik[broj] = temp;
			if(ucenik[broj].prosjecnaOcjena>najveci) najveci=ucenik[broj].prosjecnaOcjena;
			broj++;
		}
	}
	ulaz.close();
	cout << "Ukupan broj ucenika u datoteci: " << broj << endl;
	cout << "Broj ucenika 4. razreda: ";
	for(int i=0; i<broj; i++){
		if(ucenik[i].razred==4){
			br++;
		}
	}
	cout << br << endl;
	cout << "Imena ucenika koji imaju odlican uspjeh: " << endl;
	for(int i=0; i<broj; i++){
		if(!strcmp(ucenik[i].uspjeh, "odlican")){
			cout << ucenik[i].ime << endl;
			br++;
		}
	}
	cout << "Ime ucenika koji ima najbolju prosjecnu ocjenu: ";
	for(int i=0; i<broj; i++){
		if(ucenik[i].prosjecnaOcjena==najveci){
			cout << ucenik[i].ime << endl;
		}
	}
	cout << endl;
	for(int i=0; i<broj; i++){
		for(int j=i; j<broj; j++){
			if(ucenik[i].razred>ucenik[j].razred) swap(ucenik[i], ucenik[j]);
		}
	}
	cout << "\tSortirani ucenici po razredu: " << endl;
	cout << endl;
	for(int i=0; i<broj; i++){
		cout << "Ime i prezime ucenika: " << ucenik[i].ime << " " << ucenik[i].prezime << endl;
		cout << "Razred: " << ucenik[i].razred << endl;
		cout << "Uspjeh: " << ucenik[i].uspjeh << endl;
		cout << "Prosjecna ocjena: " << ucenik[i].prosjecnaOcjena << endl;
		cout << endl;
	}
	return 0;
}
