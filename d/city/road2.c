inherit ROOM;

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.

// This software can not be used, copied, or modified in any form without

// the written permission from authors.



void create()

{

        set("short", "÷��֮��");

        set("long", @LONG

���¿�֦���飬����֨֨������Ҷ���Ʈ�裬�������¡�

ż��һ������У����������������������������Ӱ�ζ���
��������������¹���ǵ���Ҵ��ˡ�
LONG

        );

        set("exits", ([ /* sizeof() == 4 */

//      "north" : "/u/smok/village",
          "east" : "/u/smok/entrance_road",

          "west" : "/d/xinfang/bieshuqu",

]));

        set("outdoors", "wanmei");

        setup();

}

void init()

{

	if(interactive(this_player()))

	{

		remove_call_out("dropleaf");

		call_out("dropleaf",random(10)+10,this_player());

	}

}



int dropleaf(object me)

{

	object leaf;

	if(me)

	if(environment(me) == this_object())

	{

		tell_object(me,"һƬ��Ҷ���Ʈ�£�������\n");

		leaf = new(__DIR__"obj/leaf");

		leaf->move(this_object());	

	}

}

