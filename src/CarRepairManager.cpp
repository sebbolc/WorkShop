/*
 * CarRepairManager.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: root
 */

#include "CarRepairManager.h"

CCarRepairManager::CCarRepairManager()
{

}

bool CCarRepairManager::AddVehicleToRepair( CVehicleShPtr poVehicle, CVehiclesMap *poRapairingVehiclesMap )
{
	bool bSuccess = false;

	list<CWorkerShPtr>::iterator poFreeWorkerIt = m_oFreeWorkersList.end();
	list<CToolSetShPtr>::iterator poFreeToolSetIt = m_oFreeToolSetsList.end();

	if( poVehicle && poRapairingVehiclesMap )
	{
		poFreeWorkerIt = GetWorkerItFromWorkersList( poVehicle.get(), &m_oFreeWorkersList );
		poFreeToolSetIt = GetToolSetItFromToolSetsList( poVehicle.get(), &m_oFreeToolSetsList );

		if(    poVehicle->GetRegistrationNr().length() > 0
			&& poRapairingVehiclesMap->find( poVehicle->GetRegistrationNr() ) == poRapairingVehiclesMap->end()
			&& poFreeWorkerIt != m_oFreeWorkersList.end()
			&& poFreeToolSetIt !=  m_oFreeToolSetsList.end() )
		{
			m_oBusyWorkersList.splice( m_oBusyWorkersList.end(), m_oFreeWorkersList, poFreeWorkerIt );
			m_oBusyToolSetsList.splice( m_oBusyToolSetsList.end(), m_oFreeToolSetsList, poFreeToolSetIt );

			pair<CVehiclesMap::iterator, bool> oResult;

			oResult = poRapairingVehiclesMap->insert( pair<string, CVehicleShPtr>( poVehicle->GetRegistrationNr(), poVehicle ));
			bSuccess = oResult.second;
		}
	}

	return bSuccess;
}

list<CWorkerShPtr>::iterator CCarRepairManager::GetWorkerItFromWorkersList( CVehicle* poVehicle, list<CWorkerShPtr>* poWorkersList )
{
	list<CWorkerShPtr>::iterator poFoundWorkerIt;

	if( poVehicle && poWorkersList )
	{
		poFoundWorkerIt = poWorkersList->end();

		for( list<CWorkerShPtr>::iterator it = poWorkersList->begin(); it != poWorkersList->end(); it++ )
		{
			CWorkerShPtr poWorker = *it;
			if( poWorker->GetHandledVehicleType() == poVehicle->GetType() )
			{
				poFoundWorkerIt = it;
				break;
			}
		}
	}

	return poFoundWorkerIt;
}

list<CToolSetShPtr>::iterator CCarRepairManager::GetToolSetItFromToolSetsList( CVehicle* poVehicle, list<CToolSetShPtr>* poToolSetsList )
{
	list<CToolSetShPtr>::iterator poFoundToolSetIt;

	if( poVehicle && poToolSetsList )
	{
		poFoundToolSetIt = poToolSetsList->end();
		for( list<CToolSetShPtr>::iterator it = poToolSetsList->begin(); it != poToolSetsList->end(); it++ )
		{
			CToolSetShPtr poToolSet = *it;
			if( poToolSet->GetHandledVehicleType() == poVehicle->GetType() )
			{
				poFoundToolSetIt = it;
				break;
			}
		}
	}

	return poFoundToolSetIt;
}

bool CCarRepairManager::RemoveVehicleFromRepair( string oRegistrationNrString, CVehiclesMap *poRapairingVehiclesMap )
{
	bool bSuccess = false;
	CVehiclesMap::iterator it;
	CVehicleShPtr poVehicleShPtr;

	if( oRegistrationNrString.length() > 0 )
	{
		it = poRapairingVehiclesMap->find( oRegistrationNrString );
		if( it != poRapairingVehiclesMap->end() )
		{
			bSuccess = RemoveVehicleFromRepair( it->second, poRapairingVehiclesMap );
		}
	}

	return bSuccess;
}

bool CCarRepairManager::RemoveVehicleFromRepair( CVehicleShPtr poVehicle, CVehiclesMap *poRapairingVehiclesMap )
{
	bool bSuccess = false;

	list<CWorkerShPtr>::iterator poBusyWorkerIt;
	list<CToolSetShPtr>::iterator poBusyToolSetIt;

	if( poVehicle && poRapairingVehiclesMap )
	{
		poBusyWorkerIt = GetWorkerItFromWorkersList( poVehicle.get(), &m_oBusyWorkersList );
		poBusyToolSetIt = GetToolSetItFromToolSetsList( poVehicle.get(), &m_oBusyToolSetsList );

		if(    poVehicle->GetRegistrationNr().length() > 0
			&& poBusyWorkerIt != m_oBusyWorkersList.end() && poBusyToolSetIt != m_oBusyToolSetsList.end() )
		{
			m_oFreeWorkersList.splice( m_oFreeWorkersList.end(), m_oBusyWorkersList, poBusyWorkerIt );
			m_oFreeToolSetsList.splice( m_oFreeToolSetsList.end(), m_oBusyToolSetsList, poBusyToolSetIt );

			bSuccess = ( poRapairingVehiclesMap->erase( poVehicle->GetRegistrationNr() ) > 0 );
		}
	}

	return bSuccess;
}

void CCarRepairManager::AddWorker( CWorkerShPtr poWorker )
{
	if( poWorker )
	{
		m_oFreeWorkersList.push_back( poWorker );
	}
}

void CCarRepairManager::AddToolSet( CToolSetShPtr poToolSet )
{
	if( poToolSet )
	{
		m_oFreeToolSetsList.push_back( poToolSet );
	}
}


