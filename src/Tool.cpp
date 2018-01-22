/*
 * Tools.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#include "Tool.h"

CToolSet::CToolSet()
{
	Clear();
}

CToolSet::~CToolSet()
{

}

void CToolSet::Clear()
{

}


CToolSetFactory::CToolSetFactory()
{

}

CToolSetShPtr CToolSetFactory::CreateToolSet( EVehicleType eHandledVehicleType )
{
	CToolSetShPtr shpoToolSet;

	switch( eHandledVehicleType )
	{
	case eCar:
		shpoToolSet.reset( new CCarToolSet );
		break;

	case eTruck:
		shpoToolSet.reset( new CTruckToolSet );
		break;

	case eUndefined:
	default:
		break;
	}

	return shpoToolSet;
}

