#include <iostream>
using namespace std;
/*Napravite program koji racuna period izmeðu dva datuma. Pri unosu testirajte
ispravnost unesenog datuma. U realizaciji programa koristite funkcije.
Napomena: Prilikom provjere ispravnosti datuma pazite na prestupne godine. U
prestupnoj godini februar ima 29 dana, a inace 28. Prestupna je godina koja je djeljiva
sa 4 (npr. 2004, 2008, 1996...) osim onih koje su djeljive sa 100 (npr. 1900, 2100...),
ali su godine djeljive sa 400 ipak prestupne (npr. 2000).
Primjer:
Unesite prvi datum (d,m,g): 31,13,2006 Neispravan datum! Unesite prvi datum
(d,m,g): 31,12,2006 Unesite drugi datum (d,m,g): 2,1,2007 Izmedju datuma je
proteklo 2 dana
*/
struct datum{
	int dan;
	int mjesec;
	int godina;
};
const int mjeseci[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // const niz sa brojem mjeseci koji se koriste
void unos(datum* d){     // funkcija za unos, u pokazivac na datum smjesta dan, mjesec i godinu
	cout << "Unesite dan: ";
	cin >> d->dan;
	cout << "Unesite mjesec: ";
	cin >> d->mjesec;
	cout << "Unesite godinu: ";
	cin >> d->godina;
}
bool provjera(datum *d){
	bool greska=false;        // provjera ispravnosti datuma
	if(d->mjesec<1 || d->mjesec>12){    // provjera broja mjeseci
		greska = true;
	}
	for(int i=0; i<12; i++){   // for petlja koja prolazi kroz sve mjesece u godini
		switch(i){            // switch uslov da se provjeri ispravnost dana
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:   // provjera za mjesece koji imaju 31 dan
				if(d->dan>31 || d->dan<1) greska = true; 
				break;
			case 4: case 6: case 9: case 11:                          // provjera za mjesece koji imaju 30 dana
				if(d->dan>30 || d->dan<1) greska = true;
				break;
			case 2:                                                 // provjera za februar
				if(d->godina%4==0){                                 // provjera da li je prestupna godina
					if(d->dan>29 || d->dan<1) greska = true;         // ako jest provjerava se za 29 dana
				}else{
					if(d->dan>28 || d->dan<1) greska = true;        // ako nije provjerava se za 28 dana
				}
			break;
		}
	}
	return greska;             // vraca se vrijednost greske
}
int prestupna(datum d){
	int godina = d.godina;          // u varijablu godina smjestam unesenu godinu
	if(d.mjesec<=2) godina --;      // ako nije presao drugi mjesec ne racunamo tu godinu kao prestupnu
	return (godina/4)-(godina/100)+(godina/400);        // racuna se broj prestupnih godina od 0 do te godine
}
int racun(datum d1, datum d2, bool greska1, bool greska2){
	if(greska1==true){        // provjera ispravnosti datuma
		return -1;
	}else if(greska2){
		return -1;
	}else{
		int dani1=d1.godina*365 + d1.dan;    // proracun broj dana do tog datuma, u varijablu dani smjestam sve dane izmedju te godine i broj dana tog mjeseca koji je trenutno
		for(int i=0; i<d1.mjesec-1; i++){    
			dani1+=mjeseci[i];              // dodaje se za sve mjesece do tog mjeseca dane u broj dana
		}
		dani1+=prestupna(d1);                 // dodaju se svi prestupni dani koji su bili do te godine
		int dani2=d2.godina*365 + d2.dan;     // isti postupak kao i za prvi datum
		for(int i=0; i<d2.mjesec-1; i++){
			dani2+=mjeseci[i];
		}
		dani2+=prestupna(d2);
		return(dani2-dani1);            // vraca se razlika dana izmedju prvog i drugog datuma
	}
}
int main(){
	datum d1, d2;
	bool greska1, greska2;
	do{
		cout << "\n\tUnesite prvi datum: " << endl;                     // do while petlje koje osiguravaju tacan unos datuma
		unos(&d1);
		if(provjera(&d1)) cout << "\n\tNeispravan datum!" << endl;
	}while(provjera(&d1));
	do{
		cout << "\n\tUnesite drugi datum: " << endl;
		unos(&d2);
		if(provjera(&d2)) cout << "\n\tNeispravan datum!" << endl;
	}while(provjera(&d2));
	if(d1.godina>d2.godina) swap(d1,d2);          //ako je 1. godina veca od 2. zamjenjujemo datume
	if(d1.godina==d2.godina && d1.mjesec>d2.mjesec) swap(d1,d2);      // ako su godine jednake, a mjesec 1. datuma veci od 2., zamjenjujemo datume
	if(d1.godina==d2.godina && d1.mjesec==d2.mjesec && d1.dan>d2.dan) swap(d1,d2);   // ako su godine i mjeseci jednaki, a dani 1. datuma veci od 2., zamjenjujemo datume
	greska1=provjera(&d1);   //probjera za ispravnost datuma
	greska2=provjera(&d2);
	int brDana=racun(d1,d2,greska1,greska2);
	if(brDana==-1) cout << "Pogrijesili ste unos datuma!" << endl;
	else{
		cout << "Broj dana izmedju " << d1.dan << "." << d1.mjesec << "." << d1.godina << ". i " << d2.dan << "." << d2.mjesec << "." << d2.godina << ". iznosi: " << brDana << endl;
	}
	return 0;
}
