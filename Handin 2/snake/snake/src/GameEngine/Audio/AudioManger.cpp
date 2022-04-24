#include "..\..\..\include\GameEngine\Audio\AudioManger.h"
#include "..\..\..\include\GameEngine\Audio\Pickup.h"
#include "..\..\..\include\GameEngine\Audio\Hit.h"
#include "..\..\..\include\GameEngine\Audio\click.h"
#include "..\..\..\include\GameEngine\Audio\Win.h"
#include "..\..\..\include\GameEngine\Audio\Death.h"
Pickup pick;
Hit hit;
Click click;
Win win;
Death death;
bool audioSanke::LoadAllAudio()
{
	if (pick.LoadAudio() == false) { return false; };
	if (hit.LoadAudio() == false) { return false; };
	if (click.LoadAudio() == false) { return false; };
	if (win.LoadAudio() == false) { return false; };
	if (death.LoadAudio() == false) { return false; };
	return true;
}



/// <summary>
/// play audio depending on the input
/// pickup, hit, click, win, death
/// 1 = pickup
/// 2 = hit
/// 3 = click
/// 4 = win
/// 5 = death
/// </summary>
/// <param name="SoundNum"></param>
void audioSanke::playAudio(int SoundNum)
{
	if (SoundNum == 1)
	{
		pick.playAudio();
	}
	if (SoundNum == 2)
	{
		hit.playAudio();
	}
	if (SoundNum == 3)
	{
		click.playAudio();
	}
	if (SoundNum == 4)
	{
		win.playAudio();
	}
	if (SoundNum == 5)
	{
		death.playAudio();
	}
}
