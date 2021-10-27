# 多级菜单

* 原作者 https://github.com/kehribar/lcdMenu

因为经常需要使用加上原本的代码过于简单所以自己添加了许多功能

修正了原本进入二级以上菜单后无法返回正确位置的bug



## 使用方法

1. 自己实现清屏、打印标题、打印选项和反色选项的函数

例子:

```C
void lcdMenu_printSelect( uint8_t i, uint8_t top, char * name )
{
    /* LcdDisplayString(x坐标,y坐标,显示字符串,是否反色) */
	LcdDisplayString( 0, (i - top) * 24 + 32, name, COLOR_CONVERT );
}

void lcdMenu_printNormal( uint8_t i, uint8_t top, char * name )
{
	LcdDisplayString( 0, (i - top) * 24 + 32, name, COLOR_NORMAL );
}
```

2. 使用`MenuItemDef(ItemName, name, func, child)`声明所有的选项

`ItemName`是变量名，`name`才是显示的字符串，并且不需要加双引号。`func`是选中后执行的函数的指针，`child`是子菜单的指针

例子：

```c
MenuItemDef(Item1, 选项一, NULL, NULL);
MenuItemDef(Item2, 选项二, NULL, NULL);
```

3. 使用`ComMenuItemDef(ArrName, ...)`合并相同菜单下的选项

`ArrName`是合并后的菜单数组名，`...`是用户自己填入的刚刚声明的选项，用`MenuItem(ItemName)`来填写。

例子：

```C
ComMenuItemDef(Arr1, MenuItem(Item1), MenuItem(Item2));
```

4. 使用`MenuDef(MenuName, name, len, ArrName, Parent)`声明所有菜单

`MenuName`是菜单变量名，`name`是菜单标题字符串，`len`菜单选项数量，`Parent`上级菜单的指针

例子：

```c
MenuDef(Menu1, 主菜单, 2, ComMenuItem(Arr1), NULL);
```

5. 使用`InitMenuState(name, MaxRox, MainMenu)`初始化菜单状态

`name`是菜单状态的变量名，`MaxRox`是单页最大显示选项数量，`MainMenu`是主菜单的指针(你会创建不止一个菜单，而初始化菜单状态则只需要把开机显示的菜单指针挂上去就可以了)

例子：

```c
InitMenuState(MenuState, 5, Menu(Menu1))
```

6. 上述都完成后，就可以调用菜单的操作函数使用了！