// foreman.c

inherit NPC;

//void relay_say();

void new_crate();

void create()

{

	set_name("��ͷ", ({ "foreman" }) );

	set("age", 48);

	set("long",

"��λ������һ�ջ�Ĺ�ͷ������ָ�ӹ��˽���������������\n"

"�����׬ЩǮ�����Ը���̸̸����\n");

//	set("inquiry", ([

//		"����" : (: relay_say() :),

//	]));



	set("chat_chance", 10);

	set("chat_msg", ({

		(: new_crate :),

		"��ͷ����ߺ�������˽�����Ӳֿ�������\n",

		"��ͷ��У�С���أ�������û������\n",

		"��ͷ˵����˭��ȥ����Щ���֣�����æ���ˡ�\n",

		"��ͷ˵����Ҫ�㹤Ǯ��һ������ ... �� ...\n"

	}) );



	setup();

	add_money("silver",2);

}



void relay_say(object me, string msg)

{

	object money;

	if( me->is_fighting() || me->is_chatting() ) return;

	if( strsrch(msg, "��Ǯ") >= 0 ) {

	int amount;

  	add_money("silver",2);

		if( amount = me->query_temp("wage_deserved") ) {

		money = new("/obj/money/coin");

		money->set_amount(amount);

		money->move(this_object());

		command("say �ã��� ... �ܹ���" + chinese_number(amount) + "��Ǯ���ģ����㡡");

		me->delete_temp("wage_deserved");

		command("give coin to " + me->query("id"));

		}

	else say("��ͷ˵������һ����������Ǯ���𻵵���������\n");

	return;

	}

}



void new_crate()

{

	object ob;

	if( !environment()

	||sizeof(all_inventory(environment())) >= 15 ) return;

	ob = new(__DIR__"obj/crate");

	ob->move(environment());

	say("��ͷ˵����ι���Ǳ�ж����С��һ�㣬���ˤ���ˣ�\n");

}

