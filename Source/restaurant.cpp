//
//  restaurant.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "restaurant.h"

Restaurant::Restaurant(string name): name(name) {
	this->list_start_index = 0;
	this->curr_num_of_meals = 0;
	this->list_end_index = 4;
}

string Restaurant::get_name(void) const {
	return this->name;
}

bool Restaurant::add_meal(Food food) {

	return true;
}

bool Restaurant::remove_first_meal(void) {
	return true;
}

bool Restaurant::remove_last_meal(void) {
	return true;
}

bool Restaurant::serve_meal(Buddy* buddy, int meal_index) const {
	return true;
}
