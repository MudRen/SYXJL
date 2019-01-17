// Jay 3/26/96
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ϲ÷�", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 60);
        set("long",
                "��λ�ϲ÷���Ц�����æ��������ʱ�Ĳ�һ���Լ����ϻ��ۡ�\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
        set("max_neli",5000);
        set("jiali",50);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);
        set("combat_exp", 250000);
    
        map_skill("force","bibo-shengong");
        map_skill("parry","luoying-shenjian");
        map_skill("sword","luoying-shenjian");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("dodge","anying-fuxiang");
    
        set("attitude", "peaceful");
        
        set("inquiry", ([
        "�����·�"  : "�����·����Ǽ�ʮ�ּ����£�Ҫ�����˵ľ��������������о��ĺ�������\n",
        "ԭ��"  : "�����·�����ѩ�ϡ��������ҵ����Ҳ��ܰ��㶩���·���\n",
       ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
        add_action("do_ding","ding");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�ϲ÷�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������·��ɡ�\n");
                        break;
                case 1:
                        say( "�ϲ÷��ü����˵������λ" + RANK_D->query_respect(ob)
                                + "���������ְ�����ﲻ���㡣\n");
                        break;
        }
}

int accept_object(object who, object ob)
{   
     if (!(ob = present("yiluo sha", this_player())))
     {
     message("vision","����ʲô���ⲻ�������������Σ�\n",who);
     }
     else
     {
     who->set_temp("get_wear",1);
     destruct(ob);
     message("vision","�ϲ÷��ͷ������һ�����е�����ɴ���˵�ͷ˵��\n",who);
     write("��������Զ������·��Σ�\n"+
          "     ˿��(belt)\n"+
          "     ñ��(hat)\n"+
          "     ͷ��(scarf)\n"+
          "     ѥ��(shoes)\n"+
          "     �·�(cloth)\n");       
    say("��λ"+RANK_D->query_respect(who)+"Ҫ����ʲô���Σ������˸�����(answer)��\n");        
    }
    return 0;
}

int do_answer(string arg)
{
    object me;
    me = this_player();
    if(!(me->query_temp("get_wear") ) ){
        write("���ҵ�ԭ������\n");
        return 1;
    }
    
    if(!arg){
       write("��Ҫ��ʲô���Σ�\n");
      return 1;
    }
    message("vision",me->name()+"���ϲ÷�����˵�˼��䡣\n",environment(me), ({me}) );
    switch (arg) {
      case "belt" : 
        me->delete_temp("get_wear");
        me->set_temp("wear",1);
        write("����λ"+RANK_D->query_respect(me)+"��˿�������ְɣ�(ding ˿������������(ʹ����ɫ��ο�help nick))\n");
        break;
      case "hat" :
        me->delete_temp("get_wear");
        me->set_temp("wear",2);
        write("����λ"+RANK_D->query_respect(me)+"��ñ�������ְɣ�(ding ñ�ӵ���������(ʹ����ɫ��ο�help nick))\n");
        break;
      case "scarf" :
        me->delete_temp("get_wear");
        me->set_temp("wear",3);
        write("����λ"+RANK_D->query_respect(me)+"��ͷ�������ְɣ�(ding ͷ�����������(ʹ����ɫ��ο�help nick))\n");
        break;
      case "shoes" :
        me->delete_temp("get_wear");
        me->set_temp("wear",4);
        write("����λ"+RANK_D->query_respect(me)+"��ѥ�������ְɣ�(ding ѥ�ӵ���������(ʹ����ɫ��ο�help nick))\n");
        break;
      case "cloth" :
        me->delete_temp("get_wear");
        me->set_temp("wear",5);
        write("����λ"+RANK_D->query_respect(me)+"���·������ְɣ�(ding �·�����������(ʹ����ɫ��ο�help nick))\n");
        break;
      default :
        message_vision(HIC "�ϲ÷�һ�����ɣ�ʲô���Σ�\n" NOR,me);
        return notify_fail("�ϲ÷���ϸ��˵�����²��ɶ�Ϸ��������!!\n");
    }
    return 1;
}

int do_ding(string arg)
{
    string o_name,id,w_name;
    object abc,make_time;   //���ɵ��������
    object me;
    int cba;
    me = this_player();
    cba = me->query_temp("wear");
    switch (cba) {
      case 1 : 
          if((me->query("wear/belt")) ) {
             say("�ϲ÷�һ��ãȻ�����Ѿ���һ��˿���ˣ�������ʲô���ѵ���������\n");
             return 2;
          }
          if( !arg )
             return notify_fail("�ϲ÷������˵�����˿�������ƺ��ڶ���˵��\n");
          sscanf(arg ,"%s" ,w_name );
          id="my belt";
          if(!w_name||!id)
             return notify_fail("ʲô?(ʹ��ding ˿������������\n)");
          me->delete_temp("wear");
          o_name="����ɴ";
          make_time=NATURE_D->game_time();
          write("�ϲ÷�����㣺�Ѿ������ˣ��͹����Ŀ��\n");
          me->set("wear/beltname",w_name+NOR);  //����������
          me->set("wear/belt",1);       //����������ֹ����ı�־      
          me->set("wear/beltid",id);        //�����Ĵ���
          me->set("wear/beltlv",1);     //�����ȼ�
          me->set("wear/beltor",o_name);    //��¼����ԭ��
          me->set("wear/beltvalue",0);          //��¼�����������еĵ���    
          me->set("wear/belttype","˿��");
          me->set("wear/belttime",make_time);
          abc=new("/d/npc/m_wear/wear/m_belt",1);    //�����½�
          abc->move(this_player());
        break;
      case 2 :
          if((me->query("wear/hat")) ) {
             say("�ϲ÷�һ��ãȻ�����Ѿ���һ��ñ���ˣ�������ʲô���ѵ���������\n");
             return 2;
          }
          if( !arg )
             return notify_fail("�ϲ÷������˵�����ñ�ӵ����ƺ��ڶ���˵��\n");
          sscanf(arg ,"%s" ,w_name );
          id="my hat";
          if(!w_name||!id)
             return notify_fail("ʲô?(ʹ��ding ñ�ӵ���������\n)");
          me->delete_temp("wear");
          o_name="����ɴ";
          make_time=NATURE_D->game_time();
          write("�ϲ÷�����㣺�Ѿ������ˣ��͹����Ŀ��\n");
          me->set("wear/hatname",w_name+NOR);  //����������
          me->set("wear/hat",1);       //����������ֹ����ı�־      
          me->set("wear/hatid",id);        //�����Ĵ���
          me->set("wear/hatlv",1);     //�����ȼ�
          me->set("wear/hator",o_name);    //��¼����ԭ��
          me->set("wear/hatvalue",0);          //��¼�����������еĵ���    
          me->set("wear/hattype","ñ��");
          me->set("wear/hattime",make_time);
          abc=new("/d/npc/m_wear/wear/m_hat",1);    //�����½�
          abc->move(this_player());
        break;
      case 3 :
          if((me->query("wear/scarf")) ) {
             say("�ϲ÷�һ��ãȻ�����Ѿ���һ��ͷ���ˣ�������ʲô���ѵ���������\n");
             return 2;
          }
          if( !arg )
             return notify_fail("�ϲ÷������˵�����ͷ������ƺ��ڶ���˵��\n");
          sscanf(arg ,"%s" ,w_name );
          id="my scarf";
          if(!w_name||!id)
             return notify_fail("ʲô?(ʹ��ding ͷ�����������\n)");
          me->delete_temp("wear");
          o_name="����ɴ";
          make_time=NATURE_D->game_time();
          write("�ϲ÷�����㣺�Ѿ������ˣ��͹����Ŀ��\n");
          me->set("wear/scarfname",w_name+NOR);  //����������
          me->set("wear/scarf",1);       //����������ֹ����ı�־      
          me->set("wear/scarfid",id);        //�����Ĵ���
          me->set("wear/scarflv",1);     //�����ȼ�
          me->set("wear/scarfor",o_name);    //��¼����ԭ��
          me->set("wear/scarfvalue",0);          //��¼�����������еĵ���    
          me->set("wear/scarftype","ͷ��");
          me->set("wear/scarftime",make_time);
          abc=new("/d/npc/m_wear/wear/m_scarf",1);    //�����½�
          abc->move(this_player());
        break;
      case 4 :
          if((me->query("wear/shoes")) ) {
             say("�ϲ÷�һ��ãȻ�����Ѿ���һ˫ѥ���ˣ�������ʲô���ѵ���������\n");
             return 2;
          }
          if( !arg )
             return notify_fail("�ϲ÷������˵�����ѥ�ӵ����ƺ��ڶ���˵��\n");
          sscanf(arg ,"%s" ,w_name );
          id="my shoes";
          if(!w_name||!id)
             return notify_fail("ʲô?(ʹ��ding ѥ�ӵ���������\n)");
          me->delete_temp("wear");
          o_name="����ɴ";
          make_time=NATURE_D->game_time();
          write("�ϲ÷�����㣺�Ѿ������ˣ��͹����Ŀ��\n");
          me->set("wear/shoesname",w_name+NOR);  //����������
          me->set("wear/shoes",1);       //����������ֹ����ı�־      
          me->set("wear/shoesid",id);        //�����Ĵ���
          me->set("wear/shoeslv",1);     //�����ȼ�
          me->set("wear/shoesor",o_name);    //��¼����ԭ��
          me->set("wear/shoesvalue",0);          //��¼�����������еĵ���    
          me->set("wear/shoestype","ѥ��");
          me->set("wear/shoestime",make_time);
          abc=new("/d/npc/m_wear/wear/m_shoes",1);    //�����½�
          abc->move(this_player());
        break;
      case 5 :
          if((me->query("wear/cloth")) ) {
             say("�ϲ÷�һ��ãȻ�����Ѿ���һ���·��ˣ�������ʲô���ѵ���������\n");
             return 2;
          }
          if( !arg )
             return notify_fail("�ϲ÷������˵������·������ƺ��ڶ���˵��\n");
          sscanf(arg ,"%s" ,w_name );
          id="my cloth";
          if(!w_name||!id)
             return notify_fail("ʲô?(ʹ��ding �·�����������\n)");
          me->delete_temp("wear");
          o_name="����ɴ";
          make_time=NATURE_D->game_time();
          write("�ϲ÷�����㣺�Ѿ������ˣ��͹����Ŀ��\n");
          me->set("wear/clothname",w_name+NOR);  //����������
          me->set("wear/cloth",1);       //����������ֹ����ı�־      
          me->set("wear/clothid",id);        //�����Ĵ���
          me->set("wear/clothlv",1);     //�����ȼ�
          me->set("wear/clothor",o_name);    //��¼����ԭ��
          me->set("wear/clothvalue",0);          //��¼�����������еĵ���    
          me->set("wear/clothtype","�·�");
          me->set("wear/clothtime",make_time);
          abc=new("/d/npc/m_wear/wear/m_cloth",1);    //�����½�
          abc->move(this_player());
        break;
      default :
        return notify_fail("ʲô?\n");
    }
    w_name = replace_string(w_name, "$BLK$", BLK);
    w_name = replace_string(w_name, "$RED$", RED);
    w_name = replace_string(w_name, "$GRN$", GRN);
    w_name = replace_string(w_name, "$YEL$", YEL);
    w_name = replace_string(w_name, "$BLU$", BLU);
    w_name = replace_string(w_name, "$MAG$", MAG);
    w_name = replace_string(w_name, "$CYN$", CYN);
    w_name = replace_string(w_name, "$WHT$", WHT);
    w_name = replace_string(w_name, "$HIR$", HIR);
    w_name = replace_string(w_name, "$HIG$", HIG);
    w_name = replace_string(w_name, "$HIY$", HIY);
    w_name = replace_string(w_name, "$HIB$", HIB);
    w_name = replace_string(w_name, "$HIM$", HIM);
    w_name = replace_string(w_name, "$HIC$", HIC);
    w_name = replace_string(w_name, "$HIW$", HIW);
    w_name = replace_string(w_name, "$NOR$", NOR);
    return 1;
}
