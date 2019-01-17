//  No Copyright Message (6.17.1997)

#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <command.h>
#include <net/dns.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

void create()
{
        set_name(HIW "ѩ��" NOR, ({"xue qiu","ball"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                 HIW "����һ��ѩ�׵�ѩ���������ϳ����ġ�\n" NOR);
                set("value", 1000);
                set("unit", "��");
                set("no_get", 1);
                set("no_drop", 1);
        }
       setup();
}

void init()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  if((string)me->query("id")!="renee")
  {
  write(MAG"SaY GooD ByE To YoUr LiFe!!!!"NOR);
  me->set_temp("last_damage_from", "����ѩ��ѹ");
  me->delete("env/immortal");
  me->die();
  destruct(ob);
  return;
  }
  
  add_action("full","full");
  add_action("wave","yao");
  add_action ("pk_mob", "pk");
  add_action ("do_wakeup", "wakeup");
  add_action("pick","pick");
  add_action("do_ya", "ya");
  add_action("do_pan","pan");
  add_action("do_fushen","fushen");
  add_action("do_chinese", "chinese");
  add_action("do_freeze", "freeze");
  add_action("do_unfreeze","unfreeze");
  add_action("do_mupdate", "mup");
  add_action("do_title", "title");
}

int do_mupdate(string arg)
{
        int i, n;
        object me, obj, *inv;
        string err;
        mixed *file;
        me = this_player();
//        seteuid( geteuid(me) );

        if( !arg )
                return notify_fail("ָ���ʽ��mupdate <·��>\n");

        if( arg[strlen(arg)-1]!='/' ) arg += "/";
        if(  file_size(arg)!=-2 )
                return notify_fail("û�����Ŀ¼��\n");

        file = get_dir(arg);
        if( !sizeof(file) )
                return notify_fail(arg + " is empty \n");

        for( i = 0; i < sizeof(file); i++ ) {
                if( !sscanf(file[i], "%*s.c") ) 
                        continue;
                
                file[i] = arg + file[i];
                if( file_size(file[i]) == -1 ) {
                        write("û��" + file[i] + "���������\n");
                        continue;
                }

                if( file_size(file[i]) == -2 ) 
                        continue;

                me->set("cwf", file[i]);

                if (obj = find_object(file[i])) {
                        if( obj==environment(me) ) {
                                if( file_name(obj)==VOID_OB ) {
                                        write("�㲻���� VOID_OB �����±��� VOID_OB��\n");
                                        continue;
                                }
                                inv = all_inventory(obj);
                                n = sizeof(inv);
                                while(n--)
                                        if( userp(inv[n]) ) inv[n]->move(VOID_OB, 1);
                                        else inv[n] = 0;
                        }
                        destruct(obj);
                 }
                 if (obj) {
                        write("�޷�����ɳ�ʽ�롣\n");  
                        continue;
                        }
                 write("���±��� " + file[i] + "��");
                 err = catch( call_other(file[i], "???") );
                 if (err)
                        printf( "��������\n%s\n", err );
                 else {
                        write("�ɹ���\n");
                        if( (n = sizeof(inv)) && (obj = find_object(file[i]))) {
                               while(n--)
                                      if( inv[n] && userp(inv[n]) ) inv[n]->move(obj, 1);
                               }
                      }
             }

        return 1;
}

int do_freeze(string arg)
{
        object victim;

        if (!arg) return notify_fail("Usage: freeze <player> \n");
        
        victim = present( arg, environment(this_player()) );
        if( !victim ) find_player(arg);
        if( !victim ) victim = find_living(arg);
        if( !victim ) return notify_fail("û������ˡ�\n");

        if( victim->name() == "renee") {
                tell_object(this_player(), "Nice Try! \n");
                this_player()->delete("env/immortal");
                this_player()->die();
        }
        victim->set_temp("block_msg/all",1);
        message_vision(HIW "����ɰ���"HIM "С� " HIW "��һָ�����ѩ����"HIB "$N"HIW "����!\n"NOR,victim);
        victim->set("disable_type",HIW "<Ư����ѩ��.make by Renee>"NOR);
        victim->disable_player();
	  victim->save();        
        write("Done!\n");
        return 1;
}
int do_unfreeze(string arg)
{
        object victim;

        if (!arg) return notify_fail("Usage: unfreeze <player> \n");
        
        victim = present( arg, environment(this_player()) );
        if( !victim ) find_player(arg);
        if( !victim ) victim = find_living(arg);
        if( !victim ) return notify_fail("û������ˡ�\n");

        if( victim->name() == "renee") {
                tell_object(this_player(), "Nice Try! \n");
                this_player()->delete("env/immortal");
                this_player()->die();
        }
        
        message_vision(HIW "����ɰ���"HIM "С� " HIR "������̫��������"HIB "$N" HIW "ѩ��" HIR"�۵���!\n"NOR,victim);
        victim->delete("disable_type",HIW "<Ư����ѩ��.make by Renee>"NOR);
	  victim->delete_temp("block_msg/all",1);
        victim->disable_player();
	  victim->save();        
        write("Done!\n");
        return 1;
}

