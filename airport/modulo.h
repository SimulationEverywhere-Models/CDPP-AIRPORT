#ifndef __modulo_H
#define __modulo_H


#include "atomic.h"     // class Atomic

class modulo : public Atomic
{
public:
        modulo( const string &name = "modulo" );                                  //Default constructor
	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        const Port &aterriza; // Port de entrada de avion
        const Port &despega ; // Port de entrada de avion
        Port &salida_a      ; //  Port de Salida en cado de accidente
        Port &salida_d      ; //  Port de Salida en cado de accidente


       string accion;
       Time preparationTime;
       Time Pista_en_uso;



        float  avion_numero;       // el identificador del Avion

};      // class modulo

// ** inline ** // 
inline
string modulo::className() const
{
        return "modulo" ;
}


#endif   //__modulo_H
