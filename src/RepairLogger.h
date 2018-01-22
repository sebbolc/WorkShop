/*
 * RepairLogger.h
 *
 *  Created on: Jan 16, 2018
 *      Author: root
 */

#ifndef REPAIRLOGGER_H_
#define REPAIRLOGGER_H_

#include <iostream>
#include <list>
#include <map>
#include "Vehicle.h"
using namespace std;

class CRepairLogger
{
public:
	CRepairLogger();
	bool StartLog( CVehicle* poVehicle );
	bool StopLog( CVehicle* poVehicle );

};


#endif /* REPAIRLOGGER_H_ */
