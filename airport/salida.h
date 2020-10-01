
#ifndef __salida_H
#define __salida_H

#include <list>

#include "atomic.h"     // class Atomic

class salida : public Atomic
{
public:
        salida( const string &name = "salida" );                                  //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        const Port &in1;
        const Port &in2;
        const Port &in3;
        const Port &in4;
        Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

      
      
};      // class salida

// ** inline ** // 
inline
string salida::className() const
{
        return "salida" ;
}


#endif   //__salida_H
