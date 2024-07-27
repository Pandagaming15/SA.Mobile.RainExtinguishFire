#include "library.h"
#include "mod/amlmod.h"
#include "mod/config.h"
#include "mod/logger.h"
#include "GTASA/common.h"
#include "shared/CEvents.h"

MYMOD(RainExtinguishFire, GTASA, 1.0, PandaGaming)
NEEDGAME(com.rockstargames.gtasa)

using namespace plugin;

#include "RainExtinguishFire.h"

processScriptsEvent = []
{
	RainExtinguishFire::Process();
};

extern "C" void OnModLoad()
{
    SetEventBefore(processScripts);
}
