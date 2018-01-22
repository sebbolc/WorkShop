/*
 * Tools.h
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#ifndef TOOL_H_
#define TOOL_H_

#include <iostream>
#include "boost/shared_ptr.hpp"

#include "Vehicle.h"
using namespace std;

class CToolSet
{
public:
	CToolSet();
	virtual ~CToolSet();
	void Clear();
	virtual EVehicleType GetHandledVehicleType() const = 0;
};

class CCarToolSet : public CToolSet
{
public:
	CCarToolSet() {}
	virtual EVehicleType GetHandledVehicleType() const { return eCar; }
};

class CTruckToolSet : public CToolSet
{
public:
	CTruckToolSet() {}
	virtual EVehicleType GetHandledVehicleType() const { return eTruck; }
};

typedef boost::shared_ptr<CToolSet> CToolSetShPtr;

class CToolSetFactory
{
public:
	CToolSetFactory();
	CToolSetShPtr CreateToolSet( EVehicleType eHandledVehicleType );
};




#endif /* TOOL_H_ */
