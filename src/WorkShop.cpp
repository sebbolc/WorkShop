/*
 * WorkShop.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#include "WorkShop.h"

CWorkShop::CWorkShop()
:m_oGarage( &m_oCarRepairManager )
{

}

bool CWorkShop::AddCarToRepair( CVehicleShPtr poVehicle )
{
	bool bSuccess = false;

	if(    poVehicle
		&& m_oRepairLogger.StartLog( poVehicle.get() )
		&& m_oGarage.AddVehicleToRepair( poVehicle ) )
	{
		bSuccess = true;
	}

	return bSuccess;
}

bool CWorkShop::FinishCarRepair( string oRegistrationNrString )
{
	bool bSuccess = false;
	CVehicleShPtr poVehicleShPtr( m_oGarage.GetVehicle( oRegistrationNrString ) );

	if( poVehicleShPtr )
	{
		if(    m_oGarage.RemoveVehicleFromRepair( oRegistrationNrString )
			&& m_oRepairLogger.StopLog( poVehicleShPtr.get() ) )
		{
			bSuccess = true;
		}
	}

	return bSuccess;
}

void CWorkShop::AddWorker( CWorkerShPtr poWorker )
{
	if( poWorker )
	{
		m_oCarRepairManager.AddWorker( poWorker );
	}
}

void CWorkShop::AddToolSet( CToolSetShPtr poToolSet )
{
	if( poToolSet )
	{
		m_oCarRepairManager.AddToolSet( poToolSet );
	}
}

bool CWorkShop::ExportToFile( string oFileNameString )
{
	return false;
}

bool CWorkShop::ImportFromFile( string oFileNameString )
{
	return false;
}
