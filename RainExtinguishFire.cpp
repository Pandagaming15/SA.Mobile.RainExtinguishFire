#include "RainExtinguishFire.h"

int32_t currAreas;
float Rains;

void GetVal()
{
    Rains = *(float*)(libs.pGame + 0xA7D164);
    currAreas = *(int32_t*)(libs.pGame + 0x95957C);
}



void RainExtinguishFire::Process()
{
	GetVal();
	float rainIntensity = Rains - 0.3f;
    if (rainIntensity > 0.1f && currAreas == 0)
    {
		rainIntensity *= 0.75f;
		for (int i = 0; i < MAX_NUM_FIRES; ++i)
        {
			if (gFireManager.m_aFires[i].m_fStrength > 0.0f)
            {
				CVector firePos = gFireManager.m_aFires[i].m_vecPosition;
                eZoneAttributes zoneAttr = CCullZones::FindAttributesForCoors(firePos);
				if ((zoneAttr & eZoneAttributes::ATTRZONE_NORAIN) == 0)
				{
				    gFireManager.ExtinguishPointWithWater(gFireManager.m_aFires[i].m_vecPosition, 0.5f, rainIntensity);
				}
			}
		}
	}
}
         
