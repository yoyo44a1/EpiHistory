/*
**  src/Mygame.cpp
**  Bomberman
**
**  Created by Quentin PIDOUX on 30/04/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "../inc/Mygame.hh"
#include "../inc/Map.hh"
#include "../inc/Character.hh"

#include <string>
#include <fstream>
#include <iostream>

MyGame::MyGame()
  : gdl::Game()
{
  this->Character1 = NULL;
  this->Character2 = NULL;
}

MyGame::~MyGame()
{}

void MyGame::initialize(void)
{
  window_.create();
  this->Character1->camera_->initialize();
  this->Character1->camera_->setpos(10.0f, 15.5f, 4.0f);
  this->Character1->camera_->setrot(10.0f, 0.0f, 8.0f);

  std::list<AObject*>::iterator itb = this->objects_.begin();

  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void MyGame::update(void)
{
  std::list<AObject*>::iterator itb = this->objects_.begin();

  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
    if (this->Character1 != NULL)
      this->Character1->camera_->update(gameClock_, input_);

  if (input_.isKeyDown(gdl::Keys::Escape) == true)
    this->window_.close();
}

void MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();

  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();

  this->window_.display();
}

void MyGame::unload()
{}

void MyGame::add_object(AObject *obj)
{
  this->objects_.push_front(obj);
}

void MyGame::setMap(map::map *M)
{
  this->map = M;
}

void MyGame::setCharacter1(Character *player)
{
  this->Character1 = player;
}


void MyGame::setCharacter2(Character *player)
{
  this->Character2 = player;
}

Player *MyGame::getCharacter1() const
{
  return this->Character1;
}

Player *MyGame::getCharacter2() const
{
  return this->Character2;
}

void MyGame::save_game(std::string str)
{
  this->str = str;
  mkdir(str.data(), 0777);
  // save_player();
  // save_bomb();
}