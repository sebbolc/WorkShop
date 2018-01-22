/*
 * GarageTest.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: root
 */

#include <boost/test/unit_test.hpp>
#include "Garage.h"
#include "CarRepairManager.h"

BOOST_AUTO_TEST_SUITE( CGarageSuite )

static string oTruckRegistrationNr = "3456";
static string oCarRegistrationNr = "123";

struct SGarageTestStruct
{
	SGarageTestStruct() : oGarage( &oCarRepairManager )
	{
		poWorkerShPtr = oWorkerFactory.CreateWorker( eCar );
		poToolSetShPtr = oToolSetFactory.CreateToolSet( eCar );
		poCarShPtr = oVehicleFactory.CreateVehicle( oCarRegistrationNr, eCar );
		poTruckShPtr = oVehicleFactory.CreateVehicle( oTruckRegistrationNr, eTruck );
		oCarRepairManager.AddWorker( poWorkerShPtr );
		oCarRepairManager.AddToolSet( poToolSetShPtr );
	}

	CCarRepairManager oCarRepairManager;
	CGarage oGarage;

	CVehicleFactory oVehicleFactory;
	CVehicleShPtr poCarShPtr, poTruckShPtr;
	CWorkerFactory oWorkerFactory;
	CWorkerShPtr poWorkerShPtr;
	CToolSetFactory oToolSetFactory;
	CToolSetShPtr poToolSetShPtr;
} oSGarageTestStruct;



BOOST_AUTO_TEST_CASE( AddVehicleToRepairTest )
{
	BOOST_CHECK( oSGarageTestStruct.oGarage.AddVehicleToRepair( oSGarageTestStruct.poCarShPtr ) );
	BOOST_CHECK( oSGarageTestStruct.oGarage.AddVehicleToRepair( oSGarageTestStruct.poTruckShPtr ) == false );
}

BOOST_AUTO_TEST_CASE( GetVehicleTest )
{
	CVehicleShPtr poVehicleShPtr;

	poVehicleShPtr = oSGarageTestStruct.oGarage.GetVehicle( oTruckRegistrationNr );
	BOOST_CHECK( poVehicleShPtr == NULL );

	poVehicleShPtr = oSGarageTestStruct.oGarage.GetVehicle( oCarRegistrationNr );
	BOOST_CHECK( poVehicleShPtr != NULL );
	if( poVehicleShPtr != NULL )
	{
		BOOST_CHECK( poVehicleShPtr->GetRegistrationNr() == oSGarageTestStruct.poCarShPtr->GetRegistrationNr() );
		BOOST_CHECK( poVehicleShPtr->GetType() == oSGarageTestStruct.poCarShPtr->GetType() );
	}
}

BOOST_AUTO_TEST_CASE( GetRepairingVehiclesMap )
{
	CVehiclesMap* poVehiclesMap = NULL;

	poVehiclesMap = oSGarageTestStruct.oGarage.GetRepairingVehiclesMap();
	BOOST_CHECK( poVehiclesMap != NULL );
	if( poVehiclesMap != NULL )
	{
		BOOST_CHECK( poVehiclesMap->count( oTruckRegistrationNr ) == 0 );
		BOOST_CHECK( poVehiclesMap->count( oCarRegistrationNr ) == 1 );
	}
}

BOOST_AUTO_TEST_CASE( RemoveVehicleFromRepair )
{
	CVehiclesMap* poVehiclesMap = NULL;

	BOOST_CHECK( oSGarageTestStruct.oGarage.RemoveVehicleFromRepair( oTruckRegistrationNr ) == false );
	BOOST_CHECK( oSGarageTestStruct.oGarage.RemoveVehicleFromRepair( oCarRegistrationNr ) == true );

	poVehiclesMap = oSGarageTestStruct.oGarage.GetRepairingVehiclesMap();
	BOOST_CHECK( poVehiclesMap != NULL );
	if( poVehiclesMap != NULL )
	{
		BOOST_CHECK( poVehiclesMap->count( oTruckRegistrationNr ) == 0 );
		BOOST_CHECK( poVehiclesMap->count( oCarRegistrationNr ) == 0 );
	}
}

BOOST_AUTO_TEST_SUITE_END()
