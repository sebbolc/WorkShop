/*
 * WorkShop.h
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#ifndef WORKSHOP_H_
#define WORKSHOP_H_


#include <iostream>
#include <list>
#include <map>
#include "CarRepairManager.h"
#include "Garage.h"
#include "Vehicle.h"
#include "RepairLogger.h"
using namespace std;


class CWorkShop
{
public:
	CWorkShop();
	bool AddCarToRepair( CVehicleShPtr poVehicle );
	bool FinishCarRepair( string oRegistrationNrString );
	void AddWorker( CWorkerShPtr poWorker );
	void AddToolSet( CToolSetShPtr poToolSet );

	bool ExportToFile( string oFileNameString );
	bool ImportFromFile( string oFileNameString );

private:
	CGarage m_oGarage;
	CCarRepairManager m_oCarRepairManager;
	CRepairLogger m_oRepairLogger;
};

#endif /* WORKSHOP_H_ */
