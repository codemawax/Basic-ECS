#pragma once

#include <Utils.h>

class Component;

class System
{
public:
    virtual void Update() = 0;

private:
    vector<unique_ptr<Component>> components;
};