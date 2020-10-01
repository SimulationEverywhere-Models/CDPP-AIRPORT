#ifndef __control_H
#define __control_H


#include "atomic.h"     // class Atomic

class control : public Atomic
{
public:
        control( const string &name = "control" );                                  //Default constructor
	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        const Port &in_a; // Port de entrada de avion aterriza 
        const Port &in_d; // Port de entrada de avion despega
        Port &done_a      ;     //  Port de Salida en
        Port &done_d      ;     //  Port de Salida en
        Port &aterriza      ;     //  Port de Salida 
        Port &despega      ;     //  Port de Salida 
        Port &stop_d      ;     //  Port de Salida en
        Port &stop_a ;     //  Port de Salida 

       Time tiempo_aterrizaje;

       float avion_numero;       // el identificador del Avion

};      // class control

// ** inline ** // 
inline
string control::className() const
{
        return "control" ;
}


#endif   //__control_H
