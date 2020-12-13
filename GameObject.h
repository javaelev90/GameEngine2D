#pragma once
#include <string>
#include <atomic>
#include <cstdint>

struct Position {
	int x;
	int y;
};

class GameObject
{
public:
	GameObject();
	GameObject(int x, int y);
	~GameObject();
	long getID() { return _id; }
	Position& getPosition() { return *position; }

	virtual void update() = 0;
private:
	static unsigned long nextID;
	Position* position;
	long _id;
};

