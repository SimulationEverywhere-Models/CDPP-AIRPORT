
/** include files **/
#include <string>

/** my include files **/
#include "deposito.h"      // class deposito
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: deposito
* Description: 
********************************************************************/
deposito::deposito( const string &name )
: Atomic( name )
, in( this->addInputPort( "in" ) )
, out( this->addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 0 )
{
}



/*******************************************************************
* Function Name: initFunction

* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &deposito::initFunction()
{
       
        elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &deposito::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
                elements.push_back( msg.value() ) ;
                                this->holdIn( active, preparationTime);
        }


	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &deposito::internalFunction( const InternalMessage & )
{
        this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &deposito::outputFunction( const InternalMessage &msg )
{

                if( elements.size() > 0 )
		  { this->sendOutput( msg.time(), out, elements.front() ) ;
			elements.pop_front() ;
       
		  }
        return *this ;
}
