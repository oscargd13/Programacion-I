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
        //array<vector<char>, 5> save;
        for(int fila{4}; fila >= 0; fila--){
         for(int columna{0}; columna < 5; columna++){
            if(datos.at(columna).size()>= fila+1){
                cout << "| " << datos.at(columna).at(fila) << " ";

            }else{
                cout << "|   ";
            }
         }
    cout <<"|" <<endl;
        }
   cout << "---------------------";
   cout << endl;
  }
    bool addFicha(char ficha, unsigned int col){
        if(datos.at(col-1).size()==5) return false;
        if(col > 5) throw string{"Columna demasiado grande"};
        //if(!(ficha == 'x') || !(ficha == 'o')) throw string{"Ficha desconocida"};
        datos.at(col-1).push_back(ficha);

    }


    bool reconocerFicha(char x, char o){
        for(int i{0}; i <= 5; i++){
            if((x == 4) || (o == 4)){
                cout << "4 en linea" << endl;
            }
        }

    }
    bool checkFila(char c){
        unsigned short consecutivas{0};
        for(int fila {0}; fila<5; fila++){
            consecutivas = 0;
            for(int columna {0}; columna<5; columna++){
                if(datos.at(columna).size() == fila){
                    consecutivas = 0;
                }else{
                if(datos.at(columna).at(fila) == c){
                    consecutivas++;
                }else{
                    consecutivas = 0;
                }
                if(consecutivas == 4) return true;
            }
        }
        return false;
    }
}

    bool checkColumna(char c){
        unsigned short consecutivas{0};
        for(auto columna:datos){
            for(auto fila: columna){
                if(fila == c) consecutivas++;
                else consecutivas =0;
                if(consecutivas == 4)return true;
            }

        }
        return false;
    }

private:
    array<vector<char> ,5>datos;
};

int main()
{
   Tablero miJuego;
   miJuego.print();
   try{
       while(true){
           unsigned int col;
           cout << "Jugador 1, en que columna quieres jugar?";
           cin >> col;
           /*while(!miJuego.addFicha('x',col)){
               cout << "Jugador 1, en que columna quieres jugar?";
               cin >> col;
           }*/

           miJuego.addFicha('x',col);
           miJuego.print();
           miJuego.reconocerFicha('x', 'o');
         if(miJuego.checkFila('x')){
             cout<< "Has ganado jugador 1" <<endl;
             return 0;
         }


           cout << "Jugador 2, en que columna quieres jugar?";
           cin >> col;
           /*while(!miJuego.addFicha('o', col)){
               cout << "Jugador 1, en que columna quieres jugar?";
                       cin >> col;
           }*/
           miJuego.addFicha('o',col);
           miJuego.print();
           if(miJuego.checkFila('o')){
               cout<< "Has ganado jugador 2" <<endl;
               return 0;
           }

       }
   }catch(string e){
    cout << e << endl;
    return 1;
   }
    return 0;
}


