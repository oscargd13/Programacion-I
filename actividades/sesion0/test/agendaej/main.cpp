#include <iostream>
#include<vector>

using namespace std;

class Contacto{

public:
    Contacto(string _nombre, string _ap1, string _ap2, int _fijo, int _movil){

    }


    string getNombre() const;
    void setNombre(const string &value);

    string getApellido1() const;
    void setApellido1(const string &value);

    string getApellido2() const;
    void setApellido2(const string &value);

    int getFijo() const;
    void setFijo(int value);

    int getMovil() const;
    void setMovil(int value);

    void modificar(int _fijo, int _movil);
    bool isContact(const string &n, const string &a1, const string &a2) const;
    void print() const;

private:
    string nombre, apellido1, apellido2;
    int fijo, movil;

};

class Agenda{

public:
    Agenda(){}
    /**
     * @brief buscar
     * @param n
     * @param a1
     * @param a2
     * @param c
     * @return
     */

    bool buscar(const string &n, const string &a1, const string &a2, Contacto &c);
    bool modificar(const string &n, const string &a1, const string &a2, int tel, int movil);
    bool eliminar(const string &n, const string &a1, const string &a2,);
    bool añadir(const string &n, const string &a1, const string &a2 );


private:
    vector<Contacto> contactos;

};

int main()
{


    string Contacto::getNombre() const
    {
        return nombre;
    }

    void Contacto::setNombre(const string &value)
    {
        nombre = value;
    }

    string Contacto::getApellido1() const
    {
        return apellido1;
    }

    void Contacto::setApellido1(const string &value)
    {
        apellido1 = value;
    }

    string Contacto::getApellido2() const
    {
        return apellido2;
    }

    void Contacto::setApellido2(const string &value)
    {
        apellido2 = value;
    }

    int Contacto::getFijo() const
    {
        return fijo;
    }

    void Contacto::setFijo(int value)
    {
        fijo = value;
    }

    int Contacto::getMovil() const
    {
        return movil;
    }

    void Contacto::setMovil(int value)
    {
        movil = value;
    }

    void Contacto::modificar(int _fijo, int _movil)
    {
        fijo = _fijo;
        movil = _movil;
    }

    bool Contacto::isContact(const string &n, const string &a1, const string &a2) const
    {
        return(n == nombre && a1 == apellido1 && a2 == apellido2)
    }

    void Contacto::print() const
    {
        cout << "Nombre:" << nombre << " " << apellido1 << " " << apellido2 << endl;
        cout << "Telf. fijo:" << fijo << endl;
        cout << "Telf. movil:" << movil << endl;
    }
    return 0;
}
bool Agenda::añadir(const string &n, const string &a1, const string &a2, int fiji, int movil)
{
    Contacto aux
            if(! busca(n, a1, a2, aux)){
        contactos.push_back(Contacto(n, a1, a2, fijo, movil)){
            return true;
        }
        return false;
    }

}

bool Agenda::buscar(const string &n, const string &a1, const string &a2, Contacto &c)
{
    for(int i{0}; i<contactos.size(); i++){
        if(contactos.at(i).isContact(n, a1, a2)){
            c = contactos.at(i);
            return true;
        }
    }
    return false;
}

bool Agenda::modificar(const string &n, const string &a1, const string &a2, int tel, int movil)
{
    for(int i{0}; i<contactos.size(); i++){
        if(contactos.at(i).isContact(n, a1, a2)){
       contactos.at(i).modificar(tel, movil);
        return true;
        }
    }
    return false;
}

bool Agenda::eliminar(const string &n, const string &a1, const string &a2)
{
    for(int i{0}; i<contactos.size(); i++){
        if(contactos.at(i).isContact(n, a1, a2)){
            contactos.erase(contactos.begin() + i);
            return true;
        }
    }
    return false;
}
