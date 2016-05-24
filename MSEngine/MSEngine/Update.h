/* MANTAS */

#pragma once

#include <queue>

class ObjectBase;

class Update{
protected:
	static Update* updatePointer;
	std::queue<ObjectBase*> updateList;
public:
	Update();
	~Update();
	static Update* updateLogic();
	//update all the objects
	void update();
	//update the list of objects getting updated every frame
	void updateUpdateList();
};

