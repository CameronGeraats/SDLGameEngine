#include "MenuControls.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Input.h"
#include "Game.h"
#include "Scene1.h"
#include "Shooter.h"
#include "SceneMenu.h"


MenuControls::MenuControls()
{
}


MenuControls::~MenuControls()
{
}

void MenuControls::Update()
{
	int menuNavigation = Input::GetKey(SDLK_RETURN) ? 1 : 0;
	menuNavigation = Input::GetKey(SDLK_ESCAPE) ? 2 : menuNavigation;
	if (menuNavigation == 1)
	{
		Shooter* temp = dynamic_cast<Shooter*>(game);
		// Downcasts to SHOOTER game instead of generic game pointer
			// Allows for Shooter specific function/member usage
		if (temp != nullptr)
		{
			//temp->switchSceneTo = new Scene1();
		}
		// Stores a pointer to a new scene that will be used to generate a real...
		// non-temporary scene.
	}
	else if (menuNavigation == 2)
	{
		Shooter* temp = dynamic_cast<Shooter*>(game);
		// Downcasts to SHOOTER game instead of generic game pointer
			// Allows for Shooter specific function/member usage
		if (temp != nullptr)
		{
			SceneMenu* temp2 = dynamic_cast<SceneMenu*>(temp->GetCurrentScene());
			if (temp2 == nullptr)
				temp->switchSceneTo = new SceneMenu();
		}
		// Stores a pointer to a new scene that will be used to generate a real...
		// non-temporary scene.
	}
}