/*
 * ToolSetTest.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: root
 */

#include <boost/test/unit_test.hpp>
#include "Tool.h"

BOOST_AUTO_TEST_SUITE( ToolSetFactorySuite )

CToolSetFactory oToolSetFactory;
CToolSetShPtr poToolSetShPtr;

BOOST_AUTO_TEST_CASE( CreateToolSetTest )
{
	poToolSetShPtr = oToolSetFactory.CreateToolSet( eCar );
	BOOST_CHECK( poToolSetShPtr != NULL );
	if( poToolSetShPtr )
	{
		BOOST_CHECK( poToolSetShPtr->GetHandledVehicleType() == eCar );
	}

	poToolSetShPtr = oToolSetFactory.CreateToolSet( eTruck );
	BOOST_CHECK( poToolSetShPtr != NULL );
	if( poToolSetShPtr )
	{
		BOOST_CHECK( poToolSetShPtr->GetHandledVehicleType() == eTruck );
	}

	poToolSetShPtr = oToolSetFactory.CreateToolSet( eUndefined );
	BOOST_CHECK( poToolSetShPtr == NULL );


	poToolSetShPtr = oToolSetFactory.CreateToolSet( EVehicleType( 60 ) );
	BOOST_CHECK( poToolSetShPtr == NULL );
}
BOOST_AUTO_TEST_SUITE_END()


