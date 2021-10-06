#include "./Menu/menu.h"

/**
  * @brief  返回上级菜单
  * @param  ms :传入当前显示总菜单状态
  * @retval 无
  */	
void Menu_goBack( sMENUSTATE * ms )
{
	if( ms->currMenu->parent != NULL )
	{
		ms->top = ms->currMenu->last_top;
		ms->currItem = ms->currMenu->lastCurrItem;
		ms->currMenu = ms->currMenu->parent;
	}
}

/**
  * @brief  进入/执行 当前选项
  * @param  ms :传入当前菜单状态
  * @retval 无
  */
void Menu_select( sMENUSTATE * ms )
{
	if( ms->currMenu->menuarr[ ms->currItem ]->child != NULL )
	{
		ms->currMenu->menuarr[ ms->currItem ]->child->last_top = ms->top;
		ms->currMenu->menuarr[ ms->currItem ]->child->lastCurrItem = ms->currItem;
		ms->currMenu = ms->currMenu->menuarr[ ms->currItem ]->child;
		ms->top = 0;
		ms->currItem = 0;
	}
	else if( ms->currMenu->menuarr[ ms->currItem ]->Func_Handler != NULL )
	{
		lcdMenu_callFunction( ms->currMenu->menuarr[ ms->currItem ]->Func_Handler );
	}
}

/**
  * @brief  选项上移
  * @param  ms :传入当前菜单状态
  * @retval 无
  */
void Menu_goUp( sMENUSTATE * ms )
{
	if( ms->currItem != 0 )
	{
		if( !( ( ms->top == 0 ) & ( ms->currItem == 0 ) ) )
		{
			ms->currItem -= 1;
			if( ms->top > ms->currItem )
			{
				ms->top -= 1;
			}
		}
	}
	else
	{
		if ( ms->currMenu->len > ms->MAX_ROWS )
		{
			ms->top = ( ms->currMenu->len - ms->MAX_ROWS );
		}
		ms->currItem = ms->currMenu->len - 1;
	}
}

/**
  * @brief  选项下移
  * @param  ms :传入当前菜单状态
  * @retval 无
  */
void Menu_goDown( sMENUSTATE * ms )
{
	if( ms->top != ms->currMenu->len )
	{
		if( ms->currItem != ms->currMenu->len - 1 )
		{
			ms->currItem += 1;
			if( ms->currItem - ms->top == ms->MAX_ROWS )
			{
				ms->top += 1;
			}
		}
		else
		{
			ms->top = 0;
			ms->currItem = 0;
		}
	}
	else
	{
		ms->top = 0;
		ms->currItem = 0;
	}
}

/**
  * @brief  绘制当前菜单
  * @param  ms :传入当前菜单状态
  * @retval 无
  */
void LCD_drawMenu( sMENUSTATE * ms )
{
	uint8_t i;
	
	lcdMenu_clearScreen();
	
	lcdMenu_printTitle();
	for( i = ms->top; i < ms->top + ms->MAX_ROWS; i++ )
	{
		if( i < ms->currMenu->len )
		{
			if ( ms->currItem == i )
			{
				lcdMenu_printSelect();
			}
			else
			{
				lcdMenu_printNormal();
			}
		}
	}
}

/**
  * @brief  清除屏幕，用于刷新
  * @param  未确定
  * @retval 无
  */
void lcdMenu_clearScreen()
{


}

/**
  * @brief  打印菜单头(菜单名称)
  * @param  未确定
  * @retval 无
  */
void lcdMenu_printTitle()
{


}

/**
  * @brief  打印选中选项特殊效果(比如反色)
  * @param  未确定
  * @retval 无
  */
void lcdMenu_printSelect()
{


}

/**
  * @brief  打印显示选项
  * @param  未确定
  * @retval 无
  */
void lcdMenu_printNormal()
{


}
