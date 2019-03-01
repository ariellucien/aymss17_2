#include<iostream>
using namespace std;

class Product
{
public:
    void operation()
    {
        cout <<"estoy en operación";
    }
    void operation2()
    {
        cout <<"estoy en operación 2";
    }   
};

class Creator
{
private:
    virtual Product* createProduct(int type) = 0;
public:
    Product* factoryMethod(int type)
    {
        Product *p = createProduct(type);
        p->operation();
        return p;
    }
};

class CreatorA : public Creator
{
public:
    Product* createProduct(int type)
    {
        if(type == 1)
        {
            return new Product;
        }
    }
};

int main()
{
    //Creator debería se un singleton
    //Creator concretos con constructor privado
    Creator* c = new CreatorA;
    Product* p = c->factoryMethod(2);
    p->operation2();

    delete p;
    delete c;
}