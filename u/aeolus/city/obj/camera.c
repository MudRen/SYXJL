inherit ITEM;
#include <ansi.h>
#include "desc.h"

void create()
{
   set_name(HIC"�����"NOR, ({"camera"})) ;
   set_weight(500);
   if (clonep())
     set_default_object(__FILE__) ;
   else {
     set("unit", "��") ;
     set("value", 200000) ;
     set("material", "steel") ;
   }
   setup() ;
}

void init()
{
     add_action("do_shoot","shoot");
}

string per_status_msg(int per, string gender)
{                                                                               
   if ( gender == "����" ) {                                               
       if ( per>=25 )                                                  
           return ( per_msg_male1[random(sizeof(per_msg_male1))]); 
     else if ( per>=20 )
           return ( per_msg_male2[random(sizeof(per_msg_male2))]); 
     else if ( per<20 )
           return ( per_msg_male3[random(sizeof(per_msg_male3))]); 
    }                                                               
   if ( gender == "Ů��" ) {
     if ( per>=25 )
           return ( per_msg_female1[random(sizeof(per_msg_female1))]); 
     else if ( per>=20 )
        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
     else if ( per<20 )
           return ( per_msg_female3[random(sizeof(per_msg_female3))]);                                                                             
    }                                                               
}                                                                               


int do_shoot(string arg)
{
        object me, obj;
        object pic, env;
        int i;
        mixed *inv;
        string objname, objid, str, pro;

        me = this_player();

        if (!arg) {
                env = environment(me);
                str = objname = env->query("short");
                if( !env ) str = "��Ƭ�ϻ����ɵ�һƬ����֪���Ǳ��������������ǳ廵�ˡ�\n";
                else {
                        str = sprintf( "%s����Ƭ\n\n    %s%s\n",env->query("short"), env->query("long"),
                        env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

                        inv = all_inventory(env);
                        for(i=0; i<sizeof(inv); i++) {
                                if ( inv[i]==me ) continue;
                                if ( inv[i]->is_character() ) {
                                        if( !me->visible(inv[i]) ) {
                                                if(!wizardp(inv[i]))
                                                        str += "  " + BLU + inv[i]->name() + NOR;
                                                else continue;
                                        }
                                        else str += "  " + inv[i]->name();

                                        str += msg_expression[random(EXP_NUM)] + "\n";
                                }
                                else str += YEL+"  [ " + inv[i]->name() +" ]\n" +NOR;
                        }
                }

                str += "\n" + me->query("name")+"����"+NATURE_D->game_time() + "��\n";
                message_vision("$N���ᰴ���˿��š�" HIY
                        "\n������һ��ѣĿ�����������һ���졭��\nһ����������Ƭ�����ˣ���\n" NOR, me);

                pic=new(__DIR__"photo");
                pic->set_name( objname + "����Ƭ", ({ "photo" }) );
                pic->set("long", str);

                if( !pic->move(me) )
                        pic->move(env);

                return 1;
        }

        if( !objectp(obj = present(arg, environment(me)) ) )
                return notify_fail("������ʲô��\n");

        if( !(obj -> is_character()) )
                return notify_fail("������˭��\n");

        objname = obj->query("name");
        objid = obj->query("id");
        str = objname+"����Ƭ\n\n";

        switch (random(6)) {
                case 0:
                        str="һ�������ع���ȵ���Ƭ����һ������ããһƬ�����ɾ�����\n";
                        str += "\n" + me->query("name")+"����"+NATURE_D->game_time() + "��\n";
                break;
                case 1:
                        str="һ�������عⲻ�����Ƭ������������ԼԼд�š���ҹ����ѻ�ڷɡ���\n";
                        str += "\n" + me->query("name")+"����"+NATURE_D->game_time() + "��\n";
                break;
                case 2:
                case 3:
                case 4:
                case 5:
                        str += obj->name() + msg_expression[random(EXP_NUM)] + "\n";
                        str += obj->long();
                        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

                        if( (string)obj->query("race")=="����" && intp(obj->query("age")) )
                                str += sprintf("%s������Լ%s���ꡣ\n", pro, 
                                        chinese_number( ( ( obj->query("always_young") && (obj->query("age")>obj->query("fake_age")) )?
                                        obj->query("fake_age"):obj->query("age")) / 10 * 10) );

                        str += pro + per_status_msg((int)obj->query("per"), obj->query("gender"));

                        inv = all_inventory(obj);
                        if( sizeof(inv) ) {
                                inv = map_array(inv, "i_look", this_object(), obj->is_corpse()? 0 : 1 );
                                inv -= ({ 0 });
                                if( sizeof(inv) )
                                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ��ţ�\n%s\n", pro, implode(inv, "\n") );
                        }
                        str += "\n" + me->query("name")+"����"+NATURE_D->game_time() + "��\n";
                break;
        }

        message_vision("$N���ᰴ���˿��š���"+HIY+"\n������һ��ѣĿ�����������һ���죬\n"
                "$n��æ�ڸ��ܿ�����ƣ��������ˣ�\n" NOR,   me, obj);

        pic=new(__DIR__"photo");
        pic->set_name( objname + "����Ƭ", ({ objid+"'s photo", "photo" }) );
        pic->set("long", str);

        if( !pic->move(this_player()) )
        pic->move(environment(this_player()));

        return 1;
}


string i_look(object obj, int flag)
{
   string str;

   str = obj->short();
   if( obj->query("equipped") )
     str = HIC "  ��" NOR + str;
   else if( !flag )
     str = "    " + str;
   else
     return 0;

   return str;
}

