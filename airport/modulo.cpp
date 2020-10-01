/** include files **/
#include <string>

/** my include files **/
#include "modulo.h"      // class modulo
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: modulo
* Description: 
********************************************************************/
modulo::modulo( const string &name )
: Atomic( name )
, despega( this->addInputPort( "despega" ) )
, aterriza( this->addInputPort( "aterriza" ) )
, salida_d( this->addOutputPort( "salida_d" ) )
, salida_a( this->addOutputPort( "salida_a" ) )


{
  /*      string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;

	if( time != "" )
                preparationTime = time ; */
}



/*******************************************************************
* Function Name: initFunction


********************************************************************/
Model &modulo::initFunction()
{
	   avion_numero=0 ;
	   return *this ;
           Pista_en_uso="00:01:00:00";
}


/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &modulo::externalFunction( const ExternalMessage &msg )
{
                if( msg.port() == aterriza )
	{
                                accion = "aterriza";
				avion_numero = msg.value()  ;
                                this->holdIn( active, Pista_en_uso );
	}

                if( msg.port() == despega )
	{
                                accion = "despega";
				avion_numero = msg.value()  ;
                                this->holdIn( active, Pista_en_uso );
	}



	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &modulo::internalFunction( const InternalMessage & )
{
	this->passivate();
		return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &modulo::outputFunction( const InternalMessage &msg )

{
       if (accion == "despega")
                this->sendOutput( msg.time(), salida_d , avion_numero) ;

       if (accion == "aterriza")
                this->sendOutput( msg.time(), salida_a , avion_numero) ;


	return *this ;
}
