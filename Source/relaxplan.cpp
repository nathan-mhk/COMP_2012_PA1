//
//  relaxplan.cpp
//  2012PA1
//
//  Created by TONY WAI SUM JI on 3/9/2019.
//  Copyright © 2019 Tony Wai Sum JI. All rights reserved.
//

#include "relaxplan.h"

// Example solution for copy constructor, you don't have to implement it
RelaxPlan::RelaxPlan(RelaxPlan const & rp): name(rp.name) {
    // empty list
    if (!rp.head) {
        head = NULL;
        return;
    }
    // copy first node, prepare to copy second
    head = new Relaxation(*rp.head);
    Relaxation* curr_copied = head;
    Relaxation* next_to_copy = rp.head->get_next();
    // while next exists, continue copy
    while (next_to_copy) {
        Relaxation* copied = new Relaxation(*next_to_copy);
        curr_copied->set_next(copied);
        // next_to_copy is always a node in rp
        // curr_copied is always a node in self
        next_to_copy = next_to_copy->get_next();
        curr_copied = copied;
    }
}

RelaxPlan::RelaxPlan(string name) :
	name(name),
	head(NULL) {}

RelaxPlan::~RelaxPlan(void) {
	Relaxation* current = this->head;
	Relaxation* next;

	while (current) {
		next = current->get_next();
		current->set_next(NULL);
		delete current;
		current = next;
	}
}

Relaxation* RelaxPlan::get_head(void) const {
	return head;
}

void RelaxPlan::addToStart(Relaxation r) {
	Relaxation* newRelax = new Relaxation(r);
	newRelax->set_next(this->head);	// If empty: newRelax->next = NULL
	this->head = newRelax;
}

void RelaxPlan::addToEnd(Relaxation r) {
	//Create a copy
	Relaxation* newRelax = new Relaxation(r);

	//If head == NULL
	if (!this->head) {
		newRelax->set_next(this->head);
		this->head = newRelax;

	} else {
		Relaxation* end = this->head;

		while (end->get_next()) {
			end = end->get_next();
		}

		end->set_next(newRelax);
		newRelax->set_next(NULL);
	}
}

bool RelaxPlan::remove(int remove_index) {
	if (remove_index >= 0) {
		Relaxation* current = this->head;
		Relaxation* previous = current;
		//Transverse time
		for (int i = 0; i < remove_index; ++i) {
			// If not out of range
			if (current->get_next()) {
				current = current->get_next();
				if (i) {
					previous = previous->get_next();
				}

			} else {
				return false;
			}
		}

		Relaxation* next = current->get_next();

		if (previous == current) {
			this->head = next;
		} else {
			previous->set_next(next);
		}
		current->set_next(NULL);
		delete current;
		return true;
	} else {
		return false;
	}
}


























