// key.c
// by QingP

inherit ITEM;

void create()
{
	set_name("钥匙", ({"key", "mishikey"}));
	set("long",
		"这是一把暗红色的钥匙，非金非铁，不知用什么打造而成。\n");
	set("unit", "把");
	set("weight", 10);
	set("value", 10000);
        set("no_drop", "这样东西不能离开你。\n");
}

