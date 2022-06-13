#include <iostream>
using namespace std;
/*Napraviti program za evidenciju studenata na Politehnickom fakultetu. Potrebna su
dva niza struktura od kojih ce jedan sadržavati podatke o studentima (max 100
elemenata), a drugi podatke o ocjenama studenata (max 1000 elemenata). Izgled
struktura je:

struct student{
char ime[20];
char prezime [30];
int index;
};
struct ocjena{
int indeks;
int br_predmeta;
int ocjena;
};

U programu treba omoguciti:
1. Unos studenta (sprjeciti unos duplog indeksa)
2. Ispis svih studenata
3. Ispis jednog studenta i svih predmeta i ocjena koje je taj student dobio na osnovu
unesenog broja indeksa, te prosjek studenta
4. Ispis svih studenata koji iz nekog predmeta imaju ocjenu vecu od neke zadane ocjene.
Korisnik unosi putem tastature predmet i željenu minimalnu ocjenu.
*/

struct Student{                // struktura zadata u zadatku
	char ime[20]; 
	char prezime[20];
	int  index;
};
struct Ocjena{                // struktura zadata u zadatku
	int index;
	char nazivPredmeta[50];
	int ocjena;
    char odgovor[10];
};
// 1. Unos studenata
Student unosStudenata(Student studenti[], int& brojStudenata, Ocjena ocjene[]){    // funkcija za unos studenta
		cout << "Unesite broj studenata: ";                                // unos broja studenata
		cin >> brojStudenata; 
		cout << endl;                                
	for(int i=0; i<brojStudenata; i++){                                          //petlja koja ce prolaziti kroz sve unesene studente
		cout << "Unesite ime studenta: ";                                         // unos imena
		cin >> studenti[i].ime;
		cout << "Unesite prezime studenta: ";                                    // unos prezimena
		cin >> studenti[i].prezime;
		cout << "Unesite broj indexa studenta: ";                            // unos broja indexa studenta
		cin >> studenti[i].index;
		for(int j=0; j<i; j++){                                               // petlja za prolaz kroz indexe, zbog provjere duplikata
			if(studenti[j].index==studenti[i].index){                          // ako postoji index koji smo vec unijeli, onda ispisat sljedecu poruku
				cout << "Ovaj broj index-a postoji, unesite novi broj: "; 
				cin >> studenti[i].index;                                     // unos novog broja indexa
				j=-1;                                                       
			}
		}
		cout << endl;
		ocjene[i].index=studenti[i].index;                                    
	    cin.ignore();
		cout << "Ponudjeni predmeti su: " << endl;                                   // ponuda predmeta
	    cout << " \t1. EJ\n \t2. NTP\n \t3. OS\n \t4. RM\n \t5. DM\n" << endl;      // neki od predmetana studiju
	    cout << "Unesite predmet: ";                                                 // unos predmeta preko cin.getline()
	    cin.getline(ocjene[i].nazivPredmeta, 50);
	   do{
	    	cout << "Unesite ocjenu: ";                                          // unos ocjene
		    cin >> ocjene[i].ocjena;                                            // preko do while petlje sam ogranicila da se ne moze unijeti manja ocjena od 6 i veca od 10
		    cout << endl;
	    }while(ocjene[i].ocjena<6 || ocjene[i].ocjena>10);
		

	}
}
// 2. Ispis studenta
Student ispisStudenata(Student studenti[], int brojStudenata, Ocjena ocjene[]){                             // funkcija za ispis studenta
	cout << "\nInformacije o studentima: " << endl;
	for(int i=0; i<brojStudenata; i++){                                                                       //petlja koja prolazi kroz sve studente i ispisuje podatke o njima
		cout << "\tIme: " << studenti[i].ime << endl;                                                         // ispis imena
		cout << "\tPrezime: " << studenti[i].prezime << endl;                                                // ispis prezimena
		cout << "\tBroj index-a: " << studenti[i].index << endl;                                             // ispis broja index-a
		cout << "\tOcjena iz predmeta " << ocjene[i].nazivPredmeta<< " je: " << ocjene[i].ocjena << endl;    // ispis iz kojeg predmeta student ima ocjenu
		cout << endl;
	}
}
// Unos ocjene
Ocjena ispis(Ocjena ocjene[], int brojStudenata, Student studenti[]){                                 
	int index;
	cout << "Unesite broj indexa: ";                                        // unos broja index-a, na osnovu unesenog broja index-a, ispis svih informacija o studentu
	cin >> index;
	int brojac=0;
	for(int i=0; i<brojStudenata; i++){
		if(studenti[i].index==index){
			cout << "\tIme studenta: " << studenti[i].ime << endl;
			cout << "\tPrezime studenta: " << studenti[i].prezime << endl;
			cout << "\tPredmeti iz kojih student ima ocjenu su: " << ocjene[i].nazivPredmeta << endl;
			cout << "\tOcjene iz tih predmeta su: " << ocjene[i].ocjena << endl;
			brojac++;
		}
	}
	cout << endl;
}
Ocjena ispisVece(Ocjena ocjene[], int brojStudenata, Student studenti[]){                                  // funkcija za vecu ocjenu od minimalno unesene
	char predmet[50];
	cout << "\nPredmeti: " << endl;
	cout << " \t1. EJ\n \t2. NTP\n \t3. OS\n \t4. RM\n \t5. DM\n" << endl;                              // odabir predmeta
	cout << "Unesite predmet koji zelite: ";
	cin.ignore();
	cin.getline(predmet, 50);
	int ocjena;
	string predmet1=predmet;                   
	string predmet2;
	cout << "Unesite najmanju ocjenu: ";                                                             // unos najmanje ocjene za odabrani predmet
	cin >> ocjena;
	for(int i=0; i<brojStudenata; i++){                                                             // petlja koja prolazi kroz sve studente i trazi koji student ima vecu ocjenu iz nekog predmeta
		predmet2=ocjene[i].nazivPredmeta;                                                          // kad nadje, ispise studenta sa vecom ocjenom
		if(predmet2==predmet1 && ocjene[i].ocjena>ocjena){
			cout << "\tIme studenta: " << studenti[i].ime << endl;
			cout << "\tPrezime studenta: " << studenti[i].prezime << endl;
			cout << "\tNjegova ocjena iz predmeta " << ocjene[i].nazivPredmeta << " je: " << ocjene[i].ocjena << endl;
			cout << endl;
		}else{
			cout << "Ni jedan studenat nema ocjenu iz tog predmeta!" << endl;
			break;
		}
	}
}
int main(){
	Student studenti[100];                                         // deklaracija
	int brojStudenata=0;
	Ocjena ocjene[1000];
	unosStudenata(studenti, brojStudenata, ocjene);                    // u glavnom programu se vrsi poziv funkcija
	ispisStudenata(studenti, brojStudenata, ocjene);
	ispis(ocjene, brojStudenata, studenti);
	ispisVece(ocjene, brojStudenata, studenti);
	return 0;
}
