// shihunxing.c ʴ����
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("ʴ����", ({ "shihun xing", "xing" }) );
	set("long", 
		"����һ������ɫ��С���裬�������������ۣ��ƺ������������֮���ƳɵĻ𵯡�\n" );
	set_weight(15);
	set("unit", "��");
	set("value", 30000);

	setup();
}