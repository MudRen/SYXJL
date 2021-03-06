// zhaixing.c 摘星子
// by QingP
#include <ansi.h>

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();
string do_xuncha();
string do_guard();
string do_cancl();
void do_kill(string);
void get_exp_in_xuncha(object me, object obj);
void get_money_in_xuncha(object me, object obj);
int count = 0;
object ob;

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "星宿派大师兄");
	set("long", 
		"他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
		"他二十多岁，身材高瘦，脸色青中泛黄，面目却颇英俊。\n");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);

	set("max_qi", 1000);
	set("max_jing", 900);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 70);
	set("combat_exp", 370000);
	set("score", 50000);

          set_skill("force", 110);
          set_skill("dodge", 90);
          set_skill("strike", 95);
          set_skill("claw", 95);
	  set_skill("poison", 100);
	  set_skill("throwing", 90);
          set_skill("staff", 70);
          set_skill("parry", 110);
	  set_skill("literate", 110);
	set_skill("beiming-zhenqi", 105);
	set_skill("zhaixinggong", 85);
	set_skill("xingxiu-dugong", 130);
	set_skill("wugong-zhao", 120);
	set_skill("tianshan-zhang", 70);

	map_skill("force", "beiming-zhenqi");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "xingchen-zhang");
	map_skill("claw", "wugong-zhao");
	map_skill("parry", "xingchen-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "xingchen-zhang");
	prepare_skill("claw", "wugong-zhao");

	create_family("星宿派", 2, "弟子");
        
/*	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.lianxindan" :),
		(: perform_action, "strike.shihunxing" :),
	}) );*/

        set("inquiry", ([
                "巡查" : (: do_xuncha :),
                "工作" : (: do_guard :),
                "放弃" : (: do_cancl :),
        ]));
        
	setup();

	carry_object("/d/xingxiu/obj/lianxindan");
	carry_object("/d/xingxiu/obj/lianxindan");
	carry_object("/d/xingxiu/obj/bilinxing");
	carry_object("/d/xingxiu/obj/flute2");
	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

void init()
{
	object ob;
	::init();

	if (interactive(ob = this_player()) && !is_fighting()) {
		if ((ob->query("shen")>10000) && (!wizardp(ob))) {
			command("say 星宿海岂是尔等闲逛之地！\n");
			remove_call_out("do_killing");
			call_out("do_killing",0,ob);
		}
	}
           if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="zhaixing zi")
        {
                      command("chat "+ob->query("name")+"!装什么正道人士，给我滚出星宿派。\n");
                  command("expell "+ ob->query("id"));
                    this_player()->set("title","星宿派" + RED + "弃徒" NOR);   
        }      

	add_action("do_kill","kill");
	add_action("do_kill","hit");
	add_action("do_kill","touxi");
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	this_object()->kill_ob(ob);
}

void do_kill(string arg)
{
        object ob = this_player();
        object me = this_object();
        object obj;
        
	if (!arg || !objectp(obj = present(arg, environment(me))))
		return;

	if ( !(obj->query("family"))||(obj->query("family"))["family_name"] != "星宿派" ) {
	        if ( (!(ob->query("family"))||(ob->query("family"))["family_name"] != "星宿派") && ob->query("shen") < 0 )
			say (YEL+"摘星子说道：这位" + RANK_D->query_respect(me) + "想来是同道中人，何不快快拜入老仙门下，修习绝世武功？\n"+NOR);
		else if ( (!(ob->query("family"))||(ob->query("family"))["family_name"] != "星宿派") && ob->query("shen") > -1) {
			say (HIG+"摘星子说道：大胆狂徒，竟敢在星宿海撒野，活得不耐烦啦？！\n");
			me->kill_ob(ob);
			ob->fight_ob(me);
		}
		else if ( (ob->query("family"))["family_name"] == "星宿派" ) {
			command("smile " + (string)ob->query("id"));
			if ( ob->query("shen") > -2000)
				ob->add("shen", -15);
       		}
	}
	else if ( (obj->query("family"))["family_name"] == "星宿派" ) {
		if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "星宿派" ) {
			say (HIG+"摘星子说道：大胆狂徒，竟敢在星宿海撒野，活得不耐烦啦？！\n");
			me->kill_ob(ob);
			ob->fight_ob(me);
		}
		else if ( (ob->query("family"))["family_name"] == "星宿派" ) {
     			command("smile " + (string)ob->query("id"));
			if ( ob->query("shen") > -1000)
				ob->add("shen", -10);
       		}
	}
}

