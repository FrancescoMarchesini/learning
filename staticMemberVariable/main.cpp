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

