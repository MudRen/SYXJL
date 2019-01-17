// duwan.c

#include <ansi.h>
inherit ITEM;

int do_eat(string arg);

void create()
{
        set_weight(50);
        set_name(RED "����" NOR, ({"du wan", "poison", "wan", "duwan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ɶ��涾Һ���ƶ��ɵĶ�ҩ��Ҫ�����벻���ˣ����Գ�����\n");
                set("value", 50);
		set("poison_type", "poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 200,
                        "id"    : "ding chunqiu",
                        "name"  : "��",
                        "duration": 15,
                ]));
                set("no_sell", 1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();

        if( !id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$Nһ�������Ѷ�ҩȫ�����������С�\n",
                       me);
        me->set_temp("die_reason", "���˶�ҩȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}
