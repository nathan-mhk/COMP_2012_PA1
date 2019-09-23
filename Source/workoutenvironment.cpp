//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workoutenvironment.h"

WorkoutEnvironment::WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS):
	name(name),
	entry_fee(entry_fee),
	available_workouts(new Workout[MAX_NUM_OF_WORKOUTS]),
	MAX_NUM_OF_WORKOUTS(MAX_NUM_OF_WORKOUTS),
	current_num_of_workouts(0),
	participants(NULL),
	current_num_of_participants(0) {}

WorkoutEnvironment::~WorkoutEnvironment(void) {
	//TODO Debug
	//Not that simple
	delete [] available_workouts;
	delete [] participants;
	//available_workouts = NULL;
	participants = NULL;
}

string WorkoutEnvironment::get_name(void) const {
	return name;
}

int WorkoutEnvironment::get_entry_fee(void) const {
	return entry_fee;
}

bool WorkoutEnvironment::add_workout(const Workout& workout, int add_index) {
	if ((add_index >= 0) &&
		(add_index <= this->current_num_of_workouts) &&
		(this->current_num_of_workouts < this->MAX_NUM_OF_WORKOUTS)) {

		for (int i = this->current_num_of_workouts; i > add_index; --i) {
			this->available_workouts[i] = this->available_workouts[i - 1];
		}

		this->available_workouts[add_index] = workout;
		++this->current_num_of_workouts;
		return true;
	} else {
		return false;
	}
}

bool WorkoutEnvironment::remove_workout(int remove_index) {
	if ((remove_index >= 0) &&
		(remove_index < this->current_num_of_workouts) &&
		(this->current_num_of_workouts > 0)) {

		for (int i = remove_index; i < this->current_num_of_workouts - 2; ++i) {
			this->available_workouts[i] = this->available_workouts[i + 1];
		}

		--this->current_num_of_workouts;
		return true;
	} else {
		return false;
	}
}

int WorkoutEnvironment::participant_index(const Buddy* buddy) const {
	for (int i = 0; i < this->current_num_of_participants; ++i) {
		if (this->participants[i]->get_name() == buddy->get_name()) {
			return i;
		}
	}
	return -1;
}

bool WorkoutEnvironment::register_participant(Buddy* buddy) {
	return true;
}

bool WorkoutEnvironment::start_workout(int participant_index, int workout_index) const {
	/*
	 * The functions participant_index &
	 * register_participant consider two buddies
	 * as the same if and only if they have the same address
	 */
	return true;
}
