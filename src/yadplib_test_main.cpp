//yadplib tests

#include <iostream>
#include <observer.h>


using namespace std;



class Subject : public yadplib::behavior::observer::AbstractObserverSubject<Subject>
{
public:
	virtual ~Subject()
	{
	}

	void doChange()
	{
		this->notifyListners( this );
	}

};

class Observer : public yadplib::behavior::observer::AbstractObserver<Subject>
{
public:
	virtual void notify( const Subject * obj )
	{
		std::cout << "notify called" << std::endl;
	}

	void doAnotherStuf()
	{
		std::cout << "do" << std::endl;
	}
	virtual ~Observer()
	{
	}
};


int main()
{
	Subject s;
	Observer o;
	s.registerObserver( &o );
	s.doChange();
	s.removeObserver( &o );
	o.doAnotherStuf();
	cout << "" << endl; // prints 
	return 0;
}
