//
//  restaurant.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "restaurant.h"

Restaurant::Restaurant(string name): name(name), list_start_index(0), list_end_index(4), curr_num_of_meals(0) {}

string Restaurant::get_name(void) const {
	return name;
}

bool Restaurant::add_meal(Food food) {
	if (this->curr_num_of_meals == 5) {
		return false;
	} else {
		this->list_end_index = (this->list_end_index + 1) % 5;
		this->meals_list[this->list_end_index] = food;
		this->curr_num_of_meals++;
		return true;
	}
}

bool Restaurant::remove_first_meal(void) {
	if (!this->curr_num_of_meals) {
		return false;
	} else {
		return true;
	}
}

bool Restaurant::remove_last_meal(void) {
	if (!this->curr_num_of_meals) {
		return false;
	} else {
		return true;
	}
}

bool Restaurant::serve_meal(Buddy* buddy, int meal_index) const {
	return true;
}
