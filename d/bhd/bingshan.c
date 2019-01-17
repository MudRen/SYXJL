inherit ROOM;



void home( object ob ) ;



// Room: /u/setup/bingshan.c





void create()

{

        set("short", "冰山");

        set("long", @LONG

大冰山在日光的照射下发出刺眼的光芒，显得十分奇丽，这里到处都是

冰雪，冰山颇大，如陆地上之山丘，一眼望去，横百余丈，纵长几十丈，冰

山上滑不留步，这时你看见前面一小浮冰正在向北飘流。你的船就在南面不

远之处，周围结满了冰。

LONG

        );

        set("exits", ([

                "north" : __DIR__"bingshan",

                "south" : __DIR__"bingshan3",

                "east" : __DIR__"bingshan3",

                "west" : __DIR__"bingshan3",

        ]));

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

         tell_object(this_player() , "你要 enter 哪儿？\n" ) ;

         return 1 ;

       }

    ob = this_player () ;

    message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);

    message_vision("船夫升起帆，船就向北方航行。\n", ob);

    ob ->move("/d/shenlong/dahai") ;

      tell_object(ob,"哈哈\n") ;

    call_out("home", 10 , ob );

    return 1 ;

}

void home( object ob )

{

  tell_object(ob , "大船终于抵达了中原的一个繁华城市。你走下船来。\n" ) ;

    ob ->move("/d/bhd/haigang") ;

}



int do_jump(string arg)

{

        object me = this_player();



        if ( arg == "fubing") {

                if (me->query_skill("dodge", 1) >= 60) {

                        message("vision", me->name() + "吸了口气，纵身向对面跃去。\n",

                                environment(me), ({me}) );

                        write("你吸了口气，纵身向对面跃去。\n");

                        me->move(__DIR__"bingshan1");

                        message("vision", "只见人影一闪，" + me->name() +  "纵身跃了过来。\n",

                                environment(me), ({me}) );

                        return 1;

                }

                else {

                        message("vision", me->name() + "纵身向对面跃去，只听“扑通”一声，" + me->name() + "摔入冰中，狼狈的爬了回来。\n",

                                environment(me), ({me}) );

                        write("你纵身向对面跃去，只听“扑通”一声，你摔入冰中，狼狈的爬了回来。\n");

                        me->receive_damage("qi",30);

                        return 1;

                }

        }

        return 0;



}









