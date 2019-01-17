// shikuai.c ... angle

 

inherit ITEM;



void create()

{

        set_name("石块", ({ "shi kuai", "shi"}));

        set_weight(40000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "个");

                set("long", "这是一个巨大的石块。\n");

                set("value", 1);

        }

        setup();

}



void init()

{

        add_action("do_get", "get");

        add_action("do_drop", "drop");

}



int do_get(string arg)

{

        if( environment() != environment(this_player())

        ||      !id(arg) ) return 0;

        if( (int)this_player()->query("qi") < 20 ) 

                return notify_fail("以你现在的状况，不怕被石头压死？\n");

        if( move(this_player()) ) {

  message_vision("$N弯下腰将地上的" + name() + "一下子扛到背上。\n", this_player());

                return 1;

        }

}



int do_drop(string arg)

{

    if( arg == "shi kuai" || arg == "shi" )

   if( base_name(environment(this_player())) == __DIR__"shanlu7" )

{

            this_player()->add_temp("工钱",1);

 message_vision("$N气喘吁吁的把背上的" + name() + "放在地上。\n", this_player());

            this_player()->add("qi", -40);

            if( this_player()->query("qi") < 50 )

                  this_player()->add("qi", -20);                

            destruct(this_object());

            return 1;

        } else {

            write("还没到目的地呢，请注意维持本mud的环境美。\n");

            return 1;

        }

}







