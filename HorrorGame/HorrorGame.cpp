#include <iostream>
#include <SFML/Graphics.hpp>
#include <PewPewEngine/Application.h>
#include <PewPewEngine/Camera.h>
#include <PewPewEngine/ResourceManager.h>
#include <PewPewEngine/SpriteRenderer.h>
#include <PewPewEngine/physics.h>
#include <PewPewEngine/Rigibody.h>
#include <PewPewEngine/BoxCollider.h>


int main()
{
    //declaration
    PewPewEngine::ResourceManager rm;
    PewPewEngine::Application MyApp;

    //init window
    MyApp.Init(1600, 900, "BoupBipBoup");

    //create entity
    PewPewEngine::AEntity* snake = MyApp.CreateEntities<PewPewEngine::AEntity>("snake");
    PewPewEngine::AEntity* ground = MyApp.CreateEntities<PewPewEngine::AEntity>("ground");
    PewPewEngine::AEntity* collector = MyApp.CreateEntities<PewPewEngine::AEntity>("collector");

    //create ground
    PewPewEngine::SpriteRenderer* imgGroundTop = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::SpriteRenderer>(ground);
    imgGroundTop->Init(rm.getPathFromID("ground"));
    imgGroundTop->setScale(4.f, 0.8f);
    imgGroundTop->setPosition(0.f, 0.f);
    PewPewEngine::Rigibody* rbg = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::Rigibody>(ground);
    PewPewEngine::BoxCollider* colg = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::BoxCollider>(ground);
    rbg->setTypeBody(b2_staticBody);
    colg->setSize(1000.f, 1000.f);
    colg->setDensity(5);
    rbg->createBody(&MyApp.physic);

    PewPewEngine::SpriteRenderer* imgGroundBot = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::SpriteRenderer>(ground);
    imgGroundBot->Init(rm.getPathFromID("ground"));
    imgGroundBot->setScale(4.f, 0.8f);
    imgGroundBot->setPosition(0.f, 855.f);

    PewPewEngine::SpriteRenderer* imgGroundRight = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::SpriteRenderer>(ground);
    imgGroundRight->Init(rm.getPathFromID("groundRot"));
    imgGroundRight->setScale(0.8f, 4.f);
    imgGroundRight->setPosition(0.f, 0.f);

    PewPewEngine::SpriteRenderer* imgGroundLeft = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::SpriteRenderer>(ground);
    imgGroundLeft->Init(rm.getPathFromID("groundRot"));
    imgGroundLeft->setScale(0.8f, 4.f);
    imgGroundLeft->setPosition(1555.f, 0.f);

    //create snake
    PewPewEngine::SpriteRenderer* headSnake = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::SpriteRenderer>(snake);
    headSnake->Init(rm.getPathFromID("head"));
    headSnake->setScale(0.2f, 0.2f);
    headSnake->setPosition(50.f, 50.f);
    PewPewEngine::Rigibody* rb = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::Rigibody>(snake);
    PewPewEngine::BoxCollider* col = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::BoxCollider>(snake);
    rb->setTypeBody(b2_dynamicBody);
    col->setSize(50.f, 50.f);
    col->setDensity(5);
    rb->createBody(&MyApp.physic);
    rb->setLinearVelocity(b2Vec2(0.f, -100.f));

    //create heart
    PewPewEngine::SpriteRenderer* heart = MyApp.CreateComponentsAndAttachToEntity<PewPewEngine::SpriteRenderer>(collector);
    heart->Init(rm.getPathFromID("heart"));
    heart->setScale(0.35f, 0.35f);
    heart->setPosition(800.f, 450.f);

    //loop update etc..
    MyApp.Loop(&MyApp);

    return 0;
}
