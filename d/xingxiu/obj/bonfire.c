// bonfire.c �����
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"�����"NOR, ({"huoyan dui", "huoyan", "bonfire"}));
	set("long","����һ�Ѹ�Լ��ߵĻ��棬ɫ�����̣�����ɭɭ����Ѱ��������졣\n");
	set("unit", "��");
	set("weight", 300);
        set("no_get", 1);
}