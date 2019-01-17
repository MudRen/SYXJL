// zhaixing.c ժ����
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
	set_name("ժ����", ({ "zhaixing zi", "zhaixing" }));
	set("nickname", "�����ɴ�ʦ��");
	set("long", 
		"�����Ƕ�����Ĵ���ӡ������ɴ�ʦ��ժ���ӡ�\n"
		"����ʮ���꣬��ĸ��ݣ���ɫ���з��ƣ���Ŀȴ��Ӣ����\n");
	set("gender", "����");
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

	create_family("������", 2, "����");
        
/*	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.lianxindan" :),
		(: perform_action, "strike.shihunxing" :),
	}) );*/

        set("inquiry", ([
                "Ѳ��" : (: do_xuncha :),
                "����" : (: do_guard :),
                "����" : (: do_cancl :),
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
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}

void init()
{
	object ob;
	::init();

	if (interactive(ob = this_player()) && !is_fighting()) {
		if ((ob->query("shen")>10000) && (!wizardp(ob))) {
			command("say ���޺����Ƕ����й�֮�أ�\n");
			remove_call_out("do_killing");
			call_out("do_killing",0,ob);
		}
	}
           if((int)ob->query("shen")>=1000&&ob->query("family/master_id")=="zhaixing zi")
        {
                      command("chat "+ob->query("name")+"!װʲô������ʿ�����ҹ��������ɡ�\n");
                  command("expell "+ ob->query("id"));
                    this_player()->set("title","������" + RED + "��ͽ" NOR);   
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

	if ( !(obj->query("family"))||(obj->query("family"))["family_name"] != "������" ) {
	        if ( (!(ob->query("family"))||(ob->query("family"))["family_name"] != "������") && ob->query("shen") < 0 )
			say (YEL+"ժ����˵������λ" + RANK_D->query_respect(me) + "������ͬ�����ˣ��β��������������£���ϰ�����书��\n"+NOR);
		else if ( (!(ob->query("family"))||(ob->query("family"))["family_name"] != "������") && ob->query("shen") > -1) {
			say (HIG+"ժ����˵�����󵨿�ͽ�����������޺���Ұ����ò��ͷ�������\n");
			me->kill_ob(ob);
			ob->fight_ob(me);
		}
		else if ( (ob->query("family"))["family_name"] == "������" ) {
			command("smile " + (string)ob->query("id"));
			if ( ob->query("shen") > -2000)
				ob->add("shen", -15);
       		}
	}
	else if ( (obj->query("family"))["family_name"] == "������" ) {
		if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "������" ) {
			say (HIG+"ժ����˵�����󵨿�ͽ�����������޺���Ұ����ò��ͷ�������\n");
			me->kill_ob(ob);
			ob->fight_ob(me);
		}
		else if ( (ob->query("family"))["family_name"] == "������" ) {
     			command("smile " + (string)ob->query("id"));
			if ( ob->query("shen") > -1000)
				ob->add("shen", -10);
       		}
	}
}

string do_xuncha()
{
        ob = this_player(); 
   
        if ( !(ob->query("family"))||(ob->query("family"))["family_name"] != "������")
                return RANK_D->query_respect(this_player()) + 
                "���������֮ͽ�����ܲ����������޵�����\n";

        if ( environment(this_object())->query("short")!="���޺�" )
                return "���ﲻ�����޺������뵽�Ķ�Ѳ�飿";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

        if ( ob->query("in_xuncha") || ob->query("work_xuncha"))
                return "�㲻�Ǽ�����Ѳ������ ����㲻��ɣ��ͷ����ɡ�\n";

//	if (count>=4) {
//		message_vision(YEL"$N��ԸΪժ����Ѳ�����޺���\n"NOR,ob);
//		return "����Ѳ����˼������ˣ���Ȼ������ɡ�\n";
//	}
        if ( (int)ob->query_condition("after_xuncha" ) > 0 )
                return "��ղ�Ѳ����ˣ���������Ϣһ�������ɣ�\n";
        
//	++count;
        
        ob->start_busy(2);

        ob->set("in_xuncha",1);

        ob->set("oldtitle",ob->query("title"));
        ob->set("title",HIW"����Ѳ��"NOR);
	ob->apply_condition("in_xuncha", 17);
        message_vision(YEL"$N��ԸΪժ����Ѳ�����޺�����\n"NOR,ob);
        return "�������ںú�Ѳ��ɣ��ɱ����������֮ͽײ�����޺����������ɡ�\n";
}

string do_guard()
{
        ob = this_player();

        if ( environment(this_object())->query("short")!="���޺�" )
                return "���ﲻ�����޺������뵽�Ķ�Ѳ�飿";

        if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

        if ( ob->query("in_xuncha") || ob->query("work_xuncha"))
                return "�㲻�Ǽ�����Ѳ������ ����㲻��ɣ��ͷ����ɡ�\n";

//	if (count>=4){
//		message_vision(YEL"$N��Ϊժ����Ѳ�����޺���\n"NOR,ob);
//		return "����Ѳ����˼������ˣ���Ȼ������ɡ�\n";
//	}
        if ( (int)ob->query_condition("after_xuncha" ) > 0 )
                return "��ղ�Ѳ����ˣ���������Ϣһ�������ɣ�\n";

//	++count;
	
	ob->start_busy(2);

        ob->set("work_xuncha",1);

        ob->set("oldtitle",ob->query("title"));
        ob->set("title",HIW"����Ѳ��"NOR);
	ob->apply_condition("in_xuncha", 17);
        message_vision(YEL"$N��ΪΪժ����Ѳ�����޺���\n"NOR,ob);
        return "�������ںú�Ѳ��ɣ��ɱ����������֮ͽײ�����޺����������ɡ�\n";
}

string do_cancl()
{
	mapping fam;
	
        ob=this_player();
        fam = (mapping)ob->query("family");

        if (!ob->query("in_xuncha") && !ob->query("work_xuncha"))
                return "�㻹ûѲ�������Ҫ�����ˣ�";

        ob->delete("in_xuncha");
        ob->delete("work_xuncha");
	ob->apply_condition("in_xuncha", 0);

        if (count<=0) count=0;

        ob->set("title",ob->query("oldtitle"));
        ob->delete("oldtitle");
	ob->apply_condition("after_xuncha", 7);
        message_vision(YEL"$NͻȻ������Ѳ�����޺��ˡ�\n",ob);
        if ( fam["family_name"] == "������" )
        	return "�������¸���Ӣ������......Ҳ��Ҳ�գ�����ɣ�\n";
        else return "���°�;���ϣ��㻹�ǿ������������£��������ɽ̻�Ϊ�ϡ�\n";
}

int accept_object(object me, object obj)
{
        mapping myfam, objfam;
        myfam = (mapping)me->query("family");
        objfam = (mapping)obj->query("family");

        if ( !me || environment(me) != environment() ) return 0;

	if ( !objectp(obj) ) return 0;
	
	if ( !present(obj, me) ) {say("��û�����������\n"); return 0;}

	if (  (string)obj->query("gender") == "Ů��"
	||    (string)obj->query("gender") == "����"
	||    (string)obj->query("gender") == "����" ) {
		if ( obj->query("in_xuncha") || obj->query("work_xuncha") ) {
			command ("say ��λ" + RANK_D->query_respect(obj) + "�Ǻ���һ��Ѳ��ģ�����ץʲô����");
			return 1;
		}
		
		if ( !objfam["family_name"] || objfam["family_name"] != "������" ) {
		        if ( me->query("in_xuncha") && myfam["family_name"] == "������" ) {
				call_out("get_exp_in_xuncha", 0, me, obj);
				return 1;
			}
        		else if ( me->query("work_xuncha") ) {
				call_out("get_money_in_xuncha", 0, me, obj);
				return 1;
			}
		}
		else {
			if ( me->query("in_xuncha") && myfam["family_name"] == "������" ) {
			  if( objfam["generation"]==myfam["generation"] ) {
				  if( (string)obj->query("gender") == "����"
				  ||  (string)obj->query("gender") == "����" )
					  command ("say ������ôѲ��ģ��������"
						  + myfam["master_id"] == objfam["master_id"] ? "": "ͬ��"
						  + myfam["enter_time"] > objfam["enter_time"] ? "ʦ��": "ʦ��"
						  + "Ҳץ��\n");
				  else
					  command ("say ������ôѲ��ģ��������"
						  + myfam["master_id"] == objfam["master_id"] ? "": "ͬ��"
						  + myfam["enter_time"] > objfam["enter_time"] ? "ʦ��": "ʦ��"
						  + "Ҳץ��\n");
			  } else if( objfam["generation"] < myfam["generation"] ) {
				  if( myfam["master_id"] == obj->query("id") )
					  command ("say ������ôѲ��ģ��������ʦ��Ҳץ��\n");
				  else if( myfam["generation"] - objfam["generation"] > 1 )
					  command ("say ������ôѲ��ģ��������ͬ�ų���Ҳץ��\n");
				  else if( objfam["enter_time"] < myfam["enter_time"] )
					  command ("say ������ôѲ��ģ��������ʦ��Ҳץ��\n");
				  else
					  command ("say ������ôѲ��ģ��������ʦ��Ҳץ��\n");
			  } else {
				  if( objfam["generation"] - myfam["generation"] > 1 )
					  command ("say ������ôѲ��ģ��������ͬ����Ҳץ��\n");
				  else if( objfam["master_id"] == me->query("id") )
					  command ("say ������ôѲ��ģ�������ĵ���Ҳץ��\n");
				  else
					  command ("say ������ôѲ��ģ��������ʦֶҲץ��\n");
			  }
			}
			else if ( me->query("work_xuncha") )
			  command ("say ���������޺���������������ץ���޵��ӵ��𣿣�");

			return 1;
		}
	}
	else return 0;
}

void get_exp_in_xuncha(object me, object obj)
{
        int exp, pot, rate;

	if (obj->query("combat_exp") < 7000)
                write("������������Ҳץ����ÿɵ�������ѽ��");
                return ;

	if ( (rate = obj->query("combat_exp") / me->query("combat_exp")) > 1)
		rate = 1;

	exp = 30 + random(20) + 100 * rate;
	pot = 10 + random(10)/2 + 20 * rate;

	obj->move("/d/xingxiu/laofang");

	me->add("combat_exp", exp);
	me->add("potential", pot);

	command("nod " + me->query("id"));
	command("say ��Ѳ��ò���������Ľ��͡�");
	tell_object(me, sprintf("��õ���%s��Ǳ�ܣ�%s�㾭�顣\n",chinese_number(pot),chinese_number(exp)));
}

void get_money_in_xuncha(object me, object obj)
{
        object mo;
        int amount, rate;

	if (obj->query("combat_exp") < 7000)
                write("������������Ҳץ����ÿɵ�������ѽ��");
                return ;

	if ( (rate = obj->query("combat_exp") / me->query("combat_exp")) > 1)
		rate = 1;

	mo=new("/clone/money/silver");
	amount=20 + random(20) + 50 * rate;
	mo->set_amount(amount);
	mo->move(me);

	obj->move("/d/xingxiu/laofang");

	command("nod " + me->query("id"));
	command("say �㹤���ò���������Ľ��͡�");
	tell_object(me, sprintf("��õ���%s��������Ϊ���͡�\n",chinese_number(amount)));
}
