//http://www.learncpp.com/cpp-tutorial/43-static-duration-variables/
/*
 *Il seguente programma indata la keyword static
 * */

//NB il significato di "static" dipende dal contesto nella quale viene usato ed è opposto a "dinamic"

#include<iostream>

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

int main(){
    incrementaAndStampa();
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
    }
};
