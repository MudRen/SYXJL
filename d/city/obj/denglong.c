#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_use", "use");
}

void create()
{
        set_name("����", ({"deng long", "deng","long"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������������ҹ�����ߵ�ʱ������(use)������\n");
                set("value", 1000);
                set("unique", 1); 
        }
        setup();
}

int do_use(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô������\n");
        if (query("used"))
        return notify_fail("�����Ѿ���ȼ���ˡ�\n");
        message_vision(HIY "$N��ȼ�˵�����һ����һ�������ܶ�ʱ����������\n" NOR, this_player());
        set("used",1);
        me->set_temp("night/light", "����");
        set("no_drop",1);
        call_out("do_used",30+random(5),me);
        return 1;
}

int do_used(object me)
{
        message_vision("$N���е����Ļ�����������ˡ�\n",me);
        me->delete_temp("night/light");
        destruct(this_object());
        return 1;
}       

