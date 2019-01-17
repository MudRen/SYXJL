// duanyu.c ����

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"duan yu", "duan", "yu"}));
	set("nickname", GRN"��������"NOR);
	set("gender", "����");
	set("age", 20);
	set("long", 
		"����һ�����������������ӡ������Լ⣬����һ�������Ĵ�����\n");
	set("attitude", "peaceful");
	
	set("str", 12);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�˿�����������������ʱ���ټ������̰�������\n",
		(: random_move :),
	}));

	set("inquiry", ([
		"����" : "�����Ǹ��õط���ɽ��ˮ�㣬�羰���ˡ�\n",
		"������" : "����������ֻ������磬������û���ҷ������\n",
		"��ʦ" : "��....���ҵ�ʦ�������ӡ����Ӻ�ׯ�ӣ����ǵ�ѧ���һ�ûѧȫ�ء�\n",
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
	 
	set_skill("force", 100);		// �����ڹ�
	set_skill("beiming-shengong", 100);	// ��ڤ��
	set_skill("finger", 120);		// ����ָ��
	set_skill("sword", 120);		// ��������
	set_skill("liumai-shenjian", 120);	// ������
	set_skill("dodge", 150);		// ��������
	set_skill("lingboweibu", 150);		// �貨΢��
	set_skill("parry", 80);			// �����м�
	
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

  if (room->query("short")!="�ϴ��")
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
    message_vision("$N��æ���ţ�����������¡�\n",me);
    message_vision("$N����û�뵽�����ɻ��������ң�\n\n",me);
    message_vision("$N˵������Ҫȥ�����ɡ�\n",me);
  }
  // already given letter before
  else
  {
    message_vision("$N��$n������λ"+RANK_D->query_respect(who)+
                   "���������ţ�������ô��л����ء�\n",me,who);
  }
  remove_call_out("give_dan");
  call_out("give_dan",3,me,who);
}

void give_dan (object me, object who)
{
  object ling = new ("/clone/medicine/dan");
  ling->move(who);
  message_vision("$N˵����$n����֮��������Ϊ��������һ��������ҩ�ɣ�\n\n",
                 me,who);
  message_vision("$N�ݸ�$nһ��������������\n",me,who);
  who->set("duanwang","given_letter");
  who->set_temp("duanwang","given_letter");
  destruct(this_object());
  who->save();
}
