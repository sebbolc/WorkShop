/*
 * Worker.h
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <iostream>
#include "boost/shared_ptr.hpp"
#include <list>

#include "Vehicle.h"
using namespace std;

class CWorker
{
public:
	CWorker( EVehicleType eHandledVehicleType );

	EVehicleType GetHandledVehicleType() const;

private:
	EVehicleType m_eHandledVehicleType;
};

typedef boost::shared_ptr<CWorker> CWorkerShPtr;

class CWorkerFactory
{
public:
	CWorkerFactory();
	CWorkerShPtr CreateWorker( EVehicleType eHandledVehicleType );
};


#endif /* WORKER_H_ */
