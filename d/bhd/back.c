inherit ROOM;



void home( object ob ) ;



// Room: /u/setup/bingshan.c





void create()

{

        set("short", "��ɽ");

        set("long", @LONG

���ɽ���չ�������·������۵Ĺ�â���Ե�ʮ�����������ﵽ������

��ѩ����ɽ�Ĵ���½����֮ɽ��һ����ȥ��������ɣ��ݳ���ʮ�ɣ���

ɽ�ϻ�����������ʱ�㿴��ǰ��һС����������Ʈ������Ĵ��������治

Զ֮������Χ�����˱���

LONG

        );

        set("no_clean_up", 0);



        setup();

}



void init()

{

    add_action("do_enter", "enter");

add_action("do_jump", "jump");

add_action("do_jump", "yue");

}

int do_enter ( string arg )

{

    object ob ;

    if( !arg || arg !="chuan" ) 

       {

         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;

         return 1 ;

       }

    ob = this_player () ;

    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);

    message_vision("�������𷫣������򱱷����С�\n", ob);

    ob ->move("/d/shenlong/dahai") ;

      tell_object(ob,"����\n") ;

    call_out("home", 10 , ob );

    return 1 ;

}

void home( object ob )

{

  tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;

  ob->move ("/u/chenww/bhd/haigang") ;

}



int do_jump(string arg)

{

        object me = this_player();



        if ( arg == "fubing") {

                if (me->query_skill("dodge", 1) >= 60) {

                        message("vision", me->name() + "���˿��������������Ծȥ��\n",

                                environment(me), ({me}) );

                        write("�����˿��������������Ծȥ��\n");

                        me->move(__DIR__"bingshan1");

                        message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n",

                                environment(me), ({me}) );

                        

                        return 1;

                }

                else {

                        message("vision", me->name() + "���������Ծȥ��ֻ������ͨ��һ����" + me->name() + "ˤ����У��Ǳ������˻�����\n",

                                environment(me), ({me}) );

                        write("�����������Ծȥ��ֻ������ͨ��һ������ˤ����У��Ǳ������˻�����\n");

                        me->receive_damage("qi",30);

                        return 1;

                }

        }

        return 0;



}







