// ����ս�� by Aeolus 5/30/99
// 1999-2000 (C)opyright Aeolus All Right Reserved

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_COMMAND;

void create()
{
	seteuid(getuid());
	set_name(HIY "����ս��" NOR, ({ "cloak" }));

	set("unit","��");
	set("no_drop",1);
	set("no_get",1);
	set("material", "cloth");
	set("armor_prop/armor", 1000);
	set("armor_prop/dodge", 1000);
	set("light",1);
	setup();
}

void init()
{

       seteuid(geteuid());
       if (geteuid(this_player()) != "aeolus"){
	add_action ("do_give","give");
	add_action ("do_present","gift");
	set("long",@LONG
[1;35m�����ѱ�������ֻ�������·�����
[1;32m--------------------------------------------------
| [1;33m������ [1;32m|     [1;33m��  ��       [1;32m|      [1;33mЧ   ��       [1;32m|
|------------------------------------------------|
|  gift  [1;32m| gift <file name> [1;32m|����ҷ����      [1;32m|
|--------|------------------|--------------------|
|  give  [1;32m| give<cloak>to<id>[1;32m|��ĳ������ս�ס�    [1;32m|
[1;32m--------------------------------------------------[2;37;0m
LONG );
	return;
       } else {
	set("long",@LONG
    [1;33m����һ������ս�ף����׵��ռ�������[2;37;0m
[37m������������������[1;32m��[1;31m����ھ�[1;32m��[2;37;0m[37m��������������������
       ---[1;32m�� [1;37m�� [1;33m�� [2;37;0m[31m�� [1;34m�� [1;35m�� [1;31m�� [1;36m�� [2;37;0m[33mǰ[2;37;0m[37m---      
ӵ�з���֮����������ɣ���1�����������ߡ�
                        ��2���������ߡ�
                        ��3�������֮���ߡ�

ע������*�ŵĿ�����ʱ��صĶ�ĳ��ʹ�ã�ֻҪ֪����
Ӣ�����������������ϣ��κεط�����Ч����NPCҲһ��
���ã���Ҫ��NPC��ǰʹ�á���
[1;32m--------------------------------------------------
| [1;33m������ [1;32m|     [1;33m��  ��       [1;32m|      [1;33mЧ   ��       [1;32m|
|------------------------------------------------|
|*full   [1;32m|full <id>         [1;32m|�����ָ�ĳ�˵ľ���  [1;32m|
|*suck   [1;32m|suck <id>         [1;32m|����ĳ�˵ľ���      [1;32m|
| take   [1;32m|take<genre><value>[1;32m|��Ǯ��һ�ű�����    [1;32m|   
|--------|------------------|--------------------|
|*whereis[1;32m| whereis <id>     [1;32m|�г����������˵�λ��[1;32m|
|provoke [1;32m|provoke<ob>and<id>[1;32m|����ĳ�˺�ĳ�˴�ܡ�[1;32m|
|  nk    [1;32m| nk <ob> with <id>[1;32m|��ĳ��ɱĳ�ˡ�      [1;32m|
|  pk    [1;32m| pk <id> with <id>[1;32m|����Ҷ�ɱ��        [1;32m| 
|*cease  [1;32m| cease <id>       [1;32m|��ĳ�˲��ٴ�ܡ�    [1;32m|
|*dizzy  [1;32m| faint <id>       [1;32m|��ĳ���ε���        [1;32m|
|*wake   [1;32m| wake <id>        [1;32m|��ĳ�����ѡ�        [1;32m|
|*chuqiao[1;32m| chuqiao <id>     [1;32m|�Ž�ɱĳ�ˡ�        [1;32m|
|*revive [1;32m| revive <id>      [1;32m|��������(�ָ��书)  [1;32m|
|  act   [1;32m| act <id> <msg>   [1;32m|װ��ĳ��˵����      [1;32m|
|overhear[1;32m| overhear <id>    [1;32m|����ĳ��������һ��  [1;32m|
|  fly   [1;32m| fly <id>or<place>[1;32m|ȥĳ�����ڵĵط�    [1;32m|
|*freeze [1;32m| freeze <id>      [1;32m|����ĳ�ˡ�          [1;32m|
|*defrost[1;32m| defrost <id>     [1;32m|���ĳ�ˡ�          [1;32m|
|*offline[1;32m| offline <id>     [1;32m|��ĳ�����ߣ�        [1;32m|
|  gift  [1;32m| gift <file name> [1;32m|����ҷ����      [1;32m|
|  give  [1;32m| give<cloak>to<id>[1;32m|��ĳ������ս�ס�    [1;32m|
|����......                                      |[2;37;0m
LONG);
       add_action("do_full","full");
       add_action("do_suck","suck");
       add_action("do_take","take");
       add_action ("do_whereis", "whereis");
       add_action ("do_provoke", "provoke");
       add_action ("do_mob", "nk");
       add_action ("do_killer","pk");
       add_action ("do_halt","cease");
       add_action ("do_faint","dizzy"); 
       add_action ("do_wakeup", "wake");
       add_action ("do_die","chuqiao");
       add_action ("do_reincarnate","revive");
       add_action ("do_act","act");
       add_action ("do_snoop","overhear");
       add_action ("do_goto","fly");
       add_action ("do_closecommand","freeze");
       add_action ("do_opencommand","defrost");
       add_action ("do_offline","offline");
       add_action ("do_command","order");
       add_action ("do_give","give");
       add_action ("do_present","gift");
       this_player()->set_temp("heat",1);
       }
}

int do_present(string str)
{
        int i;
        object ob,*inv;
        object me;
        inv=users();
        me=this_player();
        if(!str) return notify_fail(YEL"ս��֮��˵�����뷢ʲô����������������ң�\n"NOR);
 	if(file_size(str) == -1) return notify_fail(YEL"ս��֮��˵��û���������\n"NOR);
	for(i=0;i<sizeof(inv);i++)
	{
//		if(!wizardp(inv[i]) ) continue;
		ob=new(str);
		ob->move(inv[i]);
		tell_object(inv[i],HIR""+me->name()+"������������������������������������\n
		��Ȼ����һ������������Ϻ�����˵�ʲô��������ϸһ����ԭ����"+ob->name()+"\n"NOR);

	}
	if (me->query("id")!="aeolus") log_file("GIFT", sprintf("%s ������Ƿ� %s\n", me->name(), ob->name() ));
	return 1;
}

int do_full(string str, object ob)
{
  int max;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str){
	me=this_player();
	message_vision(HIY"$N���Ϸ�����⣬�ֻ����ؽ��š���������ӡ����������������š���Ѫ�䡹��ƣ����$N�����ر��������� ...\n"NOR, me);
  } else {
	ob=this_player();
	me = LOGIN_D->find_body(str);
	message_vision(HIY"$N���Ϸ�����⣬�ֻ����ؽ��š���������ӡ����������������š���Ѫ�䡹��ƣ����$n�����ر��������� ...\n"NOR, ob, me);
	if (!me) return notify_fail (YEL"ս��֮��˵���������: �Ҳ���"+str+"\n"NOR);
  }
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);

// modified by aeolus
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_jingli");
  me->set("eff_jingli",max);
  max = me->query("max_neili");
  me->set("eff_neili",max);

  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
  return 1;
}

int do_suck(string str, object ob)
{
  int min;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str)
	return notify_fail (YEL"ս��֮��˵���������Լ���Ԫ����������\n"NOR);
  else {
	ob=this_player();  
	me = LOGIN_D->find_body(str);
	message_vision(HIY"$N����¶���Ͱ���Ц�ݣ��ֽᡸ�ȱ�ӡ�����������š������䡹��Ұ����$nͻȻȫ�����������赹 ...\n"NOR, ob, me);
	if (!me) return notify_fail (YEL"ս��֮��˵: �ݻٶ������: �Ҳ���"+str+"\n"NOR);
  }
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_sen");
  me->set("eff_sen",min);
  me->set("sen",min);

// modified by aeolus
  min = me->query("min_jing");
  me->set("eff_jing",min);
  me->set("jing",min);
  min = me->query("min_qi");
  me->set("eff_qi",min);
  me->set("qi",min);
  min = me->query("min_jingli");
  me->set("eff_jingli",min);
  min = me->query("min_neili");
  me->set("eff_neili",min);

  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);

  return 1;

}

int do_take(string str)
{
        string kind;
        int amount;
        object n_money;

        if( !str || sscanf(str, "%d %s", amount, kind)!=2 )
          return notify_fail(HIM"Syntax: take <����Ǯ> <Ǯ������>\nע�������ȱ���������Ǯ��"NOR);

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail(YEL"ս��֮��˵�������û�У�ҡ��ƨѽ��\n"NOR);
        if( amount < 1 )
                return notify_fail(YEL"��Ҫ���٣�\n"NOR);

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

		message_vision( sprintf(HIY"$N������ս�׵Ŀڴ����ͳ�%s%s%s"+HIY+"��\n"NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                       this_player());
               return 1;
}

int do_whereis(string str)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (str!=NULL_VALUE){
    fd = LOGIN_D->find_body(str);
    if (!fd) return notify_fail(YEL"ս��֮�������£��������Ϻ���û�����ѽ����\n"NOR);
    }
  me = this_player();
  if (str) {
    where = environment(find_player(str));
    if (!where) return notify_fail (YEL"ս��֮�����㱨�棺�������Ԫ�ռ䡣\n"NOR);
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

//added by aeolus 5/30/99 
int do_provoke(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail (YEL"ս��֮��˵��������˭ fight ˭��\n"NOR);
        if (sscanf( str,"%s and %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: provoke <ob1> and <ob2>\n"NOR);

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"ս��֮��˵���Ҳ��� "+st1+" �������.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"ս��֮��˵���Ҳ��� "+st2+" �������.\n"NOR);

       message_vision(HIR ""+ob1->name()+"����"+ob2->name()+"���󣺡����ְɣ�����\n" NOR,
       this_player());
               ob1->fight_ob(ob2);
               return 1;
}

int do_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail (YEL"ս��֮��˵��������˭ nk ˭��\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: nk <ob1> with <ob2>\n"NOR);

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"ս��֮��˵���Ҳ��� "+st1+" �������.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"ս��֮��˵���Ҳ��� "+st2+" �������.\n"NOR);

       message_vision(HIR ""+ob1->name()+"����"+ob2->name()+"���һ����������������\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_killer(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"ս��֮��˵��������˭��˭���?\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: pk <ob1> with <ob2>\n"NOR);
       if (!ob1 = LOGIN_D->find_body(st1))
          return notify_fail(YEL"�Ҳ��� "+st1+" �������.\n"NOR);

        if (!ob2 = LOGIN_D->find_body(st2))
          return notify_fail(YEL"�Ҳ��� "+st2+" �������.\n"NOR);
       ob1->set_temp("looking_for_trouble", 0);
       ob2->set_temp("looking_for_trouble", 0);
       ob1->kill_ob(ob2);
       write(YEL "ս��֮��˵���������ɹ�����\n" NOR);
       return 1;
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail(HIM"Syntax: cease <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"ս��֮��˵�������޴��ˣ�\n"NOR);       
  if( !ob->is_fighting() )
       return notify_fail(YEL"ս��֮��˵���������ڲ�û�д��С�\n"NOR);

  tell_room(environment(ob),HIW "����к�Ȼ������"+(string)this_player()->query("name")+"�񿡵���Ӱ��\n���Ͱ��Ķ�"+(string)ob->query("name")+"˵�����������˴������ˣ��ҿ���λ"+RANK_D->query_respect(ob)+"�������˰ɣ���\n" NOR, ob);
  tell_object(ob,HIW "����к�Ȼ������"+(string)this_player()->query("name")+"�񿡵���Ӱ��\n���Ͱ��Ķ���˵�����������˴������ˣ��ҿ���λ"+RANK_D->query_respect(ob)+"�������˰ɣ���\n"NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),CYN "�ţ�"+(string)ob->query("name")+"˵��������˵�Ķԣ��Ҳ����ٴ��ˡ���\n" NOR, ob);
  tell_object(ob,CYN "�ţ���˵��������˵�Ķԣ��Ҳ����ٴ��ˡ���\n" NOR, ob);
  tell_room(environment(ob), HIG"..."+(string)ob->query("name")+"�����ܵ����٣����������ˣ�\n"NOR, ob);
  tell_object(ob, HIG"...�������ܵ����٣����������ˣ�\n"NOR, ob);
  return 1;    
}

int do_faint (string str)
{
  object who;
  object me=this_player();
  if (!str) return notify_fail (YEL"ս��֮��˵���㲻�ܰ����Լ�Ū�Σ�\n"NOR);
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail (YEL"ս��֮��˵���� û��"+str+"��\n"NOR);
  }
  message_vision( HIR "$NͻȻ����$n����Ŀ�ཻ��$n��ʱ�����˯����󡰰ȡ���һ���赹�ڵ��ϡ�\n" NOR,me,who);
  who->delete("env/immortal");
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}

int do_wakeup (string str)
{
  object who;
  object me=this_player();
  if (!str) return notify_fail (HIM"Syntax: wake <id>\n"NOR);
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail (YEL"ս��֮��˵���� û��"+str+"��\n"NOR);
  }
  message_vision( HIG "$N���������һЩû���˶��������һ�����$n�ӵ�������������\n" NOR,me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}

int do_die (string str, object me)
{
       object ob;
  if (!str) return notify_fail(HIM"Syntax: chuqiao <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"ս��֮��˵��û�����ʣ�û����ˡ�\n"NOR);
       me=this_player();
  message_vision(HIY"ֻ��$N���ֶ������һָ����У����������������ʡ���\nһ�Ѿ޽���$N���Ľ�����ɵ��˿��У�����һ�����춯�ص��ƿ�֮����������ȥ...\n" NOR, me);
  message_vision(HIR "һ�Ѿ޽�������������羪�ף��������硣ֻ���޽���$N������ǲ��룬Ȼ��޽�����ɻؿ��У�������ȥ��\n"NOR, ob);
  ob->delete("env/immortal");
  ob->die();
  ob->set_temp("last_damage_from", "��������������");
  message_vision(HIY "ֻ��$N���ֶ������һָ����У����������������ʡ���\nһ�Ѿ޽�������лص���$N���Ľ����\n"NOR, me);
  return 1;
}

int do_reincarnate(string str)
{
  object ob;
  if (!str) return notify_fail(HIM"Syntax: revive <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"ս��֮��˵�����������\n"NOR);
  if (ob->is_ghost()){
	   write(HIW"ս��֮��˵�������������������� ... Revival Program Initializing ...\n"NOR);
           tell_object(ob,HIG"3... 2... 1... �������ȫ������ ...\n"NOR);
     } else { 
           return notify_fail(YEL"ս��֮��˵����...����˺����ǻ�ģ�\n"NOR);
  }
  write(HIW"ս��֮��˵��ɨ���� ... Scanning Object ...\n"NOR);
  tell_object(ob,HIB"ɨ���� ... ... ���ǹ�!��Ҫ���㸴����ָ�����ǰ��һ�����ݡ�\n"NOR);
  tell_room(environment(ob),HIY"һ�����ͻȻ��������������������"+(string)ob->query("name")+"����Χ��\n"NOR, ob);
  tell_object(ob,HIG"ͻȻһ����������������𣬡����������㡣�������ˣ�����ɡ�...����\n��ͻȻ�е�һ�����...\n"NOR);
  ob->reincarnate();

  ob->add("kill/killer_die",-1);
  if(ob->query("normal_die")>=1)
	ob->add("normal_die",-1);
   else 
	ob->delete("normal_die",0);

  if(ob->query("dietimes")>=1)
	ob->add("dietimes",-1);
   else 
	ob->delete("dietimes",0);

  if(ob->query("death_count")>=1)
	ob->add("death_count",-1);
   else 
	ob->delete("death_count",0);

  ob->move("/d/city/guangchang");
  ob->save();
  tell_object(ob,CYN"�㿴�˿�ͷ�ϵ����գ����ֵ���Ⱥ�����û�������������Լ��ո�����һ�����Σ�\n"NOR);
  write(HIW"ս��֮��˵������ɹ�! Revived Successfully!\n"NOR);
  return 1;    
}

int do_act(string str)
{
        object ob1;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"ս��֮��˵����Ҫװ��˭��˵����\n"NOR);
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail (YEL"act <id> say <message>\n"NOR);
       if (!ob1=present(st1,environment(this_player())))
               return notify_fail(YEL"ս��֮��˵���������û��"+st1+"�ɡ�\n"NOR);
       message("sound", CYN + ob1->name() + "˵����" + CYN +  st2 + "\n" NOR, environment(ob1), ob1);
       return 1;
}

int do_snoop(string str)
{
        object me=this_player();
        object ob;
        object obj;
        if( !str ) {
                if( objectp(ob = query_snooping(me)) )
                        write(YEL"��ս��֮�꡿�����������ڼ���" + ob->query("name") + ""YEL"���յ���ѶϢ����\n"NOR);
                return 1;

        } else if( str=="none" ) {
              if( objectp(ob = query_snooping(me))
              &&      wiz_level(ob) >= wiz_level(me) )
                snoop(me);
                write(HIG "������ֹͣ�������˵�ѶϢ��\n" NOR);
                return 1;
	}

        ob = find_player(str);
        if(!ob) ob = find_living(str);
        if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail(YEL"��ս��֮�꡿����û�м���" + ob->name() + "������ѶϢ��Ȩ����\n"NOR);

        if( me==ob ) return notify_fail(YEL"��ս��֮�꡿������ snoop none ���������\n"NOR);
                
        snoop(me, ob);
        write(YEL"��ս��֮�꡿�������ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n"NOR);
/*
        if (me->query("id")!="aeolus") {
        if( userp(ob) ) log_file("SNOOP_PLAYER",
                sprintf("%s(%s) ���� %s �� %s.\n", me->name(1), geteuid(me), ob->name(1),
                        ctime(time()) ) );
        }
*/
        if( find_player("aeolus")) {
                obj = find_player("aeolus");
                tell_object(obj,YEL+"��ս��֮�꡿��"+HIG+""+me->query("name")+""+YEL+"��ʼ����"+HIM+""+ ob->query("name")+""+YEL+"���յ���ѶϢ��\n"NOR);
        }
        return 1;
}

int do_goto(string str)
{
        object me=this_player();
        int goto_inventory = 0;
        object obj;

        if( !str ) return notify_fail(YEL"ս��֮��˵����Ҫȥ���\n"NOR);

        if( sscanf(str, "-i %s", str) ) goto_inventory = 1;

        obj = find_player(str);
        if(!obj) obj = find_living(str);
        if(!obj || !me->visible(obj)) {
                str = resolve_path(me->query("cwd"), str);
                if( !sscanf(str, "%*s.c") ) str += ".c";
                if( !(obj = find_object(str)) ) {
                        if( file_size(str)>=0 )
                                return me->move(str);
                        return notify_fail(YEL"ս��֮��˵��û�������ҡ������ط���\n"NOR);
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail(YEL"ս��֮��˵��������û�л������� goto��\n"NOR);

        me->move(obj);

        return 1;
}

int do_closecommand(string arg)
{
        object me=this_player(),victim;
        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !arg )
                return notify_fail(YEL"ս��֮��˵����ӡ˭��\n"NOR);
        victim = LOGIN_D->find_body(arg);
        if (!victim) victim = present(arg, environment(me));
        if( !victim || !victim->is_character())
                return notify_fail(YEL"ս��֮��˵��û�д��ˡ�\n"NOR);

        if( victim->name() == "aeolus") {
                tell_object(me, "������<��ħ��>������ȥ��һ���غ�~\n");
                me->delete("env/immortal");
                me->die();
        }
	message_vision(HIB"$N��һ�һ��ӡ��<��ħ��>���ֵķ�ֽ��$n���˹�����$n��û�з�Ӧ��������ֽ�Ѿ�մ����$n��ͷ...\n"NOR, me, victim);
	victim->set_temp("block_msg/all",1);
	victim->disable_player();
	victim->set("disable_type",HIB"<��ħ��>"NOR);
	victim->save();

        return 1;
}

int do_opencommand(string arg)
{
        object me=this_player(),victim;
        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !arg )
                return notify_fail(YEL"ս��֮��˵����˭��⣿\n"NOR);
        victim = LOGIN_D->find_body(arg);
        if (!victim) victim = present(arg, environment(me));
        if( !victim || !victim->is_character())
                return notify_fail(YEL"ս��֮��˵��û�д��ˣ�\n"NOR);

	message_vision(HIB"$Nһ���֣�<��ħ��>��$n��ͷ�Ϸ�����$N�����С�$n���̾���ȫ����̩���ָֻ������� ...\n"NOR, me, victim);
	victim->set_temp("block_msg/all",0);
	victim->enable_player();
	victim->delete("disable_type");
	victim->save();

        return 1;
}

int do_offline (string str)
{
  object ob;
  seteuid(ROOT_UID);
  if (!str) return notify_fail(HIM"Syntax: offline <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"ս��֮��˵��û�ҵ�����ˡ�\n"NOR);     
  if (ob->query("name")=="����") {
       tell_object(ob,""+this_player()->query("name")+"��"+this_player()->query("id")+"������մ�Ҫ������ߣ�\n");
       return notify_fail(HIR"ս��֮���ŭ��˵�����������׶�����ߣ�û�Ŷ���\n"NOR);
       }  
  tell_object(ob,HIR"������ս�ס������㣺��Υ������������������ȥ��...\n"NOR);
  destruct(ob);
  if(ob) write(YEL"ս��֮��˵�����޷�������˸��ߡ�\n"NOR);
        else write(YEL"ս��֮��˵��"+ob->query("name")+"��"+ob->query("id")+"���Ѿ����������ˣ�\n"NOR);
  return 1;    
}

int do_command(string str)
{
        int res;
        object ob;
        string who, cmd, verb, path;
        object me=this_player();

        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !str || str=="" || sscanf(str, "%s to %s", who, cmd)!=2 )
                return notify_fail(YEL"ս��֮��˵����Ҫ����˭��ʲô��\n"NOR);
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
        if( !ob || !ob->is_character())
                return notify_fail(YEL"ս��֮��˵��û�д��ˣ�\n"NOR);

        if( sscanf(cmd, "%s %*s", verb) != 2 ) verb = cmd;

        stringp(path = ob->find_command(verb));

        if( wizardp(ob) && wiz_level(me) < wiz_level(ob) )
                return notify_fail(YEL"ս��֮��˵���㲻����������С��������ɱ����\n"NOR);
        write(HIW"������" + ob->name() + "ȥ" + cmd + "\n"NOR);
        seteuid(export_uid(ob));
        seteuid(getuid());
        res = ob->force_me(cmd);
        if (!res) return notify_fail(YEL"ս��֮��˵���Ҳ���������\n"NOR);
	return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  if (!str) return notify_fail(HIM"Syntax: give <cloak> to <id>\n"NOR);
  if (sscanf (str, "%s to %s", obs, whos)!= 2 || sscanf (str, "%s %s", whos, obs)!= 2 )
     return notify_fail(HIM"Syntax: give <cloak> to <id>\n"NOR);
  me = this_player();
  who = find_player(whos);
  wiz = wizhood (who);
  if (obs != "cloak")
     return notify_fail(HIM"Syntax: give <cloak> to <id>\n"NOR);
  write (HIG"�Է�����ʦ�ȼ� : "+wiz_level(who)+"\n"NOR);
  if (wiz_level(who) > 1)
  if(wiz_level(who)<wiz_level("(wizard)")) {
    write (YEL"ս��֮��˵������û�м�Ԧ�ҵķ�������\n"NOR);
    return 1;
  }

  ob = present ("cloak", me);
  if (!ob) write (YEL"ս��֮��˵����û������������\n"NOR);
  if (!who) write (YEL"ս��֮��˵��û������ˡ�\n"NOR);
  if (ob && who) {
    ob->move (who);
    message_vision (HIY"$N��$nһ�����׵��ռ�������������ս�ס���\n"NOR, me, who);
  }
  return 1;
}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}
