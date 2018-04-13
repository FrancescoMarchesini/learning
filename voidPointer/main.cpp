/*
 * Puntatori void, conosciuto anche come "generic pointer"
 * Tale puntatore può puntare a qualsisi tipo di dato
 */
#include <iostream>

struct Qualcosa
{
    int n;
    int f;
};

enum Type
{
    INT,
    FLOAT,
    CSTRING
};

void printValue(void *ptr, Type type);

int main()
{
    Qualcosa sValue;
    int nValue = 6;
    float fValue = 5.f;
    char szValue[] = "bella li";

    void *ptr;
    ptr = &sValue;
    ptr = &fValue;
    ptr = &nValue;

    /* essendo che il void pointer non sa a chi punta,
     * non è possibile deferenziarlo direttamente.
     * Per deferenziarlo serve fare un cast esplito
     */
     int *intPtr = static_cast<int*>(ptr);
     std::cout << "deferenziato il void pointer " << *intPtr << std::endl;

     printValue(&nValue, INT);
     printValue(&fValue, FLOAT);
     printValue(szValue, CSTRING);

     return 0;
}

void printValue(void *ptr, Type type)
{
    switch(type)
    {
        case INT:
            std::cout << *static_cast<int*>(ptr) << '\n';
            break;
        case FLOAT:
            std::cout << *static_cast<float*>(ptr) << '\n';
            break;
        case CSTRING:
            std::cout << static_cast<char*>(ptr) << '\n';
            break;
    }
}
