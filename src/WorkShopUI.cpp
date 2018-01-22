/*
 * WorkShopUI.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: root
 */


#include "WorkShopUI.h"

CWorkShopUI::CWorkShopUI()
{

}

void CWorkShopUI::Run()
{
	CWorkShopUI::EMainMenuOption eMainMenuOption = eExit;

	do
	{
		eMainMenuOption = GetOptionFromMainMenu();

		switch( eMainMenuOption )
		{
		case eAddVehicle:
			AddVehicleToRepair();
			break;
		case eRemoveVehicle:
			FinishCarRepair();
			break;
		case eAddWorker:
			AddWorker();
			break;
		case eAddToolSet:
			AddToolSet();
			break;
		case eExit:
			break;
		default:
			eMainMenuOption = eExit;
			break;

		}
	}
	while( eMainMenuOption != eExit );

	cout << "You chose to quit application." << endl;
}


CWorkShopUI::EMainMenuOption CWorkShopUI::GetOptionFromMainMenu()
{
	int iOption = eExit;

	cout << "\r\nSelect option:\r\n1 - Add vehicle\r\n2 - Remove vehicle\r\n3 - Add worker\r\n4 - Add tool set\r\nother - quit"<<endl;
	cin >> iOption;

	return CWorkShopUI::EMainMenuOption( iOption );
}

void CWorkShopUI::AddWorker()
{
	CWorkerFactory oWorkerFactory;

	int iSpecialist = eCar;

	do
	{
		cout << "Select specialist:\n1 - Cars\n2 - Trucks"<<endl;
		cin >> iSpecialist;
	}
	while( iSpecialist != eCar && iSpecialist != eTruck );

	m_oWorkShop.AddWorker( oWorkerFactory.CreateWorker( EVehicleType( iSpecialist ) ) );
}

void CWorkShopUI::AddToolSet()
{
	CToolSetFactory oToolSetFactory;

	int iHandledVehicleType = eCar;

	do
	{
		cout << "Select specialist:\n1 - Cars\n2 - Trucks"<<endl;
		cin >> iHandledVehicleType;
	}
	while( iHandledVehicleType != eCar && iHandledVehicleType != eTruck );

	m_oWorkShop.AddToolSet( oToolSetFactory.CreateToolSet( EVehicleType( iHandledVehicleType ) ) );
}

void CWorkShopUI::AddVehicleToRepair()
{
	CVehicleFactory oVehicleFactory;

	int iVehicleType = eCar;
	string oRegistrationNrString;

	do
	{
		cout << "Select vehicle type:\n1 - Car\n2 - Truck"<<endl;
		cin >> iVehicleType;
	}
	while( iVehicleType != eCar && iVehicleType != eTruck );

	do
	{
		cout << "Enter registration number:"<<endl;
		cin >> oRegistrationNrString;
	}
	while( oRegistrationNrString.length() <= 0 );

	if( !m_oWorkShop.AddCarToRepair( oVehicleFactory.CreateVehicle( oRegistrationNrString, EVehicleType( iVehicleType ) ) ) )
	{
		cout << "Couldn't add car to repair shop.\nNo free workers or tool sets."<<endl;
	}
	else
	{
		cout << "Car with registration number: '" << oRegistrationNrString << "' was added to repair shop successfully."<<endl;
	}
}

void CWorkShopUI::FinishCarRepair()
{
	string oRegistrationNrString;

	do
	{
		cout << "Enter registration number:"<<endl;
		cin >> oRegistrationNrString;
	}
	while( oRegistrationNrString.length() <= 0 );

	if( m_oWorkShop.FinishCarRepair( oRegistrationNrString ) )
	{
		cout << "Car repair with registration number: '" << oRegistrationNrString << "' was finished successfully."<<endl;
	}
	else
	{
		cout << "Could not find car with registration number: '" << oRegistrationNrString <<"'"<< endl;
	}
}
