#include <iostream>
using namespace std;

struct Aniversare{
    int an = 0, luna = 0, zi = 0, nr_ordine = 0; //default 
}tanar, batran, aux;


/*
1998 5 26
    aux.an = 1998;
    aux.luna = 5;
    aux.zi = 26;
    aux.nr_ordine = 1;
    
    tanar, batran?????? => tanar = aux, batran = aux;

1987 12 18
    aux.an = 1987;
    aux.luna = 12;
    aux.zi = 18;
    aux.nr_ordine = 2;
    
    aux.an > tanar.an ???
     1987  > 1998
     
    aux.an < batran.an ???
     1987  <  1998 => batran = aux
     
1987 9 25
    aux.an = 1987;
    aux.luna = 9;
    aux.zi = 25;
    aux.nr_ordine = 3;
    
    aux.an > tanar.an ???
     1987  > 1998
     
    aux.an < batran.an ???
     1987  <  1987 => batran = aux
    
    aux.an == batran.an ???
        => am gasit pe cineva cu aproape aceeasi varsta 
         (doi oameni nascuti in acelasi an)
         
        aux.luna < batran.luna ???
         9  <  12 => am gasit oe cineva mai batran decat batranul nostru 
         => batran = aux

2015 1 16
    aux.an = 2015;
    aux.luna = 1;
    aux.zi = 16;
    aux.nr_ordine = 4;
    
    aux.an > tanar.an ???
     2015  > 1998 => AM GASIT UN TANAR MAI TANAR DECAT TANARUL NOSTRU
    =>tanar = aux     
    
    
    aux.an < batran.an ???
     1987  <  1987 => batran = aux
    
    aux.an == batran.an ???
        => am gasit pe cineva cu aproape aceeasi varsta 
         (doi oameni nascuti in acelasi an)
         
        aux.luna < batran.luna ???
         9  <  12 => am gasit oe cineva mai batran decat batranul nostru 
         => batran = aux

2015 1 8
    aux.an = 2015;
    aux.luna = 1;
    aux.zi = 8;
    aux.nr_ordine = 5;
    
    aux.an > tanar.an ???
     2015  > 1998 => AM GASIT UN TANAR MAI TANAR DECAT TANARUL NOSTRU
    =>tanar = aux   
    
    aux.an == tanar.an ???
     => verificam luna
     aux.luna > tanar.luna ??
        1  >  5 =>
        
    aux.an < batran.an ???
     1987  <  1987 => batran = aux
    
    aux.an == batran.an ???
        => am gasit pe cineva cu aproape aceeasi varsta 
         (doi oameni nascuti in acelasi an)
         
        aux.luna < batran.luna ???
         9  <  12 => am gasit oe cineva mai batran decat batranul nostru 
         => batran = aux

*/

int main(){
    int nr_total_de_persoane;
    cin>>nr_total_de_persoane;

    for(int i = 0; i < nr_total_de_persoane; i++){ //0 1 2 3 4 => 5 iteratii 
                                                  // 1 2 3 4 5 => 5 iteratii 
        cin>>aux.an>>aux.luna>>aux.zi;
        aux.nr_ordine = i + 1; // 0 + 1 = 1,  1 + 1 = 2...

        if (aux.nr_ordine == 1){
            //initializam valorile
            tanar.an = aux.an;
            tanar.luna = aux.luna;
            tanar.zi = aux.zi;
            tanar.nr_ordine = aux.nr_ordine;
            batran.an = aux.an;
            batran.luna = aux.luna;
            batran.zi = aux.zi;
            batran.nr_ordine = aux.nr_ordine;
        }else {
            if (aux.an > tanar.an){
                //am gasit pe cineva mai tanar
                tanar.an = aux.an;
                tanar.luna = aux.luna;
                tanar.zi = aux.zi;
                tanar.nr_ordine = aux.nr_ordine;
            } else if (aux.an < batran.an){
                //am gasit pe cineva mai batran
                batran.an = aux.an;
                batran.luna = aux.luna;
                batran.zi = aux.zi;
                batran.nr_ordine = aux.nr_ordine;
            } else if (aux.an == tanar.an){
                //verificam luna
                if (aux.luna > tanar.luna){
                    //am gasit pe cineva mai tanar
                    tanar.an = aux.an;
                    tanar.luna = aux.luna;
                    tanar.zi = aux.zi;
                    tanar.nr_ordine = aux.nr_ordine;
                } else if (aux.luna == tanar.luna){
                    //verificam ziua
                    if(aux.zi > tanar.zi){
                        //am gasit pe cineva mai tanar
                        tanar.an = aux.an;
                        tanar.luna = aux.luna;
                        tanar.zi = aux.zi;
                        tanar.nr_ordine = aux.nr_ordine;
                    }
                }
            } else if (aux.an == batran.an){
                //verificam luna
                if(aux.luna < batran.luna){
                    //am gasit pe cineva mai batran
                    batran.an = aux.an;
                    batran.luna = aux.luna;
                    batran.zi = aux.zi;
                    batran.nr_ordine = aux.nr_ordine;
                }else if (aux.luna == batran.luna){
                    //verificam ziua
                    if(aux.zi < batran.zi){
                        //am gasit pe cineva mai batran
                        batran.an = aux.an;
                        batran.luna = aux.luna;
                        batran.zi = aux.zi;
                        batran.nr_ordine = aux.nr_ordine;
                    }
                }
            }
        }     
    }
    cout<<tanar.nr_ordine<< " "<<batran.nr_ordine;
    return 0;
}