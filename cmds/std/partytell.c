// by chenww

#include <ansi.h>;

// inherit F_CLEAN_UP;



int main(object me, string arg)

{

                  object *target;

                           int i;

                  mapping my_fam  = me->query("family");                  

                  target=users();

          if(! my_fam ) return notify_fail("�㲻�����κ����ɣ��޷�ʹ�á�ͬ�Ŵ�����Ƶ����\n");

         for(i=0;i<sizeof(target);i++)

     {

        if(target[i]->query("family/family_name") != my_fam["family_name"])

            continue;

        if(!arg) {

       message("vission",HIG"��"  + my_fam["family_name"]  +  "��"+me->name(1) +"(" + me->query("id") + ")�� " +  ".........."  +".\n" NOR,target[i]);

            continue;

               }

        if( sscanf(arg, "%s", arg)==1 )  {

      message("vission",HIG"��"  + my_fam["family_name"]  +  "��"+me->name(1) +"(" + me->query("id") + ")�� " +  arg +".\n" NOR,target[i]);

            continue;

               }

     }

return 1;

}



int help(object me)

{

        write(@HELP

ָ���ʽ��

ͬ���ɵ���֮��ͨѶ���á�

HELP

         );

           return 1;

}