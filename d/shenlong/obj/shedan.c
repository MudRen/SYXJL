inherit ITEM;





void init()

{

        add_action("do_eat", "eat");

}



void create()

{

	set_name("���ߵ�", ({"dan"}));

        set("unit", "ö");

	set("long", "����һö���ĸ��ߵ���\n");

	set("value", 500);

          set("no_eat", "��Ҫ��ʲô?");
        setup();

}

