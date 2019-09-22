//
//  relaxation.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxation.h"

Relaxation::Relaxation(string name, int energy_gain): name(name), energy_gain(energy_gain), next(NULL) {}

string Relaxation::get_name(void) const {
	return this->name;
}

int Relaxation::get_energy_gain(void) const {
	return this->energy_gain;
}

Relaxation* Relaxation::get_next(void) const {
	return this->next;
}

void Relaxation::set_next(Relaxation* next) {
	this->next = next;
}
