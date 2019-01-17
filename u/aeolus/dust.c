
// dust.c
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name(YEL"��ʬ��" NOR, ({"dust"}));
        set("long",
                "����һ��������ʬ�𼣵Ļ�ʬ�ۣ�ֻҪ��һ����Ϳ���\n"
                "��ȥ(dissolve)һ��ʬ�壡\n");
        set("value", 1000);
        set("unit", "��");
        set("base_unit", "��");
        set("base_weight", 1);
        set_amount(1);
}

void init()
{
        if( this_player()==environment() )
                add_action("do_dissolve", "dissolve");
}

int do_dissolve(string arg)
{
        object ob;

        if( !arg ) return notify_fail("��Ҫ�û�ʬ���ܽ�ʲô������\n");
        if( !objectp(ob = present(arg, environment(this_player()))) )
                return notify_fail("����û������������\n");
        if( living(ob) || !ob->id("corpse") )
                return notify_fail("��ʬ��ֻ�������ܽ�ʬ�塣\n");
        message_vision(YEL
                "$N��ָ������һ�㻯ʬ����$n�ϣ�ֻ����һ�����͡��������\n"
                "һ�ɿ��µĶ����$nֻʣ��һ̲��ˮ��\n" NOR, this_player(), ob);
        destruct(ob);
        add_amount(-1);
        return 1;
}
