// fashao.c ������

inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIM"������"NOR, ({"kete ling", "ling"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ο��Ե�ҩ����Ч������\n");
                set("value", 200);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if (!me->query_condition("ill_kesou"))
        {
                write("��������û�п��ԣ����ҳ�ҩ��\n");
                return 1;
        } else {
                me->clear_condition("ill_kesou");
                message_vision("$N����һ�������飬�������ö��ˡ�\n", me);
                me->start_busy(2);
                destruct(this_object());
                return 1;
        }
}

