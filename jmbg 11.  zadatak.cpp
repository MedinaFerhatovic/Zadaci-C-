#include <iostream>
using namespace std;
/*Napisati funkciju koja kao argument uzima znakovno polje jmbg (jedinstveni maticni
broj gradjanina) a kao izlaz vraca strukturnu varijablu koja predstavlja datum rodjenja
doticne osobe. Nakon poziva funkcije fdatum() ispisuje datum rodjeja osobe sa
doticnim jedinstvenim maticnim brojem.
*/
struct Gradjanin{   //pravim strukturu gradjanin, sa podacima jmbg koji sadrzi 13 karaktera i datum rodjenja sa 9 karaktera, zbog 2 tacke koje cu koristit da odvoje dan, mjesec i godinu
	char jmbg[13];
	char datumRodjenja[9];
}; 
Gradjanin podaci(Gradjanin gradjanin){   //pravim funkciju preko strukture dajem joj naziv podaci, prima argument gradjanin
	char karakter{46};    // ASCII tabela, karakter 46 je tacka
	for(int i=0; i<2; i++){  //pravim for petlju, koja ide od 0 do 2, jer su prva dva broja u jmbg-u dan rodjenja
		gradjanin.datumRodjenja[i]=gradjanin.jmbg[i];  // izjednacavam datum rodjenja sa jmbg
	}
	gradjanin.datumRodjenja[2]=karakter;   //postavljam karakter na 2. mjesto 
	for(int i=2; i<4; i++){   // for petlja koja ide od 2 do 4, jer su na tim mjestima mjesec rodjenja
		gradjanin.datumRodjenja[i+1]=gradjanin.jmbg[i];  // uvecavamo i za 1, jer se na indeksu 2 nalazi karakter
	}
	gradjanin.datumRodjenja[5]=karakter; //postavljam karakter na 5. mjesto
	char vrijednost[1]={48};   // ASCII tabela, broj 0 iz tabele oznacavam kao vrijednost 1, jer char ne prima vrijednost koja sadrzi nulu
	if(gradjanin.jmbg[4]>vrijednost[0]){  // if uslov, ako je dio jmbg krenuvsi od mjeseca veci od nule
		gradjanin.datumRodjenja[6]=49;;   // ispisat ce broj 1
	}else{
		gradjanin.datumRodjenja[6]=50; // u suprotnom, ako nije, ispisat ce 2
	}
	for(int i=4; i<7; i++){  // for petlja koja ide od 4 do 7, jer se na tim mjestima nalazi godina rodjenja
		gradjanin.datumRodjenja[i+3]=gradjanin.jmbg[i];  // uvecavamo i za 3, jer je na indeksu 4 mjesec, a na indeksu 5 karakter
	}
    	cout << gradjanin.datumRodjenja << endl;  // ispisujemo datum rodjenja
}
void fdatum(Gradjanin gradjanin){  // pravim funkciju bespovratnog tipa, naziv fdatum zadat u zadatku, prima argument gradjanin
	cout << "\t\tJMBG gradjanina je: " << gradjanin.jmbg << endl;  //ispisujem uneseni jmbg
	cout << "\t\tDatum rodjenja gradjanina je: ";  // ispis datuma
	podaci(gradjanin);  // poziv funkcije za ispis datuma
}
int main(){
	Gradjanin gradjanin;  // dajem strukturi novi naziv
	cout << "Unesite JMBG gradjanina: ";   // unos jmbg
	cin.getline(gradjanin.jmbg,13); // unos jbmg gradjanina
	fdatum(gradjanin);  // pouivam funkciju za ispis 
	return 0;
}
