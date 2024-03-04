#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("qclasa.in");
ofstream fout("qclasa.out");

struct ELEV {
    int cod;
    int media;
    int absente;
}clasa[30], aux;

int main(){
    //ELEV clasa[30];
    int nr_elevi, nr_elevi_media_10 = 0, suma_medie = 0, nr_absente_maxim_1 = -1, nr_absente_maxim_2 = -1;
    fin >> nr_elevi;

    for(int i = 0; i < nr_elevi; i++){ 
        fin>>clasa[i].cod;
        fin>>clasa[i].media;
        fin>>clasa[i].absente;

        if(clasa[i].media == 10){
            nr_elevi_media_10++;
        }

        suma_medie += clasa[i].media; //suma_medie = suma_medie + clasa[i].media;
        //suma_medie++ => suma_medie = suma_medie + 1;

    }
    fout<<nr_elevi_media_10<<endl;
    fout<<(int)(suma_medie/nr_elevi)<<endl;
    
    //bubble sort
    for (int i=0; i < nr_elevi -1 ; i++){
        for(int j=i+1; j< nr_elevi; j++)
            if(clasa[i].absente < clasa[j].absente){
                aux = clasa[i];
                clasa[i] = clasa[j];
                clasa[j] = aux; 

                //swap(clasa[i], clasa[j]);
            }else if(clasa[i].absente == clasa[j].absente){
                if(clasa[i].cod > clasa[j].cod){
                    aux = clasa[i];
                    clasa[i] = clasa[j];
                    clasa[j] = aux;
                }
            }
    }
    fout<<clasa[0].cod<<" "<<clasa[0].media<<" "<<clasa[0].absente<<endl;
    fout<<clasa[1].cod<<" "<<clasa[1].media<<" "<<clasa[1].absente;

    fout.close();

    return 0;
}