#include <iostream>
using namespace std;

// 7/14 <4/18 
// 1/2 < 4/3
// 3/6 < 8/6 
    
struct Fractie{
    int numarator_ireductibil, numitor_ireductibil;
}X,Y;

// metode cmmdc 2: Euclid, scaderi repetate (resturi) 
//cea mai eficienta : scaderi repetate(resturi)

//scaderi repetate
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

//euclid 
/*
    int cmmdc_Euclid(int a, int b){
        while(a != b){
            if (a > b) a = a-b;
            else b = b-a;
        }
        return a;
    }
*/

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    int cmmdc_a_b = cmmdc(a,b);
    int cmmdc_c_d = cmmdc (c,d);
    
    X.numarator_ireductibil = a / cmmdc_a_b;
    X.numitor_ireductibil = b / cmmdc_a_b;
    
    Y.numitor_ireductibil = d / cmmdc_c_d;
    Y.numarator_ireductibil = c / cmmdc_c_d;
    
    double rezultat_x = X.numarator_ireductibil / X.numitor_ireductibil;
    double rezultat_y = Y.numarator_ireductibil / Y.numitor_ireductibil;
    
    if(rezultat_x > rezultat_y){ // negatia: rezultat_x <= rezultat_y
        cout<<X.numarator_ireductibil<< " " <<X.numitor_ireductibil;
    }else {
        cout<<Y.numarator_ireductibil<< " "<<Y.numitor_ireductibil;
    }
    
    return 0;
}