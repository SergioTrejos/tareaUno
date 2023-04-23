#include <stdio.h>
#include <iostream>

using namespace std;

class Aula{
    public:
        int _piso;
        int _identificador;
        int _pupitres;
        bool _proyector;
    Aula(int piso, int identificador, int pupitres, bool proyector){
        _piso = piso;
        _identificador = identificador;
        _pupitres = pupitres;
        _proyector = proyector;
    };
};

class Edificio{
    public:
        bool _ascensor;
        string _nombre;
    Edificio(bool ascensor, string nombre){
        _ascensor = ascensor;
        _nombre = nombre;
    }
};

class Edicifio_aulas:public Edificio{
    public:
        bool _soda;
        Aula* _aulas;
    Edicifio_aulas(bool soda, Aula* aulas, bool ascensor, string nombre):Edificio(ascensor, nombre){
        _soda = soda;
        this -> _aulas = aulas;
    };
};

class Edificio_parqueo:public Edificio{
    public:
};

class Finca{
    public:
        string _nombre;
        bool _bus;
        Edificio* _edificios;
    Finca(string nombre, bool bus, Edificio* edificios){
        _nombre = nombre;
        _bus = bus;
        this -> _edificios = edificios;
    };
};

class Campus{
    public:
        string _nombre;
        Finca* _fincas;
    Campus(string nombre, Finca* fincas){
        _nombre = nombre;
        this -> _fincas = fincas;
    }
};

int main(void){
    Aula aula1(2, 22909595, 27, false);
    Aula aula2(2, 14587695, 27, false);
    Aula aulas[] = {aula1,aula2};
    Edicifio_aulas edif_aulas_1 (true, aulas, true, "Ingenieria Electrica");
    Edificio edificios1[] = {edif_aulas_1};
    Finca finca_1 ("aire", true, edificios1);
    Finca finca_2 ("fuego", false, edificios1);
    Finca finca_3 ("viento", true, edificios1);
    Finca finca_4 ("agua", false, edificios1);
    Finca fincas[] = {finca_1,finca_2,finca_3,finca_4};
    Campus campus1("Rodrigo Facio",fincas);
    cout << "El campus " << campus1._nombre << " tiene las siguientes fincas: " << endl;
    cout << finca_1._nombre << ", " << finca_2._nombre << ", " << finca_3._nombre << " y " << finca_4._nombre << ", " << endl;
    cout << "Las aulas registradas son: " << endl;
    cout << "El aula " << aula1._identificador << " , esta ubicada en el piso numero : " << aula1._piso << " , tiene : "<< aula1._pupitres << " pupitres y tiene : " << aula1._proyector << " , proyector(es) : "<< endl;
    cout << "El aula " << aula2._identificador << " , esta ubicada en el piso numero : " << aula2._piso << " , tiene : "<< aula2._pupitres << " pupitres y tiene : " << aula2._proyector << " , proyector(es) : "<< endl;

    return(0);
}