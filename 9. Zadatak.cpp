#include <iostream>
#include <cstring>
using namespace std;
/* Napraviti funkciju sa sljedecim prototipom:

int ispravna(char *adresa)

Funkcija vraca vrijednost 1 ako primljeni string predstavlja ispravnu email adresu iz Bosne i
Hercegovine, a u suprotnom vraca 0. Radi jednostavnosti, primijenite sljedece testove:
• u stringu se nalazi tacno jedan znak @
• posljednja tri karaktera stringa su ".ba"
Ukoliko jedan od testova nije zadovoljen, funkcija vraca 0.
*/
int ispravna(char *adresa){    //naziv funkcije zadat u zadatku
	bool x=false, y=false;   // pravim bool za x i y, oba postavljam na netacno
	char karakter={64};     // ASCII tabela, 64=@
	char karakteri[3]={46,98,97}; // ASCII tabela za ova 3 karaktera ".ba", 46=".", 98="b", 97="a"
	int duzina=strlen(adresa);    // uvodim novu varijablu duzina i pridruzujem joj funkciju strlen ic cstring biblioteke, koja mjeri duzinu adrese
	for(int i=0; i<duzina; i++){  // for petlja koja prolazi kroz adresu
		if(adresa[i]==karakter){  // ako je adresa izjednacena sa karakterom 64, tj. ako imamo @
			x=true;               // onda vraca true
		}
	}
	if(adresa[duzina-3,duzina-2,duzina-1]==karakteri[0,1,2]){ // sljedeci uslov: ako se duzina adrese umanjuje za 3, pa za 2, pa za 1, onda adresu izjednacavam sa karakterima 
 		y=true;                                               // ako je ovo ispunjeno vraca true, sto znaci da imam posljednja 3 karaktera ".ba"
	}
	if(x&&y){                     // samo u slucaju ako su oba true, funkcija ce vratiti 1
		return 1;
	}else{
		return 0;                 // u suprotnom, ako bar jedan od uslova ne bude zadovoljen, funkcija vraca 0
	}
}
int main(){
	char adresa[60];          // deklarisem adresu, sa max 60 karaktera (proizvoljno)
	cout << "Unesite e-mail adresu: ";  // unos e-mail adrese
	cin >> adresa;
	int funkcija=ispravna(adresa);   // uvodim novu varijablu kojoj pridruzujem vrijednost funkcije ispravna(adresa)
	if(funkcija==1){                 // i onda ispitujem, ako je funkcija jednaka 1
		cout << "Ova e-mail adresa je iz Bosne i Hercegovine!" << endl;  // adresa postoji na podrucju Bosne i Hercegovine
	}else{
		cout << "Ova e-mail adresa nije iz Bosne i Hercegovine!" << endl;  // u suprotnom, tj. ako je 0 adresa ne postoji na podrucju Bosne i Hercegovine
	}
	return 0;
}
