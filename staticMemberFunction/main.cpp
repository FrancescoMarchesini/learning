//http://www.learncpp.com/cpp-tutorial/43-static-duration-variables/
/*
 *Il seguente programma indata la keyword static
 * */

//NB il significato di "static" dipende dal contesto nella quale viene usato ed è opposto a "dinamic"

#include<iostream>
#include <array>
#include<vector>

//durata automatica(default)
void incrementaAndStampa(){
    int valore = 0; //durata automatica di default
    ++valore;
    std::cout << valore << std::endl;
} // la variabile "valore" è distrutta qui

//ogni volta che incrementaAndStampa() è chiamata
//la variabile "valore" è:
//  creata
//  incrementata
//  distrutta poichè fuori dalla scopo

//static duration(usando "static")

void incrementaAndStampaStatic(){
    int static s_valore = 0; //durata static, questa line è eseguita una volta
    ++s_valore;
    std::cout << s_valore << std::endl;
} // la variabile "valore" non è distrutta qui, ma diventa inaccesibile
//"s_value" è creato e inizializzato a 1 una sola volta.
//quando esce dalla scopo non è distrutto.
//e quindi il valore permane

//uno degli utilizzi primaria dell'utilizzo di una variabile statica è
//la generazione di indentificatori univoci.
int generatoreID(){
    static int s_itemID = 0;
    return s_itemID++; //faccio una copia di s_itemID, incremento il vero s_itemID, poi ritorno il valore copia
}


//http://www.learncpp.com/cpp-tutorial/811-static-member-variables/
//il secondo significato di static:
//applicato ad una varibile globale da ad essa un "link interno" (internal linkage)
//overo riduce il suo uso e vista al solo file nella quale è richimata

/*
 * Static member variable
 * */

//variabile global
class Qualcosa
{
public:
    int m_valore = 1;
};

//varible global definita static
//l'oggetto statico è condiviso tra tutte le istanze della classe
class QualcosaDiStatico
{
public:
    int static m_valore;
};

//Definendo una variabile statica all'interno di una classe definiamo
//semplicemente che questa esiste. Essendo che la varibile statica non appartiene
// a nessuna instanza particolare, oggetto, questa deve essere dicharata globalmente
// e inizializzata quando il programma inizia.
int QualcosaDiStatico::m_valore;// = 1;
//la linea precende a due fini:
//  1:istanziare la variabile
//  2:inizializzare la varibile (0 defualt se la non inzializzata)

//inizializzazione inline di varibile statiche all'interno della classe
//è possibile farlo quando la varibile statica è costante (const)
//c++ static constexpr ...
//utilità:?
// generatore di ID unici per ogni instanza della classe
class QualcosaDiStaticoUnico
{
private :
    static int s_idGeneratore;
    int m_id;
public:
    QualcosaDiStaticoUnico(){ m_id = s_idGeneratore++;} // prendi il valore succesivo dal generatore di id
    int getID() const {return m_id;}
};

//posso accedere alla varibile fuori dalla classe anche sela variabile è private
// e inizializzare i generatore di ID a 0
int QualcosaDiStaticoUnico::s_idGeneratore; // inizializzo ID generator

int main(){
 /*
  * incrementaAndStampa();
    incrementaAndStampa();
    incrementaAndStampa();
    incrementaAndStampaStatic();
    incrementaAndStampaStatic();
    incrementaAndStampaStatic();
    std::cout << "ID: " << generatoreID() << std::endl;

    int i = 10;
    while (i != 0){
        std::cout << "ID: " << generatoreID() << std::endl;
        --i;
    }//s_itemID maniente il suo valore su multiple chiamate di funzione
**/
    /*
     * Secondo Significato di "static"
     * */

    //istazio due oggetti ognuno dei quali ha una copia di "m_valoe"
    Qualcosa Uno;
    Qualcosa Due;
    //istazio due oggetti essi condiveranno la variabile statica
    QualcosaDiStatico s_uno;
    QualcosaDiStatico s_due;

    //assegno valore alle varibili
    Uno.m_valore = 2;
    s_uno.m_valore = 3;

    //ognuna della due varibile "m_valore" è distanta
    std::cout<< "una varibile globale: " << Uno.m_valore << std::endl;
    std::cout<< "una varibile globale: " << Due.m_valore << std::endl;
    //Due instanze distinte che condividono una varibile
    std::cout<< "una varibile globale statica: " << s_uno.m_valore << std::endl;
    std::cout<< "una varibile globale statica: " << s_due.m_valore << std::endl;

    //una variabile globale statica può essere usata senza inizializzare l'oggeto che la possiede
    QualcosaDiStatico::m_valore = 8;
    std::cout<< "una varibile globale statica senza oggetto: " << QualcosaDiStatico::m_valore << std::endl;

    //riferisi alla varibile statica direttamente con il nome della classe piu che con l'oggetto
    //è il metodo più opportuno di maneggiare i membri statici

    //Essendo che la varibile statica globale è condivisa da tutte le possibile
    //instanze della classe, oggetti, questa ad ogni nuovo aggeeto è incrementata
    QualcosaDiStaticoUnico a;
    QualcosaDiStaticoUnico b;
    QualcosaDiStaticoUnico c;
    std::cout<< "Qualcosa di Statico e constante: " << a.getID() << std::endl;
    std::cout<< "Qualcosa di Statico e constante: " << b.getID() << std::endl;
    std::cout<<  "Qualcosa di Statico e constante: " << c.getID() << std::endl;

    //questo comporatamente è molto utile per il debug oggetti multipli all'inteno di una array
    //far vedere a che classe appartengono
    std::vector<QualcosaDiStaticoUnico> s_array(5, QualcosaDiStaticoUnico());
    for (int i =0; i<s_array.size(); i++)
    {
        std::cout << s_array[i].getID() << std::endl;
    }

    return 0;
};

http://www.learncpp.com/cpp-tutorial/812-static-member-functions/
