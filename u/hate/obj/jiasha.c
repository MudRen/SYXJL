#include <ansi.h>
#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name(HIY"ʮ����������"NOR, ({ "longxiang jiasha" }) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ѩɽ�����������ģ��ʵ����ᣬȴ��ǹ���롣\n");
                set("unit", "��");
                set("unique", 1);
                set("longxiangli",1);
         set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
               set("remove_msg", HIY "$N��$n"HIY"�����������������۵���СС��һ�š�\n" NOR);
                set("armor_prop/armor", 500);
        }
        setup();
}

void init()
{
        add_action("zhu", "zhu");
        add_action("zhu", "guan");
}
int do_zhu(string arg)
{
        int lxl;
        object me,target;
        lxl=this_object()->query("longxiangli");
        me = this_player();
        if (!arg) 
                  return notify_fail("��Ҫ��ʲô��\n");
       if (lxl>14) return notify_fail("��������ֻ���ܵõ�ʮ����������!\n"); 
        if (arg=="longxiang jiasha")
{
                tell_object(me,"��Ħȭ����,��������,׼������������ע������֮��!\n"); 
       {
message_vision(HIR"$N������������,��˫�ƽ�������,�����ʹ�����,������������ע���˵�"+ chinese_number(lxl)+"������֮��!\n"NOR,me, target);
             this_object()->add("longxiangli",1);
     me->add("neili",-500);
       }
                  return 1;     
}
}
