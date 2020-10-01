
/** include files **/
#include <string>

/** my include files **/
#include "salida.h"      // class salida
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: salida
* Description: 
********************************************************************/
salida::salida( const string &name )
: Atomic( name )
, in1( this->addInputPort( "in1" ) )
, in2( this->addInputPort( "in2" ) )
, in3( this->addInputPort( "in3" ) )
, in4( this->addInputPort( "in4" ) )
, out( this->addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 0 )
{
}



/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &salida::initFunction()
{
        elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &salida::externalFunction( const ExternalMessage &msg )
{
        if( msg.port() == in1 )
	{
		elements.push_back( msg.value() ) ;
                                this->holdIn( active, preparationTime);
        }
        if( msg.port() == in2 )
	{
		elements.push_back( msg.value() ) ;
                                this->holdIn( active, preparationTime);
        }
        if( msg.port() == in3 )
	{
		elements.push_back( msg.value() ) ;
                                this->holdIn( active, preparationTime);
        }
        if( msg.port() == in4 )
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
Model &salida::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &salida::outputFunction( const InternalMessage &msg )
{

		if( elements.size() > 0 )
		  { this->sendOutput( msg.time(), out, elements.front() ) ;
			elements.pop_front() ;
       
		  }
        return *this ;
}
