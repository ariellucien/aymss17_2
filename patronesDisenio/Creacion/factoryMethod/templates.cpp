#include<iostream>
using namespace std;

class FactoryProduct
{
public:
    template<class Prod>
    Prod* factoryMethod()
    {
        return new Prod;
    }
};
class ProductA : public FactoryProduct
{
public:
    void operation()
    {
        cout << "estoy en el producto A";
    }
};
int main()
{
    FactoryProduct* p = new FactoryProduct;
    ProductA *a = p->factoryMethod<ProductA>(); 
    a->operation();
}