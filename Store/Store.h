#ifndef ZAD3_H_INCLUDED
#define ZAD3_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

const int MAX = 100;

class Product // shirt
{
    public:
        Product(int = 0, const char* = "", const char* = "", double = 0.0, unsigned = 0, unsigned = 0);
        Product(const Product&);
        Product& operator=(const Product&);
        ~Product();
        int getSKU() const;
        char* getBrand() const;
        char* getModel() const;
        double getPrice() const;
        unsigned getCountPr() const;
        unsigned getSizePr() const;
        void setSKU(int _SKU);
        void setBrand(char* _brand);
        void setModel(char* _model);
        void setPrice(double _price);
        void setCountPr(unsigned _countPr);
        void setSizePr(unsigned _sizePr);
        void create(Product& pr);
        void read();
        void readWithoutSKU();
        void print()const;
        friend istream& operator>>(istream& is, Product& pr)
        {
            cout<<"SKU of the product: ";
            is>>pr.SKU;
            cin.ignore();
            cout<<"Name of the brand: ";
            is.getline(pr.brand, MAX);
            cout<<"Name of the model: ";
            is.getline(pr.model, MAX);
            cout<<"Price of the product: ";
            is>>pr.price;
            cout<<"Count of the product in the store: ";
            is>>pr.countPr;
            cout<<"Size of the product: ";
            is>>pr.sizePr;
            return is;
        }
        friend ostream& operator<<(ostream& os, const Product& pr)
        {
            os<<"SKU of the product: "<<pr.SKU<<endl;
            os<<"Name of the brand: "<<pr.brand<<endl;
            os<<"Name of the model: "<<pr.model<<endl;
            os<<"Price of the product: "<<pr.price<<endl;
            os<<"Count of the product in the store: "<<pr.countPr<<endl;
            os<<"Size of the product: "<<pr.sizePr<<endl;
            return os;
        }
    private:
        int SKU; // stock keeping unit
        char* brand; // brand
        char* model; // model of the product
        double price; // price of the product
        unsigned countPr; // count of the product in the store
        unsigned sizePr; // size of the shirt
};
Product::Product(int _SKU, const char* _brand, const char* _model, double _price, unsigned _countPr, unsigned _sizePr)
{
    SKU = _SKU;
    brand = new char[strlen(_brand) + 1];
    if(!brand)
    {
        cout<<"Error!"<<endl;
        exit(1);
    }
    strcpy(brand, _brand);
    model = new char[strlen(_model) + 1];
    if(!model)
    {
        cout<<"Error!"<<endl;
        exit(1);
    }
    strcpy(model, _model);
    price = _price;
    countPr = _countPr;
    sizePr = _sizePr;
}
Product::Product(const Product& pr)
{
    SKU = pr.SKU;
    brand = new char[strlen(pr.brand) + 1];
    if(!brand)
    {
        cout<<"Error!"<<endl;
        exit(1);
    }
    strcpy(brand, pr.brand);
    model = new char[strlen(pr.model) + 1];
    if(!model)
    {
        cout<<"Error!"<<endl;
        exit(1);
    }
    strcpy(model, pr.model);
    price = pr.price;
    countPr = pr.countPr;
    sizePr = pr.sizePr;
}
Product& Product::operator=(const Product& other)
{
    if(this != &other)
    {
        delete []brand;
        delete []model;
        SKU = other.SKU;
        brand = new char[strlen(other.brand) + 1];
        if(!brand)
        {
            cout<<"Error!"<<endl;
            exit(1);
        }
        strcpy(brand, other.brand);
        model = new char[strlen(other.model) + 1];
        if(!brand)
        {
            cout<<"Error!"<<endl;
            exit(1);
        }
        strcpy(brand, other.brand);
        price = other.price;
        countPr = other.countPr;
        sizePr = other.sizePr;
    }
    return *this;
}
Product::~Product()
{
    delete []brand;
    delete []model;
}
int Product::getSKU()const
{
    return SKU;
}
char* Product::getBrand()const
{
    return brand;
}
char* Product::getModel()const
{
    return model;
}
double Product::getPrice()const
{
    return price;
}
unsigned Product::getCountPr()const
{
    return countPr;
}
unsigned Product::getSizePr()const
{
    return sizePr;
}
void Product::setSKU(int _SKU)
{
    SKU = _SKU;
}
void Product::setBrand(char* _brand)
{
    delete []brand;
    brand = new char[strlen(_brand) + 1];
    if(!brand)
    {
        cout<<"Error!"<<endl;
        exit(1);
    }
    strcpy(brand, _brand);
}
void Product::setModel(char* _model)
{
    delete []model;
    model = new char[strlen(_model) + 1];
    if(!model)
    {
        cout<<"Error!"<<endl;
        exit(1);
    }
    strcpy(model, _model);
}
void Product::setPrice(double _price)
{
    price = _price;
}
void Product::setCountPr(unsigned _countPr)
{
    countPr = _countPr;
}
void Product::setSizePr(unsigned _sizePr)
{
    sizePr = _sizePr;
}
void Product::create(Product& pr)
{
    cout<<"SKU of the product: ";
    cin>>pr.SKU;
    cin.ignore();
    cout<<"Name of the brand: ";
    brand = new char[MAX];
    cin.getline(pr.brand, MAX);
    cout<<"Name of the model: ";
    model = new char[MAX];
    cin.getline(pr.model, MAX);
    cout<<"Price of the product: ";
    cin>>pr.price;
    cout<<"Count of the product in the store: ";
    cin>>pr.countPr;
    cout<<"Size of the product in the store: ";
    cin>>pr.sizePr;
}
void Product::read()
{
    cout<<"SKU of the product: ";
    cin>>SKU;
    cin.ignore();
    cout<<"Name of the brand: ";
    brand = new char[MAX];
    cin.getline(brand, MAX);
    cout<<"Name of the model: ";
    model = new char[MAX];
    cin.getline(model, MAX);
    cout<<"Price of the product: ";
    cin>>price;
    cout<<"Count of the product in the store: ";
    cin>>countPr;
    cout<<"Size of the product: ";
    cin>>sizePr;
}
void Product::readWithoutSKU()
{
    cin.ignore();
    cout<<"Name of the brand: ";
    brand = new char[MAX];
    cin.getline(brand, MAX);
    cout<<"Name of the model: ";
    model = new char[MAX];
    cin.getline(model, MAX);
    cout<<"Price of the product: ";
    cin>>price;
    cout<<"Count of the product in the store: ";
    cin>>countPr;
    cout<<"Size of the product: ";
    cin>>sizePr;
}
void Product::print()const
{
    cout<<"SKU of the product: "<<SKU<<endl;
    cout<<"Name of the brand: "<<brand<<endl;
    cout<<"Name of the model: "<<model<<endl;
    cout<<"Price of the product: "<<price<<endl;
    cout<<"Count of the product in the store: "<<countPr<<endl;
    cout<<"Size of the product: "<<sizePr<<endl;
}
class Store
{
    public:
        Store();
        Store(int _capacity);
        Store(const Store&);
        Store& operator=(const Store&);
        ~Store();
        int getCurrent();
        int getCapacity();
        Product* getProduct();
        void addPr(const Product&);
        void changePr();
        void removePr();
        void display()const;
    private:
        int current;
        int capacity;
        Product* products;
        void resize()
        {
            Product* helper;
            helper = new Product[capacity];
            for(int i =0 ; i <= current; i++)
                helper[i] = products[i];
            delete [] products;
            capacity *= 2;
            products = new Product[capacity];
            for(int i = 0; i <= current; i++)
                products[i] = helper[i];
            delete [] helper;
        }
        int sku(int num) const
        {
            for (int i = 0; i < current; i++)
            {
                if (products[i].getSKU() == num)
                    return i;
            }
            return -1;
        }
        friend ostream& operator<<(ostream& os, const Store& other)
        {
            if(other.current < 0)
            {
                os<<"There are no products in the store!"<<endl;
            }
            else
            {
                for(int i = 0; i <= other.current - 1; i++)
                {
                    os<<other.products[i];
                }
                return os;
            }
        }
};
Store::Store()
{
    current = 0;
    capacity = 10;
    products = new Product[10];
}
Store::Store(int _capacity)
{
    current = 0;
    capacity = _capacity;
    products = new Product[_capacity];
}
Store::Store(const Store& st)
{
    current = st.current;
    capacity = st.capacity;
    products = new Product[capacity];
    for(int i = 0; i <= capacity - 1; i++)
        products[i] = st.products[i];
}
Store& Store::operator=(const Store& other)
{
    if(this!=&other)
    {
        delete [] products;
        current = other.current;
        capacity = other.capacity;
        products = new Product[capacity];
        for(int i = 0; i <= capacity - 1; i++)
            products[i] = other.products[i];
    }
    return *this;
}
Store::~Store()
{
    delete []products;
}
int Store::getCurrent()
{
    return current;
}
int Store::getCapacity()
{
    return capacity;
}
Product* Store::getProduct()
{
    return products;
}
void Store::addPr(const Product& other)
{
    if(current == capacity)
    {
        resize();
    }
    products[current] = other;
    current++;
    cout<<"The site has been successfully added!"<<endl;
}
void Store::changePr()
{
    if(current < 0)
    {
        cerr<<"There are no items in the store!"<<endl;
        exit(1);
    }
    cout<<"Change product: "<<endl;
    cout<<"Type the SKU of the product: ";
    int skuForChange;
    cin>>skuForChange;
    int skuInStore = sku(skuForChange);
    if(skuInStore >= 0)
    {
        /*for (int i = skuForChange + 1; i < current; i++)
        {
            products[i - 1] = products[i];
        }
        current--; // delete this item*/
        cout<<"Type the new details: "<<endl;
        Product itemtochange;
        itemtochange.setSKU(skuForChange);
        itemtochange.readWithoutSKU();
        products[skuInStore] = itemtochange; // insert new item with new details
        //current++;
        cout<<"This product has been successfully changed!"<<endl;
    }
    else
    {
        cerr<<"No such item!"<<endl;
        exit(1);
    }
}
void Store::removePr()
{
    if(current < 0)
    {
        cerr<<"There are no items in the store!"<<endl;
        exit(1);
    }
    cout<<"Delete product: "<<endl;
    cout<<"Type the SKU of the product: ";
    int nPos;
    cin>>nPos;
    int skuInStore = sku(nPos);
    if(skuInStore >= 0)
    {
        for (int i = nPos + 1; i < current; i++)
        {
            products[i - 1] = products[i];
        }
        current--;
        cout<<"This item is deleted!"<<endl;
    }
    else
    {
        cerr<<"This item is already deleted!"<<endl;
        exit(1);
    }
}
void Store::display()const
{
    cout<<"Display all products in the store: "<<endl;
    if(current < 0)
    {
        cout<<"There are no products in the store!"<<endl;
    }
    else
    {
        for(int i = 0; i <= current - 1; i++)
        {
            cout<<products[i];
        }
    }
}
#endif // ZAD3_H_INCLUDED
