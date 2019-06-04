#include <iostream>
using namespace std;
class Felid
{
	public:
		Felid()
		{ 
			cout<<"Felid constructor."<<endl; 
		}
		~Felid()
		{ 
			cout<<"Felid destructor."<<endl; 
		}
		virtual void sound() const
		{ 
			cout<<"Felid sound!"<<endl;
		}	
};
class Cat: public Felid
{
	public:
		Cat()
		{
			cout<<"Cat constructor."<<endl; 
		}
		~Cat()
		{
			cout<<"Cat destructor."<<endl; 
		}
		virtual void sound() const
		{ 
			cout<<"Miaow !"<<endl; 
		}
};
class Leopard: public Felid
{
	public:
		Leopard()
		{ 
			cout<<"Leopard constructor."<<endl; 
		}
		~Leopard()
		{ 
			cout<<"Leopard destructor."<<endl; 
		}
		virtual void sound() const
		{ 
			cout<<"Howl !"<<endl; 
		}
};

int main()
{
	Felid *animal;
	animal = new Cat;
	animal->sound();
	delete animal;

	animal = new Leopard;
	animal->sound();
	delete animal;
	return 0;
}

