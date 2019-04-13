#pragma once

#include <Utils.h>

class Component;

class Entity
{
public:
    inline const vector<unique_ptr<Component>>& GetComponents() { return components; }

private:
    vector<unique_ptr<Component>> components;
};