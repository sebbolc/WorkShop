/*
 * VehicleTest.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: root
 */

#include <boost/test/unit_test.hpp>
#include "Vehicle.h"

BOOST_AUTO_TEST_SUITE( CVehicleSuite )
CVehicleFactory oVehicleFactory;
CVehicleShPtr poVehicleShPtr;

BOOST_AUTO_TEST_CASE( CreateVehicleTest )
{
	poVehicleShPtr = oVehicleFactory.CreateVehicle( "ABC123", eCar );
	BOOST_CHECK( poVehicleShPtr != NULL );
	if( poVehicleShPtr )
	{
		BOOST_CHECK( poVehicleShPtr->GetType() == eCar );
		BOOST_CHECK( poVehicleShPtr->GetRegistrationNr() == "ABC123" );
	}

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "789", eTruck );
	BOOST_CHECK( poVehicleShPtr != NULL );
	if( poVehicleShPtr )
	{
		BOOST_CHECK( poVehicleShPtr->GetType() == eTruck );
		BOOST_CHECK( poVehicleShPtr->GetRegistrationNr() == "789" );
	}

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "", eTruck );
	BOOST_CHECK( poVehicleShPtr == NULL );

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "789", EVehicleType( 88 ) );
	BOOST_CHECK( poVehicleShPtr == NULL );
}
BOOST_AUTO_TEST_SUITE_END()
