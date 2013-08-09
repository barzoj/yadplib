//
//  AbstractObserverSubject.h

#ifndef AbstractObserverSubject_h
#define AbstractObserverSubject_h

#include <list>
#include "AbstractObserver.h"

namespace yadplib
{
namespace behavior
{
namespace observer
{
    template <typename ObserverTypeSubject> class AbstractObserverSubject
    {
    protected:
        std::list<yadplib::behavior::observer::AbstractObserver< ObserverTypeSubject> *> m_observers;
        
        virtual void notifyListners( const ObserverTypeSubject * obj )
        {
            for ( typename std::list<AbstractObserver< ObserverTypeSubject> *>::iterator it = m_observers.begin(); it != m_observers.end(); ++it )
            {
                (*it)->notify( obj );
            }
        }
    public:
        AbstractObserverSubject() : m_observers()
        {
        }
        virtual void registerObserver( AbstractObserver< ObserverTypeSubject> * const observer  )
        {
            this->m_observers.push_back( observer );
        }
        
        virtual void removeObserver(  AbstractObserver< ObserverTypeSubject> * const observer )
        {
        	this->m_observers.remove( observer );
            return;
        }
        
        virtual ~AbstractObserverSubject() {}

    };
}
}
}
#endif
