// card3.c

inherit ITEM;

void create()
{
        set_name("佻����ɻ�������", ({"card3"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",
                "����佻����ɻ��������,�������һֻ�׻���\n");
        set("unit", "��");
        set("weight", 10);
}
}

