// sheep.c ɽ��
// by QingP

inherit NPC;

void create()
{
	set_name("ɽ��", ({ "shan yang", "yang", "sheep" }) );
	set("race", "Ұ��");
	set("age", 5);
	switch( random(3) )
	{
		case 0:	
			set_name("ɽ��", ({ "shan yang", "yang", "sheep" }) );
			set("long", "һֻ��ɫ��Сɽ��\n");
		break;
		case 1:
			set("long", "һֻ��ɫ��Сɽ��\n");
		break;
		case 2:
			set("long", "һֻ��ɫ��С����\n");
		break;
		case 3:
			set("long", "һֻ��ɫ��С����\n");
		break;
	}
        set("long", "һֻ��ɫ��Сɽ��\n");
        set("attitude", "peaceful");
        
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
//      set("shen_type", 0);

//      set("chat_chance", 6);
//      set("chat_msg", ({
//              (: this_object(), "random_move" :),
//      }) );
        
== δ����� 57% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}

void die()
{
        object ob;
        message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new(__DIR__"turou");
        ob->move(environment(this_object()));
        destruct(this_object());
}