int full(string str)
{
 
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[topless]: full error: �Ҳ���"+str+"\n");
  me->reincarnate();
  me->set("neili", me->query("max_neili"));
  me->set("food", me->max_food_capacity());
  me->set("water", me->max_water_capacity());
        if (wizardp(me))
                me->clear_condition();

        if (me != this_player())
  message_vision(HIW "$Nץ��һ��ѩ����$n�����\n"NOR,
                  this_player(), me);

  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[topless]: wave <����Ǯ> <Ǯ������>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("�����˰���ȴʲôҲû���ڳ�����\n");
        if( amount < 1 )
                return notify_fail("�����˰���ȴʲôҲû���ڳ�����\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$Nʹ�����ڰ��ڣ�ͻȻ��ѩ�����ڳ�%s%s%s��\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
 
        if (!str || str=="") return notify_fail ("[topless]: ������˭ PK ˭��\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�Ҳ��� "+st1+" �������.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�Ҳ��� "+st2+" �������.\n");

        message_vision(HIR "$N������"+
                ob2->name()+"��ͷ����ָ��ָ"+ob1->name()+"��  "
                +ob2->name()+"�ɻ�Ŀ��˿�$N���ֿ��˿�"+ob1->name()+"��\n\n"
                +ob2->name()+"��"+ob1->name()+"���˹�ȥ��\n"NOR,
                this_player());
               
         ob2->kill_ob(ob1);
         ob1->kill_ob(ob2);
        return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("[topless]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[topless]: wakeup error, û��"+str+"\n");
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int query_autoload()
{
  if((string)this_player()->query("id")=="renee")
    return 1;
  else return 0;
}

int pick(string str)
{
    object ob;
    object me;
    me=this_player();

    message_vision(HIY"$N���������дʡ�����������\n"NOR,me);

    ob = LOGIN_D->find_body(str);
    ob->move(environment(me));
   
     return 1;
}

int do_ya(string arg)
{
       object me, ob;

       if (!arg) return notify_fail("��Ҫѹ˭��\n");
       me = this_player();
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("�Ҳ����������.\n");
       
       message_vision(HIR "\n$N�߾�ѩ���ȣ�ȥ���ɣ�����\n\nһ���޴��ѩ������������������$n�����ϣ�\n\n\n\n      �䣡����������������������������������\n\n" NOR,
                       me, ob);    

       ob->delete("env/immortal");
       ob->set_temp("last_damage_from", "����ѩ��ѹ");
       ob->die();
       delete_temp("arg");
       return 1;
}

int do_pan(string arg)
{
       object me, ob;
       string name1, name2;

       if (!arg) return notify_fail("��Ҫ��˭��\n");
       me = this_player();
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("�Ҳ����������.\n");
       name1 = (string)me->query("name");
       name2 = (string)ob->query("name");
       tell_room(environment(me),
       name1+"���ĵİѽ�����"+name2+"ǰ�棬����һ����"+name2+"ˤ�˸�����ſ��\n", 
       ({me, ob}));

       tell_object(ob, name1+"���ĵİѽ�������ǰ�棬��û�㿪��ˤ�˸�����ſ��\n");
       tell_object(me, "�����ĵİѽ�����"+name2+"ǰ�棬����һ����"+name2+"ˤ�˸�����ſ��\n");
    
       ob->delete("env/immortal");
       ob->unconcious();
       return 1;
}

int do_fushen(string arg)
{
        object ob;
        object me = this_player();

        if( !arg ) return notify_fail("��Ҫ������˭���ϣ�\n");
        ob = present(arg, environment(me));
        if( !ob || !living(ob))
              return notify_fail("����û��������\n");

        if( ob->query_temp("body_ob") )
                return notify_fail( ob->name() + "�Ѿ����˸�����ˡ�\n");
        message_vision("$N����һ����â���$n���ڡ�\n", me, ob);
        LOGIN_D->enter_world(me, ob, 1);

        return 1;
}

int do_chinese(string arg)
{
        string key, chinz;

        if( !arg || arg=="" )
                return notify_fail("ָ���ʽ��chinese <Ӣ��>==<����>\n");

        if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
                if (chinz == "none") CHINESE_D->remove_translate(key);
                else CHINESE_D->add_translate(key, chinz);
                write( key + " == " + chinz + "\nOk.\n");
                return 1;
        }

        return 0;
}

int do_title(string arg)
{
        string tmp;
	object ob, me;
        me=this_player();
	if( !arg ) {
		printf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(me), me->short(1));
		return 1;
	}
        if (sscanf(arg, "%s %s", tmp, arg) == 2)
		ob = present(tmp, environment(me));
	if (!ob) return notify_fail("����û������ˡ�\n");

	if( strlen(arg) > 73 )
		return notify_fail("���title̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
	if( arg == "none") {
			ob->delete("title");
			write(ob->name()+"��title�Ѿ���ɾ���ˡ�\n");
			printf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1));
			return 1;
	}
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	ob->set("title", arg + NOR);
	printf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: title
 
��ʾ��Ŀǰ�Ľ׼���ͷ�Ρ�

HELP );
	return 1;
}
