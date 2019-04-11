#include "PlayerStats.h"



PlayerStats::PlayerStats()
{
	currentWep = WeaponEquipped::pistol;
	currentArm = ArmorEquipped::light;
	health = 100;
	money = 100;
}


PlayerStats::~PlayerStats()
{
}
