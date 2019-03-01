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

template<class Base, class SubClass>
class Clone : public Base
{
public: 
    Base* clone()
    {
        return new SubClass(dynamic_cast<SubClass&>(*this));
    }
};

class Princesa : public Clone<Personaje, Princesa>
{
public:
    Princesa(string n)
    {
        nombre = n;
    }
    Princesa(const Princesa& p)
    {
        nombre = p.nombre;
        telefono = p.telefono;
        mundo = new Mundo(p.mundo->nombreMundo);
        correo = p.correo;    
    }
    void grita(){cout << "aaaaaaa" <<endl ;}
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
    Princesa* pp = dynamic_cast<Princesa*>(p->clone());
    pp->mundo->nombreMundo = "Paletita";
}







