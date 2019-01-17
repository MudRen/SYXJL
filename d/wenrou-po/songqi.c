// songqi.c ....angle

inherit NPC;



void new_shikuai();

int ask_job();

int shikuai = 1;



void create()

{

        set_name("����", ({ "song qi","song" }) );



        set("combat_exp", 10000);

        set("max_jing", 300);

        set("max_qi", 300);

        set_skill("dodge", 40);

        set_skill("unarmed", 40);

        set_temp("apply/armor", 60);

        set_temp("apply/damage", 20);

        set("inquiry",([

                "����"  : (: ask_job :),

                "job"  : (: ask_job :),

        ]));

        set("age", 34);

        set("long",

          "�����ǲ�ʯ���Ĺ���֮һ�����ֿ���������ȡһЩ�򵥵����񣬱���˵��ʯͷ������

ɽ���ġ������֡����ڽ����У����Լ���ҪһЩ���ֽ������ʯͷ�˵�ɽ����\n");

        set("chat_chance", 10);

        set("chat_msg", ({

                "����һ�߸��򹤵����Ź�Ǯ��һ�ߺ����������ֻ��ǲ�������������ȥ�ҵ���أ���\n",

                "����Ĩ��һ�Ѷ�ͷ�ϵĺ�ˮ�������ֹ��ţ�������ģ����˻����������ӵİ࣬�������ˣ���\n",

                "����ָ���Ź����ǰ���ʯͷ������ʱ����֣�\n",

                "����͵͵�Ķ���˵������˵�������ֵ�ʦ̫���Ǹ���ɫ���ˣ��ٺ٣����롭���ٺ١�����\n"

        }) );

        setup();                



        add_money("silver", 8);

        carry_object("/clone/misc/cloth")->wear();

}

void init()

{

        object ob;

         ::init();

        if (interactive(ob = this_player()) && !is_fighting()) {

                remove_call_out("greeting");

                call_out("greeting", 1, ob);

        }

    call_out("enable_shikuai",50);

    if( shikuai )

        call_out("new_shikuai",3);

    shikuai = 0;



}



void greeting(object me)

{

    command("look " + me->query("id"));

     if (me->query("combat_exp")<1000) {

       command("say �����������壬��ȥ�Ա����մ��������ɣ�");

       command("kick " + me->query("id"));

       me->move(__DIR__"shichang1");

       message("vision", me->name() +"������һ���߳��˲�ʯ����\n", 

                environment(me), ({me}));

       }

}



int accept_fight()

{

        command("say һ��ȥ��û������æ���أ��������Ĵ���ȥ��");

        return 0;

}



int ask_job()

{

        object silver,me;

        int amount;

        me = this_player();



        if( is_fighting() ) return 1;



        if( amount = me->query_temp("��Ǯ") ) {

            switch(random(3)){

                case 0:

                    silver = new("/clone/money/silver");

          silver->set_amount((random(5)+1) * me->query_temp("��Ǯ") );

                    silver->move(this_object());

                    command("say �а��㣡������Ӧ�õģ�");

                    command("give silver to " + me->query("id") );

                    break;

                case 1:

               if( me->query("combat_exp") <10000 )            me->add("combat_exp",me->query_temp("��Ǯ")*(random(10)+10) );

                    command("say �а��㣡������Ӧ�õģ�");

                    break;

                case 2:

               if( !me->query("potential") || me->query("potential") <100 )



             me->add("potential",me->query_temp("��Ǯ")*(random(5)+1) );

                    else if( me->query("combat_exp") <10000 )

          me->add("combat_exp",me->query_temp("��Ǯ")*(random(25)+8) ); 

                    command("say �а��㣡������Ӧ�õģ�");

                    break;

            }

            me->delete_temp("��Ǯ");

        } else if( (present("shi kuai",environment(this_object()))))

            command("say ȥ�ɣ���ʯͷ̧���������ǰ�����ˣ��������������");

        else command("say �����һ�����˵����������ô����û����û����æ�ĺ���");

    return 1;

}



void new_shikuai()

{

        object ob;

        

        if( !environment()

          ||      sizeof(all_inventory(environment())) >= 8 ) return;



        ob = new(__DIR__"shikuai");

        ob->move(environment());

        say("����˵��������ҼӰѾ�ѽ���ô��Ǵ��ģ�\n");

        call_out("new_shikuai",100);     

}













