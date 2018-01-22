/*
 * VehicleType.h
 *
 *  Created on: Jan 14, 2018
 *      Author: root
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
using namespace std;

#include "boost/shared_ptr.hpp"

enum EVehicleType {
eUndefined,
eCar,
eTruck
};

class CVehicle
{
public:
	CVehicle();
	virtual ~CVehicle();

	virtual void Clear();

	void SetRegistrationNr( string oRegistrationNrString );
	void SetBrand( string oBrandString );
	void SetModel( string oModelString );
	void SetPowerSupplyType( string oPowerSupplyTypeString );
	void SetColor( string oColorString );
	void SetMileage( double dMileage );
	void SetRepairingTimeHours( double dRepairingTimeHours );

	string GetRegistrationNr() const;
	string GetBrand() const;
	string GetModel() const;
	string GetPowerSupplyType() const;
	string GetColor() const;
	double GetMileage() const;
	double GetRepairingTimeHours() const;
	virtual EVehicleType GetType() const = 0;

protected:
	string m_oRegistrationNrString;
	string m_oBrandString;
	string m_oModelString;
	string m_oPowerSupplyTypeString;
	string m_oColorString;
	double m_dMileage;
	double m_dRepairingTimeHours;
};

class CCar : public CVehicle
{
public:
	CCar(){};
	virtual EVehicleType GetType() const { return eCar;}
};

class CTruck : public CVehicle
{
public:
	CTruck(){}
	virtual EVehicleType GetType() const { return eTruck;}
};

typedef boost::shared_ptr<CVehicle> CVehicleShPtr;

class CVehicleFactory
{
public:
	CVehicleFactory();
	CVehicleShPtr CreateVehicle( string oRegistrationNrString, EVehicleType eVehicleType );
};

#endif /* VEHICLE_H_ */
