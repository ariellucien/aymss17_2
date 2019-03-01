#import <iostream>
using namespace std;

class IntIterator;
class IntCollection
{
protected:
    int* array;
    int size;
    int cont;
public:
    IntCollection(){
        size=10;
        array = new int(size);
        cont = 0;
    }
    void addElement(int value)
    {
        if(cont<=size)
        {
            array[cont++] = value;
            return;
        }
        cout << "ya no hay espacio para agregar elementos";
    }
    
    IntIterator* getIterator();

    int at(int pos)
    {
        return array[pos];
    }
};

class IntIterator
{

};