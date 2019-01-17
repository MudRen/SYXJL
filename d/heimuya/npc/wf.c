#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB"����"NOR, ({ "wolf king","king"}) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ����˶�����۷����̹���ǡ�\n");
        set("attitude", "peaceful");
        
        set("str", 100);
        set("cor", 100);
        set("dex", 100);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000000);
        set("shen_type", -1);

        set("chat_chance", 6);
        set("chat_msg", ({
          (: this_object(), "random_move" :),
        }) );
        
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "Ұ�Ǵ�����ร�ร�ร�ร�ร�ร�\n",
                "Ұ��ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
        }) );
                
        set_temp("apply/attack", 150);
        set_temp("apply/damage", 300);
        set_temp("apply/armor",  200);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        setup();
}


void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }       
}
void die()
{
        object ob;
        message_vision("$N�Һ�һ�������ˣ�\n", this_object());
        ob = new(__DIR__"obj/goupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

