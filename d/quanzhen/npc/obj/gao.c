// gao.c ���߸�
// By csy 1999.03

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"���߸�"NOR, ({"guiling gao","gao"}));
        set_weight(3000);
        set("unit", "��");
        set("long", "����һ�����ڹ�׺��������óɵĹ��߸࣬�����������١�\n");
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="gao")
        {
                if ((int)me->query("max_jingli")<=300) {
                        write(YEL"�������һ����߸ֻ࣬���þ�����֮��������ֱ
�����ڶ�����\n"NOR);
                        me->add("max_jingli",25);
                        me->add("jingli",25);
                }
                else {
                        write("�������һ����߸࣬���Ǻ���ûʲô�á�\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}