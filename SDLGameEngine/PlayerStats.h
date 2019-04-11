#pragma once
class PlayerStats
{
private:
	int money;
	int health;
	int armor;
	struct WeaponUpgrade
	{
		enum UpgradeType { dmg, speed, fireSpeed};
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
	PlayerStats();
	~PlayerStats();
	enum ArmorEquipped { light, medium, heavy, assault };
	ArmorEquipped currentArm;
	enum WeaponEquipped { pistol, rifle, shotgun};
	WeaponEquipped currentWep;

	WeaponUpgrade upgrades[3] = {WeaponUpgrade(),WeaponUpgrade(),WeaponUpgrade()};

	void BuyUpgrade(WeaponUpgrade::UpgradeType upg)
	{
		if (upg == WeaponUpgrade::UpgradeType::dmg)
			upgrades[int(currentWep)].dmgMod += 0.1f;
		else if (upg == WeaponUpgrade::UpgradeType::speed)
			upgrades[int(currentWep)].speedMod += 0.1f;
		else if (upg == WeaponUpgrade::UpgradeType::fireSpeed)
			upgrades[int(currentWep)].fireSpeedMod += 0.1f;
	}
	void GetUpgradeStats(int& a, int& b, int& c)
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

