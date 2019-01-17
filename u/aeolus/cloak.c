// ÁúÁÛÕ½¼× by Aeolus 5/30/99
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
	set_name(HIY "ÁúÁÛÕ½¼×" NOR, ({ "cloak" }));

	set("unit","¼ş");
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
[1;35m·¨±¦ÒÑ±»·âÒı£¬Ö»ÄÜÓÃÒÔÏÂ·¨Á¦£º
[1;32m--------------------------------------------------
| [1;33mÖäÓïÃû [1;32m|     [1;33mÓÃ  ·¨       [1;32m|      [1;33mĞ§   ¹û       [1;32m|
|------------------------------------------------|
|  gift  [1;32m| gift <file name> [1;32m|¸øÍæ¼Ò·¢ÀñÎï¡£      [1;32m|
|--------|------------------|--------------------|
|  give  [1;32m| give<cloak>to<id>[1;32m|¸øÄ³ÈËÁúÁÛÕ½¼×¡£    [1;32m|
[1;32m--------------------------------------------------[2;37;0m
LONG );
	return;
       } else {
	set("long",@LONG
    [1;33mÕâÊÇÒ»¼şÁúÁÛÕ½¼×£¬ÁÒÑ×µÄÖÕ¼«·¨±¦¡£[2;37;0m
[37m¡«¡«¡«¡«¡«¡«¡«¡«£­[1;32m¡¼[1;31mÖäÓï¿Ú¾÷[1;32m¡½[2;37;0m[37m¡«¡«¡«¡«¡«¡«¡«¡«¡«¡«
       ---[1;32mÁÙ [1;37m±ù [1;33m¶· [2;37;0m[31mÕß [1;34m½Ô [1;35mÕó [1;31mÁĞ [1;36mÔÚ [2;37;0m[33mÇ°[2;37;0m[37m---      
ÓµÓĞ·¨±¦Ö®ÈËÓĞÈı´ó½û¼É£º¡¾1¡¿ĞÄÊõ²»ÕıÕß¡£
                        ¡¾2¡¿²»»á±à³ÌÕß¡£
                        ¡¾3¡¿·ÇÌì½çÖ®ÉñÕß¡£

×¢£º±êÓĞ*ºÅµÄ¿ÉÒÔËæÊ±ËæµØµÄ¶ÔÄ³ÈËÊ¹ÓÃ£¬Ö»ÒªÖªµÀÆä
Ó¢ÎÄÃû£¬¶øÇÒÆäÔÚÏßÉÏ£¬ÈÎºÎµØ·½¶¼ÓĞĞ§¹û£¨NPCÒ²Ò»Ñù
ÓĞÓÃ£¬µ«ÒªÔÚNPCÃæÇ°Ê¹ÓÃ¡££©
[1;32m--------------------------------------------------
| [1;33mÖäÓïÃû [1;32m|     [1;33mÓÃ  ·¨       [1;32m|      [1;33mĞ§   ¹û       [1;32m|
|------------------------------------------------|
|*full   [1;32m|full <id>         [1;32m|ÓÃÀ´»Ö¸´Ä³ÈËµÄ¾«Æø  [1;32m|
|*suck   [1;32m|suck <id>         [1;32m|ÎüÊÕÄ³ÈËµÄ¾«Æø      [1;32m|
| take   [1;32m|take<genre><value>[1;32m|±äÇ®£¬Ò»ÕÅ±äÊıÕÅ    [1;32m|   
|--------|------------------|--------------------|
|*whereis[1;32m| whereis <id>     [1;32m|ÁĞ³öËùÓĞÏßÉÏÈËµÄÎ»ÖÃ[1;32m|
|provoke [1;32m|provoke<ob>and<id>[1;32m|Ìô²¦Ä³ÈËºÍÄ³ÈË´ò¼Ü¡£[1;32m|
|  nk    [1;32m| nk <ob> with <id>[1;32m|ÈÃÄ³ÈËÉ±Ä³ÈË¡£      [1;32m|
|  pk    [1;32m| pk <id> with <id>[1;32m|ÈÃÍæ¼Ò¶ÔÉ±¡£        [1;32m| 
|*cease  [1;32m| cease <id>       [1;32m|ÈÃÄ³ÈË²»ÔÙ´ò¼Ü¡£    [1;32m|
|*dizzy  [1;32m| faint <id>       [1;32m|ÈÃÄ³ÈËÔÎµ¹¡£        [1;32m|
|*wake   [1;32m| wake <id>        [1;32m|ÈÃÄ³ÈËËÕĞÑ¡£        [1;32m|
|*chuqiao[1;32m| chuqiao <id>     [1;32m|·Å½£É±Ä³ÈË¡£        [1;32m|
|*revive [1;32m| revive <id>      [1;32m|ÆğËÀ»ØÉú(»Ö¸´Îä¹¦)  [1;32m|
|  act   [1;32m| act <id> <msg>   [1;32m|×°°çÄ³ÈËËµ»°¡£      [1;32m|
|overhear[1;32m| overhear <id>    [1;32m|¼àÌıÄ³ÈËËù×öµÄÒ»ÇĞ  [1;32m|
|  fly   [1;32m| fly <id>or<place>[1;32m|È¥Ä³ÈËËùÔÚµÄµØ·½    [1;32m|
|*freeze [1;32m| freeze <id>      [1;32m|¶³½áÄ³ÈË¡£          [1;32m|
|*defrost[1;32m| defrost <id>     [1;32m|½â·âÄ³ÈË¡£          [1;32m|
|*offline[1;32m| offline <id>     [1;32m|¸ÏÄ³ÈËÏÂÏß£¡        [1;32m|
|  gift  [1;32m| gift <file name> [1;32m|¸øÍæ¼Ò·¢ÀñÎï¡£      [1;32m|
|  give  [1;32m| give<cloak>to<id>[1;32m|¸øÄ³ÈËÁúÁÛÕ½¼×¡£    [1;32m|
|´ıĞø......                                      |[2;37;0m
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
        if(!str) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÄãÏë·¢Ê²Ã´¶«Î÷¸øËùÓĞÔÚÏßÍæ¼Ò£¿\n"NOR);
 	if(file_size(str) == -1) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»ÓĞÕâ¸ö¶«Î÷\n"NOR);
	for(i=0;i<sizeof(inv);i++)
	{
//		if(!wizardp(inv[i]) ) continue;
		ob=new(str);
		ob->move(inv[i]);
		tell_object(inv[i],HIR""+me->name()+"¸ßÉùĞû²¼£ºµ±µ±µ±¡£¡£¡£·¢ÀñÎïÀ²£¡£¡£¡\n
		ºöÈ»ÁÁ¹âÒ»ÉÁ£¬Äã¾õµÃÉíÉÏºÃÏó¶àÁËµãÊ²Ã´¶«Î÷£¡×ĞÏ¸Ò»¿´£ºÔ­À´ÊÇ"+ob->name()+"\n"NOR);

	}
	if (me->query("id")!="aeolus") log_file("GIFT", sprintf("%s ¸øÍæ¼ÒÃÇ·¢ %s\n", me->name(), ob->name() ));
	return 1;
}

int do_full(string str, object ob)
{
  int max;
  object me;
  if (!geteuid()) seteuid (getuid());
  if(!str){
	me=this_player();
	message_vision(HIY"$NÁ³ÉÏ·ºÆğÉñ¹â£¬ÊÖ»º»ºµØ½á×Å¡¸²»¶¯Ã÷»ÊÓ¡¡¹£¬¿ÚÖĞÇáÇáµØÄî×Å¡¸ÁéÑªÖä¡¹¡£Æ£±¹µÄ$N½¥½¥µØ±äµÃÉñ²ÉŞÈŞÈ ...\n"NOR, me);
  } else {
	ob=this_player();
	me = LOGIN_D->find_body(str);
	message_vision(HIY"$NÁ³ÉÏ·ºÆğÉñ¹â£¬ÊÖ»º»ºµØ½á×Å¡¸²»¶¯Ã÷»ÊÓ¡¡¹£¬¿ÚÖĞÇáÇáµØÄî×Å¡¸ÁéÑªÖä¡¹¡£Æ£±¹µÄ$n½¥½¥µØ±äµÃÉñ²ÉŞÈŞÈ ...\n"NOR, ob, me);
	if (!me) return notify_fail (YEL"Õ½¼×Ö®»êËµ£º¶ÔÏó´íÎó: ÕÒ²»µ½"+str+"\n"NOR);
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
	return notify_fail (YEL"Õ½¼×Ö®»êËµ£ºÄãÏëÎü×Ô¼ºµÄÔªÆø£¿ÓĞÓÃÂğ£¿\n"NOR);
  else {
	ob=this_player();  
	me = LOGIN_D->find_body(str);
	message_vision(HIY"$NÁ³ÉÏÂ¶³öºÍ°ªµÄĞ¦Èİ£¬ÊÖ½á¡¸´È±¯Ó¡¡¹£¬¿ÚÖĞÄî×Å¡¸¾²ĞÄÖä¡¹¡£Ò°ÂùµÄ$nÍ»È»È«ÉíÍÑÁ¦£¬²îµã»èµ¹ ...\n"NOR, ob, me);
	if (!me) return notify_fail (YEL"Õ½¼×Ö®»êËµ: ´İ»Ù¶ÔÏó´íÎó: ÕÒ²»µ½"+str+"\n"NOR);
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
          return notify_fail(HIM"Syntax: take <¶àÉÙÇ®> <Ç®±ÒÖÖÀà>\n×¢£ºÄãÊ×ÏÈ±ØĞëÓĞÕâÖÖÇ®£¡"NOR);

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÄã·ÖÎÄÃ»ÓĞ£¬Ò¡¸öÆ¨Ñ½£¡\n"NOR);
        if( amount < 1 )
                return notify_fail(YEL"ÄãÒª¶àÉÙ£¿\n"NOR);

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

		message_vision( sprintf(HIY"$N´ÓÁúÁÛÕ½¼×µÄ¿Ú´üÖĞÌÍ³ö%s%s%s"+HIY+"¡£\n"NOR,
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
    if (!fd) return notify_fail(YEL"Õ½¼×Ö®»ê¶ÔÄã´óÈÂ£º¡°ÔÚÍøÉÏºÃÏóÃ»Õâ¸öÈËÑ½£¡¡±\n"NOR);
    }
  me = this_player();
  if (str) {
    where = environment(find_player(str));
    if (!where) return notify_fail (YEL"Õ½¼×Ö®»êÏòÄã±¨¸æ£ºËûÔÚÒì´ÎÔª¿Õ¼ä¡£\n"NOR);
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
        if (!str || str=="") return notify_fail (YEL"Õ½¼×Ö®»êËµ£ºÄãÏëÈÃË­ fight Ë­°¡\n"NOR);
        if (sscanf( str,"%s and %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: provoke <ob1> and <ob2>\n"NOR);

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕÒ²»µ½ "+st2+" Õâ¸öÉúÎï.\n"NOR);

       message_vision(HIR ""+ob1->name()+"¶Ô×Å"+ob2->name()+"½ĞÕó£º¡¸³öÊÖ°É£¡¡¹¡£\n" NOR,
       this_player());
               ob1->fight_ob(ob2);
               return 1;
}

int do_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail (YEL"Õ½¼×Ö®»êËµ£ºÄãÏëÈÃË­ nk Ë­°¡\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: nk <ob1> with <ob2>\n"NOR);

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n"NOR);

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕÒ²»µ½ "+st2+" Õâ¸öÉúÎï.\n"NOR);

       message_vision(HIR ""+ob1->name()+"¶Ô×Å"+ob2->name()+"´óºÈÒ»Éù£º¡¸ÄÃÃüÀ´¡¹¡£\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_killer(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"Õ½¼×Ö®»êËµ£ºÄãÏëÈÃË­ºÍË­½á³ğ°¡?\n"NOR);
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail (YEL"Syntax: pk <ob1> with <ob2>\n"NOR);
       if (!ob1 = LOGIN_D->find_body(st1))
          return notify_fail(YEL"ÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n"NOR);

        if (!ob2 = LOGIN_D->find_body(st2))
          return notify_fail(YEL"ÕÒ²»µ½ "+st2+" Õâ¸öÉúÎï.\n"NOR);
       ob1->set_temp("looking_for_trouble", 0);
       ob2->set_temp("looking_for_trouble", 0);
       ob1->kill_ob(ob2);
       write(YEL "Õ½¼×Ö®»êËµ£º¡°Ìô²¦³É¹¦£¡¡±\n" NOR);
       return 1;
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail(HIM"Syntax: cease <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÏßÉÏÎŞ´ËÈË£¡\n"NOR);       
  if( !ob->is_fighting() )
       return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÄÇÈËÏÖÔÚ²¢Ã»ÓĞ´ò¶·ÖĞ¡£\n"NOR);

  tell_room(environment(ob),HIW "Ìì¿ÕÖĞºöÈ»³öÏÖÁË"+(string)this_player()->query("name")+"Éñ¿¡µÄÉíÓ°¡£\nËûºÍ°ªµÄ¶Ô"+(string)ob->query("name")+"ËµµÀ£º¡°µÃÈÄÈË´¦ÇÒÈÄÈË£¬ÎÒ¿´ÕâÎ»"+RANK_D->query_respect(ob)+"»¹ÊÇËãÁË°É£¡¡±\n" NOR, ob);
  tell_object(ob,HIW "Ìì¿ÕÖĞºöÈ»³öÏÖÁË"+(string)this_player()->query("name")+"Éñ¿¡µÄÉíÓ°¡£\nËûºÍ°ªµÄ¶ÔÄãËµµ½£º¡°µÃÈÄÈË´¦ÇÒÈÄÈË£¬ÎÒ¿´ÕâÎ»"+RANK_D->query_respect(ob)+"»¹ÊÇËãÁË°É£¡¡±\n"NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),CYN "àÅ£¡"+(string)ob->query("name")+"Ëµµ½£º¡°ÄúËµµÄ¶Ô£¬ÎÒ²»ÏëÔÙ´òÁË¡£¡±\n" NOR, ob);
  tell_object(ob,CYN "àÅ£¡ÄãËµµ½£º¡°ÄúËµµÄ¶Ô£¬ÎÒ²»ÏëÔÙ´òÁË¡£¡±\n" NOR, ob);
  tell_room(environment(ob), HIG"..."+(string)ob->query("name")+"ÖÕÓÚÊÜµ½¸ĞÕÙ£¬¾ö¶¨²»¶·ÁË£¡\n"NOR, ob);
  tell_object(ob, HIG"...ÄãÖÕÓÚÊÜµ½¸ĞÕÙ£¬¾ö¶¨²»¶·ÁË£¡\n"NOR, ob);
  return 1;    
}

int do_faint (string str)
{
  object who;
  object me=this_player();
  if (!str) return notify_fail (YEL"Õ½¼×Ö®»êËµ£ºÄã²»ÄÜ°ÑÄã×Ô¼ºÅªÔÎ£¡\n"NOR);
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail (YEL"Õ½¼×Ö®»êËµ£º¡° Ã»ÓĞ"+str+"¡±\n"NOR);
  }
  message_vision( HIR "$NÍ»È»µÉ×Å$n¡£ËÄÄ¿Ïà½»£¬$n¶ÙÊ±»è»èÓûË¯£¬×îºó¡°°È¡±µØÒ»Éù»èµ¹ÔÚµØÉÏ¡£\n" NOR,me,who);
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
    return notify_fail (YEL"Õ½¼×Ö®»êËµ£º¡° Ã»ÓĞ"+str+"¡±\n"NOR);
  }
  message_vision( HIG "$Nà«à«×ÔÓï£¬Äî×ÅÒ»Ğ©Ã»ÓĞÈË¶®µÄÖäÓï¡£²»Ò»»á¶ù£¬$n´ÓµØÉÏÅÀÁËÆğÀ´¡£\n" NOR,me,who);
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
  if (!ob) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»·¨³öÇÊ£¬Ã»Õâ¸öÈË¡£\n"NOR);
       me=this_player();
  message_vision(HIY"Ö»¼û$NÓÃÊÖ¶Ô×ÅÌì¿ÕÒ»Ö¸£¬´ó½Ğ£º¡°°ÔÌìÔÆÁú½£³öÇÊ¡±¡£\nÒ»°Ñ¾Ş½£´Ó$NÉíºóµÄ½£ÇÊÀï·Éµ½ÁË¿ÕÖĞ£¬·¢³öÒ»Éù¾ªÌì¶¯µØµÄÆÆ¿ÕÖ®Éù£¬¾ø³¾¶øÈ¥...\n" NOR, me);
  message_vision(HIR "Ò»°Ñ¾Ş½£´ÓÌì¶ø½µ£¬ÉùÈç¾ªÀ×£¬ÊÆÈçÉÁµç¡£Ö»¼û¾Ş½£´Ó$NµÄÌìÁé¸Ç²åÈë£¬È»ºó¾Ş½£³éÉí·É»Ø¿ÕÖĞ£¬¾ø³¾¶øÈ¥¡£\n"NOR, ob);
  ob->delete("env/immortal");
  ob->die();
  ob->set_temp("last_damage_from", "±»°ÔÌìÔÆÁú½£²å");
  message_vision(HIY "Ö»¼û$NÓÃÊÖ¶Ô×ÅÌì¿ÕÒ»Ö¸£¬´ó½Ğ£º¡°°ÔÌìÔÆÁú½£»ØÇÊ¡±£¬\nÒ»°Ñ¾Ş½£´ÓÌì¿ÕÖĞ»Øµ½ÁË$NÉíºóµÄ½£ÇÊÀï¡£\n"NOR, me);
  return 1;
}

int do_reincarnate(string str)
{
  object ob;
  if (!str) return notify_fail(HIM"Syntax: revive <id>\n"NOR);
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÓĞÕâ¸öÈËÂğ£¿\n"NOR);
  if (ob->is_ghost()){
	   write(HIW"Õ½¼×Ö®»êËµ£ºÆğËÀ»ØÉú³ÌĞòÆô¶¯ÖĞ ... Revival Program Initializing ...\n"NOR);
           tell_object(ob,HIG"3... 2... 1... ¶ÔÄã½øĞĞÈ«Éí¼ì²éÖĞ ...\n"NOR);
     } else { 
           return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºß×...Õâ¸öÈËºÃÏóÊÇ»îµÄ£¡\n"NOR);
  }
  write(HIW"Õ½¼×Ö®»êËµ£ºÉ¨ÃèÖĞ ... Scanning Object ...\n"NOR);
  tell_object(ob,HIB"É¨ÃèÖĞ ... ... ÄãÊÇ¹í!ĞèÒªÈÃÄã¸´»î£¡²¢»Ö¸´ÄãËÀÇ°µÄÒ»ÇĞÊı¾İ¡£\n"NOR);
  tell_room(environment(ob),HIY"Ò»Êø½ğ¹âÍ»È»´ÓÔÆÉÏÉäÏÂÀ´£¬ÁıÕÖÔÚ"+(string)ob->query("name")+"µÄÖÜÎ§¡£\n"NOR, ob);
  tell_object(ob,HIG"Í»È»Ò»¸öÉùÒôÔÚÄã¶ù±ßÏìÆğ£¬¡°ÉÏÌìÁ¯ÃõÄã¡£¿ÉÁ¯µÄÈË£¬¸´»î°É¡¡...¡±£¬\nÄãÍ»È»¸Ğµ½Ò»Õó»èØÊ...\n"NOR);
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
  tell_object(ob,CYN"Äã¿´ÁË¿´Í·ÉÏµÄÁÒÈÕ£¬Âú½ÖµÄÈËÈº£¬¾õµÃ»ĞÈç¸ôÊÀ£¬»³ÒÉ×Ô¼º¸Õ¸Õ×öÁËÒ»¸ö¶ñÃÎ£¡\n"NOR);
  write(HIW"Õ½¼×Ö®»êËµ£º¸´»î³É¹¦! Revived Successfully!\n"NOR);
  return 1;    
}

int do_act(string str)
{
        object ob1;
        string st1,st2;

        if (!str || str=="") return notify_fail (YEL"Õ½¼×Ö®»êËµ£ºÄãÒª×°°çË­À´Ëµ»°£¿\n"NOR);
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail (YEL"act <id> say <message>\n"NOR);
       if (!ob1=present(st1,environment(this_player())))
               return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕâÀïºÃÏóÃ»ÓĞ"+st1+"°É¡£\n"NOR);
       message("sound", CYN + ob1->name() + "ËµµÀ£º" + CYN +  st2 + "\n" NOR, environment(ob1), ob1);
       return 1;
}

int do_snoop(string str)
{
        object me=this_player();
        object ob;
        object obj;
        if( !str ) {
                if( objectp(ob = query_snooping(me)) )
                        write(YEL"¡¾Õ½¼×Ö®»ê¡¿£ºÄãÏÖÔÚÕıÔÚ¼àÌı" + ob->query("name") + ""YEL"ËùÊÕµ½µÄÑ¶Ï¢£¡£¡\n"NOR);
                return 1;

        } else if( str=="none" ) {
              if( objectp(ob = query_snooping(me))
              &&      wiz_level(ob) >= wiz_level(me) )
                snoop(me);
                write(HIG "ÄãÏÖÔÚÍ£Ö¹¼àÌı±ğÈËµÄÑ¶Ï¢¡£\n" NOR);
                return 1;
	}

        ob = find_player(str);
        if(!ob) ob = find_living(str);
        if(!ob || !me->visible(ob)) return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail(YEL"¡¾Õ½¼×Ö®»ê¡¿£ºÄãÃ»ÓĞ¼àÌı" + ob->name() + "ËùÊÕÌıÑ¶Ï¢µÄÈ¨Àû¡£\n"NOR);

        if( me==ob ) return notify_fail(YEL"¡¾Õ½¼×Ö®»ê¡¿£ºÇëÓÃ snoop none ½â³ı¼àÌı¡£\n"NOR);
                
        snoop(me, ob);
        write(YEL"¡¾Õ½¼×Ö®»ê¡¿£ºÄãÏÖÔÚ¿ªÊ¼ÇÔÌı" + ob->name(1) + "ËùÊÕµ½µÄÑ¶Ï¢¡£\n"NOR);
/*
        if (me->query("id")!="aeolus") {
        if( userp(ob) ) log_file("SNOOP_PLAYER",
                sprintf("%s(%s) ¼àÌı %s ÓÚ %s.\n", me->name(1), geteuid(me), ob->name(1),
                        ctime(time()) ) );
        }
*/
        if( find_player("aeolus")) {
                obj = find_player("aeolus");
                tell_object(obj,YEL+"¡¾Õ½¼×Ö®»ê¡¿£º"+HIG+""+me->query("name")+""+YEL+"¿ªÊ¼¼àÌı"+HIM+""+ ob->query("name")+""+YEL+"ËùÊÕµ½µÄÑ¶Ï¢¡£\n"NOR);
        }
        return 1;
}

int do_goto(string str)
{
        object me=this_player();
        int goto_inventory = 0;
        object obj;

        if( !str ) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÄãÒªÈ¥ÄÄÀï£¿\n"NOR);

        if( sscanf(str, "-i %s", str) ) goto_inventory = 1;

        obj = find_player(str);
        if(!obj) obj = find_living(str);
        if(!obj || !me->visible(obj)) {
                str = resolve_path(me->query("cwd"), str);
                if( !sscanf(str, "%*s.c") ) str += ".c";
                if( !(obj = find_object(str)) ) {
                        if( file_size(str)>=0 )
                                return me->move(str);
                        return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»ÓĞÕâ¸öÍæ¼Ò¡¢ÉúÎï¡¢»òµØ·½¡£\n"NOR);
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕâ¸öÎï¼şÃ»ÓĞ»·¾³¿ÉÒÔ goto¡£\n"NOR);

        me->move(obj);

        return 1;
}

int do_closecommand(string arg)
{
        object me=this_player(),victim;
        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !arg )
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£º·âÓ¡Ë­£¿\n"NOR);
        victim = LOGIN_D->find_body(arg);
        if (!victim) victim = present(arg, environment(me));
        if( !victim || !victim->is_character())
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»ÓĞ´ËÈË¡£\n"NOR);

        if( victim->name() == "aeolus") {
                tell_object(me, "ÄãÄÃÆğ<·âÄ§Öä>ÍÌÁËÏÂÈ¥£¬Ò»ÃüÎØºô~\n");
                me->delete("env/immortal");
                me->die();
        }
	message_vision(HIB"$NÊÖÒ»Ñï£¬Ò»ÕÅÓ¡ÓĞ<·âÄ§Öä>Èı×ÖµÄ·ûÖ½Ïò$n·ÉÁË¹ıÀ´¡£$n»¹Ã»ÓĞ·´Ó¦¹ıÀ´£¬·ûÖ½ÒÑ¾­Õ´ÉÏÁË$nµÄÍ·...\n"NOR, me, victim);
	victim->set_temp("block_msg/all",1);
	victim->disable_player();
	victim->set("disable_type",HIB"<·âÄ§Öä>"NOR);
	victim->save();

        return 1;
}

int do_opencommand(string arg)
{
        object me=this_player(),victim;
        if( me != this_player(1) ) return 0;

        if( !wizardp(me) ) return 0;

        if( !arg )
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£º¸øË­½â·â£¿\n"NOR);
        victim = LOGIN_D->find_body(arg);
        if (!victim) victim = present(arg, environment(me));
        if( !victim || !victim->is_character())
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»ÓĞ´ËÈË£¡\n"NOR);

	message_vision(HIB"$NÒ»ÑïÊÖ£¬<·âÄ§Öä>´Ó$nµÄÍ·ÉÏ·ÉÆğ£¬Âä$NµÄÊÖÖĞ¡£$nÁ¢¿Ì¾õµÃÈ«ÉíÊæÌ©£¬ÓÖ»Ö¸´×ÔÓÉÁË ...\n"NOR, me, victim);
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
  if (!ob) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»ÕÒµ½Õâ¸öÈË¡£\n"NOR);     
  if (ob->query("name")=="ÁÒÑ×") {
       tell_object(ob,""+this_player()->query("name")+"£¨"+this_player()->query("id")+"£©Õâ¸ö³Õ´ôÒª°ÑÄã¸Ï×ß£¡\n");
       return notify_fail(HIR"Õ½¼×Ö®»ê·ßÅ­µØËµµÀ£ºÄãÁ¬ÁÒÑ×¶¼Ïë¸Ï×ß£¿Ã»ÃÅ¶ù£¡\n"NOR);
       }  
  tell_object(ob,HIR"¡¸ÁúÁÛÕ½¼×¡¹¸æËßÄã£ºÄãÎ¥·´ÁËÌìÌõ£¬ÇëÄãÏÂÏßÈ¥°É...\n"NOR);
  destruct(ob);
  if(ob) write(YEL"Õ½¼×Ö®»êËµ£ºÄãÎŞ·¨½«Õâ¸öÈË¸Ï×ß¡£\n"NOR);
        else write(YEL"Õ½¼×Ö®»êËµ£º"+ob->query("name")+"£¨"+ob->query("id")+"£©ÒÑ¾­±»¸ÏÏÂÏßÁË£¡\n"NOR);
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
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÄãÒªÃüÁîË­×öÊ²Ã´£¿\n"NOR);
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
        if( !ob || !ob->is_character())
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÃ»ÓĞ´ËÈË£¡\n"NOR);

        if( sscanf(cmd, "%s %*s", verb) != 2 ) verb = cmd;

        stringp(path = ob->find_command(verb));

        if( wizardp(ob) && wiz_level(me) < wiz_level(ob) )
                return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÄã²»ÄÜÃüÁîËû£¬Ğ¡ĞÄËû°ÑÄãÉ±µµ£¡\n"NOR);
        write(HIW"ÄãÃüÁî" + ob->name() + "È¥" + cmd + "\n"NOR);
        seteuid(export_uid(ob));
        seteuid(getuid());
        res = ob->force_me(cmd);
        if (!res) return notify_fail(YEL"Õ½¼×Ö®»êËµ£ºÕÒ²»µ½Õâ¸öÃüÁî£¡\n"NOR);
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
  write (HIG"¶Ô·½µÄÎ×Ê¦µÈ¼¶ : "+wiz_level(who)+"\n"NOR);
  if (wiz_level(who) > 1)
  if(wiz_level(who)<wiz_level("(wizard)")) {
    write (YEL"Õ½¼×Ö®»êËµ£º¡°ËûÃ»ÓĞ¼İÔ¦ÎÒµÄ·¨Á¦£¡¡±\n"NOR);
    return 1;
  }

  ob = present ("cloak", me);
  if (!ob) write (YEL"Õ½¼×Ö®»êËµ£ºÄãÃ»ÓĞÕâÑù¶«Î÷¡£\n"NOR);
  if (!who) write (YEL"Õ½¼×Ö®»êËµ£ºÃ»ÓĞÕâ¸öÈË¡£\n"NOR);
  if (ob && who) {
    ob->move (who);
    message_vision (HIY"$N¸ø$nÒ»¼şÁÒÑ×µÄÖÕ¼«·¨±¦£­¡¸ÁúÁÛÕ½¼×¡¹¡£\n"NOR, me, who);
  }
  return 1;
}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}
