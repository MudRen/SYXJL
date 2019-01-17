// room: /kunlun/zhongt.c 



#include <ansi.h>

inherit ROOM;

int do_dao(string arg);



void create()

{

        set("short", "����");

        set("long", @LONG
�����������������Ϊ�������ɡ�������һ����̴ľ�İ�����������
��һ�軨��(huamiao),����ͯ���������Աߣ������������������׼��ͣ�
����һ���������ɵĴ���ӳ��棬 ������Ϳ��˻������ƽ������������
��̸�����Ҷ������ȡ�
LONG

        );



        set("exits", ([

                "south" : __DIR__"qianting",

                "north" : __DIR__"dating",

                "west" : __DIR__"zoul_3",

                "east" : __DIR__"zoul_4",

        ]));

       set("objects",([

                "/d/kunlun/npc/jiangtao" : 1,
        ]));



        set("item_desc", ([

               "huamiao" : "���������ɽ��ֲ���ɹ����磬��Ϊ���ڷ����ʧȥ������֦Ҷή�ң����ܿ������!\n"

        ]) );



        set("dao_count", 3);

        set("hua_count", 2);



        setup();

//      replace_program(ROOM);

}



void init()

{

        add_action("do_dao", "dao");

        add_action("do_ci", "ci");



}

int do_dao(string arg)

{       mapping fam;

        object me;

        object obhua;

        me = this_player();





        if ( !arg || arg != "huamiao" )

                return 0;



        if (!(fam = me->query("family")) || fam["family_name"] != "������")

               return notify_fail("���뱾�������������ֺα�����������!\n");



    if (! present("xiang cha", this_player()))

        return notify_fail("����ʲô������?!\n");

     

     message_vision(HIG"$Nϸ�ĵذѲ豭���Ů���㵽�ڻ����ϡ�\n"NOR, me);

     if (present("xiang cha", me))

     destruct(present("xiang cha",me));



     add("dao_count", -1);

     if (query("dao_count") > 0) {

        message_vision(HIG"��豻�������գ�֦Ҷ���ø������ˡ�\n"NOR, me);

        return 1;

        }

     if (query("hua_count") >=1)

      {

        add("hua_count", -1);

        write(HIM"ͻȻ�����м䳤��һ�����٣��漴������ԭ�����������ɽ���е������Ứ!\n"NOR);

        message_vision("$NС�������ժ�������Ứ���������˵ش��뻳�С�\n",me);

        obhua = new("/d/kunlun/obj/hua");

        obhua->move(me);

        set("dao_count", 3);

        return 1;

      }

      else

      {

       set("dao_count", 3);

       message_vision(HIG"����Ӫ�����������粻�ܿ�����������\n"NOR, me);

      }

        return 1;

}



