#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("�Ϻ�", ({ "lao han"}));
        set("long", 
                "�����Ǹ��𳤰���¥�����Ϻ���\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
        set("gender", "����");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 9000);
        set("max_jing", 3000);
        set("neili", 22000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 40000);

        set_skill("force", 300);
        set_skill("dodge", 685);
        set_skill("unarmed", 1100);
        set_skill("parry", 2180);

        set("inquiry", ([
                "ɨ��" : (: ask_me :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "�Ϻ���ü�����������������ײ��а�ˣ���Ȼ�Է��Ķ������Ҳ��š�\n");
}

string ask_me()
{
        this_player()->set_temp("up",1);
        return "�ǰ������첻�ܰ������ɨ�ɾ���Ҫ�����ˣ�����ҵ�������һ�Ұɡ�";
}

