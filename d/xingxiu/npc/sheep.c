// sheep.c ��
// by QingP

inherit NPC;

void create()
{
	switch( random(3) )
	{
		case 0:	
			set_name("ɽ��", ({ "shan yang", "yang", "sheep" }) );
			set("long", "һͷ��ɫ��Сɽ��\n");
			set("age", 5);
		break;
		case 1:	
			set_name("ɽ��", ({ "shan yang", "yang", "sheep" }) );
			set("long", "һͷ��ɫ��Сɽ��\n");
			set("age", 3);
		break;
		case 2: 
			set_name("����", ({ "mian yang", "yang", "sheep" }) );
			set("long", "һͷ��ɫ��С����\n");
			set("age", 4);
		break;
		case 3:	
			set_name("����", ({ "mian yang", "yang", "sheep" }) );
			set("long", "һͷ��ɫ��С����\n");
			set("age", 6);
		break;
	}
	set("race", "Ұ��");
        set("attitude", "peaceful");
        
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 700);
        
        set_temp("apply/attack", 4);
        set_temp("apply/defense", 10);
        set_temp("apply/damage", 3);
        set_temp("apply/armor", 5);

        setup();
}

void die()
{
        object ob;
        message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new(__DIR__"obj/yangrou");
        ob->move(environment(this_object()));
        destruct(this_object());
}