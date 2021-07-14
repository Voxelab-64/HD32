#ifndef _SPI_APP_H_
#define _SPI_APP_H_
#include "spi4_app.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define spi_usednum  2ul

typedef void(*spi_app_type)(void);
typedef void(*spi_mid_type)(void);
typedef void(*spi_hal_type)(void);

typedef struct {
	spi_app_type app_init;
	spi_app_type app_main;
	spi_mid_type mid_init;
	spi_mid_type mid_main;
	spi_hal_type hal_init;
	spi_hal_type hal_main;
	}spi_appcfg;

extern inline void spi_app_main(void);
extern void spi_app_init(void);

#ifdef __cplusplus
}
#endif

#endif 





