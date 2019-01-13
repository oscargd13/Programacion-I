#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Bolsa{
public:
    Bolsa(){srand(time(NULL));}
    unsigned int sumaN1{0},sumaN2{0};
    string continuarN1, continuarN2;



    void sacarBolasN1(){
        cout << "Jugador 1, quieres continuar?, si es asi pulsa s " << endl;
        cin >> continuarN1;

        if(continuarN1 != "s"){
            bolaJugador1 = 0;
        } else {
            num = rand() % (i-1);
            bolaJugador1 = bolas.at(num);
            num = num;
            bolas.erase(bolas.begin()+num);
            cout << "Al jugador 1 le ha salido la bola con el numero " << bolaJugador1 << endl;
            sumaN1 = sumaN1 + bolaJugador1;
            i--;
        }
    }

    void sacarBolasN2(){
        cout << "Jugador 2, quieres continuar?, si es asi pulsa s " << endl;
        cin >> continuarN2;

        if(continuarN2 != "s"){
            bolaJugador2 = 0;
        } else {
            num = rand() % (i-1);
            bolaJugador2 = bolas.at(num);
            num = num;
            bolas.erase(bolas.begin()+num);
            cout << "Al jugador 2 le ha salido la bola con el numero " << bolaJugador2 << endl;
            sumaN2 = sumaN2 + bolaJugador2;
            i--;
        }
    }

    void quedarBolas(){
        for(int j{0}; j <= i; j++){
            cout << "Todavia quedan estas bolas en la bolsa: " << bolas.at(j);
        }
    }


private:
    vector <int>bolas{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    unsigned short int num, bolaJugador1, bolaJugador2;
    unsigned short int i = 20;
};


class Jugador{
public:
    unsigned short int apuestaN1, apuestaN2;
    Bolsa bolsa();
    ApuestaJ(){
        cout << "Jugador 1, Cual es su apuesta? ";
        cin >> apuestaN1;
        cout << "Jugador 2, Cual es su apuesta? ";
        cin >> apuestaN2;
        if(apuestaN1 <10 || apuestaN1 >50){
            cout << "Que parte de apuesta minima 10 y maxima 50 no entiendes? " << endl;
            cout << "Jugador 1, Cual es su apuesta? ";
            cin >> apuestaN1;
            cout << "Jugardor 2, Cual su apuesta? ";
            cin >> apuestaN2;
        }
        if(apuestaN2 <10 || apuestaN2 >50){
            cout << "Que parte de apuesta minima 10 y maxima 50 no entiendes? " << endl;
            cout << "Jugardor 2, Cual su apuesta? ";
            cin >> apuestaN2;
        }
    }




private:
};

int diferenciaN1, diferenciaN2;

void caballoGanador(){
    if(diferenciaN1 < 0){
        diferenciaN1 = diferenciaN1*(-1);
    }
    if(diferenciaN2 < 0){
        diferenciaN2 = diferenciaN2*(-1);
    }

    if (diferenciaN1 == diferenciaN2){
        cout << "Los jugadores han empatado" << endl;
    }

    if(diferenciaN1 < diferenciaN2){
        cout << "Felicidades Jugador 1, eres el caballo ganador" << endl;
    }else{
        cout << "Felicidades Jugador 2, eres el caballo ganador " << endl;
    }

}



int main()
{
    Bolsa miBolsita;
    Jugador miPersonita;
    miPersonita.ApuestaJ();
        cout << "quiere continuar ";
        cin>> miBolsita.continuarN1;
        while(miBolsita.continuarN1 == "s" || miBolsita.continuarN2 == "s"){
            miBolsita.sacarBolasN1();
            miBolsita.sacarBolasN2();
        }
        cout << "j1 puntuacion: " << miBolsita.sumaN1<<endl;
        cout << "j2 puntuacion: " <<miBolsita.sumaN2<<endl;
        diferenciaN1 = miBolsita.sumaN1 - miPersonita.apuestaN1;
        diferenciaN2 = miBolsita.sumaN2 - miPersonita.apuestaN2;
        caballoGanador();

    return 0;
}
