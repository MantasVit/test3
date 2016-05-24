/* MANTAS */

#pragma once

#include "Object.h"

class Object;

class EntityBase: public Object{
protected:
	bool		alive;
public:
	EntityBase();
	~EntityBase();
	void addToList(EntityBase* entity);
	//set whether the entity is alive
	void setAlive(bool Alive);
	//get whether the entity is alive
	bool getAlive();
	//update the entity
	virtual void update(){};
};

