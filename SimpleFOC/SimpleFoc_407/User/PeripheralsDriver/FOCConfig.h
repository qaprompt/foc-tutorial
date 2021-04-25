#ifndef FocConfig_h
#define FocConfig_h

#include "stdint.h"

void Motor1FOCConfig_Init(void);
void Motor2FOCConfig_Init(void);
void Motor1FOCConfig_Printf(void);
void Motor2FOCConfig_Printf(void);
void Motor1FocControl(void);
void Motor2FocControl(void);
void Motor1SetTarIDIQ(float id,float iq);
void Motor2SetTarIDIQ(float id,float iq);
float GetMotor1Angle(void);
float GetMotor2Angle(void);

#endif /* FocConfig_h */
