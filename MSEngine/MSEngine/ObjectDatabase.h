/* MANTAS */

#pragma once

#include <vector>

class ObjectBase;

class ObjectDatabase{
protected:
	static ObjectDatabase* classPointer;
	std::vector<ObjectBase*> objectStorage;
public:
	ObjectDatabase();
	~ObjectDatabase();
	static ObjectDatabase* use();
	void add(ObjectBase* object);
	std::vector<ObjectBase*> getObjectList();
	void destroy(ObjectBase* object);
	void clear();
};

