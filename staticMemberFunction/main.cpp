//http://www.learncpp.com/cpp-tutorial/812-static-member-functions/
/*
 *Il seguente programma indagaa le funzioni statiche
 * */

#include<iostream>
#include <array>
#include<vector>

//metodi statici:
//non essendo legati all'instaza ma alla classe
//possono essere chiamati senza instaziare l'oggetto
class Qualcosa
{
private :
    static int s_value;
public:
    static int getValue() {return s_value;}
};

//inizializzo la varibile statiche
int Qualcosa::s_value; // inizializzo ID generator

//i metodi statici non hanno l'operatore this
//i metodi statici possono accedere solo a varibili statiche
//queste due cose perchè l'avorano sulla classe ma non sull'istanza

//i metodi statici possono essere definiti fuori dalla classe
class idGenerator{
private:
    static int s_nextID;
public:
    static int s_getNextID();
};

//iniziliazzo la varibile dichiarata
int idGenerator::s_nextID = 1;

//implemnto la funzione
int idGenerator::s_getNextID(){ return s_nextID++;}

int main(){
    std::cout << "metodo statico : " << Qualcosa::getValue() << std::endl;
    for(int i=0; i<5; i++){
        std::cout << "l'ID successivo è: " << idGenerator::s_getNextID() << std::endl;
    }
    return 0;
};

