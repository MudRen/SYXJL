// xueyin-dao.c  ѩ����

#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
	set_name("ѩ����", ({ "xueyin dao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѳ�ƽ���ĵ������������ߴ磬������覣�
		һ����֪��һ�Ѿ���������\n");
		set("value", 1000000);
		set("material", "steel");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("wield_msg", HIY "ֻ�������һ����ѩ�������ʷɳ�������Ծ��$N���С�
˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n" NOR);
		set("unwield_msg", HIY "ѩ������$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
	}
	init_blade(1000);
	setup();
}