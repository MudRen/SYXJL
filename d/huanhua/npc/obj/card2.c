// card2.c

inherit ITEM;

void create()
{
        set_name("佻�����ӥ������", ({"card2"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",
                "����佻�����ӥ�������,�������һֻ��ӥ��\n");
        set("unit", "��");
        set("weight", 10);
}
}

