//
//  food.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "food.h"

Food::Food(string name, int fat_gain, int protein_gain, int price) {
	this->name = name;
	this->fat_gain = fat_gain;
	this->protein_gain = protein_gain;
	this->price = price;
}

int Food::get_fat_gain(void) const {
	return this->fat_gain;
}

string Food::get_name(void) const {
	return this->name;
}

int Food::get_price(void) const {
	return this->price;
}

int Food::get_protein_gain(void) const {
	return this->protein_gain;
}
