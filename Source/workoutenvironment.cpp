//
//  workoutenvironment.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 2/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "workoutenvironment.h"

WorkoutEnvironment::WorkoutEnvironment(string name, int entry_fee, int MAX_NUM_OF_WORKOUTS) :
	name(name),
	entry_fee(entry_fee),
	available_workouts(new Workout[MAX_NUM_OF_WORKOUTS]),
	MAX_NUM_OF_WORKOUTS(MAX_NUM_OF_WORKOUTS),
	current_num_of_workouts(0),
	participants(NULL),
	current_num_of_participants(0) {}

WorkoutEnvironment::~WorkoutEnvironment(void) {
	delete [] available_workouts;
	delete [] participants;
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
		
		for (int i = remove_index; i <= this->current_num_of_workouts - 2; ++i) {
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
		if (this->participants[i] == buddy) {
			return i;
		}
	}
	return -1;
}

bool WorkoutEnvironment::register_participant(Buddy* buddy) {
	if ((this->participant_index(buddy) != -1) || 
		(buddy->get_money() < this->entry_fee)) {
		return false;
	} else {
		buddy->set_money(buddy->get_money() - this->entry_fee);

		//1. Create a new double pointer array with length current_#_parti + 1
		Buddy** members = new Buddy*[this->current_num_of_participants + 1];

		//2. copy all previous Buddy* to the new array. Only copy the addresses, not the Buddy objects.
		// ******Won't run the for loop if there's no participants/participants = NULL
		for (int i = 0; i < this->current_num_of_participants; ++i) {
			members[i] = this->participants[i];
		}

		//3. assign the passed in buddy* to the new array's 'current_num_of_participants' element, this is also copying addresses.
		members[this->current_num_of_participants] = buddy;

		//4. delete[] participants, DO NOT delete the pointers to the Buddy objects inside the array. 
		// *****Will not do anything if participants points at NULL
		delete [] this->participants;

		//5. participants = new array, update 'current_num_of_participants'.
		participants = members;
		++this->current_num_of_participants;
		return true;
	}
}

bool WorkoutEnvironment::start_workout(int participant_index, int workout_index) const {
	if ((participant_index >= 0) && 
		(participant_index < this->current_num_of_participants) && 
		(workout_index >= 0) && 
		(workout_index < this->current_num_of_workouts)) {

		Buddy* buddy = this->participants[participant_index];
		Workout workout = this->available_workouts[workout_index];
		int energy = buddy->get_energy() + workout.get_energy_change();

		if (energy >= 0) {
			int fat = buddy->get_fat() + workout.get_fat_change();
			int muscle = buddy->get_muscle() + workout.get_muscle_change();

			buddy->set_fat(fat);
			buddy->set_muscle(muscle);
			buddy->set_energy(energy);
			return true;
			
		} else {
			return false;
		}

	} else {
		return false;
	}
}
