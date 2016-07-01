#ifndef COLALE_HPP
#define COLALE_HPP

#include <ListaEnlazada.hpp>

template<class TIPO>
class ColaLE : public ListaEnlazada<TIPO>
{
    public:
        ColaLE();
        virtual ~ColaLE();

    //Métodos
    void encolar(TIPO dato);
    void desencolar();
    TIPO frente();
    int count();

    protected:
    private:
};

template<class TIPO>
void ColaLE<TIPO>::encolar(TIPO dato)
{
    IteradorLista<TIPO> itr = ColaLE::getIterador();
    ColaLE::agregar(itr, dato);
}

template<class TIPO>
void ColaLE<TIPO>::desencolar()
{
    ColaLE::removerInicio();
}

template<class TIPO>
TIPO ColaLE<TIPO>::frente()
{
    return ColaLE::getInicio()->getInfo();
}

template<class TIPO>
int ColaLE<TIPO>::count()
{
    return ColaLE::count();
}
#endif // COLALE_HPP
