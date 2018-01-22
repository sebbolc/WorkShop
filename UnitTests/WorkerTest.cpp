/*
 * WorkerTest.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: root
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE WorkShop suites
#include <boost/test/unit_test.hpp>
#include "Worker.h"

BOOST_AUTO_TEST_SUITE( WorkerFactorySuite )

CWorkerFactory oWorkerFactory;
CWorkerShPtr poWorkerShPtr;

BOOST_AUTO_TEST_CASE( CreateWorkertest )
{
	poWorkerShPtr = oWorkerFactory.CreateWorker( eCar );
	BOOST_CHECK( poWorkerShPtr != NULL );
	if( poWorkerShPtr )
	{
		BOOST_CHECK( poWorkerShPtr->GetHandledVehicleType() == eCar );
	}

	poWorkerShPtr = oWorkerFactory.CreateWorker( eTruck );
	BOOST_CHECK( poWorkerShPtr != NULL );
	if( poWorkerShPtr )
	{
		BOOST_CHECK( poWorkerShPtr->GetHandledVehicleType() == eTruck );
	}

	poWorkerShPtr = oWorkerFactory.CreateWorker( eUndefined );
	BOOST_CHECK( poWorkerShPtr != NULL );
	if( poWorkerShPtr )
	{
		BOOST_CHECK( poWorkerShPtr->GetHandledVehicleType() == eUndefined );
	}

	poWorkerShPtr = oWorkerFactory.CreateWorker( EVehicleType( 60 ) );
	BOOST_CHECK( poWorkerShPtr != NULL );
	if( poWorkerShPtr )
	{
		BOOST_CHECK( poWorkerShPtr->GetHandledVehicleType() == EVehicleType( 60 ) );
	}
}
BOOST_AUTO_TEST_SUITE_END()




