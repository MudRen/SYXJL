// duanyu.c 段誉

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("段誉", ({"duan yu", "duan", "yu"}));
	set("nickname", GRN"大理王子"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他是一个身穿青衫的年轻男子。脸孔略尖，自有一股书生的呆气。\n");
	set("attitude", "peaceful");
	
	set("str", 12);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"段誉叹了口气道：“唉……何时能再见到语嫣啊……”\n",
		(: random_move :),
	}));

	set("inquiry", ([
		"大理" : "大理是个好地方，山清水秀，风景宜人。\n",
		"王语嫣" : "唉，她心里只有她表哥，从来就没把我放在眼里。\n",
		"拜师" : "嗯....，我的师傅是老子、孔子和庄子，他们的学问我还没学全呢。\n",
	]));

	set("jing", 2000);
	set("max_jing", 2000);
	set("jingli", 2000);
	set("max_jingli", 2000);
	set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",200);
	
	set("combat_exp", 500000);
	set("score", 20000);
	 
	set_skill("force", 100);		// 基本内功
	set_skill("beiming-shengong", 100);	// 北冥神功
	set_skill("finger", 120);		// 基本指法
	set_skill("sword", 120);		// 基本剑法
	set_skill("liumai-shenjian", 120);	// 六脉神剑
	set_skill("dodge", 150);		// 基本躲闪
	set_skill("lingboweibu", 150);		// 凌波微步
	set_skill("parry", 80);			// 基本招架
	
	map_skill("sword", "liumai-shenjian");
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "liumai-shenjian");
	map_skill("finger", "liumai-shenjian");
	prepare_skill("finger","liumai-shenjian");
	
	setup();
	

carry_object("/d/city/obj/gangjian");
   this_player()->carry_object("/clone/misc/cloth")->wear();
}
int accept_object (object who, object ob)
{
  object me = this_object();
  object room = environment(me);

  if (room->query("short")!="南大街")
    return 0;

  if (ob->query("id")=="xin" &&
      who->query_temp("duanwang")=="got_letter")
  {
    remove_call_out("read_letter");
    call_out("read_letter",3,me,who,ob);
    return 1;
  }
  return 0;
}

void read_letter (object me, object who, object ob)
{
  destruct (ob);
  reset_eval_cost();
  // first time get letter from player
  if (who->query("duanwang")=="got_letter")
  {
    message_vision("$N急忙拆开信，不禁涕泪俱下。\n",me);
    message_vision("$N道：没想到，语焉还挂念着我！\n\n",me);
    message_vision("$N说道：我要去找语焉。\n",me);
  }
  // already given letter before
  else
  {
    message_vision("$N对$n道：这位"+RANK_D->query_respect(who)+
                   "，又来送信，教我怎么感谢你好呢。\n",me,who);
  }
  remove_call_out("give_dan");
  call_out("give_dan",3,me,who);
}

void give_dan (object me, object who)
{
  object ling = new ("/clone/medicine/dan");
  ling->move(who);
  message_vision("$N说道：$n送信之恩，无以为报，送你一包疗伤神药吧！\n\n",
                 me,who);
  message_vision("$N递给$n一颗天王保命丹。\n",me,who);
  who->set("duanwang","given_letter");
  who->set_temp("duanwang","given_letter");
  destruct(this_object());
  who->save();
}
