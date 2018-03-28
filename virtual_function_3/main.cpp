#include <iostream>

//quando si ha a che fare con l'eredietarietà bisogna sempre mettere il distruttore della classe
//come virtuale in modo da cancellare anche le cose delle classi base

class Base
{
public:
    virtual ~Base()
    {
        std::cout<< "Chiamo il Distruttore ~Base()"<<std::endl;
    }
};

class Derivata: public Base
{
private :
    int* m_array;
public:
    Derivata(int lenght)
    {
        m_array = new int[lenght];
    }

    virtual ~Derivata()
    {
        std::cout<<"Chiamo il Distruttore ~Derivato()"<<std::endl;
        delete[] m_array;
    }
};


int main()
{
    Derivata *derivata = new Derivata(5);
    Base *base = derivata;
    delete base;
    return 0;
}
