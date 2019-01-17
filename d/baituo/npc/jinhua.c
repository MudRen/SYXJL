// jinhua.c



#include <command.h>

#include <ansi.h>

inherit NPC;



void create()

{

	set_name("��", ({ "jin hua","hua","jin"}) );

	set("gender", "Ů��" );

	set("age", 24);

	set("long", "һ������ò���Ĺ��\n");

	set("shen_type", 1);

	set("combat_exp", 800);

	set("str", 18);

	set("dex", 18);

	set("con", 18);

	set("int", 18);

	set("attitude", "friendly");

	set("chat_chance",5);

	set("chat_msg",({

	    "�𻨿����ţ��ҵ�����ô��ô��Ӵ��\n",

	    "��Ĩ�����᣺��ѽ���Һ�����ѽ��\n",

	    "��̾����˵������֪���������ܷ��ټ��������\n"

	   }) );

       set("inquiry",([



	   "����" : "���������۾�����֪������������������������ҿ�����\n",

	   "�廨Ь" : "�𻨳Ծ��ؿ����㣺�������廨Ь�𣿿���ҿ�����\n",

	   ]) );

       setup();

}



void init()

{

	object ob;



	ob = this_player();



	::init();

	if( interactive(ob) && !is_fighting() )

	       {

			remove_call_out("greeting");

			call_out("greeting", 1, ob);

		}

}



void greeting(object ob)

{

	if( !ob || environment(ob) != environment() ) return;

	say("��һ�����˽�����æ˵����λ" + RANK_D->query_respect(ob)

	  +"�������ǡ�����ɽׯ������Ӷ�ˡ������������Ϣ��\n");

}













int accept_object(object who, object ob)

{

	int i, whoexp;

	object obn, *inv;



	if( !who || environment(who) != environment() ) return 0;

	if ( !objectp(ob) ) return 0;

	if ( !present(ob, who) ) return notify_fail("��û�����������\n");



	if (  (string)ob->query("name") != "�廨Ь")

		    return notify_fail("�𻨲���Ҫ���������\n");



	if ( userp(ob) )

	{

		if ( who->query("combat_exp") >= 2 )

		{

			whoexp = who->query("combat_exp")/2;

			who->set("combat_exp", whoexp );

		}

		who->set("balance", 0);

		ob->move(environment(who));

		write("�𻨶���ŭ��һ�����ޣ���Ȼ���ã£գ�Ĳ��������ȥ�ɡ�\n");

		inv = all_inventory(who);

		for (i = 0; i < sizeof(inv); i++)

			DROP_CMD->do_drop(who, inv[i]);

		who->die();

		return 0;

	}



       write( HIY "��˫�������廨Ь���������£�\n

       ��������ڣ���������Ů�������һ���Ϊ�����أ�\n" NOR );



       message_vision("��Ĩ�˰����ᣬ������˼ЦЦ˵����λ"

	+RANK_D->query_respect(who)+"��Ц�ˡ�\n

	    ��Ҳûʲô���������㣬��ֻ֪��ɽ��ͷ�и�Ǯ����ڴ��¡�\n

	    ����͸���������\n",who);

       message_vision("$N��𻨴Ӵ��°����һֻǮ�䣬$N�Ȳ������ش�һ����\n

	 �ۣ������ö�ö�Ľ���Ӵ��$N���������ذѽ���ȫװ���·��\n

	 ��֪����̫�����·��ų�������ӣ�����һ�Կ���ֱ�֣�\n

	 $N����ô��Ȼ��ɦɦͷ��Ҳ���š��ٺ١�ɵЦ��\n", who);

	obn = new("/clone/money/gold");

	obn->set_amount(1);

	obn->move(who);

	call_out("destroy", 1, ob);

      return 1;

}



void destroy(object ob)

{

	destruct(ob);

	return;

}

