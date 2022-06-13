#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
/* U datotekama grupa1.txt, grupa2.txt i grupa3.txt prati se rad ucenika na vježbama iz programiranja. U
svakom redu datoteka je ime ucenika, prosjecna ocjena vježbi i broj vježbi koje je ucenik propustio.
Procitati sve podatke i u datoteku izvjestaj.txt upisati sortirane ucenike, njihove zakljucne ocjene i
komentar da li je ucenik zadovoljio minimum rada na vježbama (manje od 5 propuštenih vježbi).
*/
struct Vjezbe{
	string ime;
	int brIzostanaka;
	float prosjecnaOcjena;
};
struct Izvjestaj{
	char ime[10];
	float zakljucnaOcjena;
	string komentar;
};
int main(){
	ifstream ulaz("grupa1.txt");
	ofstream unos("izvjestaj.txt", ios::app);
	Vjezbe vjezbe[20];
	Vjezbe vjezba;
	if(!ulaz){
		cout << "Greska!" << endl;
	}else{
		while(ulaz >> vjezba.ime >> vjezba.prosjecnaOcjena >> vjezba.brIzostanaka){
			unos << vjezba.ime << " " << vjezba.prosjecnaOcjena << " " << vjezba.brIzostanaka << endl;
		}
	}
	ulaz.close();
	ifstream ulaz1("grupa2.txt");
	if(!ulaz1){
		cout << "Greska!" << endl;
	}else{
		while(ulaz1 >> vjezba.ime >> vjezba.prosjecnaOcjena >> vjezba.brIzostanaka){
			unos << vjezba.ime << " " << vjezba.prosjecnaOcjena << " " << vjezba.brIzostanaka << endl;
		}
	}
	ulaz1.close();
	ifstream ulaz2("grupa3.txt");
	if(!ulaz2){
		cout << "Greska!" << endl;
	}else{
		while(ulaz2 >> vjezba.ime >> vjezba.prosjecnaOcjena >> vjezba.brIzostanaka){
			unos << vjezba.ime << " " << vjezba.prosjecnaOcjena << " " << vjezba.brIzostanaka << endl;
		}
	}
	ulaz2.close();
	unos.close();
	Izvjestaj izvjestaj[20];
	int broj=0;
	ifstream ulaz3("izvjestaj.txt");
	if(!ulaz3){
		cout << "Greska!" << endl;
	}else{
		while(ulaz3 >> vjezba.ime >> vjezba.prosjecnaOcjena >> vjezba.brIzostanaka){
			vjezbe[broj]=vjezba;
			broj++;
		}
	}
	ulaz3.close();
	for(int i=0; i<broj; i++){
		for(int j=i; j<broj; j++){
			for(int k=0; k<vjezbe[i].ime.length(); k++){
				if(int(tolower(vjezbe[i].ime[k]))>int(tolower(vjezbe[j].ime[k]))){
					swap(vjezbe[i], vjezbe[j]);
					break;
				}else if(int(tolower(vjezbe[i].ime[k]))==int(tolower(vjezbe[j].ime[k]))) continue;
				else break;
			}
		}
	}
	ofstream unos1("izvjestaj.txt");
	int br=0;
	while(br!=broj){
		unos1 << vjezbe[br].ime << " ";
		izvjestaj[br].zakljucnaOcjena=vjezbe[br].prosjecnaOcjena;
		unos1 << izvjestaj[br].zakljucnaOcjena << " ";
		if(vjezbe[br].brIzostanaka<5){
			izvjestaj[br].komentar="zadvoljio/la";
			unos1 << izvjestaj[br].komentar << endl;
		}else{
			izvjestaj[br].komentar="nije zadovoljio/la";
			unos1 << izvjestaj[br].komentar << endl;
		}
		br++;
		unos1.close();
	}
	return 0;
}
