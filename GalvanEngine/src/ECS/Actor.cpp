﻿#include "ECS/Actor.h"
#include "Prerequisites.h"
#include "ShapeFactory.h"

Actor::Actor(std::string actorName)
{
    // Setup Actor name
    n_name = actorName;

    // Setup Shape
    EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
    addComponent(shape);

    // Setup Transform

    // Setup Sprite
}