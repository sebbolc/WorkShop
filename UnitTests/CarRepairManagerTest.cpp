/*
 * CarRepairManagerTest.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: root
 */

#include <boost/test/unit_test.hpp>
#include "CarRepairManager.h"

BOOST_AUTO_TEST_SUITE( CCarRepairManagerSuite )

CVehiclesMap oVehiclesMap;
CCarRepairManager oCarRepairManager;
CVehicleFactory oVehicleFactory;
CVehicleShPtr poVehicleShPtr;
CWorkerFactory oWorkerFactory;
CWorkerShPtr poWorkerShPtr;
CToolSetFactory oToolSetFactory;
CToolSetShPtr poToolSetShPtr;

BOOST_AUTO_TEST_CASE( AddVehicleToRepairTest )
{
	poWorkerShPtr = oWorkerFactory.CreateWorker( eCar );
	oCarRepairManager.AddWorker( poWorkerShPtr );

	poToolSetShPtr = oToolSetFactory.CreateToolSet( eCar );
	oCarRepairManager.AddToolSet( poToolSetShPtr );

	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) == false );
	BOOST_CHECK( oVehiclesMap.size() == 0 );

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "123", eTruck );
	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) == false );
	BOOST_CHECK( oVehiclesMap.count( "123" ) == 0 );

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "123", eCar );
	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) );
	BOOST_CHECK( oVehiclesMap.count( "123" ) == 1 );

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "345", eCar );
	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) == false );
	BOOST_CHECK( oVehiclesMap.count( "345" ) == 0 );

	poWorkerShPtr = oWorkerFactory.CreateWorker( eCar );
	oCarRepairManager.AddWorker( poWorkerShPtr );

	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) == false );
	BOOST_CHECK( oVehiclesMap.count( "345" ) == 0 );

	poToolSetShPtr = oToolSetFactory.CreateToolSet( eCar );
	oCarRepairManager.AddToolSet( poToolSetShPtr );

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "123", eCar );
	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) == false );
	BOOST_CHECK( oVehiclesMap.count( "123" ) == 1 );

	poVehicleShPtr = oVehicleFactory.CreateVehicle( "345", eCar );
	BOOST_CHECK( oCarRepairManager.AddVehicleToRepair( poVehicleShPtr, &oVehiclesMap ) );
	BOOST_CHECK( oVehiclesMap.count( "345" ) == 1 );
}

BOOST_AUTO_TEST_CASE( RemoveVehicleFromRepairTest )
{
	BOOST_CHECK( oCarRepairManager.RemoveVehicleFromRepair( "008", &oVehiclesMap ) == false );
	BOOST_CHECK( oVehiclesMap.size() == 2 );

	BOOST_CHECK( oCarRepairManager.RemoveVehicleFromRepair( "123", &oVehiclesMap ) );
	BOOST_CHECK( oVehiclesMap.size() == 1 );

	BOOST_CHECK( oCarRepairManager.RemoveVehicleFromRepair( "345", &oVehiclesMap ) );
	BOOST_CHECK( oVehiclesMap.size() == 0 );
}

BOOST_AUTO_TEST_SUITE_END()



