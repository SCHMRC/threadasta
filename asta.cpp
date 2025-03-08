#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void offerta(int offerte[], int max, int numcomp){
    int somma = 0;
    for(int i = 0 ; i < max ;  i++){
      
       sleep(rand()%3+1);
       int offerta = rand()%41 + 10;
       offerte[i]=offerta;
       cout<<"Turno numero "<<i+1<<" compratore "<<numcomp<<" ha offerto: "<<offerta<<" per un totale di 
"<<(somma+=offerta)<<endl;
    }
}

void comp(int offerte[], int max, int numcomp){
   offerta(offerte,max,numcomp);
}


int main()
{
    int oggetto = 500;
    srand(time(NULL));
    const int MAXOFFERTE = 5;
    int compratore1[MAXOFFERTE];
    int compratore2[MAXOFFERTE];
    int compratore3[MAXOFFERTE];
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    
    thread t1(comp,compratore1,MAXOFFERTE,1);
    thread t2(comp,compratore2,MAXOFFERTE,2);
    thread t3(comp,compratore3,MAXOFFERTE,3);
    t1.join();
    t2.join();
    t3.join();

    for(int i = 0 ; i < MAXOFFERTE ;  i++){
        sum1+=compratore1[i];
        sum2+=compratore2[i];
        sum3+=compratore3[i];
    }
    if(sum1 > sum2 && sum1 > sum3){
        //vince comp1
        cout<<"vince cop1"<<endl;
    }else if(sum2 > sum1 && sum2 > sum3){
        //vince comp2
        cout<<"vince cop2"<<endl;
    }else{
        //vince vomp3
        cout<<"vince cop3"<<endl;
    }




    return 0;
}
