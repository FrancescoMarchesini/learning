#include <iostream>


class Base
{
protected:
       int m_value;
public:
       Base(int value):m_value(value){}
       const char* getName(){return "Base";}
       int getValue(){return m_value;}
};

class Derived: public Base
{
public:
    Derived(int value):Base(value){}
    const char* getName(){return "Derived";}
    int getValueDouble(){return m_value * 2;}
};
////////////////////////////////////////////////////////////////////
//Esempio pratico del motivo della necessità delle classi virtuali//
////////////////////////////////////////////////////////////////////
class Animale
{
protected:
    std::string m_nome;
    const char* m_dice;
    Animale(std::string nome, const char* dice):m_nome(nome), m_dice(dice){}
public:
    std::string getNome(){return m_nome;}
    const char* dice(){return m_dice;}
};

class Gatto: public Animale
{
public:
    Gatto(std::string nome):Animale(nome, "MIAOOO"){}
};

class Cane: public Animale
{
public:
    std::string nome;
    Cane(std::string nome):Animale(nome, "BAUUU"){}
};

////////////////////////////////////////////////
//main entry point
////////////////////////////////////////////////
int main()
{
    //Posso instanziare la classe Derived e sia con i puntatori che con le refernce accedere alla Classe Base
    //Istanzio classe derived e printo i valori della classe
    Derived derived(5);
    std::cout<<"derived is a "<<derived.getName() << " and has value " << derived.getValue() << "\n";

    //Istanzio classe derived come reference e printo i valori della classe
    Derived &rDerived = derived;
    std::cout<<"rDerived is a "<<rDerived.getName() << " and has value " << rDerived.getValue() << "\n";

    //Istanzio classe derived come pointer e printo i valori della classe
    Derived *pDerived = &derived;
    std::cout<<"pDerived is a "<<pDerived->getName() << " and has value " << pDerived->getValue() << "\n";

    //Puo il c++ fare l'opposto ovvero tramite puntatore o indirizzo di memoria accedere alla classe derivata
    //tramite la classe Base? yes we can
    Base &rBase = derived;
    Base *pBase = &derived;
    std::cout<<"derived is a "<<derived.getName() << " and has value " << derived.getValue() << "\n";

    //Istanzio classe derived come reference e printo i valori della classe
    std::cout<<"rBase is a "<<rBase.getName() << " and has value " << rBase.getValue() << "\n";

    //Istanzio classe derived come pointer e printo i valori della classe
    std::cout<<"pBase is a "<<pBase->getName() << " and has value " << pBase->getValue() << "\n";

    /////////////////////////////////////////////////////////////////////////////////////////////////
    Gatto gatto("micio");
    std::cout<<"il nome del Gatto è "<<gatto.getNome() << " e dice " << gatto.dice() << "\n";

    Cane cane("cane");
    std::cout<<"il nome del Cane è "<<cane.getNome() << " e dice " << cane.dice() << "\n";

    Animale *pAnimale = &gatto;
    std::cout<<"L'animale che punta all'indizzo di memoria del gatto si chiama "<<pAnimale->getNome() << " e dice " << pAnimale->dice() << "\n";

    pAnimale = &cane;
    std::cout<<"Lo stesso animale che però punta all'indizzo di memoria del cane si chiama "<<pAnimale->getNome() << " e dice " << pAnimale->dice() << "\n";

    Gatto fred("Fred"), misty("Misty"), zeke("Zeke");
    Cane  garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
    Animale *animali[] = {&fred, &misty, &zeke, &garbo, &pooky, &truffle};
    for(int i = 0; i <6; i++)
        std::cout<<"L'animale che punta all'indizzo di memoria dell'istanza si chiama "<<animali[i]->getNome() << " e dice " << animali[i]->dice() << "\n";

    return 0;
}
