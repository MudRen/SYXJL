//ds
 
#include <ansi.h>
inherit NPC;

int time_period(int timep,object me);
int potential_lv(int exp);
 
void create()
{
        set("chat_chance", 25);
 
        set_name("����", ({ "wu qing", "wu"}) );
        set("title",HIW "����"NOR);
        set("gender", "����" );
        set("age", 28);
        set("long",
                "�����ˣ��ϳ��͡�\n");
	set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set_max_encumbrance(100000000);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set("qi",10000);
        set("max_qi", 10000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 150);
        set("combat_exp", 5000000);
        set("score", 250000);


        set_skill("force", 90);
        set_skill("taiji-shengong", 80);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 80);
        set_skill("unarmed", 90);
        set_skill("taiji-quan", 80);
        set_skill("parry", 90);
        set_skill("sword", 100);
        set_skill("taiji-jian", 90);
        set_skill("taoism", 150);
        set_skill("literate", 60);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

 
	set("inquiry", ([  "����": "���Ǳ���ү�� \n",]) );
 
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();

}
int accept_fight(object me)
{
        command("say ������������");
        return 0;
}
 
void init()
{
        add_action("give_quest", "quest");
}
 
int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
	string *levels = ({
			"1000",
			"1500",
			"2000",
			"3000",
			"5000",
			"8000",
			"10000",
			"13000",
			"17000",
			"22000",
			"30000",
			"45000",
			"60000",
			"80000",
			"100000",
			"200000",
			"350000",
			"600000",
			"1000000",
			"1500000",
			"2500000",
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
 
        if(combatexp<1000)
          {
        message_vision("�����$N����һ����: �����Ҳ�Ҫ������С���Ӱ�æ��\n",me);
         return 1;
          }
 
// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
        {
          message_vision("�����$N���յ�Ц�������� �����Ȱ����������ɰɡ�\n", me);
                  message_vision("Ȼ����ͷ��������˵������Ҫ�Ǿ����������͵ø���������ˡ�\n",me);
          return 0;
        }
        else
        {
          message_vision("�������$N̾��һ����:�����Ҿ��ٸ���һ�λ���ɡ�\n", me);
          me->add("qi",-(int)(me->query("qi")/10));
        }
        }
 
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
                      num=j;
                          factor=10;
                          break;
                        }
        }
        if (num>0)
        {
                if (random(50)>45)
                {
                num=num-1;
                }
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                num=num+1;
                factor=15;
                }
        }
        tag=levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];
 
 //       while (quest["quest_type"] == "ɱ")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }
 
        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
        tell_object(me,"������ɱ�ˡ�"+quest["quest"]+"��,�����Ҹ���ô���\n" NOR);
        else
        tell_object(me,"���һء�"+quest["quest"]+"������,�����Ҹ���ô���\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
 
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}
 
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;
 
        if(d) time = chinese_number(d) + "��";
        else time = "";
 
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "����";
        time += chinese_number(s) + "��";
 
        tell_object(me,HIW "����˵����\n��" + time + "��");
        return 1;
}
 
int accept_object(object who, object ob)
{
        int bonus, exp, pot,factor;
//	string test;
        mapping quest;

	if (ob->query("money_id")) {
		if ( who->query("quest/quest_type") == "�����͸�" ) {
			message_vision("�������$N̾��һ����:�������ŵ�����Ҳ�ܵ���������ȡ����\n", who);
			return 0;
		}
		if(!who->query("quest")) {
			message_vision("����Ц��: ���ҿɾͲ������ˡ�\n",who);
			return 1;
		}
		if ( ob->value() < 10000) {
			message_vision("���鶢��$N:���Ǯ�ɲ������ǵĿ���ѽ!\n", who);
			return 1;
		}
		else {
			message_vision("���������: û�õļһ��Ǯ���¡�\n",who);
			who->set("quest",0);
			return 1;
		}
	}
 
	if(!(quest =  who->query("quest"))) {
		tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
		return 0;
	}
 
	if( ob->query("name") != quest["quest"]) {
		tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
		return 0;
	}
 
        if ((int) who->query("task_time") < time() ) {
		tell_object(who,"����˵�������ϧ����û����ָ����ʱ���ڻ�����\n");
		destruct(ob);
		return 0;
	}
	else {
		tell_object(who,"����˵����Ŷ���㻹���У�Ӧ�õõ�������\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
//		score = questscore/2 + random(questscore/2);
		factor=who->query("quest_factor");
//		destruct(ob);
 
		if (factor) {
			exp=exp*factor/10;
			pot=pot*factor/10;
//			score=score*factor/10;
		}
 
		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus = bonus + pot;
		if ( bonus > potential_lv((int)who->query("combat_exp")) )
		bonus = potential_lv((int)who->query("combat_exp"));
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
/*
		bonus = (int) who->query("score");
		bonus += score;
		who->set("score", bonus);
*/
		tell_object(who, HIW"�㱻������\n" + chinese_number(exp)
			+ "��ʵս����\n"+ chinese_number(pot) + "��Ǳ��\n"NOR);
//			+ chinese_number(score)+"���ۺ�����\n"NOR);
		tell_object(who, "��ϲ�����һ������\n");
		who->set("quest", 0 );
		return 1;
	}
	return 1;
}

int potential_lv(int exp)
{
        int grade;

	grade = 100 + exp / 500;
        return grade;
}

