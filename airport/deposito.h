
#ifndef __deposito_H
#define __deposito_H

#include <list>

#include "atomic.h"     // class Atomic

class deposito : public Atomic
{
public:
        deposito( const string &name = "deposito" );                                  //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
      	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;
        
      
      
};      // class deposito

// ** inline ** // 
inline
string deposito::className() const
{
        return "deposito" ;
}


#endif   //__deposito_H
