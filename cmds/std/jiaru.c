inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
        object ob;
        mapping family;
        family = me->query("family");
        if((me->query("guild_name"))!=0)
        return notify_fail("�Բ������Ѿ�������"+me->query("guild_name")+"�İ�ᡣ\n");
        if( !arg ) return notify_fail("��Ҫ����˭�İ�᣿\n");
        if( !objectp(ob = find_player(arg)))
         {
            tell_object(me,"�������Ŀǰ����������ɣ�\n");
            return 1;
         }
      if(!present(arg,environment(me)))
        {
         tell_object(me,ob->query("name")+"���ڲ������\n");
         return 1;
        }
      if( ob->query_temp("yaoqing") )
         {
          if( ob->query_temp("yaoqing") == me->query("id") )
            {
             if( ! stringp(ob->query("guild_leader")) )
               return notify_fail("�Է�û�вμӰ��ɡ�\n");
             if( ! ob->query("guild_name"))
               return notify_fail("�Է�û�п������ɡ�\n");
             if( ob->query("guild_name") == "              " )
               return notify_fail("�Է�û�м�����ɡ�\n");
            tell_object(me,"���������"+ob->query("name")+"�İ�ᡣ\n");
            say(me->query("name")+"��������"+ob->query("name")+"�İ�ᡣ\n");
            me->set("guild_name",ob->query("guild_name"));
            if( me->query("family/family_name"))
            me->set("title", HIG"��" + ob->query("guild_name") + "�������ڡ�"NOR + sprintf("%s��%s������", family["family_name"],
                        chinese_number(family["generation"])));
                else
                me->set("title", HIY"��" +ob->query("guild_name")+ "�������ڡ�"NOR + "��ͨ����");
            return 1;
            }
         }
        tell_object(me,"�Է�û������������ᡣ\n");
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��jiaru <�Է�id>
���ָ���������Է��İ��.
HELP
    );
    return 1;
}

