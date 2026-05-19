#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Location {
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


void carica_dati(int n, zoneBG y[], int &resto) {
    ifstream fileInput("Comune_Bergamo_-_Numerazione_civica.csv");
    //se non è aperto si ritorna il resto -1, cosi che esca il messaggio di errore nel main
    if (!fileInput.is_open()) {
        resto = -1;
        return;
    }

    string linea;
	// Salta l'intestazione
    getline(fileInput, linea); 
    
    int i = 0;
    while (getline(fileInput, linea) && i < n) {
        stringstream ss(linea);
        string campo;

        // leggiamo le stringhe 
        getline(ss, y[i].ClasseToponimo, ',');
        getline(ss, y[i].DescrizioneToponimo, ',');
        getline(ss, y[i].Numero, ',');
        getline(ss, y[i].Subalterno, ',');
        // 
        getline(ss, campo, ',');
        if (campo.empty()) y[i].CAP = 0;
        else y[i].CAP = stoi(campo);
        // leggiamo e convertiamo se è persente un valore e lo facciamo per i prossimi valori
        getline(ss, campo, ',');
        if (campo.empty()) y[i].SezioneISTAT = 0;
        else y[i].SezioneISTAT = stoi(campo);
        
        getline(ss, campo, ',');
        if (campo.empty()) y[i].posto.Lat = 0.0;
        else y[i].posto.Lat = stod(campo);
        
        getline(ss, campo, ',');
        if (campo.empty()) y[i].posto.Lon = 0.0;
        else y[i].posto.Lon = stod(campo);
        i++; 
    }
    
    fileInput.close(); 
    resto = i; 
}


string visualizza(int n, zoneBG y[]) {
    if (n <= 0) {
        return "";
    }
    
    string s = "";
    int i = 0; 
    //dal vecchio compito ho adattato to_string
    while (i < n) {
        s += "Zona " + to_string(i + 1) + ":\n";
        s += "  Indirizzo: " + y[i].ClasseToponimo + " " + y[i].DescrizioneToponimo + ", " + y[i].Numero + "\n";
        s += "  CAP: " + to_string(y[i].CAP) + " | Sezione ISTAT: " + to_string(y[i].SezioneISTAT) + "\n";
        s += "  Coordinate: (" + to_string(y[i].posto.Lat) + " , " + to_string(y[i].posto.Lon) + ")\n";
        s += "---------------------------\n"; 
        i++;
    }
    return s;
}




int main(int argc, char** argv) {
    const int MAX_RIGHE = 1000;
    zoneBG elenco[MAX_RIGHE];
    
    int n = 0; 
    int scelta;
    int resto = 0;

    do {
    	cout<<endl;
        cout<<"1 - (C)Carica dati"<<endl;
        cout<<"2 - (R)Visualizzazione"<<endl;
        cout<<"3 - (V)Inserisci via"<<endl;
        cout<<"0 - Fine programma"<<endl;
        cout<<"Scegli l'opzione: ";
        cin>>scelta;

        switch(scelta) {
            case 1:
                cout<<"Inserisci il numero di righe che vuoi salvare ";
                cin>>n;
                if(n>MAX_RIGHE) 
				n = MAX_RIGHE;
                
                carica_dati(n, elenco, resto);
                
                if (resto == -1) {
                    cout << "file non trovato"<<endl;
                    n = 0;
                } else {
                    n = resto;
                }
                break;
            case 2: 
                if (n <= 0) {
                    cout<<"carica prima i dati."<<endl;
                } else {
                    cout<<visualizza(n,elenco);
                }
                break;   
            case 3:
            //	cout<<"inserisci la via interessata"<<endl;
            //	cin>>
            case 0:
                break;
        }
    } while (scelta != 0);
    
    return 0;
}
