// lixunhuan.c ��Ѱ��

#include <ansi.h>

inherit NPC;
void greeting(object ob);
void do_init();
void do_init1();
int ask_me();

void create()
{
        set("title",HIR"���Ƶ�һ��"NOR);
	set("nickname",HIM"����"NOR);
        set_name("��Ѱ��", ({"li xunhuan", "li", "master"}));
        set("gender", "����");
        set("age", 34);
        set("long", 
                "������һ��������Ѱ��,���а����������׵ڶ�.\n"
                "С��ɵ�,�����鷢.��֪��Ϊ�������ֺ��ܵ�ż��.\n"
                "�����İ�����¸���֪���㵹�˶��ٳ�����Ů.\n");
        set("attitude", "peaceful");
        
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("chat_chance",9);
        set("chat_msg", ({
                HIR"��Ѱ����ʼ��ͣ�Ŀ�,һ˿˿��Ѫ˳�����������������.\n"NOR,
  		HIB"��Ѱ��̾���������Խ����������˸���ƿ��������ĺ������.\n"NOR,
                HIW"��Ѱ�������Ŀ�������ĵ���,����ȴ�ѳ���.\n"NOR,
                (: call_out("do_init1", 1) :),

        }));

        set("inquiry", ([
                "��ʫ��"  : HIR"��ȥ�����黹����ʲô?��...\n"NOR, 
		"����"    : HIY"�������ҵĺ��ֵ�,����������Ϣ��?\n"NOR,
		"liwu"    : (: ask_me :),
                "����"    : (: ask_me :),
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 8000000);
        set("score", 200000);

        set_skill("dodge", 100);                
        set_skill("feidao", 200);
        set_skill("parry", 120);                
	set_skill("throwing",200);
	set_skill("force",200);
        
        map_skill("throwing", "feidao");

       
        setup();
		
        
      carry_object("/d/city/obj/cloth")->wear();
}


void greeting(object ob)
{

        int combatexp = (int) (ob->query("combat_exp"));
        if( !ob || environment(ob) != environment() ) return;
	switch ( random(2) ){
		case 0:
command("es ""��ӭ������Եϴ��¼ 202.101.10.243 8888 �������ŵ�����ʵ�н���ϵͳ. �����������.\n");
			break;
		case 1:
command("es ""��Եϴ��¼ 202.101.10.243 8888 �����ص�Ц������������ ʵ���������� ��֤��ҹ�ƽ����.\n");
			break;
	}

        if(combatexp<1000)
        {

        command("bow "+ob->query("id"));
        command("say �㲻���Ĵ�����"HIY"look"NOR CYN",������ʲô�����㶼���Լ�����"HIY"get"NOR CYN"���š���
            �����Ȳ��"HIY"i or inventory"NOR CYN"����������������Щʲô����Ҫ��ʱ��
            ���"HIY"hp"NOR CYN"�������״̬��Ҫ�Ƕ��˻���˾�ȥ��Щ�Եĺȵİɡ�����
            ����ָ��ľ����÷����Բο� "HIY"help commands"NOR CYN"��"NOR);

        return;
        }
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
int ask_me()
{
  object ob=this_player();
  if( ob->query("shizhe") )
    {command("smile "+ob->query("id"));
     command("say ��λ"+RANK_D->query_respect(ob)+"�Ѿ��ù��Ҹ��������Ŷ��");
     return 1;
    }
    ob->add("combat_exp",20000);
ob->add("potential",10000);
  ob->set("shizhe",1);

  command("addoil "+ob->query("id"));
command("chat "+ob->name(1)+HIR+"�õ����Ҹ���������ʼ������Եϴ��¼�Ϻ�վ(202.101.10.243 8888)��"+NOR+"");
  command("es "+ob->name(1)+"�õ����Ҹ���������ʼ����"+HIY+"��Եϴ��¼"HIR"(202.102.230.25 5555)"+NOR+"");
  return 1;
}
