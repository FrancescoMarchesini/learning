#include <iostream>


class Base
{
public:
    virtual const char* getName(){return "Base";}
};

class Derived: public Base
{
public:
    virtual const char* getName(){return "Derivata";}
};
////////////////////////////////////////////////////////////////////
//Esempio pratico del motivo della necessità delle classi virtuali//
////////////////////////////////////////////////////////////////////
class Animale
{
protected:
    std::string m_nome;
    Animale(std::string nome):m_nome(nome){}
public:
    std::string getNome(){return m_nome;}
    virtual const char* dice(){return "?????";}
};

///L'utilizzo della keyword Virtual nelle classi derivari da 1 a N non è necesseria
/// però è buona norma metterla per ricordarsi che è vertituale
///
/// Seconda Norma :: MAI chiamre una funzione virtuale nel costruttore e nel distruttore
/// perche per compilare la funzioni virtuali prima si compila la parte della classe Base
/// e quindi può essere che la classe derivato non è ancora costruita.
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
    virtual const char* dice(){return "BAUUU";}
};

//Tramite la funzione virtual si va a prendere l'ultima drivazione della funzioni tra la base e l'ultima
void report(Animale &istanza)
{
   std::cout<<"l'instanza di chiama' "<< istanza.getNome() << " e dice " << istanza.dice() <<"\n";
}

void report2(Animale *istanza)
{
   std::cout<<"l'instanza di chiama' "<< istanza->getNome() << " e dice " << istanza->dice() <<"\n";
}
////////////////////////////////////////////////
//main entry point
////////////////////////////////////////////////
int main()
{
    Derived derivata;
    Base &base = derivata;
    std::cout<<"Il nome della classe Base è "<< base.getName() << "\n";
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
