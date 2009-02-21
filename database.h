/*
 * database.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DATABASE_H
#define	_DATABASE_H

#include <list>
#include <iostream>
#include <fstream>
#include "equipment.h"
#include "fermentable.h"
#include "hop.h"
#include "mash.h"
#include "mashstep.h"
#include "misc.h"
#include "recipe.h"
#include "style.h"
#include "water.h"
#include "yeast.h"
#include "observable.h"

class Database;

/*
 * This class is a singleton, meaning that there should only ever be one
 * instance of this in the whole damn program.
 *
 * It only calls hasChanged() when a new ingredient or whatever gets added,
 * not when any of them actually changed.
 */

class Database : public Observable
{
public:
   Database(); // Don't EVER use this method to get the database!!!
   static Database* getDatabase(); // This should be the ONLY way you get an instance!!!
   static void initialize();
   static bool isInitialized();
   static void savePersistent(); // Save to the persistent medium.

   void addEquipment(Equipment* equip);
   void addFermentable(Fermentable* ferm);
   void addHop(Hop* hop);
   void addMash(Mash* mash);
   void addMashStep(MashStep* mashStep);
   void addMisc(Misc* misc);
   void addRecipe(Recipe* rec);
   void addStyle(Style* style);
   void addWater(Water* water);
   void addYeast(Yeast* yeast);

   void resortAll(); // Sorts all the lists by their compare methods.

   unsigned int getNumEquipments();
   unsigned int getNumFermentables();
   unsigned int getNumHops();
   unsigned int getNumMashs();
   unsigned int getNumMashSteps();
   unsigned int getNumMiscs();
   unsigned int getNumRecipes();
   unsigned int getNumStyles();
   unsigned int getNumWaters();
   unsigned int getNumYeasts();

   std::list<Equipment*>::iterator getEquipmentBegin();
   std::list<Equipment*>::iterator getEquipmentEnd();
   std::list<Fermentable*>::iterator getFermentableBegin();
   std::list<Fermentable*>::iterator getFermentableEnd();
   std::list<Hop*>::iterator getHopBegin();
   std::list<Hop*>::iterator getHopEnd();
   std::list<Mash*>::iterator getMashBegin();
   std::list<Mash*>::iterator getMashEnd();
   std::list<MashStep*>::iterator getMashStepBegin();
   std::list<MashStep*>::iterator getMashStepEnd();
   std::list<Misc*>::iterator getMiscBegin();
   std::list<Misc*>::iterator getMiscEnd();
   std::list<Recipe*>::iterator getRecipeBegin();
   std::list<Recipe*>::iterator getRecipeEnd();
   std::list<Style*>::iterator getStyleBegin();
   std::list<Style*>::iterator getStyleEnd();
   std::list<Water*>::iterator getWaterBegin();
   std::list<Water*>::iterator getWaterEnd();
   std::list<Yeast*>::iterator getYeastBegin();
   std::list<Yeast*>::iterator getYeastEnd();

private:
   static bool initialized;
   static Database* internalDBInstance;
   static std::fstream dbFile;
   static const char* dbFileName;
   static std::fstream recipeFile; // Why are these separate from the dbFile? To prevent duplicates.
   static const char* recipeFileName;
   static std::fstream mashFile; // Why are these separate from the dbFile? To prevent duplicates.
   static const char* mashFileName;

   // The stuff we care about...
   static std::list<Equipment*> equipments;
   static std::list<Fermentable*> fermentables;
   static std::list<Hop*> hops;
   static std::list<Mash*> mashs;
   static std::list<MashStep*> mashSteps;
   static std::list<Misc*> miscs;
   static std::list<Recipe*> recipes;
   static std::list<Style*> styles;
   static std::list<Water*> waters;
   static std::list<Yeast*> yeasts;
};

#endif	/* _DATABASE_H */
