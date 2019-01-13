#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <algorithm>

using namespace std;

class InfAlumno{
public:
    InfAlumno(){}



    string setNombre(vector<string> n){
        string nombre;
        cout << "Cual es el nombre del alumno?" << endl;
        cin >> nombre;
        n.push_back(nombre);


    }
    float media(vector <float> & n){
        float med{0};
        for (auto x:n){
            med = med + x;
        }

        med = med / n.size();
        return med;

    }


    float mediana(vector <float> n){
        sort(n.begin(), n.end());
        if(n.size() % 2 != 0){ //impar
            int medio = n.size()/2;
            return n.at(medio);
        }else{ //par
            int medio = n.size()/2;
            return (n.at(medio) + n.at(medio + 1)) / 2.0;
        }
    }



    float stddev(vector <float> & n){
        float suma{0};
        float m = media(n);
        for(auto x:n){
            suma = suma + (x - m)*(x-m);
        }

        return (sqrt(suma / n.size()));
    }


private:
vector<string> nombre;


};

int main()
{
    cout << "Bienvenido a la base de datos de la clase" << endl;
    cout << "Aqui podras almacenar los datos de los alumnos que tengas en clase, se hara automanticamente la media, la mediana y la desviacion tipica de cada nota y de la nota final de toda la clase" << endl;
    cout << "Todos los resultados se almacenaran en un fichero llamado notas.txt" << endl;
    cout << "Muchas gracias por su atencion" << endl;
    //vector<string> nombre;
    InfAlumno miInfAlumnito;
    vector<float> notaMPp;
    vector<float> notaMPrac;
    vector<float> notaFAr;
    vector<float> notaFr;
    vector<float> notaParr;
    string parar, nombree, correo;
    float notaPN1, notaPN2, notaMP, notaPar, notaT, notaF,notaMPar, notaFA, notaPract1, notaPract2,notaPract3,notaPract4,notaPract5;
    int DNI; // Los DNI se recogen sin letra
    int suspenso{0}, aprobados{0}, numAlumnos{0};

    while(parar != "no"){
        numAlumnos = numAlumnos + 1;
           cout << "Cual es el nombre del alumno? ";
           cin >> nombree;
           cout << "Cual es el correo del alumno? ";
           cin >> correo;
           cout << "Cual es su DNI?, debe ir sin letra ";
           cin >> DNI;
           cout << "Cual es la nota de participacion en clase? ";
           cin >> notaPar;
           if(notaPar < 0 || notaPar > 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPar;
           }
           cout << "Cual es la nota del Primer parcial? ";
           cin >> notaPN1;
           if(notaPN1 < 0 || notaPN1 > 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPN1;
           }
           cout << "Cual es la nota del Segundo parcial? ";
           cin >> notaPN2;
           if(notaPN2 < 0 || notaPN2 > 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPN2;
           }
           cout << "Cual es la nota del trabajo final? ";
           cin >> notaT;
           if(notaT < 0 || notaT > 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaT;
           }
           cout << "Cual es la nota de la Primera Practica ";
           cin >> notaPract1;
           if(notaPract1 < 0 || notaPract1> 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPract1;
           }

           cout << "Cual es la nota de la Segunda Practica ";
           cin >> notaPract2;
           if(notaPract2 < 0 || notaPract2> 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPract2;
           }
           cout << "Cual es la nota de la Tercera Practica ";
           cin >> notaPract3;
           if(notaPract3 < 0 || notaPract3> 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPract3;
           }
           cout << "Cual es la nota de la Cuarta Practica ";
           cin >> notaPract4;
           if(notaPract4 < 0 || notaPract4> 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPract4;
           }
           cout << "Cual es la nota de la Quinta Practica ";
           cin >> notaPract5;
           if(notaPract5 < 0 || notaPract5> 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaPract5;
           }
           cout << "Cual es la nota del Examen final? ";
           cin >> notaF;
           if(notaF < 0 || notaF > 10){
               cout << "La nota es sobre 10 y no puede tener nota negativa, introduce la nota correctamente" << endl;
               cin >> notaF;
           }

           notaMPar = (notaPN1 + notaPN2) / 2;
           notaMP = (notaPract1 + notaPract2 + notaPract3 + notaPract5 + notaT) / 5;
           notaFA = (notaPar * 0.05) + (notaMP * 0.20) + (notaMPar*0.10) + (notaF * 0.65);
           if(notaFA < 5){
               suspenso = suspenso + 1;
           }
           for(int i{0}; i<numAlumnos; i++){
               notaMPp.push_back(i);
              }
           for(int i{0}; i<numAlumnos; i++){
               notaFAr.push_back(i);
              }
           for(int i{0}; i<numAlumnos; i++){
               notaFr.push_back(i);
              }
           for(int i{0}; i<numAlumnos; i++){
               notaParr.push_back(i);
              }
           for(int i{0}; i<numAlumnos; i++){
               notaMPrac.push_back(i);
              }
           cout << "Nota final " << notaFA << endl;
           cout << "Ha terminado de añadir la informacion de los alumnos? Si es asi escriba SI, en caso contrario escriba NO: ";
           cin >> parar;
       }

            cout << "Numeros de alumnos: " << numAlumnos << endl;
            aprobados = numAlumnos - suspenso;
            cout << "El numero de aprobados es de: " << aprobados << endl;
            cout << "El numero de suspensos es de: " << suspenso << endl;


                    cout << "Nota media parciales: " << miInfAlumnito.media(notaMPp) << ", mediana de los parciales: " <<  miInfAlumnito.mediana(notaMPp) << ", desviacion tipica de los parciales: " << miInfAlumnito.stddev(notaMPp) << endl;
                    cout << "Nota media examenes finales : " << miInfAlumnito.media(notaFr) << ", mediana del examen final: " <<  miInfAlumnito.mediana(notaFr) << ", desviacion tipica del examen final: " << miInfAlumnito.stddev(notaFr) << endl;
                    cout << "Nota media practicas: " << miInfAlumnito.media(notaMPrac) << ", mediana de las practicas: " <<  miInfAlumnito.mediana(notaMPrac) << ", desviacion tipica de las practicas: " << miInfAlumnito.stddev(notaMPrac) << endl;
                    cout << "Nota media paticipacion: " << miInfAlumnito.media(notaParr) << ", mediana de la paticipacion: " <<  miInfAlumnito.mediana(notaParr) << ", desviacion tipica de la paticipacion: " << miInfAlumnito.stddev(notaParr) << endl;
                    cout << "Nota media de las notas finales: " << miInfAlumnito.media(notaFAr) << ", mediana de las notas finales: " <<  miInfAlumnito.mediana(notaFAr) << ", desviacion tipica de las notas finales: " << miInfAlumnito.stddev(notaFAr) << endl;


    return 0;

}
