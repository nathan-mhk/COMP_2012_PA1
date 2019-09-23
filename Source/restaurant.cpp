//
//  restaurant.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "restaurant.h"

Restaurant::Restaurant(string name):
	name(name),
	list_start_index(0),
	list_end_index(4),
	curr_num_of_meals(0) {}

string Restaurant::get_name(void) const {
	return name;
}
//TODO fix
bool Restaurant::add_meal(Food food) {
	if (this->curr_num_of_meals == 5) {
		return false;
	} else {
		this->list_end_index = (this->list_end_index + 1) % 5;
		this->meals_list[this->list_end_index] = food;
		++this->curr_num_of_meals;
		return true;
	}
}

bool Restaurant::remove_first_meal(void) {
	if (!curr_num_of_meals) {
		return false;
	} else {
		list_start_index = (list_start_index + 1) % 5;
		--curr_num_of_meals;
		return true;
	}
}

bool Restaurant::remove_last_meal(void) {
	if (!curr_num_of_meals) {
		return false;
	} else {
		list_end_index = (list_end_index + 1) % 5;
		--curr_num_of_meals;
		return true;
	}
}

bool Restaurant::serve_meal(Buddy* buddy, int meal_index) const {
	Food food = this->meals_list[meal_index];
	int money = buddy->get_money() - food.get_price();

	if (money >= 0) {
		int fat = buddy->get_fat() + food.get_fat_gain();
		int muscle = buddy->get_muscle() + food.get_protein_gain();

		buddy->set_money(money);
		buddy->set_fat(fat);
		buddy->set_muscle(muscle);
		return true;
	} else {
		return false;
	}
}
