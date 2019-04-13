#pragma once
#include <iostream>
class PlayerStats
{
private:
	int money;
	int health;
	int armor;
	struct WeaponUpgrade
	{
		float dmgMod;
		float speedMod;
		float fireSpeedMod;
		WeaponUpgrade()
		{
			dmgMod = 1;
			speedMod = 1;
			fireSpeedMod = 1;
		}
	};
public:
	enum UpgradeType { dmg, speed, fireSpeed };
	PlayerStats();
	~PlayerStats();
	enum ArmorEquipped { light, medium, heavy, assault };
	ArmorEquipped currentArm;
	enum WeaponEquipped { pistol, rifle, shotgun};
	WeaponEquipped currentWep;

	WeaponUpgrade upgrades[3] = {WeaponUpgrade(),WeaponUpgrade(),WeaponUpgrade()};

	void BuyUpgrade(UpgradeType upg)
	{
		if (money >= 50) {
			if (upg == UpgradeType::dmg)
			{
				upgrades[int(currentWep)].dmgMod += 0.1f; money -= 50;
			}
			else if (upg == UpgradeType::speed)
			{
				upgrades[int(currentWep)].speedMod += 0.1f; money -= 50;
			}
			else if (upg == UpgradeType::fireSpeed)
			{
				upgrades[int(currentWep)].fireSpeedMod += 0.1f; money -= 50;
			}
		}
	}
	void GetUpgradeStats(float& a, float& b, float& c)
	{
		a = upgrades[int(currentWep)].dmgMod;
		b = upgrades[int(currentWep)].speedMod;
		c = upgrades[int(currentWep)].fireSpeedMod;
	}
	void UpdateEquipment() { armor = 5 + currentArm * 20; }
	void UpdateHealth(int mod) { health += mod; }
	void UpdateMoney(int mod) { money += mod; }

	int GetHealth() const { return health; }
	int GetMoney() const { return money; }
	const int GetArmor() { UpdateEquipment(); return armor; }
};

