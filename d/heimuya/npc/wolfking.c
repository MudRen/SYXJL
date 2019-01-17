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
        set("chat_msg_combat", ({
                "����������ร�ร�ร�ร�ร�ร�\n",
                "����ͻȻ����������������ҧ��ȴ��֪������ҧ˭��\n"
        }) );
                
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);
        set("chat_chance", 20);

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
        message_vision(HIW "$N���쳤Х,Զ���ͱ��ϴ����������ƣ�\n" NOR,this_object());
        message_vision("$N�Һ�һ�������ˣ�\n", this_object());
        message_vision(HIR "ͻȻ�Ӱ������һȺҰ�ǣ�\n" NOR);
        ob = new(__DIR__"obj/goupi");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolf");
        ob->move(environment(this_object()));
        ob = new("wolfking");
        ob->move(environment(this_object()));
 
        destruct(this_object());
}

