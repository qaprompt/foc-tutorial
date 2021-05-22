#include "Motor1TLE5012BConfig.h"
//TLE5012B框架
#include "TLE5012B.h"
//SPI传输
#include "Motor1SPI1.h"
//时钟
#include "timer.h"


TLE5012B_EXPORT(gMorot1Encoder,45.484787f,Motor1SPI1SetCS,Motor1SPI1WriteData,Motor1SPI1ReadData,rt_hw_us_delay)





/*************************************************************
** Function name:       Motor1ReadAngel
** Descriptions:        获取电机1角度值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
float Motor1TLE5012BReadAngel(void)
{
    return ReadTLE5012BAngle(&gMorot1Encoder);
}




