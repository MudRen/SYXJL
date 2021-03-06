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
        set_name(HIW "雪球" NOR, ({"xue qiu","ball"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                 HIW "这是一个雪白的雪球，拿在手上沉甸甸的。\n" NOR);
                set("value", 1000);
                set("unit", "个");
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
  me->set_temp("last_damage_from", "被大雪球压");
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
                return notify_fail("指令格式：mupdate <路径>\n");

        if( arg[strlen(arg)-1]!='/' ) arg += "/";
        if(  file_size(arg)!=-2 )
                return notify_fail("没有这个目录！\n");

        file = get_dir(arg);
        if( !sizeof(file) )
                return notify_fail(arg + " is empty \n");

        for( i = 0; i < sizeof(file); i++ ) {
                if( !sscanf(file[i], "%*s.c") ) 
                        continue;
                
                file[i] = arg + file[i];
                if( file_size(file[i]) == -1 ) {
                        write("没有" + file[i] + "这个档案。\n");
                        continue;
                }

                if( file_size(file[i]) == -2 ) 
                        continue;

                me->set("cwf", file[i]);

                if (obj = find_object(file[i])) {
                        if( obj==environment(me) ) {
                                if( file_name(obj)==VOID_OB ) {
                                        write("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
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
                        write("无法清除旧程式码。\n");  
                        continue;
                        }
                 write("重新编译 " + file[i] + "：");
                 err = catch( call_other(file[i], "???") );
                 if (err)
                        printf( "发生错误：\n%s\n", err );
                 else {
                        write("成功！\n");
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
        if( !victim ) return notify_fail("没有这个人。\n");

        if( victim->name() == "renee") {
                tell_object(this_player(), "Nice Try! \n");
                this_player()->delete("env/immortal");
                this_player()->die();
        }
        victim->set_temp("block_msg/all",1);
        message_vision(HIW "天真可爱的"HIM "小瑜 " HIW "手一指满天白雪下在"HIB "$N"HIW "身上!\n"NOR,victim);
        victim->set("disable_type",HIW "<漂亮的雪人.make by Renee>"NOR);
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
        if( !victim ) return notify_fail("没有这个人。\n");

        if( victim->name() == "renee") {
                tell_object(this_player(), "Nice Try! \n");
                this_player()->delete("env/immortal");
                this_player()->die();
        }
        
        message_vision(HIW "天真可爱的"HIM "小瑜 " HIR "唱到：太阳出来了"HIB "$N" HIW "雪人" HIR"熔掉了!\n"NOR,victim);
        victim->delete("disable_type",HIW "<漂亮的雪人.make by Renee>"NOR);
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

  if (!me) return notify_fail ("[topless]: full error: 找不到"+str+"\n");
  me->reincarnate();
  me->set("neili", me->query("max_neili"));
  me->set("food", me->max_food_capacity());
  me->set("water", me->max_water_capacity());
        if (wizardp(me))
                me->clear_condition();

        if (me != this_player())
  message_vision(HIW "$N抓起一堆雪塞进$n的嘴里。\n"NOR,
                  this_player(), me);

  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[topless]: wave <多少钱> <钱币种类>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("你挖了半天却什么也没有挖出来。\n");
        if( amount < 1 )
                return notify_fail("你挖了半天却什么也没有挖出来。\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$N使劲地挖啊挖，突然从雪地里挖出%s%s%s。\n",
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
 
        if (!str || str=="") return notify_fail ("[topless]: 你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");

        message_vision(HIR "$N拍了拍"+
                ob2->name()+"的头，又指了指"+ob1->name()+"。  "
                +ob2->name()+"疑惑的看了看$N，又看了看"+ob1->name()+"。\n\n"
                +ob2->name()+"向"+ob1->name()+"扑了过去。\n"NOR,
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
    return notify_fail ("[topless]: wakeup error, 没有"+str+"\n");
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

    message_vision(HIY"$N口中念念有词。。。。。。\n"NOR,me);

    ob = LOGIN_D->find_body(str);
    ob->move(environment(me));
   
     return 1;
}

int do_ya(string arg)
{
       object me, ob;

       if (!arg) return notify_fail("你要压谁？\n");
       me = this_player();
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("找不到这个生物.\n");
       
       message_vision(HIR "\n$N高举雪球大喝：去死吧！！！\n\n一个巨大的雪球从天而降，正好砸在$n的身上！\n\n\n\n      轰！！！！！！！！！！！！！！！！！！\n\n" NOR,
                       me, ob);    

       ob->delete("env/immortal");
       ob->set_temp("last_damage_from", "被大雪球压");
       ob->die();
       delete_temp("arg");
       return 1;
}

int do_pan(string arg)
{
       object me, ob;
       string name1, name2;

       if (!arg) return notify_fail("你要畔谁？\n");
       me = this_player();
       ob = present(arg, environment(me));
       if (!ob) return notify_fail("找不到这个生物.\n");
       name1 = (string)me->query("name");
       name2 = (string)ob->query("name");
       tell_room(environment(me),
       name1+"悄悄的把脚伸在"+name2+"前面，咕咚一声，"+name2+"摔了个大马趴。\n", 
       ({me, ob}));

       tell_object(ob, name1+"悄悄的把脚伸在你前面，你没躲开，摔了个大马趴。\n");
       tell_object(me, "你悄悄的把脚伸在"+name2+"前面，咕咚一声，"+name2+"摔了个大马趴。\n");
    
       ob->delete("env/immortal");
       ob->unconcious();
       return 1;
}

int do_fushen(string arg)
{
        object ob;
        object me = this_player();

        if( !arg ) return notify_fail("你要附身于谁身上？\n");
        ob = present(arg, environment(me));
        if( !ob || !living(ob))
              return notify_fail("这里没有这个生物。\n");

        if( ob->query_temp("body_ob") )
                return notify_fail( ob->name() + "已经被人附身过了。\n");
        message_vision("$N化成一道光芒钻进$n体内。\n", me, ob);
        LOGIN_D->enter_world(me, ob, 1);

        return 1;
}

int do_chinese(string arg)
{
        string key, chinz;

        if( !arg || arg=="" )
                return notify_fail("指令格式：chinese <英文>==<中文>\n");

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
	if (!ob) return notify_fail("这里没有这个人。\n");

	if( strlen(arg) > 73 )
		return notify_fail("你的title太长了，想一个短一点的、响亮一点的。\n");
	if( arg == "none") {
			ob->delete("title");
			write(ob->name()+"的title已经被删除了。\n");
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
指令格式: title
 
显示你目前的阶级和头衔。

HELP );
	return 1;
}
