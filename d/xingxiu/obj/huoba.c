// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

inherit ITEM;

void create()
{
        set_name("火把", ({"fire", "huoba"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一支用于引火的火把，到了黑暗的地方就点(dian)得着了。\n");
                set("unit", "支");
                set("value", 100);
		  "remaining": 1,
        }
}

