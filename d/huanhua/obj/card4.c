// card4.c

inherit ITEM;

void create()
{
        set_name("佻����ɷ�������", ({"card4"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",
                "����佻����ɷ��������,�������һֻ��\n");
        set("unit", "��");
        set("weight", 10);
}
}

