// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

inherit ITEM;

void create()
{
        set_name("���", ({"fire", "huoba"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "����һ֧��������Ļ�ѣ����˺ڰ��ĵط��͵�(dian)�����ˡ�\n");
                set("unit", "֧");
                set("value", 100);
		  "remaining": 1,
        }
}

