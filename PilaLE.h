#ifndef PILALE_H
#define PILALE_H

#include "ListaEnlazada.h"

template<class TIPO>
class PilaLE : public ListaEnlazada<TIPO>
{
    public:
        PilaLE();
        virtual ~PilaLE();

    //Métodos
    void push(TIPO dato);
    void pop();
    TIPO top();
    int count();

    protected:
    private:
};

template<class TIPO>
void PilaLE<TIPO>::push(TIPO dato)
{
    IteradorLista<TIPO> itr = PilaLE::getIterador();
    PilaLE::agregar(itr, dato);
}

template<class TIPO>
void PilaLE<TIPO>::pop()
{
    IteradorLista<TIPO> itr = PilaLE::getIterador();
    if(itr.valido())
        PilaLE::removerFin();
}

template<class TIPO>
TIPO PilaLE<TIPO>::top()
{
    IteradorLista<TIPO> itr = PilaLE::getIterador();
    if(itr.valido())
        return PilaLE::getFin()->getInfo();
    TIPO tipo = new TIPO;
    return tipo;
}

template<class TIPO>
int PilaLE<TIPO>::count()
{
    return PilaLE::count();
}

#endif // PILALE_H