string do_xuncha()
{
        ob = this_player(); 
   
        if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) + 
                "乃旁门左道之徒，岂能参与堂堂星宿的事务？\n";

        if ( environment(this_object())->query("short")!="星宿海" )
                return "这里不是星宿海，你想到哪儿巡查？";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";

        if ( ob->query("in_xuncha") || ob->query("work_xuncha"))
                return "你不是己经在巡查了吗？ 如果你不想干，就放弃吧。\n";

//	if (count>=4) {
//		message_vision(YEL"$N自愿为摘星子巡查星宿海。\n"NOR,ob);
//		return "我这巡查的人己经满了，你等会再来吧。\n";
//	}
        if ( (int)ob->query_condition("after_xuncha" ) > 0 )
                return "你刚才巡查过了，还是先休息一会再来吧！\n";
        
//	++count;
        
        ob->start_busy(2);

        ob->set("in_xuncha",1);

        ob->set("oldtitle",ob->query("title"));
        ob->set("title",HIW"星宿巡查"NOR);
	ob->apply_condition("in_xuncha", 17);
        message_vision(YEL"$N自愿为摘星子巡查星宿海。。\n"NOR,ob);
        return "那你现在好好巡查吧，可别让旁门左道之徒撞进星宿海惊扰了老仙。\n";
}

string do_guard()
{
        ob = this_player();

        if ( environment(this_object())->query("short")!="星宿海" )
                return "这里不是星宿海，你想到哪儿巡查？";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";

        if ( ob->query("in_xuncha") || ob->query("work_xuncha"))
                return "你不是己经在巡查了吗？ 如果你不想干，就放弃吧。\n";

//	if (count>=4){
//		message_vision(YEL"$N想为摘星子巡查星宿海。\n"NOR,ob);
//		return "我这巡查的人己经满了，你等会再来吧。\n";
//	}
        if ( (int)ob->query_condition("after_xuncha" ) > 0 )
                return "你刚才巡查过了，还是先休息一会再来吧！\n";

//	++count;
	
	ob->start_busy(2);

        ob->set("work_xuncha",1);

        ob->set("oldtitle",ob->query("title"));
        ob->set("title",HIW"星宿巡查"NOR);
	ob->apply_condition("in_xuncha", 17);
        message_vision(YEL"$N想为为摘星子巡查星宿海。\n"NOR,ob);
        return "那你现在好好巡查吧，可别让旁门左道之徒撞进星宿海惊扰了老仙。\n";
}

string do_cancl()
{
	mapping fam;
	
        ob=this_player();
        fam = (mapping)ob->query("family");

        if (!ob->query("in_xuncha") && !ob->query("work_xuncha"))
                return "你还没巡查过，就要放弃了？";

        ob->delete("in_xuncha");
        ob->delete("work_xuncha");
	ob->apply_condition("in_xuncha", 0);

        if (count<=0) count=0;

        ob->set("title",ob->query("oldtitle"));
        ob->delete("oldtitle");
	ob->apply_condition("after_xuncha", 7);
        message_vision(YEL"$N突然决定不巡查星宿海了。\n",ob);
        if ( fam["family_name"] == "星宿派" )
        	return "星宿门下个个英明神武......也罢也罢，快滚吧！\n";
        else return "做事半途而废，你还是快快拜入星宿门下，聆听老仙教诲为上。\n";
}

