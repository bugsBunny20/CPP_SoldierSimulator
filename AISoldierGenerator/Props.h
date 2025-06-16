#pragma once

enum class PropType
{
	HealthBooster = 0,
	ArmorBooster = 1,
	AttackBooster = 2,
};

class Props {
protected:
	int _powerUpValue;
	int posX = 0;
	int posY = 0;
	bool _isPowerUpUtilised;
	PropType _propType;
	std::string _propName;

public:
	int GetPosX();
	int GetPosY();
	PropType GetPropType();
	std :: string GetPropName();
	int PowerUpValue();
	void SetPosition(int x, int y);
	bool GetIsPowerUpUtilised();
	void SetIsPowerUpUtilised(bool poweUpUsed);
	~Props();
};