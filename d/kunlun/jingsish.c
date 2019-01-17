// room: /kunlun/jingsish.c

 

#include <ansi.h>

inherit ROOM;

int HAVE_BOOK=1;

void create()

{

        set("short", "静思室");

        set("long", @LONG

这是历代掌门人闭门静思, 领悟武功的所在。仅设一床, 一桌, 一椅,另

外散放着几个蒲团。掌门人在此静思, 往往数月不出。此房间甚是窄小, 故此

南有门直通小练功房，便于随时去演练功夫。北面的白墙上，挂着历代掌门静

思的心得。。。。整间屋子，给人以神秘的感觉，仿佛在其中的什么秘密。

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



        if(arg!="白墙" ) return 0;



        me=this_player();



        message_vision(HIR"$N奋力击向白墙。\n"NOR,me);



        if(me->query_skill("force")<40)

        {

                message_vision(YEL"$N的内功太差了更本打不穿石壁。\n"NOR,me);

                return 1;

        }



        message_vision(HIR"$N击，$N击，$N再击……\n"NOR,me);



        message_vision(HIW"$N终于把石壁给打穿了。\n"NOR,me);



        if(HAVE_BOOK==1)

        {

                message_vision(YEL"$N看到石壁中有本旧书。\n"NOR,me);



              if( me->over_encumbranced() ) 

                        write("但你已经负荷过重了，没法再拿书了 :-( \n");

              else

        {

                        message_vision(HIM"$N拿到一本两仪剑法(下卷)。\n"NOR,me);

                      new(__DIR__"obj/kl_book2")->move(me);

                      HAVE_BOOK=0;

              }

        }

        else

        {

                message_vision(YEL"$N发现石壁中是空的，什么都没有。\n"NOR,me);

        }



        return 1;

}



int do_du(string arg)

{

        if((arg!="book")&&(arg!="shu")) return 0;



        write("你已拿到昆仑有关的秘籍，你还是带出去再读吧！\n");

        

        return 1;

}



