#pragma once

#include<iostream>
#include<atomic>
#include<optional>
#include<vector>

using namespace std;

class IBase
{

public:
    virtual void fun() = 0;
};

template<typename T>
class Base : public IBase
{
public:
    void fun()
    { 
        cout << "from base Fun"<<endl;
        (static_cast<T*> (this))->funi();
    }

};

class Derived : public Base<Derived>
{
public:
    void funi(){ cout << "Derived Fun"<<endl;}
};

template<typename T>
void crtpFun(Base<T> *obj)
{
    obj->fun();
}


void crtpFun(vector<IBase*> &data)
{
    for(auto &itr: data)
    {
        itr->fun();
    }
}

void crtp()
{
    Derived d;
    crtpFun(&d);

    vector<IBase*> data;
    data.emplace_back(&d);
    crtpFun(data);

}



