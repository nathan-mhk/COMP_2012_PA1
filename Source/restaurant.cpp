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

bool Restaurant::add_meal(Food food) {
	//If full, return false
	if (this->curr_num_of_meals == 5) {
		return false;
	} else {
		//End index should ALWAYS point at the last meal
		//Update end index, set food and update #meals
		this->list_end_index = (this->list_end_index + 1) % 5;
		this->meals_list[this->list_end_index] = food;
		++this->curr_num_of_meals;
		return true;
	}
}

bool Restaurant::remove_first_meal(void) {
	//If empty, return false
	if (!curr_num_of_meals) {
		return false;
	} else {
		//Start index should ALWAYS point at the first meal
		//Reset, update start index and #meals
		this->meals_list[this->list_start_index] = Food();
		list_start_index = (list_start_index + 1) % 5;
		--curr_num_of_meals;
		return true;
	}
}

bool Restaurant::remove_last_meal(void) {
	//If empty, return false
	if (!curr_num_of_meals) {
		return false;
	} else {
		//End index should ALWAYS point at the last meal
		//Reset, udpate end index and #meals
//TODO: Sth's wrong with the reset below
		//this->meals_list[this->list_end_index] = Food();
		list_end_index = (list_end_index - 1) % 5;
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
