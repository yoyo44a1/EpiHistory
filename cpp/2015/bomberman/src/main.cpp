/*
**  src/main.cpp
**  Bomberman
**
**  Created by Quentin PIDOUX on 30/04/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "../inc/Graph.hh"
#include "../inc/Bomberlib.hh"
#include "../inc/Mygame.hh"
#include "../inc/Vector3f.hh"
#include "../inc/Bloc.hh"
#include "../inc/Map.hh"
#include "../inc/Bomb.hh"
#include "../inc/Fire.hh"
#include "../inc/Character.hh"
#include "../inc/Setting.hh"

#include <iostream>
#include <unistd.h>

int main()
{
  Disp::Menu		*main_menu   = new Disp::Menu;
  Disp::MenuLabel	*menu_label  = new Disp::MenuLabel(-25, -15, 50, 20);
  MyGame		*game        = new MyGame;
  map::map		*map	     = new map::map(20, 20, 2);
  Bloc::Wall		*wall	     = new Bloc::Wall(*map);
  Bloc::Box		*box	     = new Bloc::Box(*map);
  Bloc::Blank		*blank	     = new Bloc::Blank(*map);
  Bloc::Morebomb	*Morebomb    = new Bloc::Morebomb(*map);
  Bloc::Lessbomb	*Lessbomb    = new Bloc::Lessbomb(*map);
  Bloc::Morepower	*Morepower   = new Bloc::Morepower(*map);
  Bloc::Lesspower	*Lesspower   = new Bloc::Lesspower(*map);

  Fire			*fire	     = new Fire(map, 0,0,1);
  Bombe			*bomb	     = new Bombe(0,0,1,fire);
  Setting1		config1;
  Setting2		config2;
  Character		*Character1  = new Character(map, &config1, 2, bomb);
  Character		*Character2  = new Character(map, &config2, 5, bomb);

  while(2)
    {
      game->setMap(map);
      game->add_object(wall);
      game->add_object(box);
      game->add_object(blank);
      game->add_object(Morebomb);
      game->add_object(Lessbomb);
      game->add_object(fire);
      game->add_object(bomb);
      game->add_object(Morepower);
      game->add_object(Lesspower);
      game->setCharacter1(Character1);
      game->setCharacter2(Character2);
      game->add_object(Character1);
      game->add_object(Character2);

      main_menu->add_object(menu_label);
      main_menu->lbl_ = menu_label;
      main_menu->run();

      if (menu_label->MenuDecide == true)
  	{
  	  switch (menu_label->MenuCurr) {
  	  case 1:
  	    menu_label->MenuDecide = false;
  	    game->run();
  	    break;
  	  case 2:
  	    //load
	    return 0;
  	    break;
  	  case 3:
  	    //save
	    return 0;
  	    break;
  	  case 4:
  	    return 0;
  	    break;
  	  }
  	}
    }
}