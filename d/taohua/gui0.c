#include <room.h>

#include <ansi.h>



inherit ROOM;



void create()

{ 

        set("short", "ׯ�ڵ�·");

        set("long",@LONG

����һ���������ѵ�С·���������Ÿ�����ľ����ס��

������ߡ�΢�������������Χ�����ĵġ�Զ��ż������һ

����С��㲻���뵽��"���ˣ��Ҹò�����·�˰ɡ�"

LONG

        );

  

	set("outdoors", "taohua");

	set("exits", ([

		"east" :  __FILE__,

		"west" :  __FILE__,

		"south" : __FILE__,

		"north" : __FILE__,

	]));             

        setup();



}

void init()

{

    this_player()->receive_damage("qi", 15);

    this_player()->receive_wound("qi",  15);

    message_vision(HIG "ͻȻһ����Ҷ�����㼲��$N��\n" NOR, this_player());

}



int valid_leave(object me, string dir)

{

       

        int  total_steps ;

        mapping myfam;

        total_steps = ( 100 - (int)this_player()->query_skill("qimen-wuxing",1) ) / 10 ;

        if ( total_steps <= 0 ) total_steps = 1 ;  

        myfam = (mapping) this_player()->query("family");

        if(myfam && myfam["family_name"] == "�һ���") total_steps = 1 ; 

	if ( dir == "north")

            me->add_temp("taohua/steps",1);

	if ( dir == "south")

            me->add_temp("taohua/steps",-1);



	if (me->query_temp("taohua/steps") == total_steps)

         {

     	    me->move(__DIR__"gui-in");

            me->delete_temp("taohua/steps");

             return notify_fail("�����˰��죬�������˳�����\n");

         }  



     if (me->query_temp("taohua/steps") == - total_steps )

	    {  

	     me->move(__DIR__"gui-out");

             me->delete_temp("taohua/steps");

             return notify_fail("�����˰��죬�������˳�����\n");

     	}



        return ::valid_leave(me,dir);

}

