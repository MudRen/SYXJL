// shikuai.c ... angle

 

inherit ITEM;



void create()

{

        set_name("ʯ��", ({ "shi kuai", "shi"}));

        set_weight(40000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

                set("unit", "��");

                set("long", "����һ���޴��ʯ�顣\n");

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

                return notify_fail("�������ڵ�״�������±�ʯͷѹ����\n");

        if( move(this_player()) ) {

  message_vision("$N�����������ϵ�" + name() + "һ���ӿ������ϡ�\n", this_player());

                return 1;

        }

}



int do_drop(string arg)

{

    if( arg == "shi kuai" || arg == "shi" )

   if( base_name(environment(this_player())) == __DIR__"shanlu7" )

{

            this_player()->add_temp("��Ǯ",1);

 message_vision("$N���������İѱ��ϵ�" + name() + "���ڵ��ϡ�\n", this_player());

            this_player()->add("qi", -40);

            if( this_player()->query("qi") < 50 )

                  this_player()->add("qi", -20);                

            destruct(this_object());

            return 1;

        } else {

            write("��û��Ŀ�ĵ��أ���ע��ά�ֱ�mud�Ļ�������\n");

            return 1;

        }

}







