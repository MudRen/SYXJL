// by chenww

#include <ansi.h>;

// inherit F_CLEAN_UP;



int main(object me, string arg)

{

                  object *target;

                           int i;

                  mapping my_fam  = me->query("family");                  

                  target=users();

          if(! my_fam ) return notify_fail("你不属于任何门派，无法使用“同门传呼”频道。\n");

         for(i=0;i<sizeof(target);i++)

     {

        if(target[i]->query("family/family_name") != my_fam["family_name"])

            continue;

        if(!arg) {

       message("vission",HIG"【"  + my_fam["family_name"]  +  "】"+me->name(1) +"(" + me->query("id") + ")： " +  ".........."  +".\n" NOR,target[i]);

            continue;

               }

        if( sscanf(arg, "%s", arg)==1 )  {

      message("vission",HIG"【"  + my_fam["family_name"]  +  "】"+me->name(1) +"(" + me->query("id") + ")： " +  arg +".\n" NOR,target[i]);

            continue;

               }

     }

return 1;

}



int help(object me)

{

        write(@HELP

指令格式：

同门派弟子之间通讯所用。

HELP

         );

           return 1;

}