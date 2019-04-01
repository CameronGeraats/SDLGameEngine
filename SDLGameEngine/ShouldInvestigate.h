#pragma once
#include "BTCondition.h"
class ShouldInvestigate :
	public BTCondition
{
public:
	void OnStart();
	BTState OnUpdate();
	ShouldInvestigate();
	~ShouldInvestigate();
};

