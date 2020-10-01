
/** include files **/
#include <string>

/** my include files **/
#include "cola.h"      // class cola
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: cola
* Description: 
********************************************************************/
cola::cola( const string &name )
: Atomic( name )
, in( this->addInputPort( "in" ) )
, stop( this->addInputPort( "stop" ) )
, done( this->addInputPort( "done" ) )
, out( this->addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 0 )
{
	string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}



/*******************************************************************
* Function Name: initFunction

********************************************************************/
Model &cola::initFunction()
{
        ocupado=0;
        elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &cola::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		elements.push_back( msg.value() ) ;
                this->holdIn( active, preparationTime );
	}

	if( msg.port() == done )
	{
                ocupado=0;
                this->holdIn( active, preparationTime );
	}

	if( msg.port() == stop )
                 { ocupado=1;
                  this->passivate();
                 }

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &cola::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &cola::outputFunction( const InternalMessage &msg )
{

        if( (elements.size() > 0)  && ocupado==0 )
          { this->sendOutput( msg.time(), out, elements.front() ) ;
            elements.pop_front() ;
          }
        return *this ;
}
