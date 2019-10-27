#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#define MAX_COMPONENTS  32
#define MAX_GROUPS      32

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID getNewComponentTypeID(){
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept{
    static ComponentID typeID = getNewComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = MAX_COMPONENTS;
constexpr std::size_t maxGroups = MAX_GROUPS;

using ComponentBitSet = std::bitset<maxComponents>;
using GroupBitSet = std::bitset<maxGroups>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component{
public:
    Entity* entity;

    virtual ~Component(){}
    virtual void init(){}
    virtual void update(double deltaTime){}
    virtual void draw(){}
};

class Entity{
private:
    Manager &manager;
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
    GroupBitSet groupBitSet;
public:
    Entity(Manager &mManager) : manager(mManager){}

    void update(double deltaTime){
        for (auto& c : components) c->update(deltaTime);
    }

    void draw(){
        for (auto& c : components) c->draw();
    }

    bool isActive() const{
        return active;
    }

    void destroy(){
        active = false;
    }

    bool hasGroup(Group mGroup){
        return groupBitSet[mGroup];
    }

    void addGroup(Group mGroup);

    void delGroup(Group mGroup){
        groupBitSet[mGroup] = false;
    }

    template <typename T>
    bool hasComponent() const{
        return componentBitSet[getComponentTypeID<T>()];
    }

    template <typename T, typename ... TArgs>
    T& addComponent(TArgs && ... mArgs){
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template <typename T>
    T& getComponent() const{
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager{
private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::array<std::vector<Entity*>, maxGroups> groupedEntities;
public:
    void update(double deltaTime){
        for (auto& e : entities) e->update(deltaTime);
    }

    void draw(){
        for (auto& e : entities) e->draw();
    }

    void refresh(){
        for (auto i(0u); i < maxGroups; i++){
            auto& vector(groupedEntities[i]);
            vector.erase(std::remove_if(std::begin(vector), std::end(vector),
            [i](Entity* mEntity){
                return !mEntity->isActive() || !mEntity->hasGroup(i);
            }), std::end(vector));
        }
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                       [](const std::unique_ptr<Entity> &mEntity){
                           return !mEntity->isActive();
                       }),
                       std::end(entities));
    }

    void addToGroup(Entity* mEntity, Group mGroup){
        groupedEntities[mGroup].emplace_back(mEntity);
    }

    std::vector<Entity*>& getGroup(Group mGroup){
        return groupedEntities[mGroup];
    }

    Entity& addEntity(){
        Entity* e = new Entity(*this);
        std::unique_ptr<Entity> uPtr(e);
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};
