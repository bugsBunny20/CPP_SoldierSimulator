#include <iostream>
#include <time.h>
#include "PropsFactory.h"
#include "Props.h"
#include "HandleProps.h"
#include "Grid.h"

HandleProps::HandleProps() {
	propsCount = 50;
	props = new Props* [propsCount];
	propsTypeCount = 3;
	propsFactory = new PropsFactory();
}

void HandleProps::CreateProps()
{

	srand(time(0));

	for (int i = 0; i < propsCount; i++)
	{
		int randomSeed = (rand() % propsTypeCount);
		PropType propType = static_cast<PropType>(randomSeed);
		Props* prop = propsFactory->CreateProp(propType);
		if (prop != NULL)
		{
			props[i] = prop;
		}
	}
}

void HandleProps::SetProps(Grid* grid)
{
	srand(time(0));
	bool isPropSet;

	for (int j = 0; j < propsCount; j++)
	{
		int posX = (rand() % grid->getSizeX()) + 1;
		int posY = (rand() % grid->getSizeY()) + 1;
		isPropSet = grid->SetProps(posX, posY, props[j]);
		if (!isPropSet)
		{
			j--;
		}
		else
		{
			std::cout << props[j]->GetPropName() << " set to : (" << posX << "," << posY << ")" << std::endl;
		}
	}
}

Props** HandleProps::GetProps()
{
	return props;
}

Props* HandleProps::GetProp(int index)
{
	return props[index];
}

int HandleProps::GetPropsCount()
{
	return propsCount;
}

HandleProps :: ~HandleProps()
{
	for (int i = 0; i < propsCount; i++) {
		delete props[i];
	}
	delete[] props;
}