#ifndef Motor1FocConfig_h
#define Motor1FocConfig_h

#include "stdint.h"

void Motor1FOCConfig_Init(void);
void Motor1FOCConfig_Printf(void);
void Motor1FocControl(void);
void Motor1SetTarIDIQ(float id,float iq);
float Motor1GetPreIDIQ(void);
float Motor1GetAngle(void);


#endif /* Motor1FocConfig_h */
