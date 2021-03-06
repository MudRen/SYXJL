// sheep.c 羊
// by QingP

inherit NPC;

void create()
{
	switch( random(3) )
	{
		case 0:	
			set_name("山羊", ({ "shan yang", "yang", "sheep" }) );
			set("long", "一头白色的小山羊。\n");
			set("age", 5);
		break;
		case 1:	
			set_name("山羊", ({ "shan yang", "yang", "sheep" }) );
			set("long", "一头黑色的小山羊。\n");
			set("age", 3);
		break;
		case 2: 
			set_name("绵羊", ({ "mian yang", "yang", "sheep" }) );
			set("long", "一头白色的小绵羊。\n");
			set("age", 4);
		break;
		case 3:	
			set_name("绵羊", ({ "mian yang", "yang", "sheep" }) );
			set("long", "一头黑色的小绵羊。\n");
			set("age", 6);
		break;
	}
	set("race", "野兽");
        set("attitude", "peaceful");
        
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
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
        message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
        ob = new(__DIR__"obj/yangrou");
        ob->move(environment(this_object()));
        destruct(this_object());
}