#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;
/*Napisati funkcije:
a) brojpoz(), koja racuna broj pozitivnih clanova niza,
b) proizvod(), koja racuna proizvod svih clanova niza,
c) zbirparnih(), koja racuna zbir svih parnih clanova,
d) brojnula(), koja racuna broj clanova jednakih nuli,
e) brojneg(), koja racuna broj negativnih clanova,
f) prosek(), koja racuna srednju vrijednost niza.
U glavnoj funkciji se unosi prirodan broj n<100, zatim niz od n cijelih brojeva i štampaju
rezultati funkcije.
*/
int brojpoz(int niz[], int n){    // funkcija pod a)
	int brojac=0;    // brojac stavljam na nulu, on ce brojati pozitivne brojeve u nizu
	for(int i=0; i<n; i++){   // petlja koja prolazi kroz niz
		if(niz[i]>0){  // ako su elemnti niza veci od 0, tj. ako su pozitivni
			brojac++;  // uvecaj brojac za jedan
		}
	}
 	return brojac;   //brojac se vraca
}
int proizvod(int niz[], int n){   // funkcija pod b)
	int mnozenje=1;              // mnozenje postavljam na 1
	for(int i=0; i<n; i++){      // petlja koja prolazi kroz niz
		if(niz[i]==0){          // ako imam neki elemenat da je jednak 0, ispisem ovu recenicu
			cout << "\n\tJedan od unesenih brojeva je 0, pa je i proizvod svih brojeva 0!\n";
		}else{
			mnozenje*=niz[i];  // u suprotnom mnozim elemente
		}
	}
	return mnozenje;  // vracam mnozenje
}
int zbirParnih(int niz[], int n){   // funkcija pod c)
	int suma=0;                     // sumu postavljam na 0
	for(int i=0; i<n; i++){         // petlja koja prolazi kroz niz
		if(niz[i]%2==0){           // provjera postoje li parni brojevi
			suma+=niz[i];        // ako postoji sabirem ih
		}

	}
	return suma;     // vracam sumu
}
int brojNula(int niz[], int n){  //funkcija pod d)
	int br=0;                  //brojac na nulu, prolazit ce kroz elemente da vidi ima li clanova jednakih 0
	for(int i=0; i<n; i++){    // petlja koja prolazi kroz niz
		if(niz[i]==0){         // ako naidje na elemenat koji je jednak nula
			br++;             // uveca brojac
		}
	}
	return br;   // vraca brojac
}
int brojNegativnih(int niz[], int n){    // funkcija pod e)
	int br=0;                          // brojac na 0, broji negaativne brojeve u nizu
	for(int i=0; i<n; i++){            // petlja koja prolazi kroz niz
		if(niz[i]<0){                 // ako naidje na negativne brojeve
			br++;                    // uveca brojac
		}
	}
	return br;              // vraca brojac
}
int prosjek(int niz[], int n){   // funkcija pod f)
	float suma=0, srednjaVrijednost;  // suma je 0, deklarisemo novu varijablu, tj srednja vrijednost
	for(int i=0; i<n; i++){       // petlja koja prolazi kroz niz
		suma+=niz[i];    // racunam sumu brojeva u nizu
		srednjaVrijednost=suma/n;   // racunam srednju vrijednost niza
	}
	return srednjaVrijednost; // vraca srednju vrijednost
}

int main(){
	int broj;       // deklaracija broja i niza
	int niz[100];
	do{
		cout << "Unesite broj clanova niza: ";  // preko do while petlje ogranicim da se ne moze unijeti vise od 100 elemenata
		cin >> broj;                 // unos broja clanova niza
	}while(broj<0 || broj>100);
	for(int i=0; i<broj; i++){           // petlja za unos elemenata u niz
		cout << i+1 << ". clan: ";               // unos clanova niza
		cin >> niz[i];
	}
	 cout << "Elemenati niza:\n";
	 for(int i=0; i<broj; i++){           // petlja za ispis elemenata niza
		cout << niz[i] << " ";
	 }
	 cout << endl;
     cout << "\n\tBroj pozitivnih clanova niza: " << brojpoz(niz, broj) << endl;                   // poziv funkcije i ispis pozitivnih clanova niza
     cout << "\n\tProizvod clanova niza: " << proizvod(niz, broj) << endl;                         // poziv funkcije i ispis proizvoda clanova niza
     cout << "\n\tZbir parnih clanova niza: " << zbirParnih(niz, broj) << endl;                    // poziv funkcije i ispis zbira parnih clanova niza
     cout << "\n\tBroj clanova niza jednakih nuli: " << brojNula(niz, broj) << endl;               // pouiv funkcije i ispis clanova niza jednakih nuli
     cout << "\n\tBroj negativnih clanova niza: " << brojNegativnih(niz, broj) << endl;            // pouiv funkcije i ispis negativnih clanova niza
     cout << "\n\tProsjek clanova niza: " << prosjek(niz, broj) << endl;                           // poziv funkcije i ispis prosjeka niza

	return 0;
}
