//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workoutenvironment.h"

/*
 * The functions participant_index &
 * register_participant consider two buddies
 * as the same if and only if they have the same address
 */

WorkoutEnvironment::WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS) {
//	this->name = name;
//	this->available_workouts = new Workout[MAX_NUM_OF_WORKOUTS];
//	this->current_num_of_workouts = 0;
//	this->participants = NULL;
//	this->current_num_of_participants = 0;
}

WorkoutEnvironment::~WorkoutEnvironment(void) {

}

string WorkoutEnvironment::get_name(void) const {
	return this->name;
}

int WorkoutEnvironment::get_entry_fee(void) const {
	return this->entry_fee;
}

bool WorkoutEnvironment::add_workout(const Workout& workout, int add_index) {
	return true;
}

bool WorkoutEnvironment::remove_workout(int remove_index) {
	return true;
}

int WorkoutEnvironment::participant_index(const Buddy* buddy) const {
	return 0;
}

bool WorkoutEnvironment::register_participant(Buddy* buddy) {
	return true;
}

bool WorkoutEnvironment::start_workout(int participant_index, int workout_index) const {
	return true;
}
