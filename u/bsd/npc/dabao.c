// weixiao bao.c ΤС��

#include <ansi.h>

inherit NPC;
void greeting(object ob);
void do_init();
void do_init1();
int ask_me();

void create()
{
        set("title",HIR"������֪ ��������"NOR);
        set_name("ΤС��", ({"wei xiaobao","wei","bao","xiaobao"}));
        set("gender", "����");
        set("age", 19);
        set("long", 
                "�����ǿ����ʵ����ԵĴ����--ΤС��,��ػ�\n"
                "��ľ������������ͦ���������ɾ��ǰ�ˣ����.\n"
                "��������һ��Ȣ���߸����š�\n"
                "�������˳�Сɫ�ǡ�\n");
        set("attitude", "peaceful");
        
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("chat_chance",9);
         set("es_msg", ({
                RED"ΤС���૵����������裬������椺úõģ�������˵¹����û�ҾͲ���¹���ǣ��Ҳ�ݲ�����\n"NOR,
  HIG"ΤС��������Ц��˵���ٺ٣�������MUD?������ҳhttp://202.102.230.25��\n"NOR,
                HIC"ΤС����������С��50000?������ȥ����ѽ�����ںӱߡ�\n"NOR,
                (: call_out("do_init1", 1) :),

        }));

        set("inquiry", ([
               "˫��" : HIM"����ϲ����Ѿͷ���������� \n"NOR,
               "����" : WHT"�Ҽ�����������Ư����һ�����ҿ�׷�����ܳ�ʱ��Ŷ��\n"NOR,
               "����" : BLU"�ҿ��Ը����㼸�����ɵķ������ʣ�Ľ�ݣ����£�ɱ�֣�佻�����÷,���ء�\n"NOR,
               "Ľ��" : HIB"����Ľ��ѽ����̩ɽ�Զ���̫����������ȥ��\n"NOR,
               "����" : HIY"������̣���������Ȫ���Ǳߡ�\n"NOR,
               "ɱ��" : YEL"ɱ��¥!��ɱ��¥!���Ǻǣ�ȥ���Ÿ������ң�\n"NOR,
               "佻�" : MAG"������ٺ٣��Ҽǲ�����ˣ��ͼǵ��������º���Ĺ��С�\n"NOR,
               "��÷" : GRN"���Ŵ�ѩ����÷ɽׯ����֪�������ǴӾ��ǵ�����һֱ�����ߡ�\n"NOR,
               "����" : CYN"�㻹��ȥ��ɽ���¿���ȥ�ɡ�\n"NOR,
               "¹����" : HIR"��¹���Ƕ���֪���������ʲô����\n"NOR,
               "Τ����" :WHT"�������������ǲ���...�ٺ�..\n"NOR,       
                "��Ʒ"  : HIR"��˵Ԫ������Ʒ����Ʒ�����ڳﱸ�У���99��1��1����ʱ��\n�Ҿͻᷢ�����ǵġ���Ҫ�ż��\n"NOR, 
				"liwu" : (: ask_me :),
                "����" : (: ask_me :),
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 800000);
        set("score", 200000);

        set_skill("dodge", 100);                // ��������
        set_skill("shenxing-baibian", 100);
        set_skill("parry", 120);                // �����м�
        
        map_skill("dodge", "shenxing-baibian");

       
        setup();
		
        
      carry_object("/d/city/obj/cloth")->wear();
}


void greeting(object ob)
{

        int combatexp = (int) (ob->query("combat_exp"));
        if( !ob || environment(ob) != environment() ) return;
        if(combatexp<1000)
        {
//         say(HIW"ΤС��������˵���������İ�Ҫ������\n"NOR);

        command("bow "+ob->query("id"));
        command("say �㲻���Ĵ�����"HIY"look"NOR CYN",������ʲô�����㶼���Լ�����"HIY"get"NOR CYN"���š���
            �����Ȳ��"HIY"i or inventory"NOR CYN"����������������Щʲô����Ҫ��ʱ��
            ���"HIY"hp"NOR CYN"�������״̬��Ҫ�Ƕ��˻���˾�ȥ��Щ�Եĺȵİɡ�����
            ����ָ��ľ����÷����Բο� "HIY"help commands"NOR CYN"��"NOR);

        return;
        }
        else if((combatexp<10000)&&(combatexp>1000))
        {   say(HIY"ΤС��Ц������˵����λ"+RANK_D->query_respect(ob)+
               ",��MUD�Ѿ������ˣ�Ҫ�ǻ������⿴��ҳȥ�ɡ�\n"NOR);
        return;
        }
        else if((combatexp<100000)&&(combatexp>10000))
        {   say(HIR"ΤС�����ֵ�����λ"+RANK_D->query_respect(ob)+
               ",Ҫ�����书Ŷ�����ڽ�����������֮�ء�\n"NOR);
        return;
        }
        else if((combatexp<500000)&&(combatexp>100000))
        {   say(HIM"ΤС�������ۣ���λ"+RANK_D->query_respect(ob)+
               "��������¹���ǵ�������Ŷ��\n"NOR);
        return;
        }
        else
        {   say(HIW"ΤС�������������쿴����λ"+RANK_D->query_respect(ob)+
               "������¹���ǵĳ������֡�\n"NOR);
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
  command("ldj "+ob->name(1)+"�õ����Ҹ���������ʼ���߽�����");
command("es "+ob->name(1)+"�õ����Ҹ���������ʼ����"+HIY+"¹������Եվ"HIR"(202.102.230.25 5555)"+NOR+"");
  return 1;
}
