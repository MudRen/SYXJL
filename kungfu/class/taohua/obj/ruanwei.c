// ruanwei jia

#include <ansi.h> 


#include <armor.h>



inherit ARMOR;



void create()

{

      set_name( HIR"��⬼�"NOR,({ "ruanwei jia","jia", }) );
    set_weight(1000);

	if( clonep() )

		set_default_object(__FILE__);

	else

	{

		set("unit", "��");

        	set("long", "һ����ƮƮ�ġ��������񵹴̵Ļ��ס�\n");

		set("material", "copper");

	        set("value",20000);

	        set("no_drop", "�������������뿪�㡣\n");

	        set("no_get", "�������������뿪�Ƕ���\n");

                  set("armor_prop/armor", 150);
	        set("armor_prop/dodge", -5);

	}

	setup();

}

