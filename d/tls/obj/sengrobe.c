// sengrobe.c ɮ��

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɫɮ��", ({"pao", "cloth", "seng pao"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	    set("female_only", 1);
        set("unit", "��");
		set("long", "���Ǽ��ʵ������ɮ�ۣ����ϻ����Ż��ء�\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
