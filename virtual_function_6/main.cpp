#include <iostream>


class Base
{
public:
    const char* diCiao(){return "Ciao";}
    virtual const char* getName(){return "Base";}
    virtual int getValue() = 0; //funzione virtuale pure rende la classe una classe "abstract base class"
};

class Derived: public Base
{
public:
    virtual const char* getName(){return "Derivata";}
};
/////////////////////////////////////////////////////////////////////////
//Esempio pratico del motivo della necessità delle classi virtuali pure//
/////////////////////////////////////////////////////////////////////////
class Animale
{
protected:
    std::string m_nome;
public:
    Animale(std::string nome):m_nome(nome){}
    std::string getNome(){return m_nome;}
    virtual const char* dice() = 0; //funzione virtuale pura
};

//posso dare un corpo alla funzione virtuale pure ma ciò fa si che questa comunque rimanga classe
//astratta e le classi derivate devono implementare la funzione. però le classi derivare possono
//usare l'implementazione della base
const char* Animale::dice()
{
    return "Bella LI";
}

//tutte le classi derivate devono implementare la fuzione virtuale altrimenti saranno anchesse astratte
class Gatto: public Animale
{
public:
    Gatto(std::string nome):Animale(nome){}
    virtual const char* dice(){return "MIAOOO";}
};

class Cane: public Animale
{
public:
    Cane(std::string nome):Animale(nome){}
    virtual const char* dice(){return Animale::dice();}
};

//Tramite la funzione virtual si va a prendere l'ultima drivazione della funzioni tra la base e l'ultima
void report(Animale &istanza)
{
   std::cout<<"l'instanza di chiama' "<< istanza.getNome() << " e dice " << istanza.dice() <<"\n";
}

void report2(Animale *istanza)
{
   std::cout<<"l'instanza si chiama  "<< istanza->getNome() << " e dice " << istanza->dice() <<"\n";
}
////////////////////////////////////////////////
//main entry point
////////////////////////////////////////////////
int main()
{
    //Base base; //questo non posso farlo poichè essendo classe Astratta non puo essere inizializzata!!!!!
    //base.getValue();
    //con le funzioni della classe derivata viene chiamata l'ultima implentazione ovvero la classe derivata

    /////////////////////////////////////////////////////////////////////////////////////////////////
    Gatto gatto("micio");
    report(gatto);

    Cane cane("cane");
    report(cane);

    Animale *pAnimale = &gatto;
    report2(pAnimale);

    pAnimale = &cane;
    report2(pAnimale);

    Gatto fred("Fred"), misty("Misty"), zeke("Zeke");
    Cane  garbo("Garbo"), pooky("Pooky"), truffle("Truffle");
    //Creo un puntatre alla classe base e ci passo gli indirizzi di memoria delle istanze per accedere alle funzoni della classe base
    Animale *animali[] = {&fred, &misty, &zeke, &garbo, &pooky, &truffle};
    for(int i = 0; i <6; i++)
        report2(animali[i]);

    return 0;
}
