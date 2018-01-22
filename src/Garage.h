/*
 * Garage.h
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#ifndef GARAGE_H_
#define GARAGE_H_

#include <iostream>
#include <list>
#include <map>
#include "Worker.h"
#include "Tool.h"
#include "Vehicle.h"
using namespace std;

typedef map<string, CVehicleShPtr> CVehiclesMap;
class CCarRepairManager;

class CGarage
{
public:
	CGarage( CCarRepairManager* poCarRepairManager );

	bool AddVehicleToRepair( CVehicleShPtr poVehicle );
	bool RemoveVehicleFromRepair( string oRegistrationNrString );

	CVehicleShPtr GetVehicle( string oRegistrationNrString );
	CVehiclesMap* GetRepairingVehiclesMap();

private:
	CVehiclesMap m_oRapairingVehiclesMap;
	CCarRepairManager* m_poCarRepairManager;
};


#endif /* GARAGE_H_ */
