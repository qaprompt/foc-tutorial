#ifndef SvpwmConfig_h
#define SvpwmConfig_h

#include "stdint.h"


void Motor1SvpwmGenerate(float uα,float uβ);
void Motor2SvpwmGenerate(float uα,float uβ);
uint8_t GetMotor1SVPWMSector(void);
uint8_t GetMotor2SVPWMSector(void);

#endif /* SvpwmConfig_h */
