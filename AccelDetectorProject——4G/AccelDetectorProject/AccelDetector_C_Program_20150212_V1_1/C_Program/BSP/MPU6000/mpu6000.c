
#include "stm32f10x.h"
#include "mpu6000.h"
#include "delay.h"

/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
void MPU6000_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(	MPU6000_GPIO_RCC_Periph, ENABLE );

	//MPU6000 SPI GPIO Init
	GPIO_InitStructure.GPIO_Pin = MPU6000_SPI_SCK_Pin | MPU6000_SPI_MISO_Pin | MPU6000_SPI_MOSI_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MPU6000_SPI_Port, &GPIO_InitStructure);

	//MPU6000 GPIO Chip select Init
	GPIO_InitStructure.GPIO_Pin = MPU6000_GPIO_CS_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MPU6000_GPIO_CS_Port, &GPIO_InitStructure);
	GPIO_SetBits(MPU6000_GPIO_CS_Port,MPU6000_GPIO_CS_Pin);

	//MPU6000 GPIO INT Init
	GPIO_InitStructure.GPIO_Pin = MPU6000_GPIO_INT_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MPU6000_GPIO_INT_Port, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(MPU6000_GPIO_INT_Port_Source, MPU6000_GPIO_INT_Pin_Source);  
	EXTI_InitStructure.EXTI_Line=MPU6000_GPIO_INT_EXTI_Line;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = MPU6000_GPIO_INT_NVIC_Channel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE;
	NVIC_Init(&NVIC_InitStructure);		
}
/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
void MPU6000_SPI_Config(void)
{
	SPI_InitTypeDef  SPI_InitStructure;

//SPI1 locates in APB2 while SPI2 locates in APB1
#if(MPU6000_USING_SPI == 2)
	RCC_APB1PeriphClockCmd(MPU6000_SPI_RCC_Periph, ENABLE );
#endif

#if(MPU6000_USING_SPI == 1)
	RCC_APB2PeriphClockCmd(MPU6000_SPI_RCC_Periph, ENABLE );
#endif

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;	//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;			//ѡ���˴���ʱ�ӵ���̬:ʱ�����ո�
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;		//���ݲ����ڵڶ���ʱ����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;			//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	//���岨����Ԥ��Ƶ��ֵ:
	//SPI1 locates in APB2 CLK = 72MHZ/Prescaler
	//SPI2 locates in APB1 CLK = 36MHZ/Prescaler
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;			//CRCֵ����Ķ���ʽ

	SPI_Init(MPU6000_SPI, &SPI_InitStructure);  		//����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	SPI_Cmd(MPU6000_SPI, ENABLE); //ʹ��SPI����	
}
/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
//0 to enable MPU chip,1 to disable MPU chip
__inline void MPU6000_SPI_CS(u8 NewState)
{
	GPIO_WriteBit(MPU6000_GPIO_CS_Port, MPU6000_GPIO_CS_Pin,(BitAction)!NewState );
}
/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
//ȫ˫��ͨ�ţ�ͬһ��ʱ�ӣ����Է���һ�����ݣ�һ�������һ������
u8 MPU6000_SPI_ReadWriteByte(u8 TxData)
{
	while (SPI_I2S_GetFlagStatus(MPU6000_SPI, SPI_I2S_FLAG_TXE) == RESET)
	; //���ָ����SPI��־λ�������:���ͻ���ձ�־λ
    /* Send byte through the SPI1 peripheral */
    SPI_I2S_SendData(MPU6000_SPI, TxData); //ͨ������SPIx����һ������
    /* Wait to receive a byte */
    while (SPI_I2S_GetFlagStatus(MPU6000_SPI, SPI_I2S_FLAG_RXNE) == RESET)
	; //���ָ����SPI��־λ�������:���ܻ���ǿձ�־
    /* Return the byte read from the SPI bus */
    return SPI_I2S_ReceiveData(MPU6000_SPI); //����ͨ��SPIx������յ����� 
}
/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
void MPU6000_WriteReg(u8 RegAddr,u8 TxData)
{
	MPU6000_SPI_CS(MPU6000_CS_ENABLE);
	MPU6000_SPI_ReadWriteByte(RegAddr);
	MPU6000_SPI_ReadWriteByte(TxData);
	MPU6000_SPI_CS(MPU6000_CS_DISABLE);		
}
/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
u8 MPU6000_ReadReg( u8 RegAddr)
{
	u8 ReturnValue;
	MPU6000_SPI_CS(MPU6000_CS_ENABLE);
	MPU6000_SPI_ReadWriteByte(RegAddr|0x80);
	ReturnValue = MPU6000_SPI_ReadWriteByte(0xff);
	MPU6000_SPI_CS(MPU6000_CS_DISABLE);	
	return ReturnValue;
}
/*-------------------------------------------------------------------------------
**
**
**
-------------------------------------------------------------------------------*/
void MPU6000_Config(void)
{
	//u8 temp = 0xff;
	MPU6000_GPIO_Config();
	MPU6000_SPI_Config();


	delay_ms(50);
	MPU6000_WriteReg(PWR_MGMT_1, 0x00);	//�������״̬
	
	//temp = MPU6000_ReadReg(WHO_AM_I);
	
	MPU6000_WriteReg(SMPLRT_DIV, 0x07);	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
	MPU6000_WriteReg(CONFIG, 0x06);		//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
	MPU6000_WriteReg(GYRO_CONFIG, 0x18);//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
	MPU6000_WriteReg(ACCEL_CONFIG, 0x00); //���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��
			
}

s16 MPU6000_GetAccel(u8 ACCEL_OUT_H,u8 ACCEL_OUT_L)
{
	s16 temp;
	u16	H;
	u16	L;

	H = MPU6000_ReadReg(ACCEL_OUT_H);
	L = MPU6000_ReadReg(ACCEL_OUT_L);
	
	temp = (H<<8 )| L;

	return temp;
}

/*---------------------------------------------------------------------------
**	Function	: 	MPU6000_Dummy_i2c_write
**	Parameters	:
**	Retval		:
**	Description	:  Ϊ��DMP�����ֲ����SPI������I2C
**	Attention	:
---------------------------------------------------------------------------*/
int MPU6000_Dummy_i2c_write(unsigned char slave_addr, unsigned char reg_addr,
     unsigned char length, unsigned char const *data)
{
	unsigned char i;

	MPU6000_SPI_CS(MPU6000_CS_ENABLE);
	MPU6000_SPI_ReadWriteByte(reg_addr);
	
	for(i=0;i<length;i++)
	{
		MPU6000_SPI_ReadWriteByte(data[i]);	
	}
	MPU6000_SPI_CS(MPU6000_CS_DISABLE);
	return 0;
		
}
/*---------------------------------------------------------------------------
**	Function	:  MPU6000_Dummy_i2c_read
**	Parameters	:
**	Retval		:
**	Description	:  Ϊ��DMP�����ֲ����SPI������I2C
**	Attention	:
---------------------------------------------------------------------------*/
int MPU6000_Dummy_i2c_read(unsigned char slave_addr, unsigned char reg_addr,
     unsigned char length, unsigned char *data)
{
	unsigned char i;

	MPU6000_SPI_CS(MPU6000_CS_ENABLE);
	MPU6000_SPI_ReadWriteByte(reg_addr|0x80);
		
	for(i=0;i<length;i++)
	{
		data[i] = MPU6000_SPI_ReadWriteByte(0xff);
	}
	MPU6000_SPI_CS(MPU6000_CS_DISABLE);
	return 0;	
}






