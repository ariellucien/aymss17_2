#include<iostream>
#include<string>
using namespace std;

class Mundo
{
public:
    Mundo(string nombreMundo) : nombreMundo(nombreMundo){}
    string nombreMundo;
};
class Personaje
{
public:
    Personaje() = default;
    Personaje(string nombre) : nombre(nombre){}
    string nombre;
    int telefono;
    Mundo* mundo;
    string correo;
    virtual Personaje* clone() = 0;
};

class Princesa : public Personaje
{
public:
    Princesa(string n) : Personaje(n){}
    Princesa(const Princesa& p)
    {
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo->nombreMundo);
        correo = p.correo;    
    }
    void grita(){cout << "aaaaaaa" <<endl ;}
    Personaje* clone()
    {
        return new Princesa(*this);
    }
};

class Villano : public Personaje
{
public:
    Villano(string n) : Personaje(n){}
    void secuestra(){cout << "te atrapé" <<endl ;}
    Personaje* clone()
    {
        return new Villano(*this);
    }
};
class Heroe : public Personaje
{
public:
    Heroe(string n) : Personaje(n){}
    void salvar(){cout << "yo te rescataréeeeee" <<endl ;}
    Personaje* clone()
    {
        return new Heroe(*this);
    }
};
int main()
{
    Princesa* pri = new Princesa("Rapunzel");
    pri->correo = "princisitamoribunda@tec.mx";
    pri->telefono = 55512424;
    pri->mundo = new Mundo("Paleta");
    Princesa* p = dynamic_cast<Princesa*>(pri->clone());
    pri->nombre = "RAPUNZEL";
    pri->mundo->nombreMundo="Paletón";
    cout << p->nombre;
    cout << p->correo;
    cout << p->telefono;
}