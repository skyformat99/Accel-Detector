
#ifndef _MPU6000_H
#define _MPU6000_H

#define MPU6000_IS_DMP_ENABLE		0
#define MPU6000_IS_SPI_USED			1
#define MPU6000_IS_I2C_USED			0

/*--------------------------------------Part 1---------------------------------------------------*/
//hardware map
//define SPI Channel right here
#define MPU6000_USING_SPI		2
//#define MPU6000_USING_SPI		2

#define	MPU6000_CS_ENABLE		1
#define	MPU6000_CS_DISABLE		0

#define MPU6000_GPIO_CS_Port	GPIOD
#define MPU6000_GPIO_CS_Pin		GPIO_Pin_9

#define MPU6000_GPIO_INT_Port			GPIOD
#define MPU6000_GPIO_INT_Pin			GPIO_Pin_8
#define MPU6000_GPIO_INT_Port_Source 	GPIO_PortSourceGPIOC
#define MPU6000_GPIO_INT_Pin_Source 	GPIO_PinSource5
#define MPU6000_GPIO_INT_EXTI_Line 		EXTI_Line5
#define MPU6000_GPIO_INT_NVIC_Channel	EXTI9_5_IRQn

#if(MPU6000_USING_SPI == 1)

	#define MPU6000_SPI				SPI1
	#define MPU6000_SPI_Port		GPIOA

	#define MPU6000_SPI_SCK_Port	GPIOA
	#define MPU6000_SPI_SCK_Pin		GPIO_Pin_5

	#define MPU6000_SPI_MISO_Port   GPIOA
	#define MPU6000_SPI_MISO_Pin   	GPIO_Pin_6

	#define MPU6000_SPI_MOSI_Port	GPIOA
	#define MPU6000_SPI_MOSI_Pin	GPIO_Pin_7			//PA7(STM_MOSI) TO MPU6000_SDI
		
	#define	MPU6000_GPIO_RCC_Periph	RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC
	#define	MPU6000_SPI_RCC_Periph	RCC_APB2Periph_SPI1


#endif

#if(MPU6000_USING_SPI == 2)

	#define MPU6000_SPI				SPI2
	#define MPU6000_SPI_Port		GPIOB

	#define MPU6000_SPI_SCK_Port	GPIOB
	#define MPU6000_SPI_SCK_Pin		GPIO_Pin_13

	#define MPU6000_SPI_MISO_Port   GPIOB
	#define MPU6000_SPI_MISO_Pin   	GPIO_Pin_14

	#define MPU6000_SPI_MOSI_Port	GPIOB
	#define MPU6000_SPI_MOSI_Pin	GPIO_Pin_15

	#define	MPU6000_GPIO_RCC_Periph	RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD
	#define	MPU6000_SPI_RCC_Periph	RCC_APB1Periph_SPI2

#endif

/*--------------------------------------Part 2---------------------------------------------------*/
//mpu6000 registers map

#define	SMPLRT_DIV		0x19
#define	CONFIG			0x1A
#define	GYRO_CONFIG		0x1B
#define	ACCEL_CONFIG	0x1C
#define INT_PIN_CFG	 	0x37
#define INT_ENABLE 		0x38
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define USER_CTRL 		0x6A
#define	PWR_MGMT_1		0x6B
#define	WHO_AM_I		0x75

extern void MPU6000_GPIO_Config(void);
extern void MPU6000_SPI_Config(void);
extern __inline void MPU6000_SPI_CS(u8 NewState);
extern u8 	MPU6000_SPI_ReadWriteByte(u8 TxData);
extern void MPU6000_WriteReg(u8 RegAddr,u8 TxData);
extern u8 	MPU6000_ReadReg( u8 RegAddr);
extern void MPU6000_Config(void);

extern s16 MPU6000_GetAccel(u8 ACCEL_OUT_H,u8 ACCEL_OUT_L);




//MPU6050 DMP移植是默认为MSP430+I2C模式的，以下的I2C读写，实际是通过SPI实现的
extern int MPU6000_Dummy_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
     unsigned char length, unsigned char const *data);
extern int MPU6000_Dummy_i2c_read(unsigned char slave_addr, unsigned char reg_addr,
     unsigned char length, unsigned char *data);


#endif

