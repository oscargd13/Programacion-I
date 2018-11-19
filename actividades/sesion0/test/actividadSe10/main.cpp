#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Tablero{
 public:
    Tablero(){

    }
    void print(){
        cout << endl;
        for(int fila{4}; fila>=0; fila--){
        for(int columna{0}; columna<5; columna++){
            if(datos.at(columna).size() == 5){
                cout << "|" << datos.at(columna).at(fila) << "|";
            }else{
                cout << "|   |";

            }
        }
        cout << " |" << endl;
      }
        cout << "---------------------------" << endl;
        cout <<endl;
    }

    bool add(char ficha, unsigned int col){
        if(col > 5) throw string {"No caben mas fichas en la columna"};
        if(datos.at(col-1).size() == 5) return false;
        if(ficha =='x' || ficha =='o') throw string {"Ficha desconocida"};
        datos.at(col-1).push_back(ficha);



    }


 private:
  array <vector<char>, 5> datos;
};

int main()
{
    int x, o;
    Tablero miJuego;
    miJuego.print();

 try{
        while(true){
            unsigned int col;
            cout <<"Jugador 1, en que columna quieres jugar?";
            cin >>col;
            while(!miJuego.meterFicha('o',col)){
                cout <<"Jugador 1, en que columna quieres jugar?";
                cin >> col;
            }
            miJuego.print();
        }
    }catch (string e){
        cout << e << endl;
        return 1;
    }
    return 0;
}
