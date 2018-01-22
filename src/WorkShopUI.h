/*
 * WorkShopUI.h
 *
 *  Created on: Jan 20, 2018
 *      Author: root
 */

#ifndef WORKSHOPUI_H_
#define WORKSHOPUI_H_


#include <iostream>
#include  "WorkShop.h"
using namespace std;



class CWorkShopUI
{
	enum EMainMenuOption
	{
		eExit,
		eAddVehicle,
		eRemoveVehicle,
		eAddWorker,
		eAddToolSet
	};

public:
	CWorkShopUI();
	void Run();

private:
	EMainMenuOption GetOptionFromMainMenu();
	void AddWorker();
	void AddToolSet();
	void AddVehicleToRepair();
	void FinishCarRepair();


private:
	CWorkShop m_oWorkShop;
};

#endif /* WORKSHOPUI_H_ */
