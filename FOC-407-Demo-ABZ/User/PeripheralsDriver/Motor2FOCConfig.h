#ifndef Motor2FocConfig_h
#define Motor2FocConfig_h

#include "stdint.h"

void Motor2FOCConfig_Init(void);
void Motor2FOCConfig_Printf(void);
void Motor2FocControl(void);
void Motor2SetTarIDIQ(float id,float iq);
float Motor2GetPreIDIQ(void);
float Motor2GetAngle(void);


#endif /* Motor2FocConfig_h */
