/*
 * Worker.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */
#include "Worker.h"

CWorker::CWorker( EVehicleType eHandledVehicleType )
{
	m_eHandledVehicleType = eHandledVehicleType;
}

EVehicleType CWorker::GetHandledVehicleType() const
{
	return m_eHandledVehicleType;
}

CWorkerFactory::CWorkerFactory()
{

}

CWorkerShPtr CWorkerFactory::CreateWorker( EVehicleType eHandledVehicleType )
{
	return CWorkerShPtr( new CWorker( eHandledVehicleType ) );
}


