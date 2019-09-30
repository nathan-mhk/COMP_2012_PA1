//
//  buddy.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "buddy.h"

Buddy::Buddy(string name, int fat, int muscle, int energy, int money) :
	name(name),
	fat(fat),
	muscle(muscle),
	energy((energy < 0) ? 0 : energy),
	money((money < 0) ? 0 : money) {}

string Buddy::get_name(void) const {
	return name;
}

int Buddy::get_fat(void) const {
	return fat;
}

int Buddy::get_muscle(void) const {
	return muscle;
}

int Buddy::get_energy(void) const {
	return energy;
}

int Buddy::get_money(void) const {
	return money;
}

void Buddy::set_fat(int fat) {
	this->fat = fat;
}

void Buddy::set_muscle(int muscle) {
	this->muscle = muscle;
}

void Buddy::set_energy(int energy) {
	this->energy = (energy < 0) ? 0 : energy;
}

void Buddy::set_money(int money) {
	this->money = (money < 0) ? 0 : money;
}

void Buddy::earn_money(int money, int times) {
	// Assume these are valid:
	// money
	// times
	this->money = this->money + money * times;
}

void Buddy::gain_energy(RelaxPlan plan) {
	Relaxation* activity = plan.get_head();
	// Proceed if the linked list is not empty
	if (activity) {
		int totalEnergyGained = this->get_energy();
		while (activity) {
			totalEnergyGained += activity->get_energy_gain();
			activity = activity->get_next();
		}
		this->set_energy(totalEnergyGained);
	}
}
