// hua.c

// csy



#include <ansi.h>

inherit ITEM;



void init()

{

        add_action("do_eat", "eat");

}



void create()

{

        set_name( HIR "�����ܻ�" NOR , ({"mantuoluo hua", "hua"}));

        set_weight(100);

        if (clonep())

                set_default_object(__FILE__);

        else

        {

                set("long", "����һ�������ܻ������˲�֪����û��Σ�ա�\n");

                set("unit", "��");

        }

}



int do_eat(string arg)

{

        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");

        if(arg=="hua") 

        {

                switch (random(5))

                {

                        case 0:

                                this_player()->set("eff_jing",this_player()->query("max_jing"));

                                this_player()->set("jing",this_player()->query("max_jing"));

tell_object(this_player(), HIG "��ֻ��ȫ��һ�𣬵�ʱ���񱶼ӣ�\n" NOR );

                                destruct(this_object());

                                break;

                        case 1:

                                this_player()->set_temp("nopoison", 1);

tell_object(this_player(), HIC "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );

                                destruct(this_object());

                                break;

                        case 2:

                                this_player()->set("eff_qi",this_player()->query("max_qi"));

                                this_player()->set("qi",this_player()->query("max_qi"));

tell_object(this_player(), HIG "��ֻ��һ��ů��ֱ�嵤���Ѫ�ָ����٣�\n" NOR );

                                destruct(this_object());

                                break;

                        case 3:

                                this_player()->add("max_neili",2);

tell_object(this_player(), HIG "��ֻ�о����������˲��٣�\n" NOR );

                                destruct(this_object());

                                break;

                        case 4:

                                this_player()->set("eff_jing",this_player()->query("max_jing"));

                                this_player()->set("jing",this_player()->query("max_jing"));

                                this_player()->set("eff_qi",this_player()->query("max_qi"));

                                this_player()->set("qi",this_player()->query("max_qi"));

tell_object(this_player(), HIG "��ֻ�о�������Ѫʮ�ֱ�����\n" NOR );

                                destruct(this_object());

                                break;

                 }

        }

        return 1;

}



