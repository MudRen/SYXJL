// card4.c

inherit ITEM;

void create()
{
        set_name("浣花剑派凤组令牌", ({"card4"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",
                "这是浣花剑派凤组的令牌,上面刻有一只金凤。\n");
        set("unit", "块");
        set("weight", 10);
}
}

