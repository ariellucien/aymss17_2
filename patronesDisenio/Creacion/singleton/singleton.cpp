#include<iostream>
using namespace std;

class Singleton
{
private:
    Singleton() = default;
public:
    
    static Singleton* getInstance()
    {
        if(!instance)
        {
            instance = new Singleton;
        }
        return instance;
    }
    void operation()
    {
        cout << "Dir de Sing:" << instance << endl;
    }
protected:
    static Singleton* instance;
};

Singleton* Singleton::instance = 0;

int main(int argc, char** argv)
{
    s.operation();
    Singleton* instance = Singleton::getInstance();
    instance->operation();
    Singleton* instance2 = Singleton::getInstance();
    instance2->operation();
    Singleton* instance3 = Singleton::getInstance();
    instance3->operation();
}
