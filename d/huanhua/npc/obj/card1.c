// card1.c

inherit ITEM;

void create()
{
        set_name("佻�������������", ({"card1"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",
                "����佻��������������,�������һֻ������\n");
        set("unit", "��");
        set("weight", 10);
}
}

