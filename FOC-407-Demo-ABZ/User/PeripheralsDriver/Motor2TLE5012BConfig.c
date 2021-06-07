#include "Motor2TLE5012BConfig.h"
//TLE5012B框架
#include "TLE5012B.h"
//SPI传输
#include "Motor2SPI2.h"
//时钟
#include "timer.h"

//11.832636
TLE5012B_EXPORT(gMorot2Encoder,46.165962f,Motor2SPI2SetCS,Motor2SPI2WriteData,Motor2SPI2ReadData,rt_hw_us_delay)





/*************************************************************
** Function name:       Motor2ReadAngel
** Descriptions:        获取电机1角度值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
float Motor2TLE5012BReadAngel(void)
{
    return ReadTLE5012BAngle(&gMorot2Encoder);
}




