#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
void carica_dati(int n,zoneBG y[],int &resto){
//apri file / controlla se esiste / se si carichiamo i dati 
int i=0;
ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");
	string linea;
    if (fileInput.is_open()) {
    	getline(fileInput, linea); 
        while (getline(fileInput, linea) && i < n){
	    	stringstream ss(linea);
        	string campo;
        	getline(ss, y[i].ClasseToponimo, ',');
        	getline(ss, y[i].DescrizioneToponimo, ',');
        	getline(ss, y[i].Numero, ',');
        	getline(ss, y[i].Subalterno, ',');
        	getline(ss, campo, ',');
        	y[i].CAP = stoi(campo); 
        	getline(ss, campo, ',');
        	y[i].SezioneISTAT = stoi(campo);
			getline(ss, campo, ',');
        	y[i].posto.Lat = stod(campo);
			getline(ss, campo, ',');
        	y[i].posto.Lon = stod(campo);
			i++; 
    }
	fileInput.close(); 
    } else {
        resto = -1;
    }
}
string visualizza(int n, zoneBG y[], int bin) {
    if (n <= 0) {
    	
        return "";
    }
	else{
    string s = "";
    for (int i = 0; i < n; i++) {
        s += "Zona " + to_string(i + 1) + ":\n";
        s += "  Indirizzo: " + y[i].ClasseToponimo + " " + y[i].DescrizioneToponimo + ", " + to_string(y[i].Numero) + "\n";
        s += "  CAP: " + to_string(y[i].CAP) + " | Sezione ISTAT: " + to_string(y[i].SezioneISTAT) + "\n";
        s += "  Coordinate: (" + to_string(y[i].posto.Lat) + " , " + to_string(y[i].posto.Lon) + ")\n";
        s += "---------------------------\n";
    }
    
    return s;
	}
}



    return output;
}
int main(int argc, char** argv) {
int n,bin = 0;
zoneBG elenco[n];
int scelta;
    do{
//visualizzazione opzioni
cout<<"1 - (C)Carica dati"<<endl;
cout<<"2 - (R)Visualizzazione"<<endl;
cout<<"0 - Fine programma"<<endl;
//scelta dell'opzione
cout<<"scegli l'opzione";

cin>>scelta;
fflush(stdin);
//elaborazione scelta
switch(scelta){
	case 1:
		int resto = 0;
		cout<<"inserisci il numero di righe che vuoi salvare"<<endl;
		cin>>n;
		carica_dati(n,elenco,resto);
		if (resto == -1)
		cout<<"file non eseguibile"<<endl;
		break;
	case 2: 
		visualizza(n,elenco,bin)
		if (bin == -1)
		cout<<"non cè nulla da stampare"<<endl;
		break;	
}
}while (scelta!=0);
	
	return 0;
} 
//{}