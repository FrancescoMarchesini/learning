#include <iostream>
//-----------------------------------------------------------------------
//il problema del diamante-----------------------------------------------
//-----------------------------------------------------------------------

class PoweredDevice
{
public:
    PoweredDevice(int Power)
    {
        std::cout<<"Poweder Device = " << Power << "\n";
    }
};

class Scanner:public PoweredDevice
{
public:
    Scanner(int scanner, int power):PoweredDevice(power)
    {
        std::cout<<"Scanner = " << scanner <<"\n";
    }
};

class Printer:public PoweredDevice
{
public:
    Printer(int printer, int power):PoweredDevice(power)
    {
        std::cout<<"Scanner = " << printer <<"\n";
    }
};

class Copier:public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        :Scanner(scanner, power), Printer(printer, power){}
};



//---------------------------------------------------------------
//copier -> Printer -> PoweredDevice
//copier -> Scanner -> powerderDevice
//come si vede dalla classe figlio copier vengono create due instanze della classe
//powerDevice
//------------------------------------------------------------

//se non si vuole ciò, ma si vuole che ci sia una sola classe powerDevice condiva fare come segue
class PoweredDevice2
{
public:
    PoweredDevice2(int Power)
    {
        std::cout<<"Poweder Device = " << Power << "\n";
    }
};

class Scanner2:virtual public PoweredDevice2
{
public:
    Scanner2(int scanner, int power):PoweredDevice2(power)
    {
        std::cout<<"Scanner = " << scanner <<"\n";
    }
};

class Printer2:virtual public PoweredDevice2
{
public:
    Printer2(int printer, int power):PoweredDevice2(power)
    {
        std::cout<<"Scanner = " << printer <<"\n";
    }
};

class Copier2:public Scanner2, public Printer2
{
public:
    Copier2(int scanner, int printer, int power)
        :Scanner2(scanner, power), Printer2(printer, power), PoweredDevice2(power){} //è l'instnaza ultima che costruisci l'oggetto base !!!!
};

int main()
{
    Copier copier(1,2, 3);
    Copier2 copier2(1, 2, 3);
}

