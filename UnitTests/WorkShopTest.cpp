/*
 * WorkShopTest.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: root
 */

#include <boost/test/unit_test.hpp>
#include "WorkShop.h"


BOOST_AUTO_TEST_SUITE( CWorkShopSuite )

static string oTruckRegistrationNr = "ABCD3456";
static string oCarRegistrationNr = "DEF123";
static string oFilePathString = "Test.dat";

struct SWorkShopTestStruct
{
	SWorkShopTestStruct()
	{
		poWorkerShPtr = oWorkerFactory.CreateWorker( eCar );
		poToolSetShPtr = oToolSetFactory.CreateToolSet( eCar );
		poCarShPtr = oVehicleFactory.CreateVehicle( oCarRegistrationNr, eCar );
		poTruckShPtr = oVehicleFactory.CreateVehicle( oTruckRegistrationNr, eTruck );

		oWorkShop.AddWorker( poWorkerShPtr );
		oWorkShop.AddToolSet( poToolSetShPtr );
	}

	CVehicleFactory oVehicleFactory;
	CVehicleShPtr poCarShPtr, poTruckShPtr;
	CWorkerFactory oWorkerFactory;
	CWorkerShPtr poWorkerShPtr;
	CToolSetFactory oToolSetFactory;
	CToolSetShPtr poToolSetShPtr;
	CWorkShop oWorkShop;

} oSWorkShopTestStruct;

BOOST_AUTO_TEST_CASE( AddCarToRepairTest )
{
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.AddCarToRepair( oSWorkShopTestStruct.poCarShPtr ) == true );
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.AddCarToRepair( oSWorkShopTestStruct.poTruckShPtr ) == false );
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.AddCarToRepair( oSWorkShopTestStruct.poCarShPtr ) == false );
}

BOOST_AUTO_TEST_CASE( FinishCarRepairTest )
{
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.FinishCarRepair( oTruckRegistrationNr ) == false );
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.FinishCarRepair( oCarRegistrationNr ) == true );
}

BOOST_AUTO_TEST_CASE( ExportToFileTest )
{
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.ExportToFile( oFilePathString ) == true );
}

BOOST_AUTO_TEST_CASE( ImportFromFileTest )
{
	BOOST_CHECK( oSWorkShopTestStruct.oWorkShop.ImportFromFile( oFilePathString ) == true );
}

BOOST_AUTO_TEST_SUITE_END()

