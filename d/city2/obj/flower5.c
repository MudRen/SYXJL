// flower.c



#include <armor.h>

#include <ansi.h>



inherit HEAD;



void create()

{

	set_name(MAG"��õ��"NOR, ({ "zi meigui", "rose" }));

	set_weight(300);

	if (clonep())

		set_default_object(__FILE__);

	else {

		set("long", "����һ�使�޵���õ�塣\n");

		set("material", "����");

		set("unit", "��");

		set("unique", 1);

		set("value", 1000);

		set("wear_msg", "$N����һ��õ�壬����ͷ�ϡ�$N�������������ޡ�\n");

		set("unequip_msg", "$N��õ���ͷ��ժ��������\n");

		set("armor_prop/personality", 5);

		set("female_only", 1);

	}

	 setup();

}



