/*
 * Garage.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */


#include "Garage.h"
#include "CarRepairManager.h"

CGarage::CGarage( CCarRepairManager* poCarRepairManager )
{
	m_poCarRepairManager = poCarRepairManager;
}

bool CGarage::AddVehicleToRepair( CVehicleShPtr poVehicle )
{
	bool bSuccess = false;

	if( m_poCarRepairManager )
	{
		bSuccess = m_poCarRepairManager->AddVehicleToRepair( poVehicle, &m_oRapairingVehiclesMap );
	}

	return bSuccess;
}

bool CGarage::RemoveVehicleFromRepair( string oRegistrationNrString )
{
	bool bSuccess = false;

	if( m_poCarRepairManager )
	{
		bSuccess = m_poCarRepairManager->RemoveVehicleFromRepair( oRegistrationNrString, &m_oRapairingVehiclesMap );
	}

	return bSuccess;
}

CVehiclesMap* CGarage::GetRepairingVehiclesMap()
{
	return &m_oRapairingVehiclesMap;
}

CVehicleShPtr CGarage::GetVehicle( string oRegistrationNrString )
{
	CVehicleShPtr poVehicleShPtr;
	CVehiclesMap::iterator it;

	if( oRegistrationNrString.length() > 0 )
	{
		it = m_oRapairingVehiclesMap.find( oRegistrationNrString );
		if( it != m_oRapairingVehiclesMap.end() )
		{
			poVehicleShPtr = it->second;
		}
	}

	return poVehicleShPtr;
}


