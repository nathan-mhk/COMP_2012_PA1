//
//  buddy.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "buddy.h"

Buddy::Buddy(string name, int fat, int muscle, int energy, int money) {
	this->name = name;
	this->fat = fat;
	this->muscle = muscle;
	set_energy(energy);
	set_money(money);
}

string Buddy::get_name(void) const {
	return this->name;
}

int Buddy::get_fat(void) const {
	return this->fat;
}

int Buddy::get_muscle(void) const {
	return this->muscle;
}

int Buddy::get_energy(void) const {
	return this->energy;
}

int Buddy::get_money(void) const {
	return this->money;
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
	this->money = this->money + money * times;
}

void Buddy::gain_energy(RelaxPlan plan) {
	//TODO
}
