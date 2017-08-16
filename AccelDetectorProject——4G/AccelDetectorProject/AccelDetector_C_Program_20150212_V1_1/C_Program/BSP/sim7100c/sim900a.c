#include "sim900a.h"
#include "usart.h"		
#include "delay.h"	 
#include "string.h" 
#include "key.h"
#include "usart.h" 
//#include "oled.h"
#include "math.h"
#include "stdio.h"
//#include "STMFLASH.h"
//********************************************************************************
//��
//////////////////////////////////////////////////////////////////////////////////	
u8 SIM900_CSQ[3];
u8 dtbuf[50];   								//��ӡ������	
u8 Flag_Rec_Message=0;
/////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//usmart֧�ֲ��� 
//���յ���ATָ��Ӧ�����ݷ��ظ����Դ���
//mode:0,������USART2_RX_STA;
//     1,����USART2_RX_STA;
void sim_at_response(u8 mode)
{
	if(USART2_RX_STA&0X8000)		//���յ�һ��������
	{ 
		USART2_RX_BUF[USART2_RX_STA&0X7FFF]=0;//��ӽ�����
		printf("%s",USART2_RX_BUF);	//���͵�����
		if(mode)USART2_RX_STA=0;		
	} 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//ATK-SIM900A �������(���Ų��ԡ����Ų��ԡ�GPRS����)���ô���
//sim900a���������,�����յ���Ӧ��
//str:�ڴ���Ӧ����
//����ֵ:0,û�еõ��ڴ���Ӧ����
//    ����,�ڴ�Ӧ������λ��(str��λ��)
u8* sim900a_check_cmd(u8 *str)
{
	char *strx=0;
	if(USART2_RX_STA&0X8000)		//���յ�һ��������
	{ 
		USART2_RX_BUF[USART2_RX_STA&0X7FFF]=0;//��ӽ�����
		strx=strstr((const char*)USART2_RX_BUF,(const char*)str);
	} 
	return (u8*)strx;
}
//��sim900a��������
//cmd:���͵������ַ���(����Ҫ��ӻس���),��cmd<0XFF��ʱ��,��������(���緢��0X1A),���ڵ�ʱ�����ַ���.
//ack:�ڴ���Ӧ����,���Ϊ��,���ʾ����Ҫ�ȴ�Ӧ��
//waittime:�ȴ�ʱ��(��λ:10ms)
//����ֵ:0,���ͳɹ�(�õ����ڴ���Ӧ����)
//       1,����ʧ��
u8 sim900a_send_cmd(u8 *cmd,u8 *ack,u16 waittime)
{
	u8 res=0; 
	USART2_RX_STA=0;USART2_RX_REC_ATCOMMAD=1;
	if((u32)cmd<=0XFF)
	{
		while(DMA1_Channel7->CNDTR!=0);	//�ȴ�ͨ��7�������   
		USART2->DR=(u32)cmd;
	}else u2_printf("%s\r\n",cmd);//��������
	if(ack&&waittime)		//��Ҫ�ȴ�Ӧ��
	{
		while(--waittime)	//�ȴ�����ʱ
		{
			delay_ms(10);
			if(USART2_RX_STA&0X8000)//���յ��ڴ���Ӧ����
			{
				if(sim900a_check_cmd(ack))break;//�õ���Ч���� 
				USART2_RX_STA=0;
			} 
		}
		if(waittime==0)res=1; 
	}
	USART2_RX_STA=0;USART2_RX_REC_ATCOMMAD=0;
	return res;
} 

u8 sim900a_work_test(void)
{
	if(sim900a_send_cmd((u8 *)"AT",(u8 *)"OK",100))
	{
		if(sim900a_send_cmd((u8 *)"AT",(u8 *)"OK",100))return SIM_COMMUNTION_ERR;	//ͨ�Ų���
	}		
	if(sim900a_send_cmd((u8 *)"AT+CPIN?",(u8 *)"READY",400))return SIM_CPIN_ERR;	//û��SIM��
	if(sim900a_send_cmd((u8 *)"AT+CREG?",(u8 *)"0,1",400))
	{
		if(strstr((const char*)USART2_RX_BUF,"0,5")==NULL)
		{
			 if(!sim900a_send_cmd((u8 *)"AT+CSQ",(u8 *)"OK",200))	
			 {
					memcpy(SIM900_CSQ,USART2_RX_BUF+15,2);
			 }
			 return SIM_CREG_FAIL;	//�ȴ����ŵ�����
		}
	}	
	return SIM_OK;
}
u8 GSM_Dect(void)
{
	u8 res;
	res=sim900a_work_test();	
	switch(res)
	{
		case SIM_OK:
			UART1SendString("GSMģ���Լ�ɹ�\r\n",strlen("GSMģ���Լ�ɹ�\r\n"));
			break;
		case SIM_COMMUNTION_ERR:
			UART1SendString("��GSMģ��δͨѶ�ɹ�����ȴ�\r\n",strlen("��GSMģ��δͨѶ�ɹ�����ȴ�\r\n"));
			break;
		case SIM_CPIN_ERR:
			UART1SendString("û��⵽SIM��\r\n",strlen("û��⵽SIM��\r\n"));	
			break;
		case SIM_CREG_FAIL:
			UART1SendString("ע�������С�����\r\n",strlen("ע�������С�����\r\n"));	
			UART1SendString("��ǰ�ź�ֵ��",strlen("��ǰ�ź�ֵ��"));	UART1SendString(SIM900_CSQ,2);UART1SendString("\r\n",2);
			break;		
		default:
			break;
	}
	return res;
}
u8 SIM900A_CONNECT_SERVER(u8 *IP_ADD,u8 *COM)
{		
		//if(sim900a_send_cmd((u8 *)"AT+NETCLOSE",(u8 *)"+NETCLOSE: 0",100))	 return 7;	  
		if(sim900a_send_cmd((u8 *)"AT+CGREG?",(u8 *)"0,1",100))	 return 1;
		//if(sim900a_send_cmd((u8 *)"AT+CIPHEAD=1",(u8 *)"OK",100))	 return 7;	  
		if(sim900a_send_cmd((u8 *)"AT+CGSOCKCONT=1,\"IP\",\"cmnet\"",(u8 *)"OK",200))	return 3;
		if(sim900a_send_cmd((u8 *)"AT+CSOCKSETPN=1",(u8 *)"OK",600))	return 4;
		//if(sim900a_send_cmd((u8 *)"AT+CIPMODE=1","",500))	return 8;	  //͸��
		if(sim900a_send_cmd((u8 *)"AT+NETOPEN",(u8 *)"+NETOPEN: 0",1000))	
		{
			//if(strstr((const char*)USART2_RX_BUF,"Network is already opened")==NULL)	
			//{
				sim900a_send_cmd((u8 *)"AT+NETCLOSE",(u8 *)"+NETCLOSE: 0",1000);
				return 5;			
			//}			
		}
		if(sim900a_send_cmd((u8 *)"AT+IPADDR",(u8 *)"OK",500))	return 6;		
	  sprintf((char*)dtbuf,"AT+CIPOPEN=0,\"TCP\",\"%s\",%s",IP_ADD,COM);
		//sprintf((char*)dtbuf,"AT+CIPOPEN=0,\"TCP\",\"%s\",\%s\",IP_ADD,COM);
	  if(sim900a_send_cmd((u8 *)dtbuf,(u8 *)"+CIPOPEN: 0,0",1000))	return 7;		
	  return 0;
}	
u8 SIM900A_CONNECT_SERVER_SEND_INFOR(u8 *IP_ADD,u8 *COM)
{
	u8 res;	
	res=SIM900A_CONNECT_SERVER(IP_ADD,COM);	
	return res;
}
u8 SIM900A_GPRS_SEND_DATA(u8 *temp_data)
{		
	 //UART3SendString("�������ݷ��ͣ��������ݣ�",strlen("�������ݷ��ͣ��������ݣ�"));	
	 if(sim900a_send_cmd("AT+CIPSEND=0,",">",100))	 return 1;
	 //UART3SendString((u8*)temp_data,strlen((u8*)temp_data));	UART3SendString("\r\n",2);
	 if(sim900a_send_cmd(temp_data,NULL,0))	return 2;
	 if(sim900a_send_cmd((u8 *)0x1a,(u8 *)"SEND OK",1500))	return 3;		
	 //UART3SendString("���ݷ��ͳɹ�",strlen("���ݷ��ͳɹ�"));	UART3SendString("\r\n",2);
	 return 0;
}	
