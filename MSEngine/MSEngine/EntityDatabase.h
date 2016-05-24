/* MANTAS */

#pragma once

#include <vector>

class EntityBase;

class EntityDatabase{
protected:
	static EntityDatabase* classPointer;
	std::vector<EntityBase*> entityStorage;
public:
	EntityDatabase();
	~EntityDatabase();
	static EntityDatabase* use();
	void add(EntityBase* entity);
	std::vector<EntityBase*> getEntityList();
	void destroy(EntityBase* entity);
	void clear();
};

