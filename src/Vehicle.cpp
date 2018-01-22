/*
 * VehicleType.cpp
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#include "Vehicle.h"

CVehicle::CVehicle()
{
	Clear();
}

CVehicle::~CVehicle()
{

}

void CVehicle::Clear()
{
	m_oRegistrationNrString.clear();
	m_oBrandString.clear();
	m_oModelString.clear();
	m_oPowerSupplyTypeString.clear();
	m_oColorString.clear();
	m_dMileage = 0;
	m_dRepairingTimeHours = 0;
}

void CVehicle::SetRegistrationNr( string oRegistrationNrString )
{
	m_oRegistrationNrString = oRegistrationNrString;
}

void CVehicle::SetBrand( string oBrandString )
{
	m_oBrandString = oBrandString;
}

void CVehicle::SetModel( string oModelString )
{
	m_oModelString = oModelString;
}

string CVehicle::GetRegistrationNr() const
{
	return m_oRegistrationNrString;
}

string CVehicle::GetBrand() const
{
	return m_oBrandString;
}

string CVehicle::GetModel() const
{
	return m_oModelString;
}

void CVehicle::SetPowerSupplyType( string oPowerSupplyTypeString )
{
	m_oPowerSupplyTypeString = oPowerSupplyTypeString;
}

void CVehicle::SetColor( string oColorString )
{
	m_oColorString = oColorString;
}

void CVehicle::SetMileage( double dMileage )
{
	m_dMileage = dMileage;
}

void CVehicle::SetRepairingTimeHours( double dRepairingTimeHours )
{
	m_dRepairingTimeHours = dRepairingTimeHours;
}

string CVehicle::GetPowerSupplyType() const
{
	return m_oPowerSupplyTypeString;
}

string CVehicle::GetColor() const
{
	return m_oColorString;
}

double CVehicle::GetMileage() const
{
	return m_dMileage;
}

double CVehicle::GetRepairingTimeHours() const
{
	return m_dRepairingTimeHours;
}

CVehicleFactory::CVehicleFactory()
{

}

CVehicleShPtr CVehicleFactory::CreateVehicle( string oRegistrationNrString, EVehicleType eVehicleType )
{
	CVehicleShPtr shpoVehicle;

	if( oRegistrationNrString.length() > 0 )
	{
		switch( eVehicleType )
		{
		case eCar:
			shpoVehicle.reset( new CCar );
			break;

		case eTruck:
			shpoVehicle.reset( new CTruck );
			break;

		case eUndefined:
		default:
			break;
		}

		if( shpoVehicle )
		{
			shpoVehicle->SetRegistrationNr( oRegistrationNrString );
		}
	}

	return shpoVehicle;
}

