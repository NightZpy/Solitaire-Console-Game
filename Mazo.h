#ifndef MAZO_H
#define MAZO_H
#include "Carta.h"
#include "PilaLE.h"

class Mazo
{
	public:
		Mazo(int cCartas);

	//Métodos

	//Getters
		PilaLE<Carta> 	getPCartas(){ return Mazo::pCartas; }
		Carta*	 		getVCartas(){ return Mazo::vCartas; }
		int				getCCartas(){ return Mazo::cCartas; }

	protected:

    private:
		PilaLE<Carta>    pCartas;
		Carta		     vCartas[52];
		int 		     cCartas;
};

Mazo::Mazo(int cCartas)
{
            Mazo::cCartas = cCartas;

            int cPorGrupo = Mazo::getCCartas() / 4;
            int cCodigo = 0;
            for(int i=3; i<=6; i++)
            {
                for(int j=1; j<=cPorGrupo; j++)
                {
                    Mazo::vCartas[cCodigo] = new Carta(j, cCodigo+1, i);
                    cCodigo++;
                }
            }

            srand(time(NULL));
            for(int i=0; i<cCartas; i++)
            {
                int cartaAleatoria = rand() % Mazo::cCartas;

                Mazo::pCartas.push(Mazo::vCartas[cartaAleatoria]);
            }
}

#endif // MAZO_H
