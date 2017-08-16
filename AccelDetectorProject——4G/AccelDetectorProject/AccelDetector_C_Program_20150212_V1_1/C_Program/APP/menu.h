

#ifndef _MENU_H
#define _MENU_H

#include "stm32f10x.h"

#define NULL	0

typedef	struct tagItem 		Item_t;
typedef	struct tagWindow 	Window_t;

struct tagItem
{
	char 		*Name;
	s16 		X;
	s16 		Y;
	Window_t 	*Window;	

	Item_t		*Father;
	Item_t		*BigSon;
	Item_t		*NextBrother;

	void 		(*OperateEsc)(void);
	void 		(*OperateUpDn)(void);
	void 		(*OperateRight)(void);
	void 		(*OperateEnter)(void);
};

struct tagWindow
{
	char *Name;
	s16 X;
	s16 Y;
	
	Item_t 		*FirstItem;
	Item_t 		*CurrentFocus;

	u8 			(*GetItemTotal)(Window_t 	*p);
	Item_t * 	(*GetCurrentFocus)(void);
	void 		(*SetCurrentFocus)(Item_t	*p);
	void 		(*SelectOneItem)(Item_t	*p);
	void 		(*DisSelectOneItem)(Item_t	*p);
	
	Window_t *	(*GetActiveWindow)(void);
	void		(*SetActiveWindow)(Window_t *p);
	void		(*DispOneWindow)(Window_t 	*p);		
};

Window_t *		GetActiveWindow(void);
void			SetActiveWindow(Window_t *p);
void			DispOneWindow(Window_t *p);

u8 				GetItemTotal(Window_t 	*p);
Item_t * 		GetCurrentFocus(void);
void 			SetCurrentFocus(Item_t	*p);
void 			SelectOneItem(Item_t	*p);
void 			SelectOneItem(Item_t	*p);
void 			DisSelectOneItem(Item_t	*p);

Item_t *		GetFather(Item_t *p);
Item_t *		GetBigSon(Item_t *p);
Item_t *		GetNextBrother(Item_t *p);
Window_t *		GetExtWindow(Item_t *p);

void Esc_Com(void);
void UpDn_Com(void);
void Right_Com(void);
void Enter_Com(void);

extern void MENU_GetInput(void);


#endif


