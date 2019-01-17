// cave1.c

// by QingP



inherit ROOM;



void close_gate();

int do_open(string arg);

int do_close(string arg);





void create()

{

	set("short", "ɽ��");

	set("long", @LONG

���ɽ������ż�֧�谵��������ɭɭ�����˸е��������¶��������

�ұߵ�ǽ��(bi)����ȥ�ƺ��е㲻��Ծ���

LONG

	);



	set("item_desc", ([

	"bi":"����ϸ���˿�ǽ�ڣ���������Ȼ��һ�����ε�ʯ�ţ��ɲ�֪��ô�򿪡�\n",

	]));

	set("exits", ([

		"out" : __DIR__"cave",

	]));



	set("objects", ([

		"/kungfu/class/xingxiu/tianlang" : 1,

	]));



	setup();

}



void init()

{

	add_action("do_open", "open");

	add_action("do_open", "unlock");

}



void close_gate()

{

	object room;



	if(!( room = find_object(__DIR__"mishi")) )

		room = load_object(__DIR__"mishi");

	if(objectp(room))

	{

		delete("exits/north");

		message("vision","ֻ��ƹ��һ���������Զ�����������\n",this_object());

                message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n" ,this_object());

		room->delete("exits/south");

		message("vision","ֻ��ƹ��һ���������Զ�����������\n",room);

	        message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" ,room );

	}

}



int do_open(string arg)

{

	object room;

        object ob;



	if (query("exits/north"))

		return notify_fail("�����Ѿ��ǿ����ˡ�\n");



	if (!arg || (arg != "bi" && arg != "north"))

		return notify_fail("��Ҫ��ʲô��\n");

	if (!(ob = present("mishikey", this_player())))

		return notify_fail("�����������\n");

	message_vision("$N��Կ�״��˰��ţ���һ��С��Կ�׿����������.\n", this_player());

	

	destruct(ob);



	if(!( room = find_object(__DIR__"mishi")) )

		room = load_object(__DIR__"mishi");

	if(objectp(room))

	{

		set("exits/north", __DIR__"mishi");

		message_vision("$Nʹ���Ѱ��Ŵ��˿�����\n",this_player());

		room->set("exits/south", __FILE__);

		message("vision","�������˰Ѱ��Ŵ��ˡ�\n",room);

		remove_call_out("close_gate");

		call_out("close_gate", 10);

	}



	return 1;

}



int valid_leave(object me, string dir)

{

	if (objectp(present("tianlang zi", environment(me)))

	&& (dir == "north"||dir == "south")

	&& living(present("tianlang zi", environment(me))))

		return notify_fail("�����ӵ�ס���㣺���˱��Ž��أ��Ͻ������ȥ����ʦ��������ʹ��²����ˣ�\n");

	return ::valid_leave(me, dir);

}