
#ifndef _SPI_HAL_H_
#define _SPI_HAL_H_

#include "ringbuffer.h"
#include "startup.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* SPI unit and clock definition */
#define SPI_UNIT                        (M4_SPI4)
#define SPI_UNIT_CLOCK                  (PWC_FCG1_PERIPH_SPI4)

#define SPI_RX_IRQn                     (Int006_IRQn)
#define SPI_RX_INT_SOURCE               (INT_SPI4_SRRI)

/* SPI DMA unit and channel definition */
#define SPI_DMA_UNIT                    (M4_DMA1)
#define SPI_DMA_CLOCK_UNIT              (PWC_FCG0_PERIPH_DMA1)
#define SPI_DMA_TX_CHANNEL              (DmaCh1)
#define SPI_DMA_RX_CAHNNEL              (DmaCh2)
#define SPI_DMA_TX_TRIG_SOURCE          (EVT_SPI3_SRTI)
#define SPI_DMA_RX_TRIG_SOURCE          (EVT_SPI3_SRRI)
#define SPI_DMA_TX_COMPLETE_IRQn        (Int003_IRQn)
#define SPI_DMA_TX_COMPLETE_NUM         (INT_DMA1_TC1) 

/* Choose SPI master or slave mode */
#define SPI_MASTER_MODE
//#define SPI_SLAVE_MODE


#define SPI_RECV_DATA_SIZE 400
#define SPI_SEND_DATA_SIZE 200
#define SPI_DMA_TX_DATA_SIZE 200
#define SPI_DMA_RX_DATA_SIZE 100
#define SPI_DMA_BLK_SIZE 200 
#define SPI_DMA_TX_CNT  1
#define spipackheadlen  3u

#define isvalidtxlen(len) (len>0?(len<=SPI_DMA_TX_DATA_SIZE?len:SPI_DMA_TX_DATA_SIZE):0);

typedef enum
{
    SPI4_INDEX=0,
    SPI3_INDEX,
    SPI_MAX,
}spiIndex;

typedef struct
{
    unsigned char      *rxBufPtr;
    unsigned short int  rxBufSize;
    unsigned char      *txBufPtr;
    unsigned short int  txBufSize;
}spi_Table;


typedef enum{
	hal= (unsigned char)0x00, 
	mid,
	app,
}spilayer;
	
typedef enum{
	rx_dir=(unsigned char)0x00,
    tx_dir,
}spi_com_dir;

typedef enum{
	tx_idle=(unsigned char)0x00,
	tx_pending,
	tx_finished,
	tx_wait_finish,
	tx_resend,
	rx_idle,
	rx_pending,
	rx_finishied,
	}spi_com_sts; 


typedef struct{
	unsigned char hal_tx_flag;
	unsigned char hal_rx_flag;
	unsigned char mid_tx_flag;
	unsigned char mid_rx_flag;
	}_spi_com_flag;

#ifdef __cplusplus
}
#endif

#endif 
