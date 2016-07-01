#ifndef CARTA_H
#define CARTA_H


class Carta
{
    public:
        Carta(int valor, int codigo, char figura);
        virtual ~Carta();

    //Métodos

	//Getters
		int 	getCodigo() { return Carta::codigo; }
		int 	getValor()  { return Carta::valor; }
		char 	getFigura() { return Carta::figura; }

    protected:
    private:
		int 	valor;
		int 	codigo;
		char 	figura;
};

Carta::Carta(int valor, int codigo, char figura)
{
    Carta::valor  = valor;
    Carta::codigo = codigo;
    Carta::figura = figura;
}

#endif // CARTA_H
