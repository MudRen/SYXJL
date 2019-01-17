// room: /kunlun/jingsish.c

 

#include <ansi.h>

inherit ROOM;

int HAVE_BOOK=1;

void create()

{

        set("short", "��˼��");

        set("long", @LONG

�������������˱��ž�˼, �����书�����ڡ�����һ��, һ��, һ��,��

��ɢ���ż������š��������ڴ˾�˼, �������²������˷�������խС, �ʴ�

������ֱͨС��������������ʱȥ�������򡣱���İ�ǽ�ϣ������������ž�

˼���ĵá��������������ӣ����������صĸо����·������е�ʲô���ܡ�

LONG

        );



        set("exits", ([

                "south" : __DIR__"guanhuat",

        ]));



        setup();

//        replace_program(ROOM);

}

void init()

{

        object ob;



        if( interactive(ob = this_player()) ) 

        {

                remove_call_out("setup_obj");

                call_out("setup_obj", 1, ob);

        }



        add_action("do_hit", "hit");

        add_action("do_du", "du");

        add_action("do_du", "read");

        }



int do_hit(string arg)

{

        object me;



        if(arg!="��ǽ" ) return 0;



        me=this_player();



        message_vision(HIR"$N���������ǽ��\n"NOR,me);



        if(me->query_skill("force")<40)

        {

                message_vision(YEL"$N���ڹ�̫���˸����򲻴�ʯ�ڡ�\n"NOR,me);

                return 1;

        }



        message_vision(HIR"$N����$N����$N�ٻ�����\n"NOR,me);



        message_vision(HIW"$N���ڰ�ʯ�ڸ����ˡ�\n"NOR,me);



        if(HAVE_BOOK==1)

        {

                message_vision(YEL"$N����ʯ�����б����顣\n"NOR,me);



              if( me->over_encumbranced() ) 

                        write("�����Ѿ����ɹ����ˣ�û���������� :-( \n");

              else

        {

                        message_vision(HIM"$N�õ�һ�����ǽ���(�¾�)��\n"NOR,me);

                      new(__DIR__"obj/kl_book2")->move(me);

                      HAVE_BOOK=0;

              }

        }

        else

        {

                message_vision(YEL"$N����ʯ�����ǿյģ�ʲô��û�С�\n"NOR,me);

        }



        return 1;

}



int do_du(string arg)

{

        if((arg!="book")&&(arg!="shu")) return 0;



        write("�����õ������йص��ؼ����㻹�Ǵ���ȥ�ٶ��ɣ�\n");

        

        return 1;

}



