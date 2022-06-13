#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstring>
using namespace std;
/* kreirajte dinamicki niz objekata tipa radnik od onoliko clanova koliko želi korisnik;
struct radnik
{
int ib;
char ime[10];
char prezime[10];
double dohodak[12];
int staz;
char spol[10];
};
• kreirati funkciju za unos obilježja za sve objekte: void unos(radnik *, int);
• kreirati funkciju za ispis obilježja jednog objekta: void ispis(radnik *);
• kreirati funkciju koja ce prebrojati koliko radnika su žene:
int prebroji_zene(radnik *, int);
• kreirati novi niz u dinamickoj memoriji;
• kreirati funkciju u kojoj cete kopirati sve žene u novonapravljeni niz kopirati sve žene:
void kopiraj_zene(radnik *, radnik *, int);
• kreirati funkciju koja ce pronaci i vratiti radnika s najdužim prezimenom:
radnik * najduze_prezime(radnik *, int);
• kreirati funkciju koja ce vršiti pretragu radnika po imenu, te ispisati sva obilježja
radnika za koje je utvrðeno da imaju traženo ime:
void pretraga_po_imenu(radnik *, char *, int);
• kreirati funkciju koja ce izracunati godišnje prihode za izabranog radnika:
double prihodi(radnik *, int, int); radnika se bira preko IB-a radnika, a prihodi se
racunaju tako da sve zbroje dohoci za 12 mjeseci + 5% za svaku godinu staža;
*/
struct radnik{
	int ib;
	char ime[10];
	char prezime[10];
	double dohodak[12];
	int staz;
	char spol[10];
};
void unos(radnik* niz, int brRadnika){
	srand(time(NULL));
	rand();
	for(int i=0; i<brRadnika; i++){
		cout << "Unesite podatke za " << i+1 << ". osobu:\n ";
		cout << "IB: ";
		cin >> niz[i].ib;
		cin.ignore();
		cout << "Ime: ";
		cin.getline(niz[i].ime, 10);
		cout << "Prezime: ";
		cin.getline(niz[i].prezime, 10);
		cout << "Dohodak: \n";
		for(int j=0; j<12; j++){
			cout << j+1 << ". mjesec: ";
			niz[i].dohodak[j]=rand()%200+801;
			cout << niz[i].dohodak[j] << endl;
		}
		cout << "Staz: ";
		cin >> niz[i].staz;
		cin.ignore();
		do{
			cout << "Spol(muski, zenski): ";
			cin.getline(niz[i].spol, 10);
		}while(strcmp(niz[i].spol,"zenski")!=0 && strcmp(niz[i].spol,"muski")!=0);
		cout << endl;
	}
}
void ispis(radnik *r){
	cout << "IB: " << r->ib << endl;
	cout << "Ime i prezime: " << r->ime << " " << r->prezime << endl;
	cout << "Dohodci po mjesecima:\n ";
	for(int i=0; i<12; i++){
		cout << i+1 << ". mjesec: " << r->dohodak[i] << endl;
	}
	cout << "Staz: " << r->staz << endl;
	cout << "Spol: " << r->spol << endl;
}

int prebroji_zene(radnik *niz, int brRadnika){
	int brojac=0;
	for(int i=0; i<brRadnika; i++){
	    if(strcmp(niz[i].spol,"zenski")==0) brojac++;
	}
	return brojac;
}
void kopiraj_zene(radnik *nizRadnika, radnik *nizZena, int brRadnika){
	int brojac=0;
	for(int i=0; i<brRadnika; i++){
		if(strcmp(nizRadnika[i].spol,"zenski")==0) nizZena[brojac++]=nizRadnika[i];
	}
}
radnik* najduze_prezime(radnik* nizRadnika, int brRadnika){
	int brSlova=0, temp=0;
	radnik *p = nullptr;   // pokazivac p ce bit pokazivac radnika, nullptr znaci da nece imati nikakvu vrijednost prilikom incijalizacije
	for(int i=0; i<brRadnika; i++){
		temp = strlen(nizRadnika[i].prezime);      // u pomocnu varijablu smjestam duzinu prezimena radnika
		if(temp>brSlova){
			brSlova=temp;
			p = nizRadnika+i;                    // pokazuje na radnika cije je prezime najduze
		}
	}
	return p;
}
void pretraga_po_imenu(radnik* niz, char* ime,int brRadnika){
	bool ima=false;
	for(int i=0; i<brRadnika; i++){
		if(strcmp(niz[i].ime, ime)==0){
			ispis(niz+i);                     // prosljedjujemo tog radnika i ispisujemo pomocu funkcije ispis
			ima = true;
		}
	}
}
double prihodi(radnik *niz, int brRadnika, int IB){
	double plata=0;
	for(int i=0; i<brRadnika; i++){
		if(niz[i].ib==IB){
			for(int j=0; j<12; j++){
				plata += niz[i].dohodak[j];
			}
			plata *=(1+0.05*niz[i].staz);
		}
	}
	return plata;
}
int main(){
	int brRadnika;
	cout << "Unesite koliko imate radnika: ";
	cin >> brRadnika;
	radnik *nizRadnika = new radnik[brRadnika];
	cout << "\n\tUnos podataka za radnike:\n ";
	unos(nizRadnika, brRadnika);
	cout << "\n\tIspis radnika:\n ";
	for(int i=0; i<brRadnika; i++){
		ispis(nizRadnika+i);
	}
	cout << "\nRadnik sa najduzim prezimenom: ";
	ispis(najduze_prezime(nizRadnika, brRadnika));  // funkcija unutar funkcije
	cout << "\n\tPretraga po imenu:\n ";
	char ime[10];
	cout << "Unesite ime za pretragu: ";
	cin.getline(ime, 10);
	pretraga_po_imenu(nizRadnika, ime, brRadnika);
	int IB;
	cout << "Unesite IB radnika za obracun: ";
	cin >> IB;
	cin.ignore();
	double prihod = prihodi(nizRadnika, brRadnika, IB);
	if(prihod!=0){
		cout << "Godisnji prihodi radnika sa IB " << IB  << " iznose: " << prihod << " KM!" << endl;
	}else{
		cout << "\nNe postoji radnik sa IB: " << IB << endl;
	}
	cout << "\tIspis zenskih radnika:\n";
	int brZena = prebroji_zene(nizRadnika, brRadnika);
	if(brZena!=0){
		radnik *nizZena=new radnik[brZena];
		kopiraj_zene(nizRadnika, nizZena, brRadnika);
		for(int i=0; i<brZena; i++){
			ispis(nizZena+i);
		}
		delete[] nizZena;
		nizZena=nullptr;
	}else{
		cout << "\nNema zenskih radnika!" << endl;
	}
	delete[] nizRadnika;
	nizRadnika=nullptr;
	return 0;
}
