#include <iostream>
#include <fstream>
#include <string>
using namespace std;

	
struct Location{
	double Lat;
	double Lon;	
};
struct zoneBG {
	string ClasseToponimo;
	string DescrizioneToponimo;
	string Numero;
	string Subalterno;
	int CAP;
	int SezioneISTAT;
	Location posto;
};
void carica_dati(int n, int &y){
//apri file / controlla se esiste / se si carichiamo i dati 
int i=0;
ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");
	string linea;
    if (fileInput.is_open()) {
        while (fileInput>>linea && i<n){
        	i++;
        }
        fileInput.close(); 
    } else {
        y = 1;
    }
}
void visualizza(){


}
int main(int argc, char** argv) {
	int scelta;
	int n,y = 0;
    do{
//visualizzazione opzioni
cout<<"1 - (C)Carica dati"<<endl;
cout<<"2 - (R)Visualizzazione"<<endl;
cout<<"0 - Fine programma"<<endl;
//scelta dell'opzione
cout<<"scegli l'opzione ";

cin>>scelta;
fflush(stdin);
//elaborazione scelta
switch(scelta){
	case 1:
		cout<<"inserisci quante righe vuoi salvare "<<endl;
		cin>>n;
		carica_dati(n,y);
		if (y == 1)
		cout << "Impossibile aprire il file";
		break;
	case 2: 
	 //   cout<<visualizza();
		break;	
}
}while (scelta!=0);

	
	return 0;
}
//{}