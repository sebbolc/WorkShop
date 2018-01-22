/*
 * CarRepairManager.h
 *
 *  Created on: Jan 15, 2018
 *      Author: root
 */

#ifndef CARREPAIRMANAGER_H_
#define CARREPAIRMANAGER_H_

#include <iostream>
#include <list>
#include <map>
#include "Garage.h"
#include "Vehicle.h"
using namespace std;

class CCarRepairManager{
public:
	CCarRepairManager();
	bool AddVehicleToRepair( CVehicleShPtr poVehicle, CVehiclesMap *poRapairingVehiclesMap );
	bool RemoveVehicleFromRepair( string oRegistrationNrString, CVehiclesMap *poRapairingVehiclesMap );

	void AddWorker( CWorkerShPtr poWorker );
	void AddToolSet( CToolSetShPtr poToolSet );

private:
	list<CWorkerShPtr>::iterator GetWorkerItFromWorkersList( CVehicle* poVehicle, list<CWorkerShPtr>* poWorkersList );
	list<CToolSetShPtr>::iterator GetToolSetItFromToolSetsList( CVehicle* poVehicle, list<CToolSetShPtr>* poToolSetsList );

	bool RemoveVehicleFromRepair( CVehicleShPtr poVehicle, CVehiclesMap *poRapairingVehiclesMap );

private:
	list<CWorkerShPtr> m_oBusyWorkersList;
	list<CToolSetShPtr> m_oBusyToolSetsList;
	list<CWorkerShPtr> m_oFreeWorkersList;
	list<CToolSetShPtr> m_oFreeToolSetsList;
};

#endif /* CARREPAIRMANAGER_H_ */
