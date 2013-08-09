//
//  AbstractObserver.h
//  happiOdds
//
//  Created by iddqd on 8/9/13.
//
//

#ifndef AbstractObserver_h
#define AbstractObserver_h

#include <iostream>
#include <list>

namespace yadplib
{
namespace behavior
{
namespace observer
{
   template <typename AbstractSubject> class AbstractObserver
    {
    public:
        virtual void notify( const AbstractSubject * obj ) = 0;
        virtual ~AbstractObserver() {}
    };
}
}
}

#endif /* defined(__happiOdds__AbstractObserver__) */
