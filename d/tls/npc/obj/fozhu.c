// fozhu.c

inherit ITEM;

void create()
{
	set_name("佛珠", ({"fozhu"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
		"这是串普普通通的佛珠，细细观看才看见上面有“枯荣”两个小字。n");
	set("unit", "串");
	set("weight", 10);
        set("no_drop", "这样东西不能离开你。\n");
        set("material", "wood");
	set("tianlongsi",1);
}
}

