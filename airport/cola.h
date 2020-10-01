
#ifndef __cola_H
#define __cola_H

#include <list>

#include "atomic.h"     // class Atomic

class cola : public Atomic
{
public:
        cola( const string &name = "cola" );                                  //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &stop;
	const Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;
        int ocupado;
};      // class cola

// ** inline ** // 
inline
string cola::className() const
{
        return "cola" ;
}


#endif   //__cola_H
