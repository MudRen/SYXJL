// wangding.c ��ľ����
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"��ľ����"NOR, ({"shenmu wangding", "wangding", "ding"}));
	set("long","����һ���������ߴ�С��ľ���������ɫ���������Ǿ�ϸ��ľ�ʼ���\n"
	"����ľ��֮������ԼԼ�ķ�����˿��\n");
	set("unit", "��");
	set("weight", 120);
        set("no_drop", "�������������뿪�㡣\n");
}

