
#include "menu.h"
#include "stm32f10x.h"
#include "lm240120.h"
#include "key.h"
#include "item.h"
#include "ir.h"
#include "param.h"

static Window_t	*ActiveWindow = &MainMenu;
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void Esc_Com(void)
{
	if(GetExtWindow(GetCurrentFocus()->Father) == NULL)
		return ;
	else
	{
		DispOneWindow(GetExtWindow(GetCurrentFocus()->Father));	
	}
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void UpDn_Com(void)
{
	if(GetCurrentFocus()->NextBrother == NULL)
	{
		return ;
	}
	else
	{
		DisSelectOneItem(GetCurrentFocus());
		SetCurrentFocus(GetCurrentFocus()->NextBrother);
		SelectOneItem(GetCurrentFocus());	
	}
		
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void Right_Com(void)
{
	
}									
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void Enter_Com(void)
{
	if(GetExtWindow(GetCurrentFocus()->BigSon) == NULL)
		return ;
	else
	{
		DispOneWindow(GetExtWindow(GetCurrentFocus()->BigSon));	
	}		
}
/*---------------------------------------------------------------------------
**	Function	: 
**	Parameters	:
**	Retval		:
**	Description	: 
---------------------------------------------------------------------------*/
void MENU_GetInput(void)
{
	u8 KeyCurrent = KEY_ID_NONE | KEY_EVENT_NONE;
	
	if(ConfigParam.CtrlMode == KEY_CTRL)
		KeyCurrent = KEY_GetValue();
	else
		KeyCurrent = IR_GetValue();

	switch(KeyCurrent)
	{
		case KEY_ID_ESC | KEY_EVENT_SHORT :
		{	
			if(	GetCurrentFocus()->OperateEsc == NULL ) 
			{
				Esc_Com();
			}
			else
			{
				GetCurrentFocus()->OperateEsc();
			}				
		}break;

		case KEY_ID_UPDOWM | KEY_EVENT_SHORT:
		{
			if(	GetCurrentFocus()->OperateUpDn == NULL )
			{
				UpDn_Com();
			}
			else
			{
				GetCurrentFocus()->OperateUpDn();
			}						
		}break;

		case KEY_ID_RIGHT | KEY_EVENT_SHORT:
		{
			if(GetCurrentFocus()->OperateRight == NULL)
			{
				Right_Com(); 
			}
			else
			{
				GetCurrentFocus()->OperateRight();	
			}
		}break;
		
		case KEY_ID_ENTER | KEY_EVENT_SHORT:
		{
			if( GetCurrentFocus()->OperateEnter == NULL )  
			{
				Enter_Com();
			}
			else
			{
				GetCurrentFocus()->OperateEnter();	
			}
		}break;	

		default :
		{
			return ;	
		}
	}		
}		
/*-----------------Data Structure Layer---------------------------------------------*/
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
Window_t *	GetActiveWindow(void)
{
	return ActiveWindow;	
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void	SetActiveWindow(Window_t *p)
{
		if(p == NULL)
			return ;
		else
		{
			ActiveWindow = p;
			return ;	
		}					
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
u8 GetItemTotal(Window_t 	*p)
{
	u8 i = 0;
	Item_t 		*pitem = p->FirstItem;
	
	while( pitem->NextBrother != p->FirstItem )
	{
		pitem = pitem->NextBrother;
		i++;			
	}
		
	return i;	
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
Item_t * 	GetCurrentFocus(void)
{
	Window_t	*ActiveWindow = GetActiveWindow();

	if(ActiveWindow == NULL)
		return NULL;
	else	
		return ActiveWindow->CurrentFocus;	
	
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void 		SetCurrentFocus(Item_t	*p)
{
	Window_t	*ActiveWindow = GetActiveWindow();
	
	if(ActiveWindow  == NULL)
		return ;
	else
	{
		SetActiveWindow(p->Window);
		GetActiveWindow()->CurrentFocus = p;
		return ;	
	}							
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void 	SelectOneItem(Item_t	*p)
{
	SetCurrentFocus(p);

	if(GetCurrentFocus() == NULL)
		return ;
	else
	{
		LM_DispIndicator(GetCurrentFocus()->X - 8,GetCurrentFocus()->Y);
	}		
}
void 	DisSelectOneItem(Item_t	*p)
{
	SetCurrentFocus(p);

	if(GetCurrentFocus() == NULL)
		return ;
	else
	{
		LM_DispChar(GetCurrentFocus()->X - 8,GetCurrentFocus()->Y,' ');
	}
}

/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
void	DispOneWindow(Window_t *p)
{
	u8 i;

	SetActiveWindow(p);
	SetCurrentFocus(p->FirstItem);

	// display window title
	LM_Clear();
	LM_DispStr(GetActiveWindow()->X,GetActiveWindow()->Y,GetActiveWindow()->Name);

	//select first item
	LM_DispStr(GetCurrentFocus()->X,GetCurrentFocus()->Y,GetCurrentFocus()->Name);
	LM_DispIndicator(GetCurrentFocus()->X - 8,GetCurrentFocus()->Y);

	SetCurrentFocus(GetCurrentFocus()->NextBrother);
	
	for(i=0;i<GetItemTotal(p);i++)
	{				
		LM_DispStr(GetCurrentFocus()->X,GetCurrentFocus()->Y,GetCurrentFocus()->Name);
		SetCurrentFocus(GetCurrentFocus()->NextBrother);
	}				
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
Item_t *	GetFather(Item_t *p)
{
	return p->Father;
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
Item_t *	GetBigSon(Item_t *p)
{
	if(p == NULL)
		return NULL;
	else
		return p->BigSon;
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
Item_t *	GetNextBrother(Item_t *p)
{
	if(p == NULL)
		return NULL;
	else
		return p->NextBrother;
}
/*---------------------------------------------------------------------------
**	Function	:
**	Parameters	:
**	Retval		:
**	Description	:
**	Attention	:
---------------------------------------------------------------------------*/
Window_t *	GetExtWindow(Item_t *p)
{	
	if(p == NULL)
		return NULL ;
	else
		return p->Window;	
}



