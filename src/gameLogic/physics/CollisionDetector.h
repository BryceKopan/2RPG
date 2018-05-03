#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "../gameObject/GameObject.h"

class CollisionDetector
{
    public:
        static void resolveCollisions(GameObject* object);
        static bool detectObjectCollision(GameObject* object, 
                ObjectVector gameObjects);
        static bool detectTileCollision(GameObject* object);

    private:
        static ObjectVector getCollidedObjects(GameObject* object,
                ObjectVector gameObjects);
};

#endif
