#include "Mazo.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

//Constantes usadas para identificar cada figura en las cartas
const int CORAZON=3;
const int DIAMANTE=4;
const int TREBOL=5;
const int PICA=6;

bool movimientoValido(Carta carta, Carta cartaSuperior);
bool conjuntoCompleto(PilaLE<Carta> conjunto);
void mostrarConjunto(PilaE<Carta> conjunto);
void mostrarConjuntos(PilaE<Carta>* conjuntos, int cConjuntos);
bool cambiarCarta(PilaLE<Carta>* conjuntos, int cConjuntos, int conjuntoOrigen, int conjuntoDestino);
bool limitesValidos(int conjuntoOrigen, int conjuntoDestino);

int main()
{
    //Mazo de cartas, contendra las 52 cartas y de una vez las revolvera
    Mazo mazo = new Mazo(52);
    PilaLE<Carta> mazoAbierto;

    //Pila que contendra las cartas combinadas (Retorno la pila desde mazo yl a asigno a una nueva variable)
    PilaLE<Carta> mazoCombinado = mazo.getPCartas();

    //Vector de Pilas usado para almacenar los 7 conjuntos de cartas que estaran en juego
    PilaLE<Carta> vPilaConjuntos[7];

    //Le doy memoria a cada conjunto
    //for(int i=0; i<7; i++)
    //    vPilaConjuntos[i] = new PilaLE<Carta>;

    //Reparto el mazo en 7 partes desde 1 a 7
    IteradorLista<Carta> itrMazo = mazoCombinado.getIterador();
    while(itrMazo.valido())
    {
        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[0].count() < 1)
        {
            vPilaConjuntos[0].push(carta);
            mazoCombinado.pop();
        }

        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[1].count() < 2)
        {
            vPilaConjuntos[1].push(carta);
            mazoCombinado.pop();
        }

        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[2].count() < 3)
        {
            vPilaConjuntos[2].push(carta);
            mazoCombinado.pop();
        }

        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[3].count() < 4)
        {
            vPilaConjuntos[3].push(carta);
            mazoCombinado.pop();
        }

        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[4].count() < 5)
        {
            vPilaConjuntos[4].push(carta);
            mazoCombinado.pop();
        }

        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[5].count() < 6)
        {
            vPilaConjuntos[5].push(carta);
            mazoCombinado.pop();
        }

        Carta carta = mazoCombinado.top();
        if(vPilaConjuntos[6].count() < 7)
        {
            vPilaConjuntos[6].push(carta);
            mazoCombinado.pop();
        }
    }
    mostrarConjuntos(vPilaConjuntos, 7);

    //Bucle principal del juego
    do
    {
        //Muestro cada uno de los 7 conjuntos
        mostrarConjuntos(vPilaConjuntos, 7);

        //Pregunto si quiero sacar una carta del mazo
        char r;
        printf("\nDesea sacar una carta del mazo (S/N): ");
        scanf("%s", &r);
        if(r == 'S')
        {
            //Saco la carta y la paso al mazo de cartas abiertas
            Carta carta = mazoCombinado.top();
            mazoAbierto.push(carta);
            mazoCombinado.pop();
        }

        //Pregunto si deseo obtener una carta del mazo abierto
        printf("\nDesea obtener la carta del mazo abierto (S/N): ");
        scanf("%s", &r);
        if(r == 'S')
        {
            Carta carta = mazoAbierto.top();

            //Pregunto a que conjunto de cartas quiero mover esta carta
            int conDestino = 0;
            printf("\nIndique el numero del conjunto al que quiere asignar la carta: ");
            scanf("%d", &conDestino);
            conDestino--;

            //Obtengo la carta del conjunto destino para comparar
            Carta cartaDestino = vPilaConjuntos[conDestino].top();

            //Verifico que sea válido el movimiento
            if(movimientoValido(carta, cartaDestino))
            {
                mazoAbierto.pop();
                vPilaConjuntos[conDestino].push(carta);
            }
            else
            {
                printf("\nMovimiento invalido--------------");
            }

        }

        //Pregunto de que conjunto quiere mover carta y a que conjunto quiere moverla
        int conOrigen=0, conDestino=0;

        printf("\nIndique el numero del conjunto del que quiere sacar la carta: ");
        scanf("%d", &conOrigen);

        printf("\nIndique el numero del conjunto al que quiere asignar la carta: ");
        scanf("%d", &conDestino);

        conOrigen--;
        conDestino--;

        //Saco las cartas tope de cada conjunto para verificar si es valido el cambio
        Carta cartaOrigen  = vPilaConjuntos[conOrigen].top();
        Carta cartaDestino = vPilaConjuntos[conDestino].top();

        //Verifico que sea válido el movimiento
        if(movimientoValido(cartaOrigen, cartaDestino))
            cambiarCarta(vPilaConjuntos, 7, conOrigen, conDestino);
        else
            printf("\nMovimiento invalido--------------");
    }while(mazoCombinado.count() > 0);
    return 0
}

//Verificar si una carta es valida en un conjuto de cartas
bool movimientoValido(Carta carta, Carta cartaSuperior)
{
	return (carta.getValor()+1==cartaSuperior.getValor() || carta.getValor()-1==cartaSuperior.getValor())
}

//Verificar si un conjunto esta completo
bool conjuntoCompleto(PilaLE<Carta> conjunto)
{
	return conjunto.count() == 13;
}

//Verificar si el mazo esta vacio
bool mazoVacio(Cola mazo)
{
	return mazo.count()==0;
}

void mostrarConjunto(PilaE<Carta> conjunto)
{
    IteradorLista<Carta> itr = conjunto.getIterador();
    while(itr.valido())
    {
        Carta carta = itr.info();
        if(carta.getValor() > 1 && carta.getValor() < 11)
            printf("%s-%d", carta.getFigura(), carta.getValor());
        else
            if(carta.getValor() == 1)
                printf("%s-A", carta.getFigura());
            else
                if(carta.getValor() == 11)
                    printf("%s-J", carta.getFigura());
                else
                    if(carta.getValor() == 12)
                        printf("%s-Q", carta.getFigura());
                    else
                        if(carta.getValor() == 13)
                            printf("%s-K", carta.getFigura());
    }
}

void mostrarConjuntos(PilaE<Carta>* conjuntos, int cConjuntos)
{
    for(int i=0; i<cConjuntos; i++)
        mostrarConjunto(conjuntos[i]);
}

bool cambiarCarta(PilaLE<Carta>* conjuntos, int cConjuntos, int conjuntoOrigen, int conjuntoDestino)
{
    if(limitesValidos(conjuntoOrigen, conjuntoDestino))
    {
        Carta cartaOrigen = conjuntos[conjuntoOrigen].top();
        conjuntos[conjuntoDestino].push(cartaOrigen);
        conjuntos[conjuntoOrigen].pop();
        return true;
    }
    return false;
}

bool limitesValidos(int conjuntoOrigen, int conjuntoDestino)
{
    return ((conjuntoOrigen >=0 && conjuntoOrigen <7) && (conjuntoDestino >=0 && conjuntoDestino <7));
}
