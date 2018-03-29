#include <iostream>


class Base
{
public:
    virtual ~Base(){std::cout<<"Cancellato Base"<<"\n";}
    virtual const char * sayWhat(){return "Sono la Base";}
    virtual const char * getName(){return nome;}
protected:
    Base(const char* _nome):nome(_nome){}
    const char* nome;
};

class Derivata: public Base
{
public:
    virtual ~Derivata(){std::cout<<"Cancellato Derviate"<<"\n";}
    Derivata(const char* _nome):Base(_nome){}
    virtual const char *sayWhat() override {return nome;}
    virtual const char *getName() override {return "Sono la Derivata";}
};
//-------------------------------------------------------------------------
//metodi virtuali----------------------------------------------------------
//-------------------------------------------------------------------------
class Animale
{
public:
    virtual ~Animale(){std::cout<<"Cancellato Animale"<<"\n";}
    virtual const char * getName(){return m_nome;}
    virtual const char * diceCosa(){return "???????";}
    const char *cosaDiconoGliAnimali(Animale &Animale);
protected:
    Animale(const char* nome):m_nome(nome){}
    const char* m_nome;
};

const char* Animale::cosaDiconoGliAnimali(Animale &animale)
{
    std::cout<< animale.diceCosa();
}

class Mucca: public Animale
{
public:
    virtual ~Mucca(){std::cout<<"Cancellato Mucca"<<"\n";}
    Mucca(const char* nome):Animale(nome){}
    virtual const char * getName() override {return m_nome;}
    virtual const char * diceCosa() override {return "MUUUUUU";}
};

class Asino: public Animale
{
public:
    virtual ~Asino(){std::cout<<"Cancellato Asino"<<"\n";}
    Asino(const char* nome):Animale(nome){}
    virtual const char * getName() override {return m_nome;}
    virtual const char * diceCosa() {return "IOIOIOIO";}
};

//-------------------------------------------------------------------------
//metodi virtuali puri-----------------------------------------------------
//-------------------------------------------------------------------------
class Genere
{
public:
    virtual ~Genere(){std::cout<<"Cancellato Cosa"<<"\n";}
    virtual void cheCosa() = 0;
protected:
    Genere(const char* tipo, int elementi):m_tipo(tipo), m_elementi(elementi){}
    const char* m_tipo;
    int m_elementi;
};

class Spece:public Genere
{
public:
    virtual ~Spece(){std::cout<<"Cancellato Cosa"<<"\n";}
    Spece(const char* nome, int elementi):Genere(nome, elementi){}
    virtual void cheCosa(){std::cout<<"Non lo so"<<"\n";}
};

int main()
{
    Derivata derivata("Derivata");
    Base &base = derivata;
    std::cout<< "--Chi sono ? " << base.getName() << " --" << " Cosa dico ? " << base.sayWhat() << "\n";
    std::cout<< "--Chi sono ? " << derivata.getName() << " --" << " Cosa dico ? " << derivata.sayWhat() << "\n";
    std::cout<<"---------------------------------------------------------"<<"\n";
    //Animale animale("Animale"); //Questo non posso chiamarlo direttamente perchè è protetto quindi devo derivare
    Asino asino("Asino");
    Mucca mucca("Mucca");
    Animale &animale = asino;
    Animale *pAnimale = &mucca;
    std::cout<< "--Chi sono ? " << animale.getName() << " --" << " Cosa dico ? " << animale.cosaDiconoGliAnimali(asino) << "\n";
    std::cout<< "--Chi sono ? " << pAnimale->getName() << " --" << " Cosa dico ? " << pAnimale->diceCosa() << "\n";
    std::cout<< "--Chi sono ? " << asino.getName() << " --" << " Cosa dico ? " << asino.diceCosa() << "\n";
    std::cout<< "--Chi sono ? " << mucca.getName() << " --" << " Cosa dico ? " << animale.cosaDiconoGliAnimali(mucca) << "\n";
    std::cout<<"---------------------------------------------------------"<<"\n";

    Asino asino1("Un Asino"), asino2("Un Secondo Asino"), asino3("Un Terzo Asino"), asino4("Un Quarto Asino");
    Mucca mucca1("Una Mucca"), mucca2("Una Seconda Mucca"), mucca3("Una Terza Mucca"), mucca4("Una Quarta Mucca");

    Animale *Animali[] = {&asino1, &asino2, &asino3, &asino4, &mucca1, &mucca2, &mucca3, &mucca4};
    for(int i = 0 ; i < 8; i ++)
    {
        std::cout<< "--Chi sono ? " << Animali[i]->getName() << " --" << " Cosa dico ? " << Animali[i]->diceCosa() << "\n";
    }

    //-------------------------------------------------------------------------------------------------
    Spece spece("Cosa", 100);
    spece.cheCosa();
    //---------------------------------------------------------------------------------------------------
    return 0;
}
