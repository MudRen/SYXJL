// card1.c

inherit ITEM;

void create()
{
        set_name("浣花剑派龙组令牌", ({"card1"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",
                "这是浣花剑派龙组的令牌,上面刻有一只青龙。\n");
        set("unit", "块");
        set("weight", 10);
}
}

