#pragma once
#include <SDL2/SDL.h>

namespace GE2D {

	struct Vector2D {
		float x;
		float y;
	};

	struct Vector2DInt {
		int x;
		int y;
	};

	class Scene;

	class GameObject
	{
	public:
		virtual ~GameObject();
		virtual void update(Scene& scene) = 0;
		virtual void handleEvent(SDL_Event& event) = 0;

		unsigned long getID() { return _id; }
		Vector2D& getPosition() { return *_position; }

	protected:
		GameObject();
		GameObject(float x, float y);

		static unsigned long nextID;
		Vector2D* _position;
		
		long _id;
	private:
		GameObject(const GameObject& other) = delete;
		const GameObject& operator=(const GameObject& other) = delete;
	};
}