//yangpi1.c
inherit ITEM;
void create()
{
        set_name( "yangpi1", ({ "yangpi1"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һС����ƾɵ���Ƥ��\n");
                set("value", 0);
                set("material", "bamboo");
              }
}