int accept_object(object me, object obj)
{
        mapping myfam, objfam;
        myfam = (mapping)me->query("family");
        objfam = (mapping)obj->query("family");

        if ( !me || environment(me) != environment() ) return 0;

	if ( !objectp(obj) ) return 0;
	
	if ( !present(obj, me) ) {say("你没有这件东西。\n"); return 0;}

	if (  (string)obj->query("gender") == "女性"
	||    (string)obj->query("gender") == "男性"
	||    (string)obj->query("gender") == "无性" ) {
		if ( obj->query("in_xuncha") || obj->query("work_xuncha") ) {
			command ("say 这位" + RANK_D->query_respect(obj) + "是和你一起巡查的，你乱抓什么！？");
			return 1;
		}
		
		if ( !objfam["family_name"] || objfam["family_name"] != "星宿派" ) {
		        if ( me->query("in_xuncha") && myfam["family_name"] == "星宿派" ) {
				call_out("get_exp_in_xuncha", 0, me, obj);
				return 1;
			}
        		else if ( me->query("work_xuncha") ) {
				call_out("get_money_in_xuncha", 0, me, obj);
				return 1;
			}
		}
		else {
			if ( me->query("in_xuncha") && myfam["family_name"] == "星宿派" ) {
			  if( objfam["generation"]==myfam["generation"] ) {
				  if( (string)obj->query("gender") == "男性"
				  ||  (string)obj->query("gender") == "无性" )
					  command ("say 你是怎么巡查的！？连你的"
						  + myfam["master_id"] == objfam["master_id"] ? "": "同门"
						  + myfam["enter_time"] > objfam["enter_time"] ? "师兄": "师弟"
						  + "也抓。\n");
				  else
					  command ("say 你是怎么巡查的！？连你的"
						  + myfam["master_id"] == objfam["master_id"] ? "": "同门"
						  + myfam["enter_time"] > objfam["enter_time"] ? "师姐": "师妹"
						  + "也抓。\n");
			  } else if( objfam["generation"] < myfam["generation"] ) {
				  if( myfam["master_id"] == obj->query("id") )
					  command ("say 你是怎么巡查的！？连你的师父也抓。\n");
				  else if( myfam["generation"] - objfam["generation"] > 1 )
					  command ("say 你是怎么巡查的！？连你的同门长辈也抓。\n");
				  else if( objfam["enter_time"] < myfam["enter_time"] )
					  command ("say 你是怎么巡查的！？连你的师泊也抓。\n");
				  else
					  command ("say 你是怎么巡查的！？连你的师叔也抓。\n");
			  } else {
				  if( objfam["generation"] - myfam["generation"] > 1 )
					  command ("say 你是怎么巡查的！？连你的同门晚辈也抓。\n");
				  else if( objfam["master_id"] == me->query("id") )
					  command ("say 你是怎么巡查的！？连你的弟子也抓。\n");
				  else
					  command ("say 你是怎么巡查的！？连你的师侄也抓。\n");
			  }
			}
			else if ( me->query("work_xuncha") )
			  command ("say 让你来星宿海工作，是让你来抓星宿弟子的吗？！");

			return 1;
		}
	}
	else return 0;
}

void get_exp_in_xuncha(object me, object obj)
{
        int exp, pot, rate;

	if (obj->query("combat_exp") < 7000)
                write("这种无名鼠辈你也抓，想得可倒是真美呀。");
                return ;

	if ( (rate = obj->query("combat_exp") / me->query("combat_exp")) > 1)
		rate = 1;

	exp = 30 + random(20) + 100 * rate;
	pot = 10 + random(10)/2 + 20 * rate;

	obj->move("/d/xingxiu/laofang");

	me->add("combat_exp", exp);
	me->add("potential", pot);

	command("nod " + me->query("id"));
	command("say 你巡查得不错，这是你的奖赏。");
	tell_object(me, sprintf("你得到了%s点潜能，%s点经验。\n",chinese_number(pot),chinese_number(exp)));
}

void get_money_in_xuncha(object me, object obj)
{
        object mo;
        int amount, rate;

	if (obj->query("combat_exp") < 7000)
                write("这种无名鼠辈你也抓，想得可倒是真美呀。");
                return ;

	if ( (rate = obj->query("combat_exp") / me->query("combat_exp")) > 1)
		rate = 1;

	mo=new("/clone/money/silver");
	amount=20 + random(20) + 50 * rate;
	mo->set_amount(amount);
	mo->move(me);

	obj->move("/d/xingxiu/laofang");

	command("nod " + me->query("id"));
	command("say 你工作得不错，这是你的奖赏。");
	tell_object(me, sprintf("你得到了%s两银子作为酬劳。\n",chinese_number(amount)));
}
