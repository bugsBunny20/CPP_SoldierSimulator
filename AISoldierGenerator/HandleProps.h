#pragma once
#include "Props.h"
#include "PropsFactory.h"
#include "Grid.h"

enum class PropType;
class HandleProps {
private: 
	   int propsCount;
	   int propsTypeCount;
	   PropsFactory* propsFactory;
	   Props** props;
public:
	HandleProps();
	void CreateProps();
	void SetProps(Grid* grid);
	Props** GetProps();
	Props* GetProp(int index);
	int GetPropsCount();
	~HandleProps();
};