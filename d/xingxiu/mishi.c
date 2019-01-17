// mishi.c

// by QingP



#include <room.h>



inherit ROOM;



void close_gate();

int do_unlock(string arg);



void create()

{

	set("short", "����");

	set("long", @LONG

��������Ƕ����������ĵط������ܰ����˸��ֶ�������ҩ��

���ҵ��м�ڷ���һ��ľ����

LONG

	);



	set("objects", ([

		__DIR__"obj/xiaoyaosan" : 1,

		__DIR__"obj/shihunxing" : 2,

		__DIR__"obj/lianxindan" : 2,

		__DIR__"obj/wangding" : 1,

	]));

	setup();

}



void init()

{

	add_action("do_unlock", "unlock");

	add_action("do_unlock", "open");

}



void close_gate()

{

    object room;



    if(!( room = find_object(__DIR__"cave1")) )

        room = load_object(__DIR__"cave1");

    if(objectp(room))

    {

        delete("exits/south");

        message("vision","ֻ��ƹ��һ���������Զ������ˡ�\n",this_object());

        message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" ,this_object());

        room->delete("exits/north");

        message("vision","ֻ��ƹ��һ���������Զ�����������\n", room);

        message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n" ,room );

     }

}





int do_unlock(string arg)

{

	object room;

	if (query("exits/south"))

		return notify_fail("�����Ѿ��Ǵ򿪵ġ�\n");

	if (!arg || (arg != "bi"))

		return notify_fail("��Ҫ��ʲô��\n");

	message_vision(	"$N��������˰��š�\n", this_player());

	set("exits/south", __DIR__"cave1");

	if(!( room = find_object(__DIR__"cave1")) )

	room = load_object(__DIR__"cave1");

	if(objectp(room))

	{

        	set("exits/south", __DIR__"cave1");

        	message_vision("$N��������ţ�ֻ��֨��һ�����ſ��ˡ�\n",this_player());

        	room->set("exits/north", __FILE__);

        	message("vision","ֻ��֨��һ�������Ŵ�������ˡ�\n", room);

		remove_call_out("close_gate");

		call_out("close_gate", 10);

	}

return 1;

}